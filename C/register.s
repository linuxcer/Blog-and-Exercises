	.file	"register.c"
	.section	.rodata
.LC0:
	.string	"RSP:%p\n"
.LC1:
	.string	"RAX:%p\n"
.LC2:
	.string	"RBX:%p\n"
.LC3:
	.string	"RCX:%p\n"
.LC4:
	.string	"RDX:%p\n"
.LC5:
	.string	"RSI:%p\n"
.LC6:
	.string	"RDI:%p\n"
.LC7:
	.string	"RBP:%p\n"
.LC8:
	.string	"R08:%p\n"
.LC9:
	.string	"R09:%p\n"
.LC10:
	.string	"R10:%p\n"
.LC11:
	.string	"R11:%p\n"
.LC12:
	.string	"R12:%p\n"
.LC13:
	.string	"R13:%p\n"
.LC14:
	.string	"R14:%p\n"
.LC15:
	.string	"R15:%p\n"
	.align 8
.LC16:
	.string	"%x %x %x %x %x %x %x %x %x %x %x\n"
	.text
	.globl	fork
	.type	fork, @function
fork:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$352, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
#APP
# 27 "register.c" 1
	mov %rsp, -336(%rbp)
# 0 "" 2
# 29 "register.c" 1
	mov %rax, -328(%rbp)
# 0 "" 2
# 30 "register.c" 1
	mov %rbx, -320(%rbp)
# 0 "" 2
# 31 "register.c" 1
	mov %rcx, -312(%rbp)
# 0 "" 2
# 32 "register.c" 1
	mov %rdx, -304(%rbp)
# 0 "" 2
# 33 "register.c" 1
	mov %rsi, -296(%rbp)
# 0 "" 2
# 34 "register.c" 1
	mov %rdi, -288(%rbp)
# 0 "" 2
# 35 "register.c" 1
	mov %rbp, -280(%rbp)
# 0 "" 2
# 36 "register.c" 1
	mov %r8, -272(%rbp)
# 0 "" 2
# 37 "register.c" 1
	mov %r9, -264(%rbp)
# 0 "" 2
# 38 "register.c" 1
	mov %r10, -256(%rbp)
# 0 "" 2
# 39 "register.c" 1
	mov %r11, -248(%rbp)
# 0 "" 2
# 40 "register.c" 1
	mov %r12, -240(%rbp)
# 0 "" 2
# 41 "register.c" 1
	mov %r13, -232(%rbp)
# 0 "" 2
# 42 "register.c" 1
	mov %r14, -224(%rbp)
# 0 "" 2
# 43 "register.c" 1
	mov %r15, -216(%rbp)
