#
# GPL                                                                        
# (c) 2015, thorsten.johannvorderbrueggen@t-online.de                        
#

MODULES = $(shell ls -d */ | cut -f1 -d'/')

.PHONY: all clean

all:
	for dir in $(MODULES); do (cd $$dir && $(MAKE) $@); done
	@echo 
	@echo "+-----------------------------------------------------+"
	@echo "|                                                     |"
	@echo "|                   Cheers $(USER)                    |"
	@echo "|                                                     |"
	@echo "+-----------------------------------------------------+"
	@echo 

clean:
	rm -f *~
	rm -f .*~

	for dir in $(MODULES); do (cd $$dir && $(MAKE) $@); done

distclean: clean
