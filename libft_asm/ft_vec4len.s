global _ft_vec4len

section .text

_ft_vec4len:
	mulps xmm0, xmm0
	haddps xmm0, xmm0
	mulps xmm1, xmm1
	haddps xmm1, xmm1
	addss xmm0, xmm1
	sqrtss xmm0, xmm0
	ret