# 0 "" 2
#NO_APP
	movq	-336(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	movq	-328(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
	movq	-320(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC2, %edi
	movl	$0, %eax
	call	printf
	movq	-312(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC3, %edi
	movl	$0, %eax
	call	printf
	movq	-304(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC4, %edi
	movl	$0, %eax
	call	printf
	movq	-296(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC5, %edi
	movl	$0, %eax
	call	printf
	movq	-288(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC6, %edi
	movl	$0, %eax
	call	printf
	movq	-280(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC7, %edi
	movl	$0, %eax
	call	printf
	movq	-272(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC8, %edi
	movl	$0, %eax
	call	printf
	movq	-264(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC9, %edi
	movl	$0, %eax
	call	printf
	movq	-256(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC10, %edi
	movl	$0, %eax
	call	printf
	movq	-248(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC11, %edi
	movl	$0, %eax
	call	printf
	movq	-240(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC12, %edi
	movl	$0, %eax
	call	printf
	movq	-232(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC13, %edi
	movl	$0, %eax
	call	printf
	movq	-224(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC14, %edi
	movl	$0, %eax
	call	printf
	movq	-216(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC15, %edi
	movl	$0, %eax
	call	printf
	movl	$1, -340(%rbp)
	cmpl	$1, -340(%rbp)
	jne	.L2
	leaq	-208(%rbp), %rax
	movq	%rax, %rdi
	call	_setjmp
	subq	$8, %rsp
	subq	$200, %rsp
	movq	%rsp, %rax
	movq	%rax, %rdi
	leaq	1792(%rbp), %rax
	movl	$25, %edx
	movq	%rax, %rsi
	movq	%rdx, %rcx
	rep movsq
	subq	$200, %rsp
	movq	%rsp, %rax
	movq	%rax, %rdi
	leaq	1592(%rbp), %rax
	movl	$25, %edx
	movq	%rax, %rsi
	movq	%rdx, %rcx
	rep movsq
	subq	$200, %rsp
	movq	%rsp, %rax
	movq	%rax, %rdi
	leaq	1392(%rbp), %rax
	movl	$25, %edx
	movq	%rax, %rsi
	movq	%rdx, %rcx
	rep movsq
	subq	$200, %rsp
	movq	%rsp, %rax
	movq	%rax, %rdi
	leaq	1192(%rbp), %rax
	movl	$25, %edx
	movq	%rax, %rsi
	movq	%rdx, %rcx
	rep movsq
	subq	$200, %rsp
	movq	%rsp, %rax
	movq	%rax, %rdi
	leaq	992(%rbp), %rax
	movl	$25, %edx
	movq	%rax, %rsi
	movq	%rdx, %rcx
	rep movsq
	subq	$200, %rsp
	movq	%rsp, %rax
	movq	%rax, %rdi
	leaq	792(%rbp), %rax
	movl	$25, %edx
	movq	%rax, %rsi
	movq	%rdx, %rcx
	rep movsq
	subq	$200, %rsp
	movq	%rsp, %rax
	movq	%rax, %rdi
	leaq	592(%rbp), %rax
	movl	$25, %edx
	movq	%rax, %rsi
	movq	%rdx, %rcx
	rep movsq
	subq	$200, %rsp
	movq	%rsp, %rax
	movq	%rax, %rdi
	leaq	392(%rbp), %rax
	movl	$25, %edx
	movq	%rax, %rsi
	movq	%rdx, %rcx
	rep movsq
	subq	$200, %rsp
	movq	%rsp, %rax
	movq	%rax, %rdi
	leaq	192(%rbp), %rax
	movl	$25, %edx
	movq	%rax, %rsi
	movq	%rdx, %rcx
	rep movsq
	subq	$200, %rsp
	movq	%rsp, %rax
	movq	%rax, %rdi
	leaq	-8(%rbp), %rax
	movl	$25, %edx
	movq	%rax, %rsi
	movq	%rdx, %rcx
	rep movsq
	subq	$200, %rsp
	movq	%rsp, %rax
	movq	%rax, %rdi
	leaq	-208(%rbp), %rax
	movl	$25, %edx
	movq	%rax, %rsi
	movq	%rdx, %rcx
	rep movsq
	movl	$.LC16, %edi
	movl	$0, %eax
	call	printf
	addq	$2208, %rsp
	movl	$0, %eax
	jmp	.L1
.L2:
.L1:
	movq	-8(%rbp), %rdx
	xorq	%fs:40, %rdx
	je	.L5
	call	__stack_chk_fail
.L5:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	fork, .-fork
	.section	.rodata
.LC17:
	.string	"%d %d\n"
.LC18:
	.string	"OK"
	.text
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$32, %edx
	movl	$4, %esi
	movl	$.LC17, %edi
	movl	$0, %eax
	call	printf
	call	fork
	movl	%eax, -52(%rbp)
	cmpl	$0, -52(%rbp)
	jne	.L7
	movl	$.LC18, %edi
	call	puts
.L7:
	movl	$0, %eax
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L9
	call	__stack_chk_fail
.L9:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.9.2-10ubuntu13) 4.9.2"
	.section	.note.GNU-stack,"",@progbits
