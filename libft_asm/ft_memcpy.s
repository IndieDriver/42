global _ft_memcpy

section .text

_ft_memcpy:
	mov rax, rdi

loop:
	cmp rdx, 0
	jle end
	mov r11b, [rsi]
	mov [rdi], r11b
	inc rsi
	inc rdi
	dec rdx
	jmp loop

end:
	ret
