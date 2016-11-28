#
# LGPL
# (c) 2016, thorsten.johannvorderbrueggen@t-online.de
#

MY_HOST_ARCH:=$(shell uname -m)
CC=gcc
CFLAGS=`pkg-config --cflags gtk+-2.0` -Wall -std=gnu1x
LDADD=`pkg-config --libs gtk+-2.0`

.PHONY: clean

all: main.c
	${CC} ${CFLAGS} -o main main.c ${LDADD}

clean:
	rm -f *~ .*~
	rm -f main

distclean: clean

