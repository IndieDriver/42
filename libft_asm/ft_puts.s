global _ft_puts
extern _ft_strlen

section .data

null:	db "(null)", 10
.len:	equ	$ - null

section .text

_ft_puts:
	mov	r11, rdi
	call _ft_strlen
	mov r12, rax
	cmp r12, byte 0
	je err
    mov rax, 0x2000004 	; write
	mov rdi, 1			; fd
	mov rsi, r11		; string
	mov rdx, r12		; len
	syscall

end:
	mov rax, 10
	ret

err:
    mov rax, 0x2000004 	; write
	mov rdi, 1			; fd
	mov rsi, null		; string
	mov rdx, null.len	; len
	syscall
	mov rax, -1
	ret


