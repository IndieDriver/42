global _ft_vec4normalize
extern _ft_vec4len
extern _ft_vec4scale

section .text

_ft_vec4normalize:
	movups xmm0, [rdi]
	movups xmm1, [rdi+8]
	movaps xmm4, xmm0
	movaps xmm5, xmm1
	call _ft_vec4len
	mov eax, 1
	cvtsi2ss xmm2, eax
	divss xmm2, xmm0
	movups xmm0, xmm4
	movups xmm1, xmm5
	call _ft_vec4scale
	movups [rdi], xmm0
	movups [rdi+8], xmm1
	ret

