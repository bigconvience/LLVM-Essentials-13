	.text
	.file	"test.ll"
	.globl	test                            # -- Begin function test
	.p2align	4, 0x90
	.type	test,@function
test:                                   # @test
	.cfi_startproc
# %bb.0:
	movl	%edx, %r8d
	movl	%esi, %eax
	movl	%edi, %ecx
	addl	%ecx, %eax
	cltd
	idivl	%r8d
	retq
.Lfunc_end0:
	.size	test, .Lfunc_end0-test
	.cfi_endproc
                                        # -- End function
	.section	".note.GNU-stack","",@progbits
