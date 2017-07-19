global _ft_isascii

section .text

_ft_isascii:
	cmp rdi, byte 0x00
	jb false
	cmp rdi, byte 0x7f
	ja false
	mov rax, dword 0x1
	ret

false:
	mov rax, dword 0x0
	ret
