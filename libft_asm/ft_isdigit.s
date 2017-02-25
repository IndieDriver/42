global ft_isdigit

section .text

ft_isdigit:
	cmp rdi, byte '0'
	jb false
	cmp rdi, byte '9'
	ja false
	mov rax, dword 0x1
	ret

false:
	mov rax, dword 0x0
	ret
