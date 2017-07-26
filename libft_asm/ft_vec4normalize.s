global _ft_vec4normalize
extern _ft_vec4len

section .text

_ft_vec4normalize:
	movups xmm0, [rdi]
	movups xmm1, [rdi+8]
	movaps xmm4, xmm0
	movaps xmm5, xmm1
	call _ft_vec4len
	mov eax, 1
	cvtsi2ss xmm6, eax
	divss xmm6, xmm0
	mulss xmm4, xmm6
	mulss r
	mulss [xmm4+8], xmm6

	movups xmm0, xmm4
	movups xmm1, xmm5
	;movups xmm0, xmm6
	;addsd   xmm6,xmm0
	ret

