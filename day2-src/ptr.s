	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 10
	.globl	_main
	.align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp0:
	.cfi_def_cfa_offset 16
Ltmp1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp2:
	.cfi_def_cfa_register %rbp
	leaq	_glob(%rip), %rax
	movl	$0, -4(%rbp)
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rax
	movq	$42, (%rax)
	movq	-16(%rbp), %rax
	movq	(%rax), %rax
	movl	%eax, %ecx
	movl	%ecx, %eax
	popq	%rbp
	retq
	.cfi_endproc

	.section	__DATA,__data
	.globl	_glob                   ## @glob
	.align	3
_glob:
	.quad	255                     ## 0xff


.subsections_via_symbols
