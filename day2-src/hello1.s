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
	subq	$16, %rsp
	movl	$0, -4(%rbp)
	movl	$10, -8(%rbp)
LBB0_1:                                 ## =>This Inner Loop Header: Depth=1
	cmpl	$0, -8(%rbp)
	jl	LBB0_3
## BB#2:                                ##   in Loop: Header=BB0_1 Depth=1
	leaq	L_.str(%rip), %rdi
	callq	_puts
	movl	-8(%rbp), %ecx
	subl	$1, %ecx
	movl	%ecx, -8(%rbp)
	movl	%eax, -12(%rbp)         ## 4-byte Spill
	jmp	LBB0_1
LBB0_3:
	xorl	%eax, %eax
	addq	$16, %rsp
	popq	%rbp
	retq

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"Hello"


.subsections_via_symbols
