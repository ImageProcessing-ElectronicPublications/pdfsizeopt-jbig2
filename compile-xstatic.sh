#! /bin/bash --
# by pts@fazekas.hu at Tue Jul 10 21:28:12 CEST 2012

# Fix ELF binaries to contain GNU/Linux as the operating system. This is
# needed when running the program on FreeBSD in Linux mode.
do_elfosfix() {
  perl -e'
use integer;
use strict;

#** ELF operating system codes from FreeBSDs /usr/share/misc/magic
my %ELF_os_codes=qw{SYSV 0 GNU/Linux 3};
my $from_oscode=$ELF_os_codes{"SYSV"};
my $to_oscode=$ELF_os_codes{"GNU/Linux"};

for my $fn (@ARGV) {
  my $f;
  if (!open $f, "+<", $fn) {
    print STDERR "$0: $fn: $!\n";
    exit 2  # next
  }
  my $head;
  # vvv Imp: continue on next file instead of die()ing
  die if 8!=sysread($f,$head,8);
  if (substr($head,0,4)ne"\177ELF") {
    print STDERR "$0: $fn: not an ELF file\n";
    close($f); next;
  }
  if (vec($head,7,8)==$to_oscode) {
    print STDERR "$0: info: $fn: already fixed\n";
  }
  if ($from_oscode!=$to_oscode && vec($head,7,8)==$from_oscode) {
    vec($head,7,8)=$to_oscode;
    die if 0!=sysseek($f,0,0);
    die if length($head)!=syswrite($f,$head);
  }
  die "file error\n" if !close($f);
}' -- "$@"
}

set -ex

rm -f *.o

xstatic gcc -static -fno-stack-protector -s -O2 -c -Isrc \
    -ffunction-sections -fdata-sections \
    -W -Wall \
    -I. \
    src/zall.c

xstatic gcc -static -fno-stack-protector -s -O2 -c -Isrc \
    -ffunction-sections -fdata-sections \
    -W -Wall -Wno-uninitialized -Wno-sign-compare \
    -I. \
    src/pngall.c

xstatic gcc -static -fno-stack-protector -s -O2 -c -Isrc \
    -ffunction-sections -fdata-sections \
    -W -Wall -Wno-uninitialized -Wno-unused-parameter -Wno-sign-compare \
    -Wno-strict-aliasing -fno-strict-aliasing \
    -I. \
    src/leptonica.c

xstatic g++ -static -fno-stack-protector -Isrc \
    -fno-exceptions -fno-rtti -s -O2 -c \
    -ffunction-sections -fdata-sections \
    -W -Wall \
    -I. \
    src/jbig2arith.cc src/jbig2.cc src/jbig2enc.cc

#g++ -Wl,--gc-sections,--print-gc-sections
xstatic g++ -static -Wl,--gc-sections \
    -fno-exceptions -fno-rtti -s -o jbig2.xstatic.uncompressed *.o

do_elfosfix jbig2.xstatic.uncompressed
cp -a jbig2.xstatic.uncompressed jbig2.xstatic
upx.pts --brute jbig2.xstatic
do_elfosfix jbig2.xstatic

: OK.
