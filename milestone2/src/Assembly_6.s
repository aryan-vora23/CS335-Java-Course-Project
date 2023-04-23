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
main:
push	%rbp
movq	%rsp, %rbp
subq	$32, %rsp
movq	-8(%rbp), %r8
movq	$3, %r8
movq	%r8, -8(%rbp)
movq	-16(%rbp), %r9
movq	$2, %r9
movq	%r9, -16(%rbp)
movq	-24(%rbp), %r10
movq	$10, %r10
movq	%r10, -24(%rbp)
movq	%r10, %rax
cltd
idivq	%r9
movq	%rax, %r11
movq	$0, %r12
addq	%r11, %r12
imulq	%r8, %r12
movq	$0, %r13
addq	%r12, %r13
addq	%r9, %r13
movq	-32(%rbp), %r14
movq	%r13, %r14
movq	%r14, -32(%rbp)
// pushq	-32(%rbp)
call	System.println
movq	$0, %rax
addq	$32, %rsp
movq	%rbp, %rsp
popq	%rbp
ret
