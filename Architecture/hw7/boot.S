.text
.global start


start:
	movl $stack_top, %esp
	push %ebx
	push %eax
	call main
loop:
	jmp loop


.section ".header", "ax"
	.set MAGIC, 0x1BADB002
	.set FLAGS, 0x00000001
	.set CHECKSUM, -(MAGIC + FLAGS)
	
	.align 4
	.long MAGIC
	.long FLAGS
	.long CHECKSUM


.extern main

.bss
.space 1000
stack_top:
