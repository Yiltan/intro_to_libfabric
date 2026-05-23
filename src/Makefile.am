# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: (c) 2026 Yiltan Temucin <yiltan.temucin@gmail.com>

bin_PROGRAMS = hello fi_getinfo fi_fabric
hello_SOURCES = main.c
fi_getinfo_SOURCES = fi_getinfo.c
fi_fabric_SOURCES = fi_fabric.c
AM_CFLAGS = $(LIBFABRIC_CFLAGS)
LDADD = $(LIBFABRIC_LIBS)
TESTS = $(bin_PROGRAMS)
