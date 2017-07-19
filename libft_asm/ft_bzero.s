global _ft_bzero

section .text

_ft_bzero:
	cmp rsi, 0
	jbe end
	dec rsi
	mov [rdi+rsi], byte 0
	jmp _ft_bzero

end:
	ret
