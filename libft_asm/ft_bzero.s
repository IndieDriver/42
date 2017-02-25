global ft_bzero

section .text

ft_bzero:
	cmp rsi, 0
	jbe end
	dec rsi
	mov [rdi+rsi], byte 0 
	jmp ft_bzero 

end:
	ret
