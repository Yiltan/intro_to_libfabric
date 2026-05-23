// SPDX-License-Identifier: MIT
// SPDX-FileCopyrightText: (c) 2026 Yiltan Temucin <yiltan.temucin@gmail.com>

#include <stdio.h>
#include <rdma/fabric.h>

int main(void)
{
  struct fi_info *info = NULL;
  int ret;

  ret = fi_getinfo(FI_VERSION(1, 5), NULL, NULL, 0, NULL, &info);
  if (ret) {
    fprintf(stderr, "fi_getinfo failed: %s\n", fi_strerror(-ret));
    return 1;
  }

  if (!info) {
    printf("No fabric providers found.\n");
    return 0;
  }

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
}
