// SPDX-License-Identifier: MIT
// SPDX-FileCopyrightText: (c) 2026 Yiltan Temucin <yiltan.temucin@gmail.com>

#include "util.h"
#include <stdio.h>
#include <rdma/fabric.h>

int main(void)
{
  struct fi_info *info = NULL;
  int err;

  err = fi_getinfo(FI_VERSION(1, 5), NULL, NULL, 0, NULL, &info);
  FI_CHECK_ZERO(err, "fi_getinfo", error);
  FI_CHECK_NNULL(info, "No fabric providers found.\n", error);

  for (struct fi_info *cur = info; cur; cur = cur->next) {
    printf("Provider: %s\n", cur->fabric_attr->prov_name);
    printf("  Fabric:  %s\n", cur->fabric_attr->name);
    printf("  Domain:  %s\n", cur->domain_attr->name);
    printf("  Version: %d.%d\n",
           FI_MAJOR(cur->fabric_attr->prov_version),
           FI_MINOR(cur->fabric_attr->prov_version));
    printf("  Type:    %s\n",
           cur->ep_attr->type == FI_EP_MSG  ? "FI_EP_MSG"    :
           cur->ep_attr->type == FI_EP_DGRAM ? "FI_EP_DGRAM" :
           cur->ep_attr->type == FI_EP_RDM  ? "FI_EP_RDM"    :
           "unknown");
    printf("\n");
  }

  fi_freeinfo(info);
  return 0;
error:
  return 1;
}
