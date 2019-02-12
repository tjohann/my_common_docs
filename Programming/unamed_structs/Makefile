# Makefile

MY_HOST_ARCH:=$(shell uname -m)

CC = gcc
CFLAGS = -g -std=c18 -fms-extensions -Wall -Wextra
LDFLAGS =

all: unamed_structs

clean:
	rm -f *~ .*~
	rm -f unamed_structs

distclean: clean

system_load: system_load.c
	@echo "+-----------------------------------------------------+"
	@echo "|   building $@ on host $(MY_HOST_ARCH) "
	@echo "+-----------------------------------------------------+"
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)


.PHONY: clean
