	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 10
	.globl	_main
	.align	4, 0x90
_main:                                  ## @main
## BB#0:
	pushq	%rbp
Ltmp0:
Ltmp1:
	movq	%rsp, %rbp
Ltmp2:
	leaq	_glob(%rip), %rax
	movl	$0, -4(%rbp)
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rax
	movl	$42, (%rax)
	movq	-16(%rbp), %rax
	movl	(%rax), %eax
	popq	%rbp
	retq

	.section	__DATA,__data
	.globl	_glob                   ## @glob
	.align	2
_glob:
	.long	255                     ## 0xff


.subsections_via_symbols
