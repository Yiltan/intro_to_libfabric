// SPDX-License-Identifier: MIT
// SPDX-FileCopyrightText: (c) 2026 Yiltan Temucin <yiltan.temucin@gmail.com>

#include "util.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <rdma/fi_domain.h>

int main(void)
{
  struct fi_info *hints = fi_allocinfo();
  hints->fabric_attr->prov_name = strdup("sockets");
  hints->domain_attr->mr_mode = FI_MR_BASIC;

  const size_t buf_size = 4096;

  struct fi_info *info;
  struct fid_fabric *fabric;
  struct fid_domain *domain;
  struct fid_mr *mr;
  char *buf;
  int err;

  err = fi_getinfo(FI_VERSION(1, 5), NULL, NULL, 0, hints, &info);
  fi_freeinfo(hints);
  FI_CHECK_ZERO(err, "fi_getinfo", done);

  err = fi_fabric(info->fabric_attr, &fabric, NULL);
  FI_CHECK_ZERO(err, "fi_fabric", freeinfo);

  err = fi_domain(fabric, info, &domain, NULL);
  FI_CHECK_ZERO(err, "fi_domain", closefabric);

  buf = malloc(buf_size);
  FI_CHECK_NNULL(buf, "malloc", closefabric);

  err = fi_mr_reg(domain, buf, buf_size, FI_READ | FI_WRITE, 0, 0, 0, &mr, NULL);
  FI_CHECK_ZERO(err, "fi_mr_reg", closedomain);

  printf("key: %#lx\n", fi_mr_key(mr));

  fi_close(&mr->fid);
  free(buf);

closedomain:
  fi_close(&domain->fid);
closefabric:
  fi_close(&fabric->fid);
freeinfo:
  fi_freeinfo(info);
done:
  return err;
}
