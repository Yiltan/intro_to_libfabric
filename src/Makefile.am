# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: (c) 2026 Yiltan Temucin <yiltan.temucin@gmail.com>

bin_PROGRAMS = fi_getinfo  \
			   fi_fabric   \
			   fi_domain   \
			   fi_endpoint \
			   fi_cq_open  \
			   fi_ep_bind  \
			   fi_enable

fi_getinfo_SOURCES = fi_getinfo.c
fi_fabric_SOURCES = fi_fabric.c
fi_domain_SOURCES = fi_domain.c
fi_endpoint_SOURCES = fi_endpoint.c
fi_cq_open_SOURCES = fi_cq_open.c
fi_ep_bind_SOURCES = fi_ep_bind.c
fi_enable_SOURCES = fi_enable.c

AM_CFLAGS = $(LIBFABRIC_CFLAGS)
LDADD = $(LIBFABRIC_LIBS)

TESTS = $(bin_PROGRAMS)
