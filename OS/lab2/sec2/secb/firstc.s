	.file	"firstc.c"
	.globl	i
	.data
	.align 4
	.type	i, @object
	.size	i, 4
i:
	.long	12345
	.globl	y
	.align 8
	.type	y, @object
	.size	y, 8
y:
	.long	4237242936
	.long	1072939201
	.section	.rodata
.LC1:
	.string	"i=%d, y=%f\n"
	.text
	.globl	display_varaibles
	.type	display_varaibles, @function
display_varaibles:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movsd	.LC0(%rip), %xmm0
	movsd	%xmm0, -8(%rbp)
	movl	i(%rip), %eax
	movq	-8(%rbp), %rdx
	movq	%rdx, -24(%rbp)
	movsd	-24(%rbp), %xmm0
	movl	%eax, %esi
	movl	$.LC1, %edi
	movl	$1, %eax
	call	printf
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	display_varaibles, .-display_varaibles
	.section	.rodata
.LC2:
	.string	"%d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	y(%rip), %rdx
	movl	i(%rip), %eax
	movq	%rdx, -24(%rbp)
	movsd	-24(%rbp), %xmm0
	movl	%eax, %esi
	movl	$.LC1, %edi
	movl	$1, %eax
	call	printf
	movl	$0, %eax
	call	display_varaibles
	movl	$0, -4(%rbp)
	movl	$0, -8(%rbp)
	jmp	.L3
.L4:
	movl	-4(%rbp), %eax
	movl	%eax, %edi
	call	fib
	movl	%eax, %esi
	movl	$.LC2, %edi
	movl	$0, %eax
	call	printf
	addl	$1, -4(%rbp)
	addl	$1, -8(%rbp)
.L3:
	cmpl	$10, -8(%rbp)
	jle	.L4
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	main, .-main
	.globl	fib
	.type	fib, @function
fib:
.LFB4:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$24, %rsp
	.cfi_offset 3, -24
	movl	%edi, -20(%rbp)
	cmpl	$0, -20(%rbp)
	jne	.L7
	movl	$0, %eax
	jmp	.L8
.L7:
	cmpl	$1, -20(%rbp)
	jne	.L9
	movl	$1, %eax
	jmp	.L8
.L9:
	movl	-20(%rbp), %eax
	subl	$1, %eax
	movl	%eax, %edi
	call	fib
	movl	%eax, %ebx
	movl	-20(%rbp), %eax
	subl	$2, %eax
	movl	%eax, %edi
	call	fib
	addl	%ebx, %eax
.L8:
	addq	$24, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4:
	.size	fib, .-fib
	.section	.rodata
	.align 8
.LC0:
	.long	2954937500
	.long	1074882674
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.11) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
