#
# LGPL                                                                        
# (c) 2015, thorsten.johannvorderbrueggen@t-online.de                        
#                                                                            

MY_HOST_ARCH:=$(shell uname -m)
HELPER_HEADER:= helper.h
HELPER_SRC:= helper.c

.PHONY: clean

all:

clean:
	rm -f *~ .*~
#	rm -f my_prog

distclean: clean


#
# my playground
#
my_prog: my_prog.c $(HELPER_SRC) $(HELPER_HEADER)
	@echo "+-----------------------------------------------------+"
	@echo "|                                                     |"
	@echo "|   building $@ on host $(MY_HOST_ARCH) "
	@echo "|                                                     |"
	@echo "+-----------------------------------------------------+"
	@echo 
	gcc -Wall -std=gnu1x -o my_prog $(HELPER_SRC) my_prog.c 


#
# ------------------------------------------------------------------------------
#


#
# some included code -> add also links to them
#
