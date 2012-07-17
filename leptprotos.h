/*
 *  This file was autogen'd by xtractprotos, v. 1.4
 */
#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */

LEPT_DLL LEPTONICA_EXTERN BOX * boxCreate ( l_int32 x, l_int32 y, l_int32 w, l_int32 h );
LEPT_DLL LEPTONICA_EXTERN BOX * boxCopy ( BOX *box );
LEPT_DLL LEPTONICA_EXTERN BOX * boxClone ( BOX *box );
LEPT_DLL LEPTONICA_EXTERN void boxDestroy ( BOX **pbox );
LEPT_DLL LEPTONICA_EXTERN l_int32 boxGetGeometry ( BOX *box, l_int32 *px, l_int32 *py, l_int32 *pw, l_int32 *ph );
LEPT_DLL LEPTONICA_EXTERN l_int32 boxSetGeometry ( BOX *box, l_int32 x, l_int32 y, l_int32 w, l_int32 h );
LEPT_DLL LEPTONICA_EXTERN l_int32 boxGetRefcount ( BOX *box );
LEPT_DLL LEPTONICA_EXTERN l_int32 boxChangeRefcount ( BOX *box, l_int32 delta );
LEPT_DLL LEPTONICA_EXTERN BOXA * boxaCreate ( l_int32 n );
LEPT_DLL LEPTONICA_EXTERN BOXA * boxaCopy ( BOXA *boxa, l_int32 copyflag );
LEPT_DLL LEPTONICA_EXTERN void boxaDestroy ( BOXA **pboxa );
LEPT_DLL LEPTONICA_EXTERN l_int32 boxaAddBox ( BOXA *boxa, BOX *box, l_int32 copyflag );
LEPT_DLL LEPTONICA_EXTERN l_int32 boxaExtendArray ( BOXA *boxa );
LEPT_DLL LEPTONICA_EXTERN l_int32 boxaExtendArrayToSize ( BOXA *boxa, l_int32 size );
LEPT_DLL LEPTONICA_EXTERN l_int32 boxaGetCount ( BOXA *boxa );
LEPT_DLL LEPTONICA_EXTERN BOX * boxaGetBox ( BOXA *boxa, l_int32 index, l_int32 accessflag );
LEPT_DLL LEPTONICA_EXTERN l_int32 boxaGetBoxGeometry ( BOXA *boxa, l_int32 index, l_int32 *px, l_int32 *py, l_int32 *pw, l_int32 *ph );
LEPT_DLL LEPTONICA_EXTERN BOX * boxClipToRectangle ( BOX *box, l_int32 wi, l_int32 hi );
LEPT_DLL LEPTONICA_EXTERN BOXA * boxaSelectBySize ( BOXA *boxas, l_int32 width, l_int32 height, l_int32 type, l_int32 relation, l_int32 *pchanged );
LEPT_DLL LEPTONICA_EXTERN NUMA * boxaMakeSizeIndicator ( BOXA *boxa, l_int32 width, l_int32 height, l_int32 type, l_int32 relation );
LEPT_DLL LEPTONICA_EXTERN BOXA * boxaSelectWithIndicator ( BOXA *boxas, NUMA *na, l_int32 *pchanged );
LEPT_DLL LEPTONICA_EXTERN PIXCMAP * pixcmapCreate ( l_int32 depth );
LEPT_DLL LEPTONICA_EXTERN PIXCMAP * pixcmapCopy ( PIXCMAP *cmaps );
LEPT_DLL LEPTONICA_EXTERN void pixcmapDestroy ( PIXCMAP **pcmap );
LEPT_DLL LEPTONICA_EXTERN l_int32 pixcmapAddColor ( PIXCMAP *cmap, l_int32 rval, l_int32 gval, l_int32 bval );
LEPT_DLL LEPTONICA_EXTERN l_int32 pixcmapGetCount ( PIXCMAP *cmap );
LEPT_DLL LEPTONICA_EXTERN l_int32 pixcmapGetColor ( PIXCMAP *cmap, l_int32 index, l_int32 *prval, l_int32 *pgval, l_int32 *pbval );
LEPT_DLL LEPTONICA_EXTERN l_int32 pixcmapHasColor ( PIXCMAP *cmap, l_int32 *pcolor );
LEPT_DLL LEPTONICA_EXTERN l_int32 pixcmapToArrays ( PIXCMAP *cmap, l_int32 **prmap, l_int32 **pgmap, l_int32 **pbmap );
LEPT_DLL LEPTONICA_EXTERN BOXA * pixConnComp ( PIX *pixs, PIXA **ppixa, l_int32 connectivity );
LEPT_DLL LEPTONICA_EXTERN BOXA * pixConnCompPixa ( PIX *pixs, PIXA **ppixa, l_int32 connectivity );
LEPT_DLL LEPTONICA_EXTERN l_int32 nextOnPixelInRaster ( PIX *pixs, l_int32 xstart, l_int32 ystart, l_int32 *px, l_int32 *py );
LEPT_DLL LEPTONICA_EXTERN l_int32 nextOnPixelInRasterLow ( l_uint32 *data, l_int32 w, l_int32 h, l_int32 wpl, l_int32 xstart, l_int32 ystart, l_int32 *px, l_int32 *py );
LEPT_DLL LEPTONICA_EXTERN BOX * pixSeedfillBB ( PIX *pixs, L_STACK *lstack, l_int32 x, l_int32 y, l_int32 connectivity );
LEPT_DLL LEPTONICA_EXTERN BOX * pixSeedfill4BB ( PIX *pixs, L_STACK *lstack, l_int32 x, l_int32 y );
LEPT_DLL LEPTONICA_EXTERN BOX * pixSeedfill8BB ( PIX *pixs, L_STACK *lstack, l_int32 x, l_int32 y );
LEPT_DLL LEPTONICA_EXTERN l_int32 pixCorrelationScoreThresholded ( PIX *pix1, PIX *pix2, l_int32 area1, l_int32 area2, l_float32 delx, l_float32 dely, l_int32 maxdiffw, l_int32 maxdiffh, l_int32 *tab, l_int32 *downcount, l_float32 score_threshold );
LEPT_DLL extern PIX * pixThresholdToBinary ( PIX *pixs, l_int32 thresh );
LEPT_DLL LEPTONICA_EXTERN void thresholdToBinaryLow ( l_uint32 *datad, l_int32 w, l_int32 h, l_int32 wpld, l_uint32 *datas, l_int32 d, l_int32 wpls, l_int32 thresh );
LEPT_DLL LEPTONICA_EXTERN void thresholdToBinaryLineLow ( l_uint32 *lined, l_int32 w, l_uint32 *lines, l_int32 d, l_int32 thresh );
LEPT_DLL extern JBCLASSER * jbCorrelationInitWithoutComponents ( l_int32 components, l_int32 maxwidth, l_int32 maxheight, l_float32 thresh, l_float32 weightfactor );
LEPT_DLL extern l_int32 jbAddPage ( JBCLASSER *classer, PIX *pixs );
LEPT_DLL LEPTONICA_EXTERN l_int32 jbAddPageComponents ( JBCLASSER *classer, PIX *pixs, BOXA *boxas, PIXA *pixas );
LEPT_DLL LEPTONICA_EXTERN l_int32 jbClassifyRankHaus ( JBCLASSER *classer, BOXA *boxa, PIXA *pixas );
LEPT_DLL LEPTONICA_EXTERN l_int32 pixHaustest ( PIX *pix1, PIX *pix2, PIX *pix3, PIX *pix4, l_float32 delx, l_float32 dely, l_int32 maxdiffw, l_int32 maxdiffh );
LEPT_DLL LEPTONICA_EXTERN l_int32 pixRankHaustest ( PIX *pix1, PIX *pix2, PIX *pix3, PIX *pix4, l_float32 delx, l_float32 dely, l_int32 maxdiffw, l_int32 maxdiffh, l_int32 area1, l_int32 area3, l_float32 rank, l_int32 *tab8 );
LEPT_DLL LEPTONICA_EXTERN l_int32 jbClassifyCorrelation ( JBCLASSER *classer, BOXA *boxa, PIXA *pixas );
LEPT_DLL LEPTONICA_EXTERN l_int32 jbGetComponents ( PIX *pixs, l_int32 components, l_int32 maxwidth, l_int32 maxheight, BOXA **pboxad, PIXA **ppixad );
LEPT_DLL LEPTONICA_EXTERN JBCLASSER * jbClasserCreate ( l_int32 method, l_int32 components );
LEPT_DLL extern void jbClasserDestroy ( JBCLASSER **pclasser );
LEPT_DLL LEPTONICA_EXTERN l_int32 jbGetULCorners ( JBCLASSER *classer, PIX *pixs, BOXA *boxa );
LEPT_DLL extern l_int32 jbGetLLCorners ( JBCLASSER *classer );
LEPT_DLL LEPTONICA_EXTERN PIX * pixDilate ( PIX *pixd, PIX *pixs, SEL *sel );
LEPT_DLL LEPTONICA_EXTERN PTA * pixaCentroids ( PIXA *pixa );
LEPT_DLL LEPTONICA_EXTERN l_int32 pixCentroid ( PIX *pix, l_int32 *centtab, l_int32 *sumtab, l_float32 *pxave, l_float32 *pyave );
LEPT_DLL LEPTONICA_EXTERN NUMA * numaCreate ( l_int32 n );
LEPT_DLL LEPTONICA_EXTERN void numaDestroy ( NUMA **pna );
LEPT_DLL LEPTONICA_EXTERN NUMA * numaClone ( NUMA *na );
LEPT_DLL LEPTONICA_EXTERN l_int32 numaAddNumber ( NUMA *na, l_float32 val );
LEPT_DLL LEPTONICA_EXTERN l_int32 numaExtendArray ( NUMA *na );
LEPT_DLL LEPTONICA_EXTERN l_int32 numaGetCount ( NUMA *na );
LEPT_DLL extern l_int32 numaGetIValue ( NUMA *na, l_int32 index, l_int32 *pival );
LEPT_DLL LEPTONICA_EXTERN l_int32 numaGetRefcount ( NUMA *na );
LEPT_DLL LEPTONICA_EXTERN l_int32 numaChangeRefcount ( NUMA *na, l_int32 delta );
LEPT_DLL LEPTONICA_EXTERN NUMAHASH * numaHashCreate ( l_int32 nbuckets, l_int32 initsize );
LEPT_DLL LEPTONICA_EXTERN void numaHashDestroy ( NUMAHASH **pnahash );
LEPT_DLL LEPTONICA_EXTERN NUMA * numaHashGetNuma ( NUMAHASH *nahash, l_uint32 key );
LEPT_DLL LEPTONICA_EXTERN l_int32 numaHashAdd ( NUMAHASH *nahash, l_uint32 key, l_float32 value );
LEPT_DLL LEPTONICA_EXTERN PIX * pixCreate ( l_int32 width, l_int32 height, l_int32 depth );
LEPT_DLL LEPTONICA_EXTERN PIX * pixCreateNoInit ( l_int32 width, l_int32 height, l_int32 depth );
LEPT_DLL LEPTONICA_EXTERN PIX * pixCreateTemplate ( PIX *pixs );
LEPT_DLL LEPTONICA_EXTERN PIX * pixCreateTemplateNoInit ( PIX *pixs );
LEPT_DLL LEPTONICA_EXTERN PIX * pixCreateHeader ( l_int32 width, l_int32 height, l_int32 depth );
LEPT_DLL extern PIX * pixClone ( PIX *pixs );
LEPT_DLL extern void pixDestroy ( PIX **ppix );
LEPT_DLL extern PIX * pixCopy ( PIX *pixd, PIX *pixs );
LEPT_DLL LEPTONICA_EXTERN l_int32 pixResizeImageData ( PIX *pixd, PIX *pixs );
LEPT_DLL LEPTONICA_EXTERN l_int32 pixCopyColormap ( PIX *pixd, PIX *pixs );
LEPT_DLL LEPTONICA_EXTERN l_int32 pixSizesEqual ( PIX *pix1, PIX *pix2 );
LEPT_DLL LEPTONICA_EXTERN l_int32 pixGetWidth ( PIX *pix );
LEPT_DLL LEPTONICA_EXTERN l_int32 pixSetWidth ( PIX *pix, l_int32 width );
LEPT_DLL LEPTONICA_EXTERN l_int32 pixGetHeight ( PIX *pix );
LEPT_DLL LEPTONICA_EXTERN l_int32 pixSetHeight ( PIX *pix, l_int32 height );
LEPT_DLL LEPTONICA_EXTERN l_int32 pixGetDepth ( PIX *pix );
LEPT_DLL LEPTONICA_EXTERN l_int32 pixSetDepth ( PIX *pix, l_int32 depth );
LEPT_DLL LEPTONICA_EXTERN l_int32 pixGetDimensions ( PIX *pix, l_int32 *pw, l_int32 *ph, l_int32 *pd );
LEPT_DLL LEPTONICA_EXTERN l_int32 pixGetWpl ( PIX *pix );
LEPT_DLL LEPTONICA_EXTERN l_int32 pixSetWpl ( PIX *pix, l_int32 wpl );
LEPT_DLL LEPTONICA_EXTERN l_int32 pixGetRefcount ( PIX *pix );
LEPT_DLL LEPTONICA_EXTERN l_int32 pixChangeRefcount ( PIX *pix, l_int32 delta );
LEPT_DLL LEPTONICA_EXTERN l_int32 pixGetXRes ( PIX *pix );
LEPT_DLL LEPTONICA_EXTERN l_int32 pixSetXRes ( PIX *pix, l_int32 res );
LEPT_DLL LEPTONICA_EXTERN l_int32 pixGetYRes ( PIX *pix );
LEPT_DLL LEPTONICA_EXTERN l_int32 pixSetYRes ( PIX *pix, l_int32 res );
LEPT_DLL LEPTONICA_EXTERN l_int32 pixCopyResolution ( PIX *pixd, PIX *pixs );
LEPT_DLL LEPTONICA_EXTERN l_int32 pixScaleResolution ( PIX *pix, l_float32 xscale, l_float32 yscale );
LEPT_DLL LEPTONICA_EXTERN l_int32 pixGetInputFormat ( PIX *pix );
LEPT_DLL LEPTONICA_EXTERN l_int32 pixSetInputFormat ( PIX *pix, l_int32 informat );
LEPT_DLL LEPTONICA_EXTERN l_int32 pixCopyInputFormat ( PIX *pixd, PIX *pixs );
LEPT_DLL LEPTONICA_EXTERN char * pixGetText ( PIX *pix );
LEPT_DLL LEPTONICA_EXTERN l_int32 pixSetText ( PIX *pix, const char *textstring );
LEPT_DLL LEPTONICA_EXTERN l_int32 pixCopyText ( PIX *pixd, PIX *pixs );
LEPT_DLL LEPTONICA_EXTERN PIXCMAP * pixGetColormap ( PIX *pix );
LEPT_DLL LEPTONICA_EXTERN l_int32 pixSetColormap ( PIX *pix, PIXCMAP *colormap );
LEPT_DLL LEPTONICA_EXTERN l_int32 pixDestroyColormap ( PIX *pix );
LEPT_DLL LEPTONICA_EXTERN l_uint32 * pixGetData ( PIX *pix );
LEPT_DLL LEPTONICA_EXTERN l_int32 pixSetData ( PIX *pix, l_uint32 *data );
LEPT_DLL LEPTONICA_EXTERN l_int32 pixSetPixel ( PIX *pix, l_int32 x, l_int32 y, l_uint32 val );
LEPT_DLL LEPTONICA_EXTERN l_int32 pixClearAll ( PIX *pix );
LEPT_DLL extern l_int32 pixSetPadBits ( PIX *pix, l_int32 val );
LEPT_DLL LEPTONICA_EXTERN PIX * pixAddBorderGeneral ( PIX *pixs, l_int32 left, l_int32 right, l_int32 top, l_int32 bot, l_uint32 val );
LEPT_DLL extern PIX * pixRemoveBorder ( PIX *pixs, l_int32 npix );
LEPT_DLL LEPTONICA_EXTERN PIX * pixRemoveBorderGeneral ( PIX *pixs, l_int32 left, l_int32 right, l_int32 top, l_int32 bot );
LEPT_DLL LEPTONICA_EXTERN l_int32 composeRGBPixel ( l_int32 rval, l_int32 gval, l_int32 bval, l_uint32 *ppixel );
LEPT_DLL LEPTONICA_EXTERN PIX * pixInvert ( PIX *pixd, PIX *pixs );
LEPT_DLL LEPTONICA_EXTERN PIX * pixXor ( PIX *pixd, PIX *pixs1, PIX *pixs2 );
LEPT_DLL LEPTONICA_EXTERN l_int32 pixZero ( PIX *pix, l_int32 *pempty );
LEPT_DLL extern l_int32 pixCountPixels ( PIX *pix, l_int32 *pcount, l_int32 *tab8 );
LEPT_DLL LEPTONICA_EXTERN NUMA * pixaCountPixels ( PIXA *pixa );
LEPT_DLL LEPTONICA_EXTERN l_int32 pixThresholdPixelSum ( PIX *pix, l_int32 thresh, l_int32 *pabove, l_int32 *tab8 );
LEPT_DLL LEPTONICA_EXTERN l_int32 * makePixelSumTab8 ( void );
LEPT_DLL LEPTONICA_EXTERN l_int32 * makePixelCentroidTab8 ( void );
LEPT_DLL LEPTONICA_EXTERN PIX * pixClipRectangle ( PIX *pixs, BOX *box, BOX **pboxc );
LEPT_DLL LEPTONICA_EXTERN PIXA * pixaCreate ( l_int32 n );
LEPT_DLL extern void pixaDestroy ( PIXA **ppixa );
LEPT_DLL LEPTONICA_EXTERN PIXA * pixaCopy ( PIXA *pixa, l_int32 copyflag );
LEPT_DLL LEPTONICA_EXTERN l_int32 pixaAddPix ( PIXA *pixa, PIX *pix, l_int32 copyflag );
LEPT_DLL LEPTONICA_EXTERN l_int32 pixaExtendArray ( PIXA *pixa );
LEPT_DLL LEPTONICA_EXTERN l_int32 pixaExtendArrayToSize ( PIXA *pixa, l_int32 size );
LEPT_DLL LEPTONICA_EXTERN l_int32 pixaAddBox ( PIXA *pixa, BOX *box, l_int32 copyflag );
LEPT_DLL LEPTONICA_EXTERN l_int32 pixaGetCount ( PIXA *pixa );
LEPT_DLL LEPTONICA_EXTERN l_int32 pixaChangeRefcount ( PIXA *pixa, l_int32 delta );
LEPT_DLL LEPTONICA_EXTERN PIX * pixaGetPix ( PIXA *pixa, l_int32 index, l_int32 accesstype );
LEPT_DLL LEPTONICA_EXTERN BOXA * pixaGetBoxa ( PIXA *pixa, l_int32 accesstype );
LEPT_DLL LEPTONICA_EXTERN BOX * pixaGetBox ( PIXA *pixa, l_int32 index, l_int32 accesstype );
LEPT_DLL LEPTONICA_EXTERN PIXAA * pixaaCreate ( l_int32 n );
LEPT_DLL LEPTONICA_EXTERN void pixaaDestroy ( PIXAA **ppixaa );
LEPT_DLL LEPTONICA_EXTERN l_int32 pixaaAddPixa ( PIXAA *pixaa, PIXA *pixa, l_int32 copyflag );
LEPT_DLL LEPTONICA_EXTERN l_int32 pixaaGetCount ( PIXAA *pixaa );
LEPT_DLL LEPTONICA_EXTERN PIXA * pixaaGetPixa ( PIXAA *pixaa, l_int32 index, l_int32 accesstype );
LEPT_DLL LEPTONICA_EXTERN PIXA * pixaSelectBySize ( PIXA *pixas, l_int32 width, l_int32 height, l_int32 type, l_int32 relation, l_int32 *pchanged );
LEPT_DLL LEPTONICA_EXTERN PIXA * pixaSelectWithIndicator ( PIXA *pixas, NUMA *na, l_int32 *pchanged );
LEPT_DLL extern PIX * pixRemoveColormap ( PIX *pixs, l_int32 type );
LEPT_DLL extern PIX * pixConvertRGBToGrayFast ( PIX *pixs );
LEPT_DLL LEPTONICA_EXTERN PIX * pixReadStreamPng ( FILE *fp );
LEPT_DLL LEPTONICA_EXTERN PIX * pixReadStreamPnm ( FILE *fp );
LEPT_DLL LEPTONICA_EXTERN l_int32 freadHeaderPnm ( FILE *fp, PIX **ppix, l_int32 *pwidth, l_int32 *pheight, l_int32 *pdepth, l_int32 *ptype, l_int32 *pbps, l_int32 *pspp );
LEPT_DLL extern PTA * ptaCreate ( l_int32 n );
LEPT_DLL extern void ptaDestroy ( PTA **ppta );
LEPT_DLL extern l_int32 ptaAddPt ( PTA *pta, l_float32 x, l_float32 y );
LEPT_DLL LEPTONICA_EXTERN l_int32 ptaExtendArrays ( PTA *pta );
LEPT_DLL LEPTONICA_EXTERN l_int32 ptaGetRefcount ( PTA *pta );
LEPT_DLL LEPTONICA_EXTERN l_int32 ptaChangeRefcount ( PTA *pta, l_int32 delta );
LEPT_DLL LEPTONICA_EXTERN l_int32 ptaGetCount ( PTA *pta );
LEPT_DLL LEPTONICA_EXTERN l_int32 ptaGetPt ( PTA *pta, l_int32 index, l_float32 *px, l_float32 *py );
LEPT_DLL LEPTONICA_EXTERN l_int32 ptaGetIPt ( PTA *pta, l_int32 index, l_int32 *px, l_int32 *py );
LEPT_DLL LEPTONICA_EXTERN l_int32 ptaJoin ( PTA *ptad, PTA *ptas, l_int32 istart, l_int32 iend );
LEPT_DLL extern PIX * pixRead ( const char *filename );
LEPT_DLL LEPTONICA_EXTERN PIX * pixReadStream ( FILE *fp, l_int32 hint );
LEPT_DLL extern l_int32 findFileFormatStream ( FILE *fp, l_int32 *pformat );
LEPT_DLL LEPTONICA_EXTERN l_int32 findFileFormatBuffer ( const l_uint8 *buf, l_int32 *pformat );
LEPT_DLL extern l_int32 pixRasterop ( PIX *pixd, l_int32 dx, l_int32 dy, l_int32 dw, l_int32 dh, l_int32 op, PIX *pixs, l_int32 sx, l_int32 sy );
LEPT_DLL LEPTONICA_EXTERN void rasteropUniLow ( l_uint32 *datad, l_int32 dpixw, l_int32 dpixh, l_int32 depth, l_int32 dwpl, l_int32 dx, l_int32 dy, l_int32 dw, l_int32 dh, l_int32 op );
LEPT_DLL LEPTONICA_EXTERN void rasteropLow ( l_uint32 *datad, l_int32 dpixw, l_int32 dpixh, l_int32 depth, l_int32 dwpl, l_int32 dx, l_int32 dy, l_int32 dw, l_int32 dh, l_int32 op, l_uint32 *datas, l_int32 spixw, l_int32 spixh, l_int32 swpl, l_int32 sx, l_int32 sy );
LEPT_DLL LEPTONICA_EXTERN void sarrayDestroy ( SARRAY **psa );
LEPT_DLL extern PIX * pixScaleGray2xLIThresh ( PIX *pixs, l_int32 thresh );
LEPT_DLL extern PIX * pixScaleGray4xLIThresh ( PIX *pixs, l_int32 thresh );
LEPT_DLL LEPTONICA_EXTERN void scaleGray2xLILineLow ( l_uint32 *lined, l_int32 wpld, l_uint32 *lines, l_int32 ws, l_int32 wpls, l_int32 lastlineflag );
LEPT_DLL LEPTONICA_EXTERN void scaleGray4xLILineLow ( l_uint32 *lined, l_int32 wpld, l_uint32 *lines, l_int32 ws, l_int32 wpls, l_int32 lastlineflag );
LEPT_DLL LEPTONICA_EXTERN SEL * selCreate ( l_int32 height, l_int32 width, const char *name );
LEPT_DLL LEPTONICA_EXTERN void selDestroy ( SEL **psel );
LEPT_DLL LEPTONICA_EXTERN SEL * selCreateBrick ( l_int32 h, l_int32 w, l_int32 cy, l_int32 cx, l_int32 type );
LEPT_DLL LEPTONICA_EXTERN l_int32 ** create2dIntArray ( l_int32 sy, l_int32 sx );
LEPT_DLL LEPTONICA_EXTERN l_int32 selGetParameters ( SEL *sel, l_int32 *psy, l_int32 *psx, l_int32 *pcy, l_int32 *pcx );
LEPT_DLL LEPTONICA_EXTERN l_int32 selSetOrigin ( SEL *sel, l_int32 cy, l_int32 cx );
LEPT_DLL LEPTONICA_EXTERN L_STACK * lstackCreate ( l_int32 nalloc );
LEPT_DLL LEPTONICA_EXTERN void lstackDestroy ( L_STACK **plstack, l_int32 freeflag );
LEPT_DLL LEPTONICA_EXTERN l_int32 lstackAdd ( L_STACK *lstack, void *item );
LEPT_DLL LEPTONICA_EXTERN void * lstackRemove ( L_STACK *lstack );
LEPT_DLL LEPTONICA_EXTERN l_int32 lstackExtendArray ( L_STACK *lstack );
LEPT_DLL LEPTONICA_EXTERN l_int32 lstackGetCount ( L_STACK *lstack );
LEPT_DLL LEPTONICA_EXTERN l_int32 returnErrorInt ( const char *msg, const char *procname, l_int32 ival );
LEPT_DLL LEPTONICA_EXTERN void * returnErrorPtr ( const char *msg, const char *procname, void *pval );
LEPT_DLL LEPTONICA_EXTERN void l_error ( const char *msg, const char *procname );
LEPT_DLL LEPTONICA_EXTERN void l_errorInt ( const char *msg, const char *procname, l_int32 ival );
LEPT_DLL LEPTONICA_EXTERN void l_warning ( const char *msg, const char *procname );
LEPT_DLL LEPTONICA_EXTERN void l_warningInt ( const char *msg, const char *procname, l_int32 ival );
LEPT_DLL LEPTONICA_EXTERN char * stringNew ( const char *src );
LEPT_DLL LEPTONICA_EXTERN l_int32 stringCopy ( char *dest, const char *src, l_int32 n );
LEPT_DLL LEPTONICA_EXTERN l_int32 stringReplace ( char **pdest, const char *src );
LEPT_DLL LEPTONICA_EXTERN void * reallocNew ( void **pindata, l_int32 oldsize, l_int32 newsize );
LEPT_DLL LEPTONICA_EXTERN size_t fnbytesInFile ( FILE *fp );
LEPT_DLL LEPTONICA_EXTERN l_uint16 convertOnBigEnd16 ( l_uint16 shortin );
LEPT_DLL LEPTONICA_EXTERN FILE * fopenReadStream ( const char *filename );
LEPT_DLL LEPTONICA_EXTERN char * genPathname ( const char *dir, const char *fname );

#ifdef __cplusplus
}
#endif  /* __cplusplus */
