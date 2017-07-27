global _ft_vec4dot

section .text

_ft_vec4dot:
	mulps xmm0, xmm2
	mulps xmm1, xmm3
	haddps xmm0, xmm1
	haddps xmm0, xmm0
	addss xmm0, xmm1
	ret
