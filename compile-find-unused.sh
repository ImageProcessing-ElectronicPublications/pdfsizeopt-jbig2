#! /bin/bash --
#
# c-find-unused.sh: Find unused symbols.
# by pts@fazekas.hu at Tue Jul 10 21:28:12 CEST 2012
#

set -ex

PREFIX=/home/pts/prg/pts-mini-gpl/uevalrun/cross-compiler
rm -f *.o

gcc -fno-stack-protector -s -O2 -c -Isrc \
    -ffunction-sections -fdata-sections \
    -W -Wall \
    -I. \
    src/zall.c

gcc -fno-stack-protector -s -O2 -c -Isrc \
    -ffunction-sections -fdata-sections \
    -W -Wall -Wno-uninitialized -Wno-sign-compare \
    -I. \
    src/pngall.c

gcc -fno-stack-protector -s -O2 -c -Isrc \
    -ffunction-sections -fdata-sections \
    -W -Wall -Wno-uninitialized -Wno-unused-parameter -Wno-sign-compare \
    -Wno-strict-aliasing -fno-strict-aliasing \
    -I. \
    src/leptonica.c

g++ -fno-stack-protector -Isrc \
    -fno-exceptions -fno-rtti -s -O2 -c \
    -ffunction-sections -fdata-sections \
    -W -Wall \
    -I. \
    src/jbig2arith.cc src/jbig2.cc src/jbig2enc.cc

# Example stdin line: /usr/bin/ld: Removing unused section '.text._Z6answerv' in file 'jbig2.o'  
demangle() {
  # We remove the dot after '.text. so c++filt can find the symbol to demangle.
  perl -pe 's@ section \x27[.](\w+)[.]@ section \x27$1\x27 \x27@g' | c++filt
}

#g++ -Wl,--gc-sections,--print-gc-sections
rm -f jbig2.unused

# Example line in unused.out /usr/bin/ld: Removing unused section '.text._Z6answerv' in file 'jbig2.o'  
g++ -Wl,--gc-sections,--print-gc-sections -fno-exceptions -fno-rtti -s -o jbig2.unused *.o 2>&1 | demangle | tee unused.out >&2 || :
test -f jbig2.unused

: OK.
