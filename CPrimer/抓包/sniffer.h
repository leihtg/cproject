#ifndef SNIFFER_HEADER
#define SNIFFER_HEADER

#include <winsock2.h>
#pragma comment(lib,"ws2_32.lib")

// Standard TCP flags 
#define URG 0x20 
#define ACK 0x10 
#define PSH 0x08 
#define RST 0x04 
#define SYN 0x02 
#define FIN 0x01 
typedef struct _iphdr //定义IP首部 
{ 
	unsigned char h_lenver; //4位首部长度+4位IP版本号 
	unsigned char tos; //8位服务类型TOS 
	unsigned short total_len; //16位总长度（字节） 
	unsigned short ident; //16位标识 
	unsigned short frag_and_flags; //3位标志位 
	unsigned char ttl; //8位生存时间 TTL 
	unsigned char proto; //8位协议 (TCP, UDP 或其他) 
	unsigned short checksum; //16位IP首部校验和 
	unsigned int sourceIP; //32位源IP地址 
	unsigned int destIP; //32位目的IP地址 
}IP_HEADER; 

typedef struct psd_hdr //定义TCP伪首部 
{ 
	unsigned long saddr; //源地址 
	unsigned long daddr; //目的地址 
	char mbz; 
	char ptcl; //协议类型 
	unsigned short tcpl; //TCP长度 
}PSD_HEADER; 

typedef struct _tcphdr //定义TCP首部 
{ 
	USHORT th_sport; //16位源端口 
	USHORT th_dport; //16位目的端口 
	unsigned int th_seq; //32位序列号 
	unsigned int th_ack; //32位确认号 
	unsigned char th_lenres;   //4位首部长度/6位保留字 
	unsigned char th_flag; //6位标志位 
	USHORT th_win; //16位窗口大小 
	USHORT th_sum; //16位校验和 
	USHORT th_urp; //16位紧急数据偏移量 
}TCP_HEADER; 

//TCP伪首部并不是真正存在的，只是用于计算检验和。校验和函数： 

USHORT checksum(USHORT *buffer, int size) 
{ 
	unsigned long cksum=0; 
	while (size > 1) 
	{ 
		cksum += *buffer++; 
		size -= sizeof(USHORT);   
	} 
	if (size) 
	{ 
		cksum += *(UCHAR*)buffer;   
	} 
	cksum = (cksum >> 16) + (cksum & 0xffff); 
	cksum += (cksum >>16); 
	return (USHORT)(~cksum); 
} 


#endif