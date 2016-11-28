# Makefile

MY_HOST_ARCH:=$(shell uname -m)

CC = gcc
CFLAGS = -Wall -Wextra -std=gnu11
LDFLAGS = 

all: video

clean:
	rm -f *~ .*~
	rm -f video

distclean: clean

video: video.c
	@echo "+-----------------------------------------------------+"
	@echo "|   building $@ on host $(MY_HOST_ARCH) "
	@echo "+-----------------------------------------------------+"
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)


.PHONY: clean
