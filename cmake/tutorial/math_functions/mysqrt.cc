/*
 * math_functions.h
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "math_functions.h"

#ifndef PRINT_FILE_ERROR
#error "PRINT_FILE_ERROR not defined"
#endif

double mysqrt(double input_val) 
{
      fprintf(stdout, "In mysqrt\n");

      PRINT_INFOS_COMPILATION
	      
      PRINT_FILE_NAME

      PRINT_FILE_ERROR

      return sqrt(input_val);
}
