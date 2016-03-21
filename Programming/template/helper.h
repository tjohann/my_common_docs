/*
 * summary file with some common helper functions
 *
 * file: helper.h
 *
 */
#ifndef _HELPER_H
#define _HELPER_H

#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <termios.h>
#include <errno.h>


/*
 * emulate a getch function
 */
void
wait_for_char(void);


#endif
