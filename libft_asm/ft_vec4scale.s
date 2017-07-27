global _ft_vec4scale

section .bss
	scalar: resq 4

section .text

_ft_vec4scale:
	shufps xmm2,xmm2, byte 0 ;populate xmm2 with scalar
	mulps xmm0, xmm2
	mulps xmm1, xmm2
	ret
