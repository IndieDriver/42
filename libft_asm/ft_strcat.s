global _ft_strcat

section .text

_ft_strcat:
	mov rax, rdi

loop:
	cmp [rdi], byte 0
	jz copy
	inc rdi
	jmp loop

copy:
	cmp[rsi], byte 0
	jz end
	mov cx, [rsi]
	mov [rdi], cx
	inc rsi
	inc rdi
	jmp copy

end:
	mov [rdi] , byte 0
	ret
