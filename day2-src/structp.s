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
	subq	$32, %rsp
	movl	$0, -4(%rbp)
	movl	$1, -8(%rbp)
LBB0_1:                                 ## =>This Inner Loop Header: Depth=1
	cmpl	$4, -8(%rbp)
	jge	LBB0_4
## BB#2:                                ##   in Loop: Header=BB0_1 Depth=1
	leaq	L_.str3(%rip), %rdi
	leaq	_it(%rip), %rax
	movl	-8(%rbp), %ecx
	subl	$1, %ecx
	movslq	%ecx, %rdx
	imulq	 $12, %rdx
	movq	%rax, %rsi
	addq	%rdx, %rsi
	movl	(%rsi), %esi
	movl	-8(%rbp), %ecx
	subl	$1, %ecx
	movslq	%ecx, %rdx
	imulq	 $12, %rdx
	addq	%rdx, %rax
	movq	4(%rax), %rdx
	movb	$0, %al
	callq	_printf
	movl	%eax, -20(%rbp)         ## 4-byte Spill
## BB#3:                                ##   in Loop: Header=BB0_1 Depth=1
	movl	-8(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -8(%rbp)
	jmp	LBB0_1
LBB0_4:
	leaq	_it(%rip), %rax
	movq	%rax, -16(%rbp)
	movl	$1, -8(%rbp)
LBB0_5:                                 ## =>This Inner Loop Header: Depth=1
	cmpl	$4, -8(%rbp)
	jge	LBB0_8
## BB#6:                                ##   in Loop: Header=BB0_5 Depth=1
	leaq	L_.str4(%rip), %rdi
	movq	-16(%rbp), %rax
	movl	(%rax), %esi
	movq	-16(%rbp), %rax
	movq	4(%rax), %rdx
	movb	$0, %al
	callq	_printf
	movq	-16(%rbp), %rdx
	addq	$12, %rdx
	movq	%rdx, -16(%rbp)
	movl	%eax, -24(%rbp)         ## 4-byte Spill
## BB#7:                                ##   in Loop: Header=BB0_5 Depth=1
	movl	-8(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -8(%rbp)
	jmp	LBB0_5
LBB0_8:
	movl	$1, %eax
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"foo"

L_.str1:                                ## @.str1
	.asciz	"bar"

L_.str2:                                ## @.str2
	.asciz	"baz"

	.section	__DATA,__data
	.globl	_it                     ## @it
	.align	4
_it:
	.long	1                       ## 0x1
	.quad	L_.str
	.long	2                       ## 0x2
	.quad	L_.str1
	.long	3                       ## 0x3
	.quad	L_.str2

	.section	__TEXT,__cstring,cstring_literals
L_.str3:                                ## @.str3
	.asciz	"item %d: %s\n"

L_.str4:                                ## @.str4
	.asciz	"item %d again: %s\n"


.subsections_via_symbols
