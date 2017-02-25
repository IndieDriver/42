global ft_tolower

section .text

ft_tolower:
	mov rax, rdi
	cmp rax, byte 'A'
	jb same
	cmp rax, byte 'Z'
	ja same
	sub rdi, 32

same:
	ret
