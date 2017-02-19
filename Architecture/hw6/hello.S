	.code16
	.text
	.global start
start:
	ljmp $0x0, $real_start

real_start:
	movw $0, %ax
	movw %ax, %ds
	movw %ax, %ss

	/* setup stack pointer */
	movw $0x7c00, %sp
	addw $0x0400, %sp

	movw $0xB800, %ax
	movw %ax, %es
	movw $data, %si
	movw $0, %di
	movw size, %cx
	call memcpy

loop:
	jmp loop

/* copies %cx bytes from %ds:%si, %es:%di */
memcpy:
	testw %cx, %cx
	jz out
again:
	movb (%si), %ah
	movb %ah, %es:(%di)
	incw %si
	incw %di
	decw %cx
	jnz again
out:
	ret

data:
	.asciz "H0e0l0l0o0,0 0W0o0r0l0d0!0"
size:
	.short . - data
