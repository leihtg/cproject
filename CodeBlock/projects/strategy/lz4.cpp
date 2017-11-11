/* Default value is 14, for 16KB, which nicely fits into Intel x86 L1 cache。
 * Increasing memory usage improves compression ratio
 * Reduced memory usage can improve speed, due to cache effect
 */

#define MEMORY_USAGE 14
#define LZ4_HASHLOG (MEMORY_USAGE - 2) /* 哈希桶位数12 */
#define HASHTABLESIZE (1 << MEMORY_USAGE) /* 哈希表大小2^14 = 16K */
#define HASHNBCELLS4 (1 << LZ4_HASHLOG) /* 哈希桶个数2^12 = 4K */
#define FORCE_INLINE inline



typedef enum { byPtr,
               byU32, byU16
             } tableType_t;

FORCE_INLINE int LZ4_hashSequence(U32 sequence, tableType_t tableType)
{
    if (tableType == byU16)
        /* 哈希表为16K，如果哈希value为16位 => 哈希key为13位 */
        return (((sequence) * 2654435761U) >> ((MINMATCH * 8) - (LZ4_HASHLOG + 1)));
    else
        /* 哈希表为16K，如果哈希value为32位 => 哈希key为12位 */
        return (((sequence) * 2654435761U) >> ((MINMATCH * 8) - LZ4_HASHLOG));
}


FORCE_INLINE int LZ4_hashPosition(const BYTE *p, tableType_t tableType)
{
    return LZ4_hashSequence(A32(p), tableType);
}

FORCE_INLINE void LZ4_putPositionOnHash(const BYTE *p, U32 h, void *tableBase, tableType_t tableType,
                                        const BYTE *srcBase)
{
    switch(tableType)
    {
    case byPtr:
    {
        const BYTE **hashTable = (const BYTE **) tableBase;
        hashTable[h] = p;
        break;
    }
    case byU32:
    {
        U32 *hashTable = (U32 *) tableBase;
        hashTable[h] = (U32) (p - srcBase);
        break;
    }
    case byU16:
    {
        U16 *hashTable = (U16 *) tableBase;
        hashTable[h] = (U16) (p - srcBase);
        break;
    }
    }
}


FORCE_INLINE void LZ4_putPosition(const BYTE *p, void *tableBase, tableType_t tableType, const BYTE *srcBase)
{
    U32 h = LZ4_hashPosition(p, tableType); /* 计算哈希值 */
    LZ4_putPositionOnHash(p, h, tableBase, tableType, srcBase); /* 把地址存入哈希表 */
}


FORCE_INLINE const BYTE *LZ4_getPositionOnHash(U32 h, void *tableBase, tableType_t tableType,
        const BYTE *srcBase)
{
    if (tableType == byPtr)
    {
        const BYTE **hashTable = (const BYTE **) tableBase;
        return hashTable[h];
    }
    if (tableType == byU32)
    {
        U32 *hashTable = (U32 *) tableBase;
        return hashTable[h] + srcBase;
    }
    {
        U16 *hashTable = (U16 *) tableBase;    /* default, to ensure a return */
        return hashTable[h] + srcBase;
    }
}


FORCE_INLINE const BYTE *LZ4_getPosition(const BYTE *p, void *tableBase, tableType, const BYTE *srcBase)
{
    U32 h = LZ4_hashPosition(p, tableType);
    return LZ4_getPositionOnHash(h, tableBase, tableType, srcBase);
}

/* LZ4_compress():
 * Compress inputSize bytes from source into dest.
 * Destination buffer must be already allocated, and must be sized to handle worst cases situations
 * (input data not compressible)
 * Worst case size evaluation is provided by function LZ4_compressBound()
 * inputSize: Max support value is LZ4_MAX_INPUT_VALUE
 * return: the number of bytes written in buffer dest or 0 if the compression fails.
 */

