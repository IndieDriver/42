global _ft_memset

section .text

_ft_memset:
	mov r10, rdi
	mov rax, rsi ;char
	mov rcx, rdx ;count
	rep stosb
	mov rax, r10
	ret
