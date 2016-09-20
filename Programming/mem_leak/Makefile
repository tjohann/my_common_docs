#
# LGPL
# (c) 2015, thorsten.johannvorderbrueggen@t-online.de
#

MODULES = $(shell ls -d */ | cut -f1 -d'/')

.PHONY: all clean

all:	mem_leak
	gcc -std=gnu11 -g -Wall -Wextra -o mem_leak mem_leak.c

clean:
	rm -f *~
	rm -f mem_leak

distclean: clean
