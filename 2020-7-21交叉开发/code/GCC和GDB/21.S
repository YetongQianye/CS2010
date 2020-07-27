	.cpu cortex-a15
	.fpu softvfp
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 2
	.eabi_attribute 30, 6
	.eabi_attribute 34, 1
	.eabi_attribute 18, 4
	.arm
	.syntax divided
	.file	"2.c"
	.section	.rodata
	.align	2
.LC0:
	.ascii	"hello world\000"
	.text
	.align	2
	.global	main
	.type	main, %function
main:
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	str	fp, [sp, #-8]!
	str	lr, [sp, #4]
	add	fp, sp, #4
	sub	sp, sp, #8
	movw	r0, #:lower16:.LC0
	movt	r0, #:upper16:.LC0
	bl	puts
	mov	r3, #3
	str	r3, [fp, #-8]
	mov	r3, #0
	mov	r0, r3
	sub	sp, fp, #4
	@ sp needed
	ldr	fp, [sp]
	add	sp, sp, #4
	ldr	pc, [sp], #4
	.size	main, .-main
	.ident	"GCC: (Buildroot 2016.11) 5.4.0"
	.section	.note.GNU-stack,"",%progbits
