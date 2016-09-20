#
# Makefile.am
#

AM_LDFLAGS = -Wl,--gc-sections -Wl,--as-needed
AM_CFLAGS = ${my_CFLAGS}

bin_PROGRAMS = baalued

baalued_SOURCES =             	\
	main.c    	        \
	gettext.h

baalued_CFLAGS = $(AM_CFLAGS)	\
	$(LIBCONFIG_CFLAGS)     \
	$(LIBBAALUE_CFLAGS)     \
	-DLOCALEDIR=\"$(localedir)\" -I$(srcdir)/../lib

baalued_LDFLAGS = $(AM_LDFLAGS)

baalued_LDADD =  		\
	$(LIBCONFIG_LIBS)   	\
	$(LIBBAALUE_LIBS)      	\
	$(LIBINTL) ../lib/libservice.a
