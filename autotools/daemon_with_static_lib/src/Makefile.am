# Makefile.am

bin_PROGRAMS = baalued

baalued_SOURCES =             	\
	main.c    	        \
	gettext.h


baalued_CFLAGS =             	\
	$(LIBCONFIG_CFLAGS)     \
	$(LIBBAALUE_CFLAGS)     \
	-DLOCALEDIR=\"$(localedir)\" -I$(srcdir)/../lib


baalued_LDADD =    	        \
	$(LIBCONFIG_LIBS)   	\
	$(LIBBAALUE_LIBS)      	\
	$(LIBINTL) ../lib/libservice.a
