/*
 * some playground
 */

#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>


int
main(void)
{
	fprintf(stdout, "Your sqlite version: %s\n",
		sqlite3_libversion());

	exit(EXIT_SUCCESS);
}
