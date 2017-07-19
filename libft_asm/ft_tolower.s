global _ft_tolower

section .text

_ft_tolower:
	mov rax, rdi
	cmp rax, byte 'A'
	jb same
	cmp rax, byte 'Z'
	ja same
	add rax, 32

same:
	ret
