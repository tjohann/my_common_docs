# Makefile.am

noinst_LIBRARIES = libservice.a

libservice_a_SOURCES =  \
	libservice.h	\
	helper.c 	\
	config.c 	\
	gettext.h

libservice_a_CFLAGS = -DLOCALDIR=\"$(localedir)\"
libservice_a_LIBADD = $(LIBINTL)
