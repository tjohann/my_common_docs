stuff around distcc and it usage
================================

https://wiki.gentoo.org/wiki/Distcc/de#Using_distcc_to_bootstrap

checkit:
-------

	#include <stdio.h>

	int main() {
		printf("Hello distcc!\n");
		return 0;
	}


	export DISTCC_VERBOSE=1
	distcc gcc -c hello_distcc.c -o hello_distcc.o
	gcc main.o -o main

	./hello_distcc
	Hello distcc!

For pump mode: pump distcc <...>
