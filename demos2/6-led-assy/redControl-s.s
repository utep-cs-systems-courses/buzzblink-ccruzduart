	.arch msp430g2553
	.p2align 1,0
	.text

	.global redControl
	.extern P1OUT

redControl:
	cmp #0, r12
	jz off
	bis #1, &P1OUT
	pop r0
off:
	and #~1, &P1OUT
	pop r0