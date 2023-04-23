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
test_10.isleap:
push	%rbp
movq	%rsp, %rbp
subq	$48, %rsp
movq	-8(%rbp), %r8
movq	$400, %r8
movq	%r8, -8(%rbp)
movq	-16(%rbp), %r9
movq	$100, %r9
movq	%r9, -16(%rbp)
movq	-24(%rbp), %r10
movq	$4, %r10
movq	%r10, -24(%rbp)
movq	16(%rbp), %r11
movq	%r11, %rax
cltd
idivq	%r8
movq	%rdx, %r12
movq	-32(%rbp), %r13
movq	%r12, %r13
movq	%r13, -32(%rbp)
movq	%r11, %rax
cltd
idivq	%r9
movq	%rdx, %r14
movq	-40(%rbp), %r15
movq	%r14, %r15
movq	%r15, -40(%rbp)
movq	%r11, %rax
cltd
idivq	%r10
movq	%rdx, %r8
movq	-48(%rbp), %r9
movq	%r8, %r9
movq	%r9, -48(%rbp)
movq	%r9, %rsi
cmp		$0, %rsi
movq	$0, %r10
movq	$1, %rsi
cmove	%rsi, %r10
cmp		$1, %r10
je	label0
jmp	label1
label0:
movq	%r13, %rsi
cmp		$0, %rsi
movq	$0, %r11
movq	$1, %rsi
cmove	%rsi, %r11
movq	%r15, %rsi
cmp		$0, %rsi
movq	$0, %r12
movq	$1, %rsi
cmove	%rsi, %r12
movq	$1, %r13
andq	%r11, %r13
andq	%r12, %r13
cmp		$1, %r13
je	label2
jmp	label3
label2:
movq	$1, %rax
jmp	label4
label3:
movq	%r15, %rsi
cmp		$0, %rsi
movq	$0, %r14
movq	$1, %rsi
cmovne	%rsi, %r14
cmp		$1, %r14
je	label5
jmp	label6
label5:
movq	$0, %rax
label6:
label4:
jmp	label7
label1:
movq	$0, %rax
label7:
addq	$48, %rsp
movq	%rbp, %rsp
popq	%rbp
ret
main:
push	%rbp
movq	%rsp, %rbp
subq	$32, %rsp
movq	-8(%rbp), %r15
movq	$2, %r15
movq	%r15, -8(%rbp)
movq	-16(%rbp), %r8
movq	$2001, %r8
movq	%r8, -16(%rbp)
pushq	-16(%rbp)
movq	-24(%rbp), %r9
call	test_10.isleap
addq	$8, %rsp
movq	%rax, %r9
movq	%rax, -24(%rbp)
movq	-32(%rbp), %r10
movq	$0, %r10
movq	%r10, -32(%rbp)
movq	-8(%rbp), %r11
movq	%r11, %rsi
cmp		$1, %rsi
movq	$0, %r12
movq	$1, %rsi
cmove	%rsi, %r12
movq	%r11, %rsi
cmp		$3, %rsi
movq	$0, %r13
movq	$1, %rsi
cmove	%rsi, %r13
movq	$0, %r14
orq 	%r12, %r14
orq 	%r13, %r14
movq	%r11, %rsi
cmp		$5, %rsi
movq	$0, %r15
movq	$1, %rsi
cmove	%rsi, %r15
movq	$0, %r8
orq 	%r14, %r8
orq 	%r15, %r8
movq	%r11, %rsi
cmp		$7, %rsi
movq	$0, %r9
movq	$1, %rsi
cmove	%rsi, %r9
movq	$0, %r10
orq 	%r8, %r10
orq 	%r9, %r10
movq	%r11, %rsi
cmp		$8, %rsi
movq	$0, %r11
movq	$1, %rsi
cmove	%rsi, %r11
movq	$0, %r12
orq 	%r10, %r12
orq 	%r11, %r12
movq	-8(%rbp), %r13
movq	%r13, %rsi
cmp		$10, %rsi
movq	$0, %r14
movq	$1, %rsi
cmove	%rsi, %r14
movq	$0, %r15
orq 	%r12, %r15
orq 	%r14, %r15
movq	%r13, %rsi
cmp		$12, %rsi
movq	$0, %r8
movq	$1, %rsi
cmove	%rsi, %r8
movq	$0, %r9
orq 	%r15, %r9
orq 	%r8, %r9
cmp		$1, %r9
je	label8
jmp	label9
label8:
movq	-32(%rbp), %r10
movq	$31, %r10
movq	%r10, -32(%rbp)
jmp	label10
label9:
movq	%r13, %rsi
cmp		$4, %rsi
movq	$0, %r11
movq	$1, %rsi
cmove	%rsi, %r11
movq	%r13, %rsi
cmp		$6, %rsi
movq	$0, %r12
movq	$1, %rsi
cmove	%rsi, %r12
movq	$0, %r13
orq 	%r11, %r13
orq 	%r12, %r13
movq	-8(%rbp), %r14
movq	%r14, %rsi
cmp		$9, %rsi
movq	$0, %r15
movq	$1, %rsi
cmove	%rsi, %r15
movq	$0, %r8
orq 	%r13, %r8
orq 	%r15, %r8
movq	%r14, %rsi
cmp		$11, %rsi
movq	$0, %r9
movq	$1, %rsi
cmove	%rsi, %r9
movq	$0, %r10
orq 	%r8, %r10
orq 	%r9, %r10
cmp		$1, %r10
je	label11
jmp	label12
label11:
movq	-32(%rbp), %r11
movq	$30, %r11
movq	%r11, -32(%rbp)
jmp	label13
label12:
movq	%r14, %rsi
cmp		$2, %rsi
movq	$0, %r12
movq	$1, %rsi
cmove	%rsi, %r12
cmp		$1, %r12
je	label14
jmp	label15
label14:
movq	-24(%rbp), %r13
movq	%r13, %rsi
cmp		$1, %rsi
movq	$0, %r14
movq	$1, %rsi
cmove	%rsi, %r14
cmp		$1, %r14
je	label16
jmp	label17
label16:
movq	$29, %r11
movq	%r11, -32(%rbp)
jmp	label18
label17:
movq	$28, %r11
movq	%r11, -32(%rbp)
label18:
jmp	label19
label15:
movq	$9999, %r11
movq	%r11, -32(%rbp)
label19:
label13:
label10:
// pushq	-32(%rbp)
call	System.println
movq	$0, %rax
addq	$32, %rsp
movq	%rbp, %rsp
popq	%rbp
ret
