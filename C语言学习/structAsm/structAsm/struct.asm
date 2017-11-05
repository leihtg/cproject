.386
.model flat,stdcall
.stack 4096
ExitProcess PROTO,exitCode:DWORD
Employe STRUCT
	idNum BYTE ?
	lastName BYTE "12"
	ALIGN WORD
	years WORD ?
	ALIGN DWORD
	salary DWORD ?
Employe ENDS

.data
emp1 Employe <>
emp2 Employe <>


.code

main PROC
	mov emp1.years,5
	mov eax,sizeof emp1
	mov emp2.years,5
	mov eax,sizeof emp2
	invoke ExitProcess,0
main ENDP

end main