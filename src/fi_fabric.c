// SPDX-License-Identifier: MIT
// SPDX-FileCopyrightText: (c) 2026 Yiltan Temucin <yiltan.temucin@gmail.com>

#include "util.h"
#include <stdio.h>
#include <rdma/fabric.h>

int main(void)
{
  struct fi_info *info;
  struct fid_fabric *fabric;
  int err;

  err = fi_getinfo(FI_VERSION(1, 5), NULL, NULL, 0, NULL, &info);
  FI_CHECK_ZERO(err, "fi_getinfo", done);

  err = fi_fabric(info->fabric_attr, &fabric, NULL);
  FI_CHECK_ZERO(err, "fi_fabric", freeinfo);

  fi_close(&fabric->fid);

freeinfo:
  fi_freeinfo(info);
done:
  return err;
}
