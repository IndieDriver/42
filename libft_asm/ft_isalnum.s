global _ft_isalnum
extern _ft_isalpha
extern _ft_isdigit

section .text

_ft_isalnum:
	call _ft_isalpha
	cmp rax, 0x0
	jne true
	call _ft_isdigit
	cmp rax, 0x0
	jne true
	mov rax, dword 0x0
	ret

true:
	mov rax, dword 0x1
	ret
