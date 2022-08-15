	.file	"prac1.cpp"
	.text
	.section	.rodata._ZN7Derive22f2Ev.str1.1,"aMS",@progbits,1
.LC0:
	.string	"Derive2 f2().\n"
	.section	.text._ZN7Derive22f2Ev,"axG",@progbits,_ZN7Derive22f2Ev,comdat
	.align 2
	.p2align 4
	.weak	_ZN7Derive22f2Ev
	.type	_ZN7Derive22f2Ev, @function
_ZN7Derive22f2Ev:
.LFB1815:
	.cfi_startproc
	endbr64
	movl	$14, %edx
	leaq	.LC0(%rip), %rsi
	leaq	_ZSt4cout(%rip), %rdi
	jmp	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	.cfi_endproc
.LFE1815:
	.size	_ZN7Derive22f2Ev, .-_ZN7Derive22f2Ev
	.section	.rodata._ZN7Derive12f1Ev.str1.1,"aMS",@progbits,1
.LC1:
	.string	"Derive1 f1().\n"
	.section	.text._ZN7Derive12f1Ev,"axG",@progbits,_ZN7Derive12f1Ev,comdat
	.align 2
	.p2align 4
	.weak	_ZN7Derive12f1Ev
	.type	_ZN7Derive12f1Ev, @function
_ZN7Derive12f1Ev:
.LFB1814:
	.cfi_startproc
	endbr64
	movl	$14, %edx
	leaq	.LC1(%rip), %rsi
	leaq	_ZSt4cout(%rip), %rdi
	jmp	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	.cfi_endproc
.LFE1814:
	.size	_ZN7Derive12f1Ev, .-_ZN7Derive12f1Ev
	.section	.rodata._ZN4Base2f1Ev.str1.1,"aMS",@progbits,1
.LC2:
	.string	"Base f1()\n."
	.section	.text._ZN4Base2f1Ev,"axG",@progbits,_ZN4Base2f1Ev,comdat
	.align 2
	.p2align 4
	.weak	_ZN4Base2f1Ev
	.type	_ZN4Base2f1Ev, @function
_ZN4Base2f1Ev:
.LFB1812:
	.cfi_startproc
	endbr64
	movl	$11, %edx
	leaq	.LC2(%rip), %rsi
	leaq	_ZSt4cout(%rip), %rdi
	jmp	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	.cfi_endproc
.LFE1812:
	.size	_ZN4Base2f1Ev, .-_ZN4Base2f1Ev
	.section	.rodata._ZN4Base2f2Ev.str1.1,"aMS",@progbits,1
.LC3:
	.string	"Base f2()\n."
	.section	.text._ZN4Base2f2Ev,"axG",@progbits,_ZN4Base2f2Ev,comdat
	.align 2
	.p2align 4
	.weak	_ZN4Base2f2Ev
	.type	_ZN4Base2f2Ev, @function
_ZN4Base2f2Ev:
.LFB1813:
	.cfi_startproc
	endbr64
	movl	$11, %edx
	leaq	.LC3(%rip), %rsi
	leaq	_ZSt4cout(%rip), %rdi
	jmp	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	.cfi_endproc
.LFE1813:
	.size	_ZN4Base2f2Ev, .-_ZN4Base2f2Ev
	.section	.text.startup,"ax",@progbits
	.p2align 4
	.globl	main
	.type	main, @function
main:
.LFB1816:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	subq	$32, %rsp
	.cfi_def_cfa_offset 48
	movq	%fs:40, %rax
	movq	%rax, 24(%rsp)
	leaq	16+_ZTV7Derive1(%rip), %rax
	leaq	8(%rsp), %rbp
	movq	%rbp, %rdi
	movq	%rax, 8(%rsp)
	leaq	16+_ZTV7Derive2(%rip), %rax
	movq	%rax, 16(%rsp)
	call	_ZN7Derive12f1Ev
	movq	%rbp, %rdi
	leaq	16(%rsp), %rbp
	call	_ZN4Base2f2Ev
	movq	%rbp, %rdi
	call	_ZN4Base2f1Ev
	movq	%rbp, %rdi
	call	_ZN7Derive22f2Ev
	movq	24(%rsp), %rax
	subq	%fs:40, %rax
	jne	.L9
	addq	$32, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 16
	xorl	%eax, %eax
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
.L9:
	.cfi_restore_state
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE1816:
	.size	main, .-main
	.p2align 4
	.type	_GLOBAL__sub_I_main, @function
