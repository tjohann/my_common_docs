#
# LGPL
# (c) 2015, thorsten.johannvorderbrueggen@t-online.de
#

MODULES = $(shell ls -d */ | cut -f1 -d'/')

.PHONY: all clean

all:
	for dir in $(MODULES); do (cd $$dir && $(MAKE) $@); done

clean:
	rm -rf hello_distcc.o
	rm -f *~
	for dir in $(MODULES); do (cd $$dir && $(MAKE) $@); done

distclean: clean
