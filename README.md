<!--
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: (c) 2026 Yiltan Temucin <yiltan.temucin@gmail.com>
-->

# Intro to libfabric

An introductory C project using libfabric.

I am learning how to use libfabric and creating simple standalone programs have
been useful as a learning tool.

## Dependencies

- libfabric (development headers and library)

## Building

```
./autogen.sh
mkdir build
cd build
../configure
make
```

## Run Examples

```
./src/fi_getinfo
```

or run as test suite

```
make check
```
