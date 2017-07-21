global _ft_strdup
extern _ft_strlen
extern _malloc

section .text

_ft_strdup:
	mov r12, rdi
	call _ft_strlen
	inc rax
	mov r13, rax
	mov rdi, rax
	call _malloc
	mov r14, rax
	mov r10, rdi
	dec r13
	mov rcx, r13
	mov rsi, r12
	mov rdi, r14
	repz movsb

end:
	mov rax, r14
	ret
