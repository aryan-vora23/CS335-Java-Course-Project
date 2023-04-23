.LC0:
	.string  "%d\n"
	.text
	.globl main
System.println:
	pushq	%rbp
	movq	%rsp, %rbp
	movq	16(%rbp), %rsi
	leaq	.LC0(%rip), %rdi
	movq	$0, %rax
	call printf@PLT
	movq	$0, %rax
	movq	%rbp, %rsp
	popq	%rbp
	ret
Shift.ShiftLeft:
push	%rbp
movq	%rsp, %rbp
subq	$8, %rsp
movq	16(%rbp), %r9
movq	24(%rbp), %r10
movq	$0, %r8
addq	%r9, %r8
movq	%r10, %rcx
salq	%cl, %r8
movq	-8(%rbp), %r11
movq	%r8, %r11
movq	%r11, -8(%rbp)
movq	%r11, %rax
addq	$8, %rsp
movq	%rbp, %rsp
popq	%rbp
ret
main:
push	%rbp
movq	%rsp, %rbp
subq	$24, %rsp
movq	-8(%rbp), %r12
movq	$1, %r12
movq	%r12, -8(%rbp)
movq	-16(%rbp), %r13
movq	$2, %r13
movq	%r13, -16(%rbp)
movq	-24(%rbp), %r14
movq	$4, %r14
movq	%r14, -24(%rbp)
pushq	-8(%rbp)
pushq	-16(%rbp)
movq	-24(%rbp), %r15
call	Shift.ShiftLeft
addq	$16, %rsp
movq	%rax, %r15
movq	%rax, -24(%rbp)
movq	-24(%rbp), %r9
movq	$0, %r8
addq	%r9, %r8
movq	$1, %rcx
sarq	%cl, %r8
movq	-16(%rbp), %r10
movq	%r8, %r10
movq	%r10, -16(%rbp)
pushq	-16(%rbp)
call	System.println
movq	$0, %rax
addq	$24, %rsp
movq	%rbp, %rsp
popq	%rbp
ret
