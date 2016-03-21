#
# LGPL
# (c) 2015, thorsten.johannvorderbrueggen@t-online.de
#

MY_HOST_ARCH:=$(shell uname -m)
HELPER_HEADER:= helper.h
HELPER_SRC:= helper.c

.PHONY: clean

all: namespaces_pid demo_uts_namespaces ns_exec unshare

clean:
	rm -f *~ .*~
	rm -f namespaces_pid demo_uts_namespaces unshare ns_exec

distclean: clean


#
# my playground
#
namespaces_pid: namespaces_pid.c $(HELPER_SRC) $(HELPER_HEADER)
	@echo "+-----------------------------------------------------+"
	@echo "|                                                     |"
	@echo "|   building $@ on host $(MY_HOST_ARCH) "
	@echo "|                                                     |"
	@echo "+-----------------------------------------------------+"
	@echo
	gcc -Wall -std=gnu1x -o namespaces_pid $(HELPER_SRC) namespaces_pid.c


#
# ------------------------------------------------------------------------------
#

#
# see https://lwn.net/Articles/531114/ for the tags below
#
demo_uts_namespaces: demo_uts_namespaces.c $(HELPER_SRC) $(HELPER_HEADER)
	@echo "+-----------------------------------------------------+"
	@echo "|                                                     |"
	@echo "|   building $@ on host $(MY_HOST_ARCH) "
	@echo "|                                                     |"
	@echo "+-----------------------------------------------------+"
	@echo
	gcc -Wall -std=gnu1x -o demo_uts_namespaces $(HELPER_SRC) demo_uts_namespaces.c

ns_exec: ns_exec.c $(HELPER_SRC) $(HELPER_HEADER)
	@echo "+-----------------------------------------------------+"
	@echo "|                                                     |"
	@echo "|   building $@ on host $(MY_HOST_ARCH) "
	@echo "|                                                     |"
	@echo "+-----------------------------------------------------+"
	@echo
	gcc -Wall -std=gnu1x -o ns_exec $(HELPER_SRC) ns_exec.c

unshare: unshare.c $(HELPER_SRC) $(HELPER_HEADER)
	@echo "+-----------------------------------------------------+"
	@echo "|                                                     |"
	@echo "|   building $@ on host $(MY_HOST_ARCH) "
	@echo "|                                                     |"
	@echo "+-----------------------------------------------------+"
	@echo
	gcc -Wall -std=gnu1x -o unshare $(HELPER_SRC) unshare.c

