# Makefile

MY_HOST_ARCH:=$(shell uname -m)

CC = gcc
CFLAGS = -Wall -Wextra -std=gnu11
LDFLAGS = -lsqlite3 

all: sqlite_libversion sqlite_libversion_query

clean:
	rm -f *~ .*~
	rm -f sqlite_libversion
	rm -f sqlite_libversion_query

distclean: clean

sqlite_libversion: sqlite_libversion.c
	@echo "+-----------------------------------------------------+"
	@echo "|   building $@ on host $(MY_HOST_ARCH) "
	@echo "+-----------------------------------------------------+"
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

sqlite_libversion_query: sqlite_libversion_query.c
	@echo "+-----------------------------------------------------+"
	@echo "|   building $@ on host $(MY_HOST_ARCH) "
	@echo "+-----------------------------------------------------+"
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

.PHONY: clean
