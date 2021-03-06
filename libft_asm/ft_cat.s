global _ft_cat

section .bss
	buf: resb 32

section .text

_ft_cat:
	mov r12, rdi
	cmp rdi, -1
	jae end

read:
    mov rax, 0x2000003 	; read
	mov rdi, r12
	lea rsi, [rel buf]
	mov rdx, 32
	syscall
	cmp r12, 3
	jae write
	cmp rax, byte 0 ;test eof
	jle end

write:
	mov rdx, rax
	mov r13, rax
    mov rax, 0x2000004 	; write
	mov rdi, 1
	lea rsi, [rel buf]
	syscall
	jc end
	cmp r13, 32
	jnz stdfd
	jmp read

stdfd:
	cmp r12, 3
	jb read

end:
	ret
