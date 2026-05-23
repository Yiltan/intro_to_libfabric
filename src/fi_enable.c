// SPDX-License-Identifier: MIT
// SPDX-FileCopyrightText: (c) 2026 Yiltan Temucin <yiltan.temucin@gmail.com>

#include "util.h"
#include <stdio.h>
#include <string.h>
#include <rdma/fi_endpoint.h>
#include <rdma/fi_domain.h>

int main(void)
{
  struct fi_info *hints = fi_allocinfo();
  hints->fabric_attr->prov_name = strdup("sockets");
  hints->ep_attr->type = FI_EP_MSG;

  struct fi_info *info;
  struct fid_fabric *fabric;
  struct fid_domain *domain;
  struct fid_ep *ep;
  struct fid_cq *cq;
  struct fi_cq_attr attr = {0};
  int err;

  err = fi_getinfo(FI_VERSION(1, 5), NULL, NULL, 0, hints, &info);
  fi_freeinfo(hints);
  FI_CHECK_ZERO(err, "fi_getinfo", done);

  err = fi_fabric(info->fabric_attr, &fabric, NULL);
  FI_CHECK_ZERO(err, "fi_fabric", freeinfo);

  err = fi_domain(fabric, info, &domain, NULL);
  FI_CHECK_ZERO(err, "fi_domain", closefabric);

  attr.format = FI_CQ_FORMAT_CONTEXT;
  err = fi_cq_open(domain, &attr, &cq, NULL);
  FI_CHECK_ZERO(err, "fi_cq_open", closedomain);

  err = fi_endpoint(domain, info, &ep, NULL);
  FI_CHECK_ZERO(err, "fi_endpoint", closedomain);

  err = fi_ep_bind(ep, &cq->fid, FI_TRANSMIT | FI_RECV);
  FI_CHECK_ZERO(err, "fi_ep_bind", closedomain);

  err = fi_enable(ep);
  FI_CHECK_ZERO(err, "fi_enable", closedomain);

  fi_close(&ep->fid);
  fi_close(&cq->fid);

closedomain:
  fi_close(&domain->fid);
closefabric:
  fi_close(&fabric->fid);
freeinfo:
  fi_freeinfo(info);
done:
  return err;
}
