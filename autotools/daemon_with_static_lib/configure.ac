# configure.ac

AC_INIT([baalued], [trunk], [thorsten.johannvorderbrueggen@t-online.de])
AC_COPYRIGHT([Copyright 2016, Thorsten Johannvorderbrueggen])

AC_CONFIG_AUX_DIR([build-aux/autoconf])
AC_CONFIG_MACRO_DIR([build-aux/m4])
AC_CONFIG_HEADER([config.h])
AC_CONFIG_FILES([		\
	Makefile		\
	lib/Makefile		\
	src/Makefile		\
	etc/Makefile	  	\
	man/Makefile	  	\
	Documentation/Makefile  \
	po/Makefile.in])

AM_GNU_GETTEXT_VERSION([0.19.8])
AM_GNU_GETTEXT([external])

AC_PROG_CC
CFLAGS="${CFLAGS} -std=gnu11 -O2 -Wall -Wextra -pedantic -Wstrict-overflow -fno-strict-aliasing"

AM_INIT_AUTOMAKE([-Wall -Werror dist-bzip2])

# libservice
AM_PROG_AR
AC_PROG_RANLIB

# -> ./configure --enable-silent-rules to get quite build behaviour
m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES([no])])

# enable debugging
AC_ARG_ENABLE([debug],
	[  --enable-debug          build with additional debugging code],
	[CFLAGS="${CFLAGS} -g"; AC_DEFINE([__DEBUG__], 1, [Enable debug infos])])

# ------

# checks for programs.
PKG_PROG_PKG_CONFIG

# Checks for libraries.
PKG_CHECK_MODULES([LIBBAALUE], [libbaalue])
PKG_CHECK_MODULES([LIBCONFIG], [libconfig])

AC_CHECK_LIB([pthread], [pthread_create], [], [AC_MSG_ERROR([** Could not find libpthread **])])
AC_CHECK_LIB([rt], [mq_open], [], [ AC_MSG_ERROR([** Could not find librt **]) ])

# Checks for header files.
AC_HEADER_STDC

# Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST

# Checks for library functions.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_OUTPUT

AC_MSG_RESULT([
        $PACKAGE $VERSION
        ========

        prefix:                 ${prefix}
        sysconfdir:             ${sysconfdir}
        libdir:                 ${libdir}
        includedir:             ${includedir}

        compiler:               ${CC}
        cflags:                 ${CFLAGS}
])
