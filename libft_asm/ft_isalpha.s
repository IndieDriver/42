global ft_isalpha

section .text

ft_isalpha:
	cmp rdi, byte 'A' 
	jb false
	cmp rdi, byte 'z'
	ja false
	cmp rdi, byte 'Z'
	jbe true
	cmp rdi, byte 'a'
	jae true

false:
	mov rax, dword 0x0
	ret

true:
	mov rax, dword 0x1 
	ret
