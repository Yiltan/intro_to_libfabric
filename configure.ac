dnl SPDX-License-Identifier: MIT
dnl SPDX-FileCopyrightText: (c) 2026 Yiltan Temucin <yiltan.temucin@gmail.com>

AC_INIT([intro_to_libfabric], [1.0], [yiltan.temucin@gmail.com])
AM_INIT_AUTOMAKE([foreign])
AC_PROG_CC
AC_CHECK_HEADER([rdma/fabric.h], [],
  [AC_MSG_ERROR([libfabric headers not found])])
AC_CHECK_LIB([fabric], [fi_getinfo],
  [LIBFABRIC_LIBS=-lfabric],
  [AC_MSG_ERROR([libfabric library not found])])
AC_SUBST([LIBFABRIC_LIBS])
AC_CONFIG_FILES([Makefile src/Makefile])
AC_OUTPUT
