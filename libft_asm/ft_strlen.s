global _ft_strlen

section .text

_ft_strlen:
	mov rax, 0

loop:
	cmp [rdi], byte 0
	jz end
	inc rdi
	inc rax
	jmp loop

end:
	ret
