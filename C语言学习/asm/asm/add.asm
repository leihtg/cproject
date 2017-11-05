;数据传送示例
.386
.model flat, stdcall
.stack 4096
ExitProcess PROTO, dwExitCode:DWORD

.data
	val1 WORD 1000h
	val2 WORD 2000h
	arrayB BYTE 10h,20h,30h,40h,50h
	arrayW WORD 100h,200h,300h,400h
	arrayD DWORD 10000h,20000h

	Rval SDWORD ?
	Xval SDWORD 26
	Yval SDWORD 30
	Zval SDWORD 40

	array SWORD -3,-6,-1,-10,10,30,40,4
	sentinel SWORD 0
	num dw 11h,12h,13h,14h
	sizeNum = ($-num)
.code
main PROC
	mov eax,1234h
	mov eax,[0989h]
	mov eax,word ptr [18h]
	;;mov eax,cs:[18h]
	;;mov eax,cs:[1]
	;;mov eax,ds:[0]
	mov eax,0
	mov ax,num
	mov ecx,sizeNum
	shr ecx,1
	mov eax,0h
	mov ebx,0h
	L1:
		add ax,word ptr num[ebx]
		add ebx,2h
	loop L1
	call sum
main ENDP

sum PROC
	mov ebx,0
	mov eax,0
	mov ecx,lengthof arrayB
	L2:
		push ebx
		movzx ebx,byte ptr arrayB[ebx]
		add eax,ebx
		pop ebx
		inc ebx
	Loop L2
	ret
sum ENDP

two PROC
	mov esi,OFFSET array
	mov ecx,LENGTHOF array
L1: test WORD PTR [esi],8000h
	pushfd
	add esi,TYPE array
	popfd
	loopnz L1
	jnz quit
	sub esi,TYPE array
	quit:
	INVOKE ExitProcess,0
two ENDP

one PROC
	mov eax,0
	mov ah,127
	add ah,1
	;mov eax,Xval
	neg Xval
	mov ebx,Yval
	sub ebx,Zval
	;add eax,ebx
	add ebx,Xval
	mov Rval,ebx
	;演示MOVZX指令
	mov   bx,0A69Bh
	movzx eax,bx
	movzx edx,bl
	movzx cx,bl
	
	;演示MOVSX指令
	mov   bx,0A69Bh
	movsx eax,bx
	movsx edx,bl
	mov   bl,7Bh
	movsx cx,bl

	;内存-内存的交换
	mov  ax,val1
	xchg ax,val2
	mov  val1,ax

	;直接-偏移量寻址（字节数组）
	mov al,arrayB
	mov al,[arrayB+1]
	mov al,[arrayB+2]

	;直接-偏移量寻址（字数组）
	mov ax,arrayW
	mov ax,[arrayW+2]

	;直接-偏移量寻址（双字数组）
	mov eax,arrayD
	mov eax,[arrayD+4]
	mov eax,[arrayD+4]
	ret
one ENDP

END main