global _ft_isprint

section .text

_ft_isprint:
	cmp rdi, byte 0x20
	jb false
	cmp rdi, byte 0x7e
	ja false
	mov rax, dword 0x1
	ret

false:
	mov rax, dword 0x0
	ret
