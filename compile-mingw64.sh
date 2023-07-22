#! /bin/bash --
# by pts@fazekas.hu at Tue Jul 10 23:07:40 CEST 2012
#
set -ex
rm -f *.o
#i586-mingw32msvc-gcc -fdump-tree-fixupcfg-lineno -g -c \

# Please note that -ffunction-sections, -fdata-sections and
# -Wl,--gc-sections doesn't seem to have any effect, even unused code gets
# compiled and linked.
x86_64-w64-mingw32-gcc -s -O2 -c -Isrc \
    -ffunction-sections -fdata-sections \
    -W -Wall \
    -I. -DNO_VIZ \
    src/zall.c

x86_64-w64-mingw32-gcc -s -O2 -c -Isrc \
    -ffunction-sections -fdata-sections \
    -W -Wall -Wno-uninitialized -Wno-sign-compare \
    -I. \
    src/pngall.c

x86_64-w64-mingw32-gcc -s -O2 -c -Isrc \
    -ffunction-sections -fdata-sections \
    -W -Wall -Wno-uninitialized -Wno-unused-parameter -Wno-sign-compare \
    -Wno-strict-aliasing -fno-strict-aliasing \
    -I. \
    src/leptonica.c

x86_64-w64-mingw32-g++ -fno-exceptions -fno-rtti -s -O2 -c -Isrc \
    -ffunction-sections -fdata-sections \
    -W -Wall \
    -I. \
    src/jbig2arith.cc src/jbig2.cc src/jbig2enc.cc

#g++ -Wl,--gc-sections,--print-gc-sections
x86_64-w64-mingw32-g++ -Wl,--gc-sections \
    -fno-exceptions -fno-rtti -s -o jbig2.exe *.o

: OK.
