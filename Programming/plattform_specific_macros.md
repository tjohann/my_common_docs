compiler specific macros
========================

A compiler defines some platform specific macros which then are available in the source file.

To get them try this:

	clang -x c /dev/null -dM -E
	gcc -x c /dev/null -dM -E

Depending on the platform, the following macros are defined:

	__linux__       defined on Linux
    __sun           defined on Solaris
    __FreeBSD__     defined on FreeBSD
    __NetBSD__      defined on NetBSD
    __OpenBSD__     defined on OpenBSD
    __APPLE__       defined on Mac OS X
    __hpux          defined on HP-UX
    __osf__         defined on Tru64 UNIX
    __sgi           defined on Irix
    _AIX            defined on AIX

For example on a linux machine the following linux specific defines are available:

	gcc -x c /dev/null -dM -E | grep linux

	#define __linux 1
	#define __gnu_linux__ 1
	#define linux 1
	#define __linux__ 1

The platform specific defines can be used in the source files. For example:

	#if defined(__FreeBSD__)
	use this and so one
	#endif

Useful links
------------

https://docs.freebsd.org/doc/4.1-RELEASE/usr/share/doc/en/books/porters-handbook/porting-versions.html
