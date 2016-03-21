/*
 * cmake tutorial
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "config.h"

#ifdef USE_MYMATH
#include "math_functions.h"
#endif

int main(int argc, char **argv)
{
	double input_val;
	double output_val;

	fprintf(stdout, "%s@version.%d.%d.%d\n",
	       argv[0],
	       tutorial_VERSION_MAJOR,
	       tutorial_VERSION_MINOR,
	       tutorial_VERSION_BUGFIX);

	if (argc < 2) {
		fprintf(stdout, "usage: %s number\n", argv[0]);
		exit(1);
	}

	input_val = atof(argv[1]);

#ifdef USE_MYMATH
	fprintf(stdout, "Use mysqrt \n");
        output_val = mysqrt(input_val);
#else
	fprintf(stdout, "Use stdlib/sqrt \n");
        output_val = sqrt(input_val);
#endif

	fprintf(stdout, "sqrt(%g) = %g\n", input_val, output_val);

	return EXIT_SUCCESS;
}
