	.text
	.file	"hadd.ll"
	.globl	hadd                            # -- Begin function hadd
	.p2align	4, 0x90
	.type	hadd,@function
hadd:                                   # @hadd
# %bb.0:
	pshufd	$255, %xmm0, %xmm1              # xmm1 = xmm0[3,3,3,3]
	movd	%xmm1, %eax
	pshufd	$238, %xmm0, %xmm1              # xmm1 = xmm0[2,3,2,3]
	movd	%xmm1, %ecx
	addl	%eax, %ecx
	pshufd	$85, %xmm0, %xmm1               # xmm1 = xmm0[1,1,1,1]
	movd	%xmm1, %edx
	addl	%ecx, %edx
	movd	%xmm0, %eax
	addl	%edx, %eax
	retq
.Lfunc_end0:
	.size	hadd, .Lfunc_end0-hadd
                                        # -- End function
	.section	".note.GNU-stack","",@progbits
