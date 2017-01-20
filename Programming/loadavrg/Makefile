# Makefile

MY_HOST_ARCH:=$(shell uname -m)

CC = gcc
CFLAGS = -g -Wall -Wextra -std=gnu11
LDFLAGS =

all: system_load

clean:
	rm -f *~ .*~
	rm -f system_load

distclean: clean

system_load: system_load.c
	@echo "+-----------------------------------------------------+"
	@echo "|   building $@ on host $(MY_HOST_ARCH) "
	@echo "+-----------------------------------------------------+"
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)


.PHONY: clean
