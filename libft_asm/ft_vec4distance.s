global _ft_vec4distance

section .text

_ft_vec4distance:
	subps xmm0, xmm2
	subps xmm1, xmm3
	mulps xmm0, xmm0
	mulps xmm1, xmm1
	haddps xmm0, xmm1
	haddps xmm1, xmm1
	addss xmm0, xmm1
	sqrtss xmm0, xmm0
	ret

