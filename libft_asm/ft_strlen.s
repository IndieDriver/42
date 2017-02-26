global ft_strlen

section .text

ft_strlen:
	mov rax, 0
	
loop:
	cmp [rdi], byte 0
	jz end
	inc rdi
	inc rax
	jmp loop

end:	
	ret
