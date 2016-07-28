/*

  Build:

  gcc -std=gnu11 -g -Wall -Wextra -o mem_leak mem_leak.c


  Check for memleak:

  valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes ./mem_leak


==3940== Memcheck, a memory error detector
==3940== Copyright (C) 2002-2015, and GNU GPL'd, by Julian Seward et al.
==3940== Using Valgrind-3.11.0 and LibVEX; rerun with -h for copyright info
==3940== Command: ./mem_leak
==3940== 
3940
==3940== Invalid write of size 1
==3940==    at 0x4006A4: main (mem_leak.c:16)
==3940==  Address 0x51d948a is 0 bytes after a block of size 10 alloc'd
==3940==    at 0x4C2AB60: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==3940==    by 0x40068C: main (mem_leak.c:12)
==3940== 
==3940== 
==3940== FILE DESCRIPTORS: 3 open at exit.
==3940== Open file descriptor 2: /dev/pts/7
==3940==    <inherited from parent>
==3940== 
==3940== Open file descriptor 1: /dev/pts/7
==3940==    <inherited from parent>
==3940== 
==3940== Open file descriptor 0: /dev/pts/7
==3940==    <inherited from parent>
==3940== 
==3940== 
==3940== HEAP SUMMARY:
==3940==     in use at exit: 1,034 bytes in 2 blocks
==3940==   total heap usage: 2 allocs, 0 frees, 1,034 bytes allocated
==3940== 
==3940== 10 bytes in 1 blocks are definitely lost in loss record 1 of 2
==3940==    at 0x4C2AB60: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==3940==    by 0x40068C: main (mem_leak.c:12)
==3940== 
==3940== 1,024 bytes in 1 blocks are still reachable in loss record 2 of 2
==3940==    at 0x4C2AB60: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==3940==    by 0x4E9C044: _IO_file_doallocate (filedoalloc.c:127)
==3940==    by 0x4EA916F: _IO_doallocbuf (genops.c:398)
==3940==    by 0x4EA85D7: _IO_file_overflow@@GLIBC_2.2.5 (fileops.c:820)
==3940==    by 0x4EA77E5: _IO_file_xsputn@@GLIBC_2.2.5 (fileops.c:1331)
==3940==    by 0x4E7E6AD: vfprintf (vfprintf.c:1631)
==3940==    by 0x4E85D98: printf (printf.c:33)
==3940==    by 0x400673: main (mem_leak.c:8)
==3940== 
==3940== LEAK SUMMARY:
==3940==    definitely lost: 10 bytes in 1 blocks
==3940==    indirectly lost: 0 bytes in 0 blocks
==3940==      possibly lost: 0 bytes in 0 blocks
==3940==    still reachable: 1,024 bytes in 1 blocks
==3940==         suppressed: 0 bytes in 0 blocks
==3940== 
==3940== For counts of detected and suppressed errors, rerun with: -v
==3940== ERROR SUMMARY: 2 errors from 2 contexts (suppressed: 0 from 0)


  Monte Carlo Method to check for memeory leak:

  https://github.com/tialaramex/leakdice
  sudo ./leakdice 3371

 */

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int main()
{
	printf("%d\n", (int) getpid());

	fflush(stdout);

	char *x = malloc(10);
	x[9] = 'a';

	/* mem leak :-) */
	x[10] = 'b';

	sleep(60);
	return 0;
}
