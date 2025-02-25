#! /bin/bash --
# by pts@fazekas.hu at Thu Jul 19 15:44:52 CEST 2012
set -ex
rm -f *.o empty.bin

gcc-mp-4.4 -static-libgcc -O2 -c -Isrc \
    -ffunction-sections -fdata-sections \
    -W -Wall \
    -I. \
    src/zall.c

gcc-mp-4.4 -static-libgcc -O2 -c -Isrc \
    -ffunction-sections -fdata-sections \
    -W -Wall -Wno-uninitialized -Wno-sign-compare \
    -I. \
    src/pngall.c

gcc-mp-4.4 -static-libgcc -O2 -c -Isrc \
    -ffunction-sections -fdata-sections \
    -W -Wall -Wno-uninitialized -Wno-unused-parameter -Wno-sign-compare \
    -Wno-strict-aliasing -fno-strict-aliasing \
    -I. \
    src/leptonica.c

g++-mp-4.4 -fno-exceptions -fno-rtti -static-libgcc -O2 -c -Isrc \
    -ffunction-sections -fdata-sections \
    -W -Wall \
    -I. \
    src/jbig2arith.cc src/jbig2.cc src/jbig2enc.cc

# Find libstdc++.a next to libstdc++.*.dylib.
echo 'main(){}' >empty.cc
g++-mp-4.4 -fno-exceptions -fno-rtti -static-libgcc -O2 -o empty.bin empty.cc
LIBSTDCPPA=$(otool -L empty.bin | awk '$1~/\/libstdc[+][+][.]/{sub(/[.][0-9]+[.]dylib$/, ".a", $1); print$1; exit}')
test "$LIBSTDCPPA"
rm -f empty.cc empty.bin

#g++ -Wl,--gc-sections,--print-gc-sections
# TODO: use GNU ld with -Wl,--gc-sections
gcc-mp-4.4 -static-libgcc \
    -fno-exceptions -fno-rtti -o jbig2.darwin *.o $LIBSTDCPPA

strip jbig2.darwin

: OK.
