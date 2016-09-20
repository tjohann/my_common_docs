#
# LGPL
# (c) 2015, thorsten.johannvorderbrueggen@t-online.de
#

MODULES = $(shell ls -d */ | cut -f1 -d'/' | grep -v daemon_with_static_lib | grep -v prog_simple)

.PHONY: all clean

all:
	for dir in $(MODULES); do (cd $$dir && $(MAKE) $@); done

clean:
	rm -f *~
	for dir in $(MODULES); do (cd $$dir && $(MAKE) $@); done

distclean: clean
