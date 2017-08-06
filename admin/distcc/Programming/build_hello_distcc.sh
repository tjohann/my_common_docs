#!/usr/bin/env bash

export DISTCC_VERBOSE=1

distcc gcc -c hello_distcc.c -o hello_distcc.o
gcc hello_distcc.o -o hello_distcc
