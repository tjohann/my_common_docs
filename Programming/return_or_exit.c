/*
 * check the difference of return and exit()
 *
 * usage:
 * gcc -S -O1 return_or_exit.c
 * cat return_or_exit.s

 *
 * result with return (only relevant parts):
 *
main:
.LFB10:
	.cfi_startproc
	movl	$0, %eax
	ret
	.cfi_endproc

 *
 * result with exit() (only relevant parts):
 *
main:
.LFB10:
	.cfi_startproc
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	movl	$0, %edi
	call	exit
	.cfi_endproc
 */

#include <stdlib.h>   // for exit()

int main(void) {

	//return 0;
	exit (0);
}
