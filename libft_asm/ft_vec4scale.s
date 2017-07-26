global _ft_vec4scale

section .bss
	scalar: resq 4

section .text

_ft_vec4scale:
	movss [scalar], xmm2
	movss [scalar+4], xmm2


