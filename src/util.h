// SPDX-License-Identifier: MIT
// SPDX-FileCopyrightText: (c) 2026 Yiltan Temucin <yiltan.temucin@gmail.com>

#pragma once

#define FI_CHECK_ZERO(value, error_msg)      \
  if (0 != value) {                          \
    fprintf(stderr,                          \
            "[%s:%d] %s failed: %s\n",       \
            __FILE__, __LINE__,              \
            error_msg, fi_strerror(-value)); \
    return 1;                                \
  }

#define FI_CHECK_NNULL(value, error_msg) \
  if (NULL == value) {                   \
    fprintf(stderr,                      \
            "[%s:%d] %s\n",              \
            __FILE__, __LINE__,          \
            error_msg);                  \
    return 1;                            \
  }
