	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 10
	.globl	_main
	.align	4, 0x90
_main:                                  ## @main
## BB#0:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	calll	L0$pb
L0$pb:
	popl	%eax
	movl	$0, -4(%ebp)
	movl	$10, -8(%ebp)
	movl	%eax, -12(%ebp)         ## 4-byte Spill
LBB0_1:                                 ## =>This Inner Loop Header: Depth=1
	cmpl	$0, -8(%ebp)
	jl	LBB0_3
## BB#2:                                ##   in Loop: Header=BB0_1 Depth=1
	movl	-12(%ebp), %eax         ## 4-byte Reload
	leal	L_.str-L0$pb(%eax), %ecx
	movl	%ecx, (%esp)
	calll	_myfunc
	movl	-8(%ebp), %eax
	addl	$4294967295, %eax       ## imm = 0xFFFFFFFF
	movl	%eax, -8(%ebp)
	jmp	LBB0_1
LBB0_3:
	xorl	%eax, %eax
	addl	$24, %esp
	popl	%ebp
	retl

	.globl	_myfunc
	.align	4, 0x90
_myfunc:                                ## @myfunc
## BB#0:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	calll	L1$pb
L1$pb:
	popl	%eax
	movl	8(%ebp), %ecx
	leal	L_.str1-L1$pb(%eax), %eax
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %ecx
	movl	%eax, (%esp)
	movl	%ecx, 4(%esp)
	calll	_printf
	movl	%eax, -8(%ebp)          ## 4-byte Spill
	addl	$24, %esp
	popl	%ebp
	retl

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"world"

L_.str1:                                ## @.str1
	.asciz	"hello %s\n"


.subsections_via_symbols
