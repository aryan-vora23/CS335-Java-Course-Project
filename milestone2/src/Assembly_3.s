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
test_5.add:
push	%rbp
movq	%rsp, %rbp
subq	$24, %rsp
movq	-16(%rbp), %r8
movq	$1, %r8
movq	%r8, -16(%rbp)
movq	-24(%rbp), %r9
movq	$1, %r9
movq	%r9, -24(%rbp)
label0:
movq	24(%rbp), %r10
movq	%r10, %rsi
cmp		$0, %rsi
movq	$0, %r11
movq	$1, %rsi
cmovg	%rsi, %r11
cmp		$0, %r11
je	label1
movq	16(%rbp), %r13
movq	$0, %r12
addq	%r8, %r12
imulq	%r13, %r12
movq	%r12, %r8
movq	%r8, -16(%rbp)
movq	$0, %r14
addq	%r10, %r14
subq	$1, %r14
movq	%r14, %r10
movq	%r10, 24(%rbp)
jmp	label0
label1:
label2:
movq	40(%rbp), %r15
movq	%r15, %rsi
cmp		$0, %rsi
movq	$0, %r8
movq	$1, %rsi
cmovg	%rsi, %r8
cmp		$0, %r8
je	label3
movq	-24(%rbp), %r10
movq	32(%rbp), %r11
movq	$0, %r9
addq	%r10, %r9
imulq	%r11, %r9
movq	%r9, %r10
movq	%r10, -24(%rbp)
movq	$0, %r12
addq	%r15, %r12
subq	$1, %r12
movq	%r12, %r15
movq	%r15, 40(%rbp)
jmp	label2
label3:
movq	-16(%rbp), %r14
movq	$0, %r13
addq	%r14, %r13
addq	%r10, %r13
movq	-8(%rbp), %r15
movq	%r13, %r15
movq	%r15, -8(%rbp)
movq	%r15, %rax
addq	$24, %rsp
movq	%rbp, %rsp
popq	%rbp
ret
main:
push	%rbp
movq	%rsp, %rbp
subq	$40, %rsp
movq	-8(%rbp), %r8
movq	$2, %r8
movq	%r8, -8(%rbp)
movq	-16(%rbp), %r9
movq	$2, %r9
movq	%r9, -16(%rbp)
movq	-24(%rbp), %r10
movq	$3, %r10
movq	%r10, -24(%rbp)
movq	-32(%rbp), %r11
movq	$3, %r11
movq	%r11, -32(%rbp)
pushq	-8(%rbp)
pushq	-16(%rbp)
pushq	-24(%rbp)
pushq	-32(%rbp)
movq	-40(%rbp), %r12
call	test_5.add
addq	$32, %rsp
movq	%rax, %r12
movq	%rax, -40(%rbp)
pushq	-40(%rbp)
call	System.println
movq	$0, %rax
addq	$40, %rsp
movq	%rbp, %rsp
popq	%rbp
ret
