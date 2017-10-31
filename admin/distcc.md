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


build linux kernel with discc
-----------------------------

http://blog.samarthparikh.com/2012/10/install-distcc-and-make-linux-kernel.html
