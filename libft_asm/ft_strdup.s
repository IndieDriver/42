global _ft_strdup
extern _ft_strlen
extern _malloc

section .text

_ft_strdup:
	mov r12, rdi
	call _ft_strlen
	cmp rax, 0
	inc rax
	mov r13, rax
	mov rdi, rax
	call _malloc
	mov r14, rax

loop:
	cmp r13, 0
	jle end
	mov r11b, [r12]
	mov [r14], r11b
	inc r12
	inc r14
	dec r13
	jmp loop

end:
	ret
