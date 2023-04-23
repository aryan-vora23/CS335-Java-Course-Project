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
subq	$24, %rsp
movq	-8(%rbp), %r8
movq	$0, %r8
movq	%r8, -8(%rbp)
movq	-16(%rbp), %r9
movq	$0, %r9
movq	%r9, -16(%rbp)
movq	-24(%rbp), %r10
movq	$0, %r10
movq	%r10, -24(%rbp)
movq	$0, %r8
movq	%r8, -8(%rbp)
label0:
movq	%r8, %rsi
cmp		$3, %rsi
movq	$0, %r11
movq	$1, %rsi
cmovl	%rsi, %r11
cmp		$1, %r11
je	label1
jmp	label2
label3:
movq	$0, %r12
addq	%r8, %r12
addq	$1, %r12
movq	%r12, %r8
movq	%r8, -8(%rbp)
jmp	label0
label1:
movq	$0, %r9
movq	%r9, -16(%rbp)
label4:
movq	%r9, %rsi
cmp		$7, %rsi
movq	$0, %r13
movq	$1, %rsi
cmovl	%rsi, %r13
cmp		$1, %r13
je	label5
jmp	label6
label7:
movq	$0, %r14
addq	%r9, %r14
addq	$1, %r14
movq	%r14, %r9
movq	%r9, -16(%rbp)
jmp	label4
label5:
movq	$0, %r15
addq	%r10, %r15
addq	$1, %r15
movq	%r15, %r10
movq	%r10, -24(%rbp)
jmp	label7
label6:
jmp	label3
label2:
pushq	-24(%rbp)
call	System.println
addq	$24, %rsp
movq	%rbp, %rsp
popq	%rbp
ret
