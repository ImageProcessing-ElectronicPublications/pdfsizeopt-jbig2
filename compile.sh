#! /bin/bash --
# by pts@fazekas.hu at Tue Jul 10 21:28:12 CEST 2012
set -ex
rm -f *.o
gcc -s -O2 -c -Isrc \
    -ffunction-sections -fdata-sections \
    -W -Wall -Wno-uninitialized -Wno-sign-compare -Wno-unused-parameter \
    src/leptonica.c

g++ -fno-exceptions -fno-rtti -s -O2 -c -Isrc \
    -ffunction-sections -fdata-sections \
    -W -Wall \
    -I. \
    src/jbig2arith.cc src/jbig2.cc src/jbig2enc.cc

#g++ -Wl,--gc-sections,--print-gc-sections
g++ -Wl,--gc-sections \
    -fno-exceptions -fno-rtti -s -o jbig2 *.o \
    -lpng -lz

echo OK.
: OK.
