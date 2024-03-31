	.file	"main.cpp"
	.text
	.section .rdata,"dr"
_ZStL19piecewise_construct:
	.space 1
	.section	.text$_ZN7Account11get_balanceEv,"x"
	.linkonce discard
	.align 2
	.globl	_ZN7Account11get_balanceEv
	.def	_ZN7Account11get_balanceEv;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN7Account11get_balanceEv
_ZN7Account11get_balanceEv:
.LFB2081:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	16(%rbp), %rax
	movsd	32(%rax), %xmm0
	movq	%xmm0, %rax
	movq	%rax, %xmm0
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZN7Account11set_balanceEd,"x"
	.linkonce discard
	.align 2
	.globl	_ZN7Account11set_balanceEd
	.def	_ZN7Account11set_balanceEd;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN7Account11set_balanceEd
_ZN7Account11set_balanceEd:
.LFB2082:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movsd	%xmm1, 24(%rbp)
	movq	16(%rbp), %rax
	movsd	24(%rbp), %xmm0
	movsd	%xmm0, 32(%rax)
	nop
	popq	%rbp
	ret
	.seh_endproc
	.text
	.align 2
	.globl	_ZN7Account8set_nameENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
	.def	_ZN7Account8set_nameENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN7Account8set_nameENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
_ZN7Account8set_nameENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE:
.LFB2083:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movq	16(%rbp), %rax
	movq	24(%rbp), %rdx
	movq	%rax, %rcx
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSERKS4_
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.align 2
	.globl	_ZN7Account7getnameB5cxx11Ev
	.def	_ZN7Account7getnameB5cxx11Ev;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN7Account7getnameB5cxx11Ev
_ZN7Account7getnameB5cxx11Ev:
.LFB2084:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movq	24(%rbp), %rdx
	movq	16(%rbp), %rax
	movq	%rax, %rcx
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1ERKS4_
	movq	16(%rbp), %rax
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.align 2
	.globl	_ZN7Account7depositEd
	.def	_ZN7Account7depositEd;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN7Account7depositEd
_ZN7Account7depositEd:
.LFB2085:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movsd	%xmm1, 24(%rbp)
	movq	16(%rbp), %rax
	movsd	32(%rax), %xmm0
	addsd	24(%rbp), %xmm0
	movq	16(%rbp), %rax
	movsd	%xmm0, 32(%rax)
	movl	$1, %eax
	popq	%rbp
	ret
	.seh_endproc
	.align 2
	.globl	_ZN7Account8withdrawEd
	.def	_ZN7Account8withdrawEd;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN7Account8withdrawEd