int LZ4_compress(const char *source, char *dest, int inputSize)
{
#if (HEAPMODE) /* 在堆中给哈希表分配内存 */
    void *ctx = ALLOCATOR(HASHNBCELLS4, 4); /* Aligned on 4-bytes boundaries */
#else /* 在栈中给哈希表分配内存，比较快，默认 */
    U32 ctx[1U << (MEMORY_USAGE - 2) ] = {0}; /* Ensure data is aligned on 4-bytes boundaries */
#endif
    int result;

    /* 输入小于64K+11，则用16位来表示滑动窗口，否则用32位*/
    if (inputSize < (int) LZ4_64KLIMIT)
        result = LZ4_compress_generic((void *)ctx, source, dest, inputSize, 0, notLimited, byU16, noPrefix);
    else
        result = LZ4_compress_generic((void *)ctx, source, dest, inputSize, 0, notLimited,
                                      (sizeof(void *) == 8 ? byU32 : byPtr, noPrefix);

#if (HEAPMODE)
                                      FREE(ctx);
#endif
                                      return result;
}



#define MINMATCH 4 /* 以4字节为单位查找哈希表 */
#define COPYLENGTH 8
#define LASTLITERALS 5
#define MFLIMIT (COPYLENGTH + MINMATCH) /* 对于最后的12个字节，不进行查找匹配 */
         const int LZ4_minLength = (MFLIMIT + 1); /* 一个块要>=13个字符，才会进行查找匹配 */
#define LZ4_64KLIMIT ((1<<16) + (MFLIMIT - 1)) /* 64K + 11 */
/* Increasing this value will make the compression run slower on incompressible data。
 * 用于控制查找匹配时的前进幅度，如果一直没找到匹配，则加大前进幅度。
 */
#define SKIPSTRENGTH 6


FORCE_INLINE int LZ4_compress_generic(void *ctx, const char *source, char *dest, int inputSize,
                                      int maxOutputSize, limitedOutput_directive limitedOutput, tableType_t tableType,
                                      prefix64k_directive prefix)
{
    const BYTE *ip = (const BYTE *) source;
    /* 用作哈希表中的srcBase */
    const BYTE *const base = (prefix == withPrefix) ? ((LZ4_Data_Structure *)ctx)->base : (const BYTE *)source);
    /* 前向窗口的起始地址 */
    const BYTE *const lowLimit = ((prefix == withPrefix) ? ((LZ4_Data_Structure *)ctx)->bufferStart : (const BYTE *)source);
    const BYTE *anchor = (const BYTE *)source;
    const BYTE *const iend = ip + inputSize; /* 输入的结束地址 */
    const BYTE *const mflimit = iend - MFLIMIT; /* iend - 12，超过此处不允许再启动一次匹配 */
    const BYTE *const matchlimit = iend - LASTLITERALS; /* iend - 5，最后5个字符不允许匹配 */

    BYTE *op = (BYTE *) dest; /* 用于操作输出缓存 */
    BYTE *const oend = op + maxOutputSize; /* 输出缓存的边界，如果有的话 */

    int length;
    const int skipStrength = SKIPSTRENGTH; /* 6 */
    U32 forwardH;

    /* Init conditions */
    if ((U32) inputSize > (U32) LZ4_MAX_INPUT_SIZE) return 0; /* 输入长度过大 */
        /* must continue from end of previous block */
        if ((prefix == withPrefix) && (ip != ((LZ4_Data_Structure *)ctx)->nextBlock)) return 0;
            /* do it now, due to potential early exit. 保存下一个块的起始地址 */
            if (prefix == withPrefix) ((LZ4_Data_Structure *)ctx)->nextBlock = iend;
                if ((tableType == byU16) && (inputSize >= LZ4_64KLIMIT)) return 0; /* Size too large (not within 64K limit) */
                    if (inputSize < LZ4_minlength) goto _last_literals; /* 如果输入长度小于13，则不查找匹配 */

                    /* First Byte */
                    LZ4_putPosition(ip, ctx, tableType, base); /* 计算以第一个字节开头的U32的哈希值，保存其位置 */
                    ip++;
                    forwardH = LZ4_hashPosition(ip, tableType); /* 计算以第二个字节开头的U32的哈希值 */

                    /* Main loop，每次循环查找一个匹配，产生一个序列 */
                    for ( ; ; )
{
    int findMatchAttempts = (1U << skipStrength) + 3;
        const BYTE *forwardIp = ip;
        const BYTE *ref;
        BYTE *token;

        /* Find a match，查找一个匹配，或者到了尽头mflimit */
        do
        {
            U32 h = forwardH; /* 当前ip对应的哈希值 */
            int step = findMatchAttempts++ >> skipStrength; /* forwardIp的偏移，一般是1 */
            ip = forwardIp;
            forwardIp = ip + step; /* 前向缓存中下个将检查的地址 */

            if unlikely(forwardIp > mflimit)
            {
                goto _last_literals;    /* >=12字节才会去匹配 */
            }
            forwardH = LZ4_hashPosition(forwardIp, tableType); /* forwardIp的哈希值 */

            /* 这里是查找的关键：按照哈希值h，获取地址ref。
             * 1. 没有匹配，ref为srcBase。
             * 2. 有匹配。
             *     2.1 不在滑动窗口内，继续。
             *     2.2 对应的U32不一样，是冲突，继续。
             *     2.3 在滑动窗口内，且对应的U32一样，找到了match，退出。
             */
            ref = LZ4_getPositionOnHash(h, ctx, tableType, base);
            LZ4_putPositionOnHash(ip, h, ctx, tableType, base); /* 保存ip、h这个对应关系 */
        }
        while ((ref + MAX_DISTANCE < ip) || (A32(ref) != A32(ip)));

        /* 找到匹配之后，看能否向前扩大匹配 */
        while((ip > anchor) && (ref > lowLimit) && unlikely(ip[-1] == ref[-1]))
        {
            ip--;
            ref--;
        }

        /* Encode Literal length，赋值Literal length */
        length = (int) (ip - anchor);
        token = op++;

        /* Check output limit */
        if ((limitedOutput) & unlikely(op + length + 2 + (1 + LASTLITERALS) + (length>>8) > oend)) return 0;

        if (length >= (int) RUN_MASK)
        {
            int len = length - RUN_MASK;
            *token = (RUN_MASK << ML_BITS);
            for(; len >= 255; len -= 255) *op++ = 255;
            *op++ = (BYTE) len;
        }
        else
            *token = (BYTE) (length << ML_BITS);

        /* Copy Literals，复制不可编码字符 */
        {
            BYTE * end = (op) + (length);
            LZ4_WILDCOPY(op, anchor, end);
            op = end;
        }

_next_match: /* 向后扩展匹配 */
        /* Encode Offset，赋值offset，op += 2 */
        LZ4_WRITE_LITTLEENDIAN_16(op, (U16) (ip - ref));

        /* Start Counting */
        ip += MINMATCH;
        ref += MINMATCH; /* MinMatch already verified */
        anchor = ip;

        while likely(ip < matchlimit - (STEPSIZE - 1))
        {
            size_t diff = AARCH(ref) ^ AARCH(ip); /* 异或，值为零表示相同 */
            if (! diff)
            {
                ip += STEPSIZE;
                ref += STEPSIZE;
                continue;
            }
            ip += LZ4_NbCommonBytes(diff); /* STEPSIZE不同，看其中有多少个字节是相同的 */
            goto _endCount;
        }

        if (LZ4_ARCH64)
            if ((ip < (matchlimit - 3)) && (A32(ref) == A32(ip)))
            {
                ip += 4;
                ref += 4;
            }
        if ((ip < matchlimit - 1)) && (A16(ref) == A16(ip)))
        {
            ip += 2;
            ref += 2;
        }
        if ((ip < matchlimit) && (*ref == *ip)) ip++;

_endCount:
            /* Ecode MatchLength，赋值match length */
            length = (int) (ip - anchor);
            /* Check output limit */
            if ((limitedOutput) && unlikely(op + (1 + LASTLITERALS) + (length >> 8) > oend)) return 0;

                if (length >= (int) ML_MASK)
                {
                    *token += ML_MASK;
                    length -= ML_MASK;
                    for (; length > 509; length -= 510)
                    {
                        *op++ = 255;
                        *op++ = 255;
                    }
                    if (length >= 255)
                    {
                        length -= 255;
                        *op++ = 255;
                    }
                    *op++ = (BYTE) (length);
                }
                else
                    *token += (BYTE) (length);

                    /* Test end of chunk */
                    if (ip > mflimit)
                {
                    anchor = ip;    /* 不再进行匹配了 */
                    break;
                }
    /* Fill table，顺便保存 */
    LZ4_putPosition(ip - 2, ctx, tableType, base);

    /* Test next position，尝试着找匹配 */
    ref = LZ4_getPosition(ip, ctx, tableType, base);
    LZ4_putPosition(ip, ctx, tableType, base);
    /* 如果找到匹配，说明没有literals，可以直接跳过查找、赋值literal length */
    if ((ref + MAX_DISTANCE >= ip) && (A32(ref) == A32(ip)))
        {
            token = op++;
            *token = 0;
            goto _next_match;
        }

        /* Prepare next loop，准备进行下个循环 */
        anchor = ip++;
        forwardH = LZ4_hashPosition(ip, tableType);
    }

