Howto build latest GCC
======================

A simple howto build a specific GCC version (for example 13.2 with latest C/C++23 support). Target location is /usr/local! The intention is NOT to replaces your default compiler.


Downloads/Links
---------------

Get sources via https://gcc.gnu.org/ ... check sha512.sum ...


Preparations
------------

Install the latest compiler of your distribution:

	xbps-query -R -s gcc
	SNIP
	[*] gcc-12.2.0_4     GNU Compiler Collection
	SNIP

Create build-folder (for example):

	/usr/local/src/build_gcc_13.2


Copy the downloaded files to it and untar it. Go into the gcc folder:

	/usr/local/src/build_gcc_13.2/gcc-13.2.0

Download prerequisites:

	/usr/local/src/build_gcc_13.2/gcc-13.2.0$ ./contrib/download_prerequisites

Create build folder and cd to it:

	mkdir objdir
	cd objdir

	/usr/local/src/build_gcc_13.2/gcc-13.2.0/objdir

Configure gcc:

	../configure --prefix=/usr/local --disable-multilib

Now lets build it:

	make
	make -k check

Install it:

	su -l
	YOUR_ROOT_PASSWD
	cd /usr/local/src/build_gcc_13.2/gcc-13.2.0/objdir
	make install

Howto use it
------------

The compile is locate at /usr/local/bin. So when you want to use your newly build compile, make shure to use the fully quilified name:

	cat Makefile
	SNIP
	CC = /usr/local/bin/g++
	CFLAGS = -Wall -Wextra -std=c++23
	...
	SNIP
