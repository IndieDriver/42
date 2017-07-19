global _ft_toupper

section .text

_ft_toupper:
	mov rax, rdi
	cmp rax, byte 'a'
	jb same
	cmp rax, byte 'z'
	ja same
	sub rax, 32

same:
	ret
