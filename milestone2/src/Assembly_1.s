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
test_7.increment:
push	%rbp
movq	%rsp, %rbp
subq	$8, %rsp
movq	16(%rbp), %r9
movq	$0, %r8
addq	%r9, %r8
addq	$1, %r8
movq	-8(%rbp), %r10
movq	%r8, %r10
movq	%r10, -8(%rbp)
movq	%r10, %rax
addq	$8, %rsp
movq	%rbp, %rsp
popq	%rbp
ret
test_7.stepby:
push	%rbp
movq	%rsp, %rbp
subq	$8, %rsp
label0:
movq	24(%rbp), %r11
movq	%r11, %rsi
cmp		$0, %rsi
movq	$0, %r12
movq	$1, %rsi
cmovg	%rsi, %r12
cmp		$0, %r12
je	label1
movq	$0, %r13
addq	%r11, %r13
subq	$1, %r13
movq	%r13, %r11
movq	%r11, 24(%rbp)
pushq	16(%rbp)
movq	-8(%rbp), %r14
call	test_7.increment
addq	$8, %rsp
movq	%rax, %r14
movq	%rax, -8(%rbp)
movq	16(%rbp), %r15
movq	-8(%rbp), %r8
movq	%r8, %r15
movq	%r15, 16(%rbp)
jmp	label0
label1:
movq	%r15, %rax
addq	$8, %rsp
movq	%rbp, %rsp
popq	%rbp
ret
main:
push	%rbp
movq	%rsp, %rbp
subq	$24, %rsp
movq	-8(%rbp), %r9
movq	$3, %r9
movq	%r9, -8(%rbp)
movq	-16(%rbp), %r10
movq	$5, %r10
movq	%r10, -16(%rbp)
pushq	-8(%rbp)
pushq	-16(%rbp)
movq	-24(%rbp), %r11
call	test_7.stepby
addq	$16, %rsp
movq	%rax, %r11
movq	%rax, -24(%rbp)
pushq	-24(%rbp)
call	System.println
movq	$0, %rax
addq	$24, %rsp
movq	%rbp, %rsp
popq	%rbp
ret
