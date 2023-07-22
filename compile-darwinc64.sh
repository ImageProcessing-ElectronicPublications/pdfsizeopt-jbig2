#! /bin/bash --
# by pts@fazekas.hu at Mon Jul 24 13:45:31 CEST 2017
set -ex
rm -f *.o empty.bin

# $ docker image ls --digests multiarch/crossbuild
# The image ID is also a digest, and is a computed SHA256 hash of the image configuration object, which contains the digests of the layers that contribute to the image's filesystem definition.
# REPOSITORY             TAG                 DIGEST                                                                    IMAGE ID            CREATED             SIZE
# multiarch/crossbuild   latest              sha256:84a53371f554a3b3d321c9d1dfd485b8748ad6f378ab1ebed603fe1ff01f7b4d   846ea4d99d1a        5 months ago        2.99 GB
  CCC="docker run -v $PWD:/workdir multiarch/crossbuild /usr/osxcross/bin/o64-clang -mmacosx-version-min=10.5 -c"
 CXXC="docker run -v $PWD:/workdir multiarch/crossbuild /usr/osxcross/bin/o64-clang++ -mmacosx-version-min=10.5 -c"
 CCLD="docker run -v $PWD:/workdir multiarch/crossbuild /usr/osxcross/bin/o64-clang -mmacosx-version-min=10.5 -Ldarwin_libgcc/x86_64-apple-darwin10/4.9.4 -lSystem -lgcc -lcrt1.10.5.o -nostdlib"
STRIP="docker run -v $PWD:/workdir multiarch/crossbuild /usr/osxcross/bin/x86_64-apple-darwin14-strip"
test -f darwin_libgcc/x86_64-apple-darwin10/4.9.4/libgcc.a

$CCC -O2 -Isrc \
    -ffunction-sections -fdata-sections \
    -W -Wall \
    -I. \
    src/zall.c

$CCC -O2 -Isrc \
    -ffunction-sections -fdata-sections \
    -W -Wall -Wno-uninitialized -Wno-sign-compare -Wno-self-assign \
    -I. \
    src/pngall.c

$CCC -O2 -Isrc \
    -ffunction-sections -fdata-sections \
    -W -Wall -Wno-uninitialized -Wno-unused-parameter -Wno-sign-compare \
    -Wno-strict-aliasing -fno-strict-aliasing \
    -I. \
    src/leptonica.c

$CXXC -fno-exceptions -fno-rtti -O2 -Isrc \
    -ffunction-sections -fdata-sections \
    -W -Wall \
    -I. \
    src/jbig2arith.cc src/jbig2.cc src/jbig2enc.cc

# ld: unknown option: --gc-sections
# -Wl,-dead_strip instead of -l,-gc-sections
$CCLD -Wl,-dead_strip -o jbig2.darwinc64 *.o
$STRIP jbig2.darwinc64

: OK.
