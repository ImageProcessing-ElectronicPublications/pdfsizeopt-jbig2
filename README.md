# pdfsizeopt-jbig2

This is an encoder for JBIG2.

JBIG2 encodes bi-level (1 bpp) images using a number of clever tricks to get
better compression than G4. This encoder can:
   * Generate JBIG2 files, or fragments for embedding in PDFs
   * Generic region encoding
   * Perform symbol extraction, classification and text region coding
   * Perform refinement coding and,
   * Compress multipage documents

It uses the (Apache-ish licensed) Leptonica library:
  http://leptonica.com/

You'll need version 1.68.

## Known bugs

The refinement coding causes Acrobat to crash. It's not known if this is a bug
in Acrobat, though it may well be.


## Usage

See the `jbig2enc.h` header for the high level API, or the `jbig2` program for an
example of usage:

```
$ jbig2 -s -p -v *.jpg && jbig2topdf.py output >out.pdf
```
or
```
$ jbig2 -p -v my.tif > my.jbig2 && jbig2topdf.py -s my.jbig2 > my.pdf
```

to encode jbig2 files for pdf creation.
If you want to encode an image and then view output first to include in pdf

```
$ jbig2 -s -S -p -v -O out.png *.jpg
```

If you want to encode an image as jbig2 (can be view in STDU Viewer) run:

```
$ jbig2 -s feyn.tif > feyn.jb2
```
