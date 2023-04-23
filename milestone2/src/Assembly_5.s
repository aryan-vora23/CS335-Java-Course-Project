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
test_5.f:
push	%rbp
movq	%rsp, %rbp
subq	$0, %rsp
movq	16(%rbp), %r9
movq	$1, %r8
xorq	%r9, %r8
cmp		$1, %r8
je	label0
jmp	label1
label0:
movq	$0, %r10
addq	%r9, %r10
addq	$2, %r10
movq	%r10, %r9
movq	%r9, 16(%rbp)
jmp	label2
label1:
movq	$0, %r11
addq	%r9, %r11
subq	$2, %r11
movq	%r11, %r9
movq	%r9, 16(%rbp)
label2:
movq	%r9, %rax
movq	%rbp, %rsp
popq	%rbp
ret
main:
push	%rbp
movq	%rsp, %rbp
subq	$32, %rsp
movq	-8(%rbp), %r12
movq	$5, %r12
movq	%r12, -8(%rbp)
movq	-16(%rbp), %r13
movq	$3, %r13
movq	%r13, -16(%rbp)
movq	-24(%rbp), %r14
movq	$0, %r14
movq	%r14, -24(%rbp)
label3:
movq	%r14, %rsi
cmp		$10, %rsi
movq	$0, %r15
movq	$1, %rsi
cmovl	%rsi, %r15
cmp		$1, %r15
je	label4
jmp	label5
label6:
movq	$0, %r8
addq	%r14, %r8
addq	$1, %r8
movq	%r8, %r14
movq	%r14, -24(%rbp)
jmp	label3
label4:
movq	$0, %r9
addq	%r13, %r9
addq	$2, %r9
movq	%r9, %r13
movq	%r13, -16(%rbp)
jmp	label6
label5:
pushq	-8(%rbp)
movq	-8(%rbp), %r10
call	test_5.f
addq	$8, %rsp
movq	%rax, %r10
movq	%rax, -8(%rbp)
movq	-16(%rbp), %r11
movq	-8(%rbp), %r12
movq	%r11, %rax
cltd
idivq	%r12
movq	%rdx, %r13
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
