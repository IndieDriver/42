global ft_isalnum
extern ft_isalpha
extern ft_isdigit

section .text

ft_isalnum:
	call ft_isalpha
	cmp rax, 0x0
	jne true 
	call ft_isdigit
	cmp rax, 0x0
	jne true
	mov rax, dword 0x0
	ret

true:
	mov rax, dword 0x1
	ret
