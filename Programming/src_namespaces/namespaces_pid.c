/*-*- Mode: C; c-basic-offset: 8; indent-tabs-mode: nil -*-*/

/*
 * demonstrate creation of a pid namespace
 *
 *
 * compile: gcc -Wall -std=gnu1x -o namespaces_pid helper.c namespaces_pid.c
 * run: ./namespaces_pid
 *
 * output (user):
 * tjohann@SI-Z09IX [~/my_docs/src]$ ./namespaces_pid
 * pid after clone = ffffffff
 * output (with sudo):
 * tjohann@SI-Z09IX [~/my_docs/src]$ sudo ./namespaces_pid
 * pid after clone = 14ed
 * "my"-pid: 1
 */

#include "helper.h"

#include <sys/wait.h>
#include <sched.h>

/*
 * child stack
 */
#define STACK_SIZE (1024 * 1024)
static char child_stack[STACK_SIZE];

static int
child_func() {
	fprintf(stdout, "Child: my pid is %x\n", getpid());

	wait_for_char();

	fprintf(stdout, "Leave child \n");
	return 0;
}

int
main(void) {
	pid_t cpid = clone(child_func,
				child_stack + STACK_SIZE,
				CLONE_NEWPID | SIGCHLD,
				NULL);

	fprintf(stdout, "Parent: the child pid is %x\n", cpid);

	/*
	 * wait for child to return
	 */
	waitpid(cpid, NULL, 0);

	wait_for_char();

	fprintf(stdout, "Leave parent \n");
	exit(EXIT_SUCCESS);
}
