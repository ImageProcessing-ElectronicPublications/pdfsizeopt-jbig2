#! /bin/bash --
# by pts@fazekas.hu at Thu Jul 19 14:51:33 CEST 2012
set -ex
rm -f *.o

gcc -s -O2 -c -Isrc \
    -ffunction-sections -fdata-sections \
    -W -Wall \
    -I. \
    src/zall.c

gcc -s -O2 -c -Isrc \
    -ffunction-sections -fdata-sections \
    -W -Wall -Wno-uninitialized -Wno-sign-compare \
    -I. \
    src/pngall.c

gcc -s -O2 -c -Isrc \
    -ffunction-sections -fdata-sections \
    -W -Wall -Wno-uninitialized -Wno-sign-compare -Wno-unused-parameter \
    -I. \
    src/leptonica.c

g++ -fno-exceptions -fno-rtti -s -O2 -c -Isrc \
    -ffunction-sections -fdata-sections \
    -W -Wall \
    -I. \
    src/jbig2arith.cc src/jbig2.cc src/jbig2enc.cc

#g++ -Wl,--gc-sections,--print-gc-sections
g++ -Wl,--gc-sections \
    -fno-exceptions -fno-rtti -s -o jbig2.halfstatic *.o

echo OK.
: OK.
