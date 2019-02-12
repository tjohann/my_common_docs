/*
 * example for unamed structs (see book "C im 21 Jahrhundert")
 *
 * Note: see https://gcc.gnu.org/onlinedocs/gcc/Unnamed-Fields.html
 *       -fms-extensions is NEEEDED!!!
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct s1 {
	int b;
} s1;

typedef struct {

	struct s1;

	struct {
		int a;
	};
} s2;


int
a_value(s2 p)
{
	return p.a;
}

int
b_value(s2 p)
{
	return p.b;
}

int main(void)
{

	s2 p = { .a = 1, .b = 2 };

	printf("a value is %d\n", a_value(p));
	printf("b value is %d\n", b_value(p));

	exit(EXIT_SUCCESS);
}


