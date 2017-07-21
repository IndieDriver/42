global _ft_strlen

section	.data

max_value equ 18446744073709551615

section .text

_ft_strlen:
	xor rax, rax
	mov rcx, max_value
	repnz scasb
	mov rax, max_value
	sub rax, rcx
	cmp rax, 0
	jz end
	dec rax

end:
	ret
