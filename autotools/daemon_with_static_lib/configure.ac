#
# configure.ac
#

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
	scripts/Makefile  	\
	Documentation/Makefile  \
	po/Makefile.in])

AM_GNU_GETTEXT_VERSION([0.19.8])
AM_GNU_GETTEXT([external])

AM_INIT_AUTOMAKE([-Wall -Werror dist-bzip2 silent-rules])

# checks for programs
AC_PROG_CC
AM_PROG_AR
AC_PROG_RANLIB

# ./configure --enable-silent-rules/--disable-silent-rules
AM_SILENT_RULES([yes])

# enable debug info
AC_ARG_ENABLE([debug],
        AS_HELP_STRING([--enable-debug], [enable debug messages @<:@default=disabled@:>@]),
        [], [enable_debug=no])
AM_CONDITIONAL([__DEBUG__], [test "$enable_debug" = yes])

# my common CFLAGS
my_CFLAGS="\
-Wall \
-Wchar-subscripts \
-Wformat-security \
-Wmissing-declarations \
-Wmissing-prototypes \
-Wnested-externs \
-Wpointer-arith \
-Wshadow \
-Wsign-compare \
-Wstrict-prototypes \
-Wtype-limits
"
AC_SUBST([my_CFLAGS])

# ------

# checks for programs.
PKG_PROG_PKG_CONFIG

# Checks for libraries.
PKG_CHECK_MODULES([LIBBAALUE], [libbaalue])
PKG_CHECK_MODULES([LIBCONFIG], [libconfig])

AC_CHECK_LIB([pthread], [pthread_create], [], [AC_MSG_ERROR([** Could not find libpthread **])])
AC_CHECK_LIB([rt], [mq_open], [], [ AC_MSG_ERROR([** Could not find librt **]) ])

# checks for header files
AC_HEADER_STDC
AC_CHECK_HEADERS([unistd.h])

# checks for typedefs, structures, and compiler characteristics
AC_C_CONST

# checks for library functions and more
AC_CHECK_FUNCS([strcasecmp strdup strndup])

AC_CHECK_LIB([rt], [shm_open],
			[],
			[AC_MSG_ERROR([** Could not find librt **])])
AC_CHECK_LIB([pthread], [pthread_create],
			[],
			[AC_MSG_ERROR([** Could not find libpthread **])])

AC_OUTPUT

# show some basic config info
AC_MSG_RESULT([
        $PACKAGE $VERSION
        ========

        prefix:                 ${prefix}
        sysconfdir:             ${sysconfdir}
        libdir:                 ${libdir}
        includedir:             ${includedir}

        compiler:               ${CC}
        cflags:                 ${CFLAGS}

	debug:                  ${enable_debug}
])
