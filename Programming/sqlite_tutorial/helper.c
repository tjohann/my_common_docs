/*
 * summary file with some common helper functions
 *
 * file: helper.c
 *
 */
#include "helper.h"


void
wait_for_char(void)
{
	int character;
	struct termios old_term, new_term;

	fprintf(stdout, "Press a key to continue\n");

	tcgetattr(STDIN_FILENO, &old_term);

	/*
	 * do something like disabling line buffering
	 */
	new_term = old_term;
	new_term.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &new_term);

	character = getchar();

	if (character != 10)
		fprintf(stdout, "You pressed key %c\n", character);

	tcsetattr(STDIN_FILENO, TCSANOW, &old_term);
}
