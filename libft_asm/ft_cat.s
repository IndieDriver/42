global _ft_cat

section .bss
	buf resb 32

section .text

_ft_cat:
	mov r12, rdi
	cmp rdi, -1
	jae end

cat:
    mov rax, 0x2000003 	; read
	mov rdi, r12
	mov rsi, buf
	mov rdx, 32
	syscall
	cmp rax, -1
	je end
	mov rdx, rax
	mov r13, rax
    mov rax, 0x2000004 	; write
	mov rdi, 1
	mov rsi, buf
	syscall
	cmp r13, 32
	jnz stdfd
	jmp cat

stdfd:
	cmp r12, 3
	jb cat

end:
	ret
