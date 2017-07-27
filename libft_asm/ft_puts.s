global _ft_puts
extern _ft_strlen

section .data

null:	db "(null)", 10
newline: db 10

section .text

_ft_puts:
	cmp rdi, 0x0
	je _null
	mov	r12, rdi
	call _ft_strlen
	mov r13, rax
    mov rax, 0x2000004 	; write
	mov rdi, 1			; fd
	mov rsi, r12		; string
	mov rdx, r13		; len
	syscall

end:
    mov rax, 0x2000004 	; write
	mov rdi, 1			; fd
	lea rsi, [rel newline]
	mov rdx, 1			; len
	syscall
	mov rax, 10
	ret

_null:
    mov rax, 0x2000004 	; write
	mov rdi, 1			; fd
	lea rsi, [rel null]
	mov rdx, 7	; len
	syscall
	mov rax, 10
	ret
