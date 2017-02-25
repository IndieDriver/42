global ft_toupper

section .text

ft_toupper:
	mov rax, rdi
	cmp rax, byte 'a'
	jb same
	cmp rax, byte 'z'
	ja same
	add rax, 32

same:
	ret
