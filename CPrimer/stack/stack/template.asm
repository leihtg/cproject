.386
.model flat, stdcall
.stack 4096
ExitProcess PROTO, dwExitCode:DWORD

.data
	aName BYTE "Welcome to BeiJing!",0
	nameSize = ($-aName)-1
	array DWORD 1h,2h,3h,4h
	sum DWORD ?
.code
main PROC
	mov esi, OFFSET array
	mov ecx, LENGTHOF array
	call ArraySum
	mov sum,eax
	
	mov ecx, nameSize
	mov esi, 0
L1: movzx eax,aName[esi]
	push  eax
	inc   esi
	Loop L1

	mov ecx, nameSize
	mov esi, 0
L2: pop eax
	mov aName[esi], al
	inc esi
	Loop L2

	INVOKE ExitProcess, 0

main ENDP

;计算32位整数数组元素之和
ArraySum PROC
	push esi
	push ecx
	mov  eax,0

L1: add  eax,[esi]
	add  esi,TYPE DWORD

	Loop L1

	pop  ecx
	pop  esi

	ret
ArraySum ENDP
END main