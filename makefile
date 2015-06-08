# only for cleaning 

MODULES = $(shell ls -d */ | cut -f1 -d'/')

all:: 
	@echo Cheers

clean::
	rm -f *~
	for dir in $(MODULES); do (cd $$dir && $(MAKE) $@); done

distclean: clean
