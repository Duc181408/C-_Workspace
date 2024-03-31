	.file	"main.cpp"
	.text
	.section .rdata,"dr"
.LC0:
	.ascii "Hello Hao\0"
	.text
	.align 2
	.globl	_ZN7MyClass8functionEv
	.def	_ZN7MyClass8functionEv;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN7MyClass8functionEv
_ZN7MyClass8functionEv:
.LFB1739:
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movl	$9, %r8d
	leaq	.LC0(%rip), %rdx
	movq	.refptr._ZSt4cout(%rip), %rbx
	movq	%rbx, %rcx
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_x
	movq	(%rbx), %rax
	movq	-24(%rax), %rax
	movq	240(%rax,%rbx), %rbx
	testq	%rbx, %rbx
	je	.L5
	cmpb	$0, 56(%rbx)
	je	.L3
	movzbl	67(%rbx), %edx
.L4:
	movsbl	%dl, %edx
	movq	.refptr._ZSt4cout(%rip), %rcx
	call	_ZNSo3putEc
	movq	%rax, %rcx
	call	_ZNSo5flushEv
	nop
	addq	$32, %rsp
	popq	%rbx
	ret
.L5:
	call	_ZSt16__throw_bad_castv
.L3:
	movq	%rbx, %rcx
	call	_ZNKSt5ctypeIcE13_M_widen_initEv
	movq	(%rbx), %rax
	movl	$10, %edx
	movq	%rbx, %rcx
	call	*48(%rax)
	movl	%eax, %edx
	jmp	.L4
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC1:
	.ascii "Main ne \0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB1740:
	subq	$56, %rsp
	.seh_stackalloc	56
	.seh_endprologue
	call	__main
	leaq	.LC1(%rip), %rdx
	movq	.refptr._ZSt4cout(%rip), %rcx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movq	%rax, %rcx
	call	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	leaq	47(%rsp), %rcx
	call	_ZN7MyClass8functionEv
	movl	$0, %eax
	addq	$56, %rsp
	ret
	.seh_endproc
	.ident	"GCC: (Rev5, Built by MSYS2 project) 13.2.0"
	.def	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_x;	.scl	2;	.type	32;	.endef
	.def	_ZNSo3putEc;	.scl	2;	.type	32;	.endef
	.def	_ZNSo5flushEv;	.scl	2;	.type	32;	.endef
	.def	_ZSt16__throw_bad_castv;	.scl	2;	.type	32;	.endef
	.def	_ZNKSt5ctypeIcE13_M_widen_initEv;	.scl	2;	.type	32;	.endef
	.def	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc;	.scl	2;	.type	32;	.endef
	.def	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_;	.scl	2;	.type	32;	.endef
	.section	.rdata$.refptr._ZSt4cout, "dr"
	.globl	.refptr._ZSt4cout
	.linkonce	discard
.refptr._ZSt4cout:
	.quad	_ZSt4cout