_GLOBAL__sub_I_main:
.LFB2310:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	leaq	_ZStL8__ioinit(%rip), %rbp
	movq	%rbp, %rdi
	call	_ZNSt8ios_base4InitC1Ev@PLT
	movq	_ZNSt8ios_base4InitD1Ev@GOTPCREL(%rip), %rdi
	movq	%rbp, %rsi
	popq	%rbp
	.cfi_def_cfa_offset 8
	leaq	__dso_handle(%rip), %rdx
	jmp	__cxa_atexit@PLT
	.cfi_endproc
.LFE2310:
	.size	_GLOBAL__sub_I_main, .-_GLOBAL__sub_I_main
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I_main
	.weak	_ZTS4Base
	.section	.rodata._ZTS4Base,"aG",@progbits,_ZTS4Base,comdat
	.type	_ZTS4Base, @object
	.size	_ZTS4Base, 6
_ZTS4Base:
	.string	"4Base"
	.weak	_ZTI4Base
	.section	.data.rel.ro._ZTI4Base,"awG",@progbits,_ZTI4Base,comdat
	.align 8
	.type	_ZTI4Base, @object
	.size	_ZTI4Base, 16
_ZTI4Base:
	.quad	_ZTVN10__cxxabiv117__class_type_infoE+16
	.quad	_ZTS4Base
	.weak	_ZTS7Derive1
	.section	.rodata._ZTS7Derive1,"aG",@progbits,_ZTS7Derive1,comdat
	.align 8
	.type	_ZTS7Derive1, @object
	.size	_ZTS7Derive1, 9
_ZTS7Derive1:
	.string	"7Derive1"
	.weak	_ZTI7Derive1
	.section	.data.rel.ro._ZTI7Derive1,"awG",@progbits,_ZTI7Derive1,comdat
	.align 8
	.type	_ZTI7Derive1, @object
	.size	_ZTI7Derive1, 24
_ZTI7Derive1:
	.quad	_ZTVN10__cxxabiv120__si_class_type_infoE+16
	.quad	_ZTS7Derive1
	.quad	_ZTI4Base
	.weak	_ZTS7Derive2
	.section	.rodata._ZTS7Derive2,"aG",@progbits,_ZTS7Derive2,comdat
	.align 8
	.type	_ZTS7Derive2, @object
	.size	_ZTS7Derive2, 9
_ZTS7Derive2:
	.string	"7Derive2"
	.weak	_ZTI7Derive2
	.section	.data.rel.ro._ZTI7Derive2,"awG",@progbits,_ZTI7Derive2,comdat
	.align 8
	.type	_ZTI7Derive2, @object
	.size	_ZTI7Derive2, 24
_ZTI7Derive2:
	.quad	_ZTVN10__cxxabiv120__si_class_type_infoE+16
	.quad	_ZTS7Derive2
	.quad	_ZTI4Base
	.weak	_ZTV7Derive1
	.section	.data.rel.ro.local._ZTV7Derive1,"awG",@progbits,_ZTV7Derive1,comdat
	.align 8
	.type	_ZTV7Derive1, @object
	.size	_ZTV7Derive1, 32
_ZTV7Derive1:
	.quad	0
	.quad	_ZTI7Derive1
	.quad	_ZN7Derive12f1Ev
	.quad	_ZN4Base2f2Ev
	.weak	_ZTV7Derive2
	.section	.data.rel.ro.local._ZTV7Derive2,"awG",@progbits,_ZTV7Derive2,comdat
	.align 8
	.type	_ZTV7Derive2, @object
	.size	_ZTV7Derive2, 32
_ZTV7Derive2:
	.quad	0
	.quad	_ZTI7Derive2
	.quad	_ZN4Base2f1Ev
	.quad	_ZN7Derive22f2Ev
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.hidden	__dso_handle
	.ident	"GCC: (Ubuntu 11.2.0-19ubuntu1) 11.2.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4: