	.arch msp430g2553
	.p2align 1,0
	.text

	.global led_init
	.global led_update
	.global toggle_red
	.global toggle_green
	.extern P1OUT P1DIR

led_init:
	bis #65, &P1DIR
	pop r0

led_update:
	cmp #0, r12
	jnz off
	bis #1, &P1OUT
	and #~64, &P1OUT
	pop r0
off:	
	and #~1, &P1OUT
	bis #64, &P1OUT
	pop r0

toggle_red:
	cmp #0, r12
	jnz onRed
	and #~1, &P1OUT
	pop r0
onRed:
	bis #1, &P1OUT
	pop r0

toggle_green:
	cmp #0, r12
	jnz onGreen
	and #~64, &P1OUT
	pop r0
onGreen:
	bis #64, &P1OUT
	pop r0
