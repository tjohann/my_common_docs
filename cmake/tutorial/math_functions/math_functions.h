/*
 * math_functions.h
 */

#ifndef _MATH_FUNCTIONS_H
#define _MATH_FUNCTIONS_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "config.h"

#define PRINT_FILE_ERROR {						\
		fflush(stderr);						\
		fflush(stdout);						\
		fprintf(stderr, "\n*******************************\n"); \
		fprintf(stderr, "%s [%d]\n", __FILE__, __LINE__);	\
		fprintf(stderr, "*******************************\n\n");	\
		fflush(stderr);						\
	}

#define PRINT_FILE_NAME {						\
		fflush(stderr);						\
		fflush(stdout);						\
		fprintf(stdout, "\n*******************************\n"); \
		fprintf(stdout, "FILE: %s \n", __FILE__);		\
		fprintf(stdout, "*******************************\n\n"); \
		fflush(stdout);						\
	}

#define PRINT_INFOS_COMPILATION {					\
		fflush(stderr);						\
		fflush(stdout);						\
		fprintf(stdout, "\n*******************************\n"); \
		fprintf(stdout, "FILE: %s \n", __FILE__);		\
		fprintf(stdout, "COMPILE-DATE: %s\n", __DATE__);	\
		fprintf(stdout, "COMPILE-TIME: %s\n", __TIME__);	\
		fprintf(stdout, "*******************************\n\n"); \
		fflush(stdout);						\
	}

double mysqrt(double input_val); 

#endif
