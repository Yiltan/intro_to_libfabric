# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: (c) 2026 Yiltan Temucin <yiltan.temucin@gmail.com>

bin_PROGRAMS = hello fi_getinfo
hello_SOURCES = main.c
fi_getinfo_SOURCES = fi_getinfo.c
AM_CFLAGS = $(LIBFABRIC_CFLAGS)
LDADD = $(LIBFABRIC_LIBS)
TESTS = $(bin_PROGRAMS)