_ZN7Account8withdrawEd:
.LFB2086:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movsd	%xmm1, 24(%rbp)
	movq	16(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN7Account11get_balanceEv
	movq	%xmm0, %rax
	movq	%rax, %xmm2
	comisd	24(%rbp), %xmm2
	setnb	%al
	testb	%al, %al
	je	.L10
	movq	16(%rbp), %rax
	movsd	32(%rax), %xmm0
	subsd	24(%rbp), %xmm0
	movq	16(%rbp), %rax
	movsd	%xmm0, 32(%rax)
	movl	$1, %eax
	jmp	.L11
.L10:
	movl	$0, %eax
.L11:
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZN7AccountC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	_ZN7AccountC1Ev
	.def	_ZN7AccountC1Ev;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN7AccountC1Ev
_ZN7AccountC1Ev:
.LFB2091:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	16(%rbp), %rax
	movq	%rax, %rcx
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1Ev
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZN7AccountD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	_ZN7AccountD1Ev
	.def	_ZN7AccountD1Ev;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN7AccountD1Ev
_ZN7AccountD1Ev:
.LFB2094:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	16(%rbp), %rax
	movq	%rax, %rcx
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC0:
	.ascii "frank_account\0"
.LC3:
	.ascii "Deposit OK\0"
.LC4:
	.ascii "Deposit not allowed\0"
.LC6:
	.ascii "Withdraw OK\0"
.LC7:
	.ascii "With draw is not successful\0"
.LC8:
	.ascii "Helloo\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB2087:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$136, %rsp
	.seh_stackalloc	136
	leaq	128(%rsp), %rbp
	.seh_setframe	%rbp, 128
	.seh_endprologue
	call	__main
	leaq	-96(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN7AccountC1Ev
	leaq	-9(%rbp), %rax
	movq	%rax, -8(%rbp)
	nop
	nop
	leaq	-9(%rbp), %rdx
	leaq	-48(%rbp), %rax
	movq	%rdx, %r8
	leaq	.LC0(%rip), %rdx
	movq	%rax, %rcx
.LEHB0:
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcRKS3_
.LEHE0:
	leaq	-48(%rbp), %rdx
	leaq	-96(%rbp), %rax
	movq	%rax, %rcx
.LEHB1:
	call	_ZN7Account8set_nameENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
.LEHE1:
	leaq	-48(%rbp), %rax
	movq	%rax, %rcx
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
	leaq	-9(%rbp), %rax
	movq	%rax, %rcx
	call	_ZNSt15__new_allocatorIcED2Ev
	nop
	movsd	.LC1(%rip), %xmm0
	leaq	-96(%rbp), %rax
	movapd	%xmm0, %xmm1
	movq	%rax, %rcx
	call	_ZN7Account11set_balanceEd
	movsd	.LC2(%rip), %xmm0
	leaq	-96(%rbp), %rax
	movapd	%xmm0, %xmm1
	movq	%rax, %rcx
	call	_ZN7Account7depositEd
	testb	%al, %al
	je	.L15
	leaq	.LC3(%rip), %rax
	movq	%rax, %rdx
	movq	.refptr._ZSt4cout(%rip), %rax
	movq	%rax, %rcx
.LEHB2:
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movq	%rax, %rcx
	movq	.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_(%rip), %rax
	movq	%rax, %rdx
	call	_ZNSolsEPFRSoS_E
	jmp	.L16
.L15:
	leaq	.LC4(%rip), %rax
	movq	%rax, %rdx
	movq	.refptr._ZSt4cout(%rip), %rax
	movq	%rax, %rcx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movq	%rax, %rcx
	movq	.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_(%rip), %rax
	movq	%rax, %rdx
	call	_ZNSolsEPFRSoS_E
.L16:
	movsd	.LC5(%rip), %xmm0
	leaq	-96(%rbp), %rax
	movapd	%xmm0, %xmm1
	movq	%rax, %rcx
	call	_ZN7Account8withdrawEd
	testb	%al, %al
	je	.L17
	leaq	.LC6(%rip), %rax
	movq	%rax, %rdx
	movq	.refptr._ZSt4cout(%rip), %rax
	movq	%rax, %rcx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movq	%rax, %rcx
	movq	.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_(%rip), %rax
	movq	%rax, %rdx
	call	_ZNSolsEPFRSoS_E
	jmp	.L18
.L17:
	leaq	.LC7(%rip), %rax
	movq	%rax, %rdx
	movq	.refptr._ZSt4cout(%rip), %rax
	movq	%rax, %rcx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movq	%rax, %rcx
	movq	.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_(%rip), %rax
	movq	%rax, %rdx
	call	_ZNSolsEPFRSoS_E
.L18:
	leaq	.LC8(%rip), %rax
	movq	%rax, %rdx
	movq	.refptr._ZSt4cout(%rip), %rax
	movq	%rax, %rcx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movq	%rax, %rcx
	movq	.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_(%rip), %rax
	movq	%rax, %rdx
	call	_ZNSolsEPFRSoS_E
.LEHE2:
	movl	$0, %ebx
	leaq	-96(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN7AccountD1Ev
	movl	%ebx, %eax
	jmp	.L26
.L24:
	movq	%rax, %rbx
	leaq	-48(%rbp), %rax
	movq	%rax, %rcx
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
	jmp	.L21
.L23:
	movq	%rax, %rbx
.L21:
	leaq	-9(%rbp), %rax
	movq	%rax, %rcx
	call	_ZNSt15__new_allocatorIcED2Ev
	nop
	jmp	.L22
.L25:
	movq	%rax, %rbx
.L22:
	leaq	-96(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN7AccountD1Ev
	movq	%rbx, %rax
	movq	%rax, %rcx
.LEHB3:
	call	_Unwind_Resume
.LEHE3:
.L26:
	addq	$136, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.def	__gxx_personality_seh0;	.scl	2;	.type	32;	.endef
	.seh_handler	__gxx_personality_seh0, @unwind, @except
	.seh_handlerdata
.LLSDA2087:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE2087-.LLSDACSB2087
.LLSDACSB2087:
	.uleb128 .LEHB0-.LFB2087
	.uleb128 .LEHE0-.LEHB0
	.uleb128 .L23-.LFB2087
	.uleb128 0
	.uleb128 .LEHB1-.LFB2087
	.uleb128 .LEHE1-.LEHB1
	.uleb128 .L24-.LFB2087
	.uleb128 0
	.uleb128 .LEHB2-.LFB2087
	.uleb128 .LEHE2-.LEHB2
	.uleb128 .L25-.LFB2087
	.uleb128 0
	.uleb128 .LEHB3-.LFB2087
	.uleb128 .LEHE3-.LEHB3
	.uleb128 0
	.uleb128 0
.LLSDACSE2087:
	.text
	.seh_endproc
	.section	.text$_ZNSt15__new_allocatorIcED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	_ZNSt15__new_allocatorIcED2Ev
	.def	_ZNSt15__new_allocatorIcED2Ev;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt15__new_allocatorIcED2Ev
_ZNSt15__new_allocatorIcED2Ev:
.LFB2352:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	nop
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
_ZNSt8__detail30__integer_to_chars_is_unsignedIjEE:
	.byte	1
_ZNSt8__detail30__integer_to_chars_is_unsignedImEE:
	.byte	1
_ZNSt8__detail30__integer_to_chars_is_unsignedIyEE:
	.byte	1
	.align 8
.LC1:
	.long	0
	.long	1083129856
	.align 8
.LC2:
	.long	0
	.long	1080623104
	.align 8
.LC5:
	.long	0
	.long	1082081280
	.ident	"GCC: (Rev5, Built by MSYS2 project) 13.2.0"
	.def	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSERKS4_;	.scl	2;	.type	32;	.endef
	.def	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1ERKS4_;	.scl	2;	.type	32;	.endef
	.def	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1Ev;	.scl	2;	.type	32;	.endef
	.def	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev;	.scl	2;	.type	32;	.endef
	.def	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcRKS3_;	.scl	2;	.type	32;	.endef
	.def	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc;	.scl	2;	.type	32;	.endef
	.def	_ZNSolsEPFRSoS_E;	.scl	2;	.type	32;	.endef
	.def	_Unwind_Resume;	.scl	2;	.type	32;	.endef
	.section	.rdata$.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, "dr"
	.globl	.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	.linkonce	discard
.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_:
	.quad	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	.section	.rdata$.refptr._ZSt4cout, "dr"
	.globl	.refptr._ZSt4cout
	.linkonce	discard
.refptr._ZSt4cout:
	.quad	_ZSt4cout