_last_literals:
    /* Encode Last Literals */
    {
        int lastRun = (int) (iend - anchor); /* 最后原字符串长度 */

        if ((limitedOutput) && (((char *)op - dest) + lastRun + 1 + ((lastRun + 255 - RUN_MASK) / 255) >
                                (U32) maxOutputSize))
            return 0; /* check output limit */

        if (lastRun >= (int) RUN_MASK)
        {
            *op ++ = (RUN_MASK << ML_BITS);
            lastRun -= RUN_MASK;
            for (; lastRun >= 255; lastRun -=255) *op++ = 255;
            *op++ = (BYTE) lastRun;
        }
        else
            *op++ = (BYTE) (lastRun << ML_BITS);

        memcpy(op, anchor, iend - anchor); /* 复制literals */
        op += iend - anchor;
    }

    /* End */
    return (int) (((char *)op) - dest); /* 返回压缩后的长度 */
}

#define LZ4_MAX_INPUT_SIZE 0x7E000000 /* 2 113 929 216 bytes */
#define ML_BITS 4 /* Token: 4-low-bits, match length */
#define ML_MASK ((1U << ML_BITS) - 1)
#define RUN_BITS (8 - ML_BITS) /* Token: 4-high-bits, literal length */
#define RUN_MASK ((1U << RUN_BITS) - 1)

#define MAXD_LOG 16 /* 滑动窗口的位数 */
#define MAX_DISTANCE ((1 << MAXD_LOG) - 1) /* 滑动窗口的最大值 */
