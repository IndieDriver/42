global _ft_memcpy

section .text

_ft_memcpy:
	mov r10, rdi
	mov rcx, rdx
	rep movsb
	mov rax, r10

end:
	ret
