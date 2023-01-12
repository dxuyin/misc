/********************************************************************
 *                                                                  *
 * THIS FILE IS PART OF THE OggVorbis SOFTWARE CODEC SOURCE CODE.   *
 * USE, DISTRIBUTION AND REPRODUCTION OF THIS LIBRARY SOURCE IS     *
 * GOVERNED BY A BSD-STYLE SOURCE LICENSE INCLUDED WITH THIS SOURCE *
 * IN 'COPYING'. PLEASE READ THESE TERMS BEFORE DISTRIBUTING.       *
 *                                                                  *
 * THE OggVorbis SOURCE CODE IS (C) COPYRIGHT 1994-2009             *
 * by the Xiph.Org Foundation https://xiph.org/                     *
 *                                                                  *
 ********************************************************************

 function: key psychoacoustic settings for 44.1/48kHz

 ********************************************************************/


/* preecho trigger settings *****************************************/

static const vorbis_info_psy_global _psy_global_44[8]={
/*
  { lines per eighth octave,
   { pre-echo thresh.},
   { post-echo thresh.}, stretch penalty, pre-echo minimum energy,
   ampmax att 1/sec,
   {coupling point(kHz)},{{coupling point limit0},{coupling point limit1}},
     {coupling pre-point amp},{coupling post-point amp},{{sliding lowpass0},{sliding lowpass1}}
  },
*/
/* q-2 */
  {8,   /* lines per eighth octave */
   {24.f,14.f,14.f,14.f,14.f,14.f,14.f,  16.f,16.f,16.f,16.f,12.f},
   {-60.f,-30.f,-40.f,-40.f,-40.f,-40.f,-40.f,  -40.f,-40.f,-40.f,-60.f,-60.f}, 2,-75.f,
   -6.f,
   {99.},{{99.},{99.}},{0},{0},{{0.},{0.}}
  },
  {8,   /* lines per eighth octave */
   {20.f,14.f,12.f,12.f,12.f,12.f,12.f,  14.f,14.f,14.f,14.f,12.f},
   {-60.f,-30.f,-40.f,-40.f,-40.f,-40.f,-40.f,  -40.f,-40.f,-40.f,-60.f,-60.f}, 2,-75.f,
   -6.f,
   {99.},{{99.},{99.}},{0},{0},{{0.},{0.}}
  },
  {8,   /* lines per eighth octave */
   {14.f,10.f,10.f,10.f,10.f,10.f,10.f,  14.f,14.f,14.f,14.f,12.f},
   {-40.f,-30.f,-25.f,-25.f,-25.f,-25.f,-25.f,  -25.f,-25.f,-35.f,-40.f,-40.f}, 2,-80.f,
   -6.f,
   {99.},{{99.},{99.}},{0},{0},{{0.},{0.}}
  },
  {8,   /* lines per eighth octave */
   {12.f,10.f,10.f,10.f,10.f,10.f,10.f,  10.f,10.f,10.f,10.f,10.f},
   {-20.f,-20.f,-15.f,-15.f,-15.f,-15.f,-15.f,  -15.f,-15.f,-20.f,-20.f,-20.f}, 0,-80.f,
   -6.f,
   {99.},{{99.},{99.}},{0},{0},{{0.},{0.}}
  },
  {8,   /* lines per eighth octave */
   {10.f,8.f,8.f,6.f,6.f,6.f,7.f,  8.f,8.f,8.f,8.f,8.f},
   {-20.f,-15.f,-12.f,-12.f,-12.f,-12.f,-12.f,  -12.f,-12.f,-15.f,-20.f,-20.f}, 0,-80.f,
   -6.f,
   {99.},{{99.},{99.}},{0},{0},{{0.},{0.}}
  },
  {8,   /* lines per eighth octave */
   {10.f,6.f,6.f,6.f,6.f,6.f,6.f,  8.f,8.f,8.f,8.f,8.f},
   {-15.f,-14.f,-10.f,-10.f,-10.f,-11.f,-12.f,  -12.f,-12.f,-15.f,-20.f,-20.f}, 0,-85.f,
   -6.f,
   {99.},{{99.},{99.}},{0},{0},{{0.},{0.}}
  },
 /* GT3b2 values */
  {8,   /* lines per eighth octave */
   {11.f,8.f,8.f,8.f,8.f,8.f,8.f,  8.f,8.f,8.f,8.f,8.f},
   {-16.f,-14.f,-12.f,-12.f,-12.f,-12.f,-12.f,  -12.f,-12.f,-15.f,-20.f,-20.f}, 0,-85.f,
   -6.f,
   {99.},{{99.},{99.}},{0},{0},{{0.},{0.}}
  },
  {8,   /* lines per eighth octave */
   {10.f,6.f,6.f,6.f,6.f,6.f,6.f,  8.f,8.f,8.f,8.f,8.f},
   {-15.f,-14.f,-10.f,-10.f,-10.f,-10.f,-10.f,  -12.f,-12.f,-15.f,-20.f,-20.f}, 0,-85.f,
   -6.f,
   {99.},{{99.},{99.}},{0},{0},{{0.},{0.}}
  },
};

/* noise compander lookups * low, mid, high quality ****************/
static compandblock _psy_compand_44[6]={
  /* sub-mode Z short */
  {{
     0, 1, 2, 3, 4, 5, 6,  6,     /* 7dB */
     6, 6, 7, 7, 7, 7, 8,  8,     /* 15dB */
     9,10,11,12,13,14,15, 16,     /* 23dB */
    17,18,19,20,21,22,23, 24,     /* 31dB */
    25,26,27,28,29,30,31, 32,     /* 39dB */
  }},
  /* mode_Z nominal short */
  {{
     0, 1, 2, 3, 4, 5, 6,  6,     /* 7dB */
     6, 6, 7, 7, 7, 7, 7,  7,     /* 15dB */
     7, 8, 9,10,11,12,13, 14,     /* 23dB */
    15,16,17,17,17,18,18, 19,     /* 31dB */
    19,19,20,21,22,23,24, 25,     /* 39dB */
  }},
  /* mode A short */
  {{
    0, 1, 2, 3, 4, 5, 5,  5,     /* 7dB */
    6, 6, 6, 6, 6, 6, 6,  6,     /* 15dB */
    6, 6, 6, 6, 6, 7, 7,  7,     /* 23dB */
    8, 8, 8, 9, 9, 9,10, 11,     /* 31dB */
    11,12,13,14,15,16,17, 18,     /* 39dB */
  }},
  /* sub-mode Z long */
  {{
     0, 1, 2, 3, 4, 5, 6,  7,     /* 7dB */
     8, 9,10,11,12,12,13, 13,     /* 15dB */
    13,14,14,15,15,16,16, 17,     /* 23dB */
    17,18,19,20,21,22,23, 24,     /* 31dB */
    25,26,27,28,29,30,31, 32,     /* 39dB */
  }},
  /* mode_Z nominal long */
  {{
    0, 1, 2, 3, 4, 5, 6,  7,     /* 7dB */
    8, 9,10,11,12,12,13, 13,     /* 15dB */
    13,14,14,14,15,15,15, 15,     /* 23dB */
    16,16,17,17,17,18,18, 19,     /* 31dB */
    19,19,20,21,22,23,24, 25,     /* 39dB */
  }},
  /* mode A long */
  {{
    0, 1, 2, 3, 4, 5, 6,  7,     /* 7dB */
    7, 7, 7, 6, 6, 6, 6,  6,     /* 15dB */
    6, 6, 6, 6, 6, 7, 7,  7,     /* 23dB */
    8, 8, 8, 9, 9, 9,10, 11,     /* 31dB */
    11,12,13,14,15,16,17, 18,     /* 39dB */
  }}
};

/* tonal masking curve level adjustments *************************/

static vp_adjblock _vp_tonemask_adj_longblock[13]={
   /* 63     125     250     500       1       2       4       8      16 */
   {{-13,-13,-13,-13,-13,-13,-13,-13,-13,-13,-13,-12, -6, -1,  1,  0,  1}}, /* -2(addition) */
   {{-15,-15,-15,-15,-15,-15,-15,-14,-13,-13,-13,-13, -8, -2,  0, -1,  0}}, /* -1 */
   {{-16,-16,-16,-16,-16,-16,-16,-16,-15,-14,-14,-14,-14, -6, -4, -5,  0}}, /* 0 */
   {{-16,-16,-16,-16,-16,-16,-16,-16,-15,-14,-14,-14,-14, -6, -4, -5,  0}}, /* 1 */
   {{-16,-16,-16,-16,-16,-16,-16,-16,-15,-14,-14,-14,-14, -6, -4, -5,  0}}, /* 2 */
   {{-16,-16,-16,-16,-16,-16,-16,-16,-15,-14,-14,-14,-14, -7, -5, -6,  0}}, /* 3 */
   {{-16,-16,-16,-16,-16,-16,-16,-16,-15,-14,-14,-14,-14, -9, -7, -8,  0}}, /* 4 */
   {{-16,-16,-16,-16,-16,-16,-16,-16,-15,-14,-14,-14,-14, -9, -7, -8,  0}}, /* 5 */
   {{-16,-16,-16,-16,-16,-16,-16,-16,-15,-14,-14,-14,-14, -9, -7, -8,  0}}, /* 6 */
   {{-16,-16,-16,-16,-16,-16,-16,-16,-15,-14,-14,-14,-14, -9, -7, -8,  0}}, /* 7 */
   {{-16,-16,-16,-16,-16,-16,-16,-16,-15,-14,-14,-14,-14, -9, -7, -8,  0}}, /* 8 */
   {{-16,-16,-16,-16,-16,-16,-16,-16,-15,-14,-14,-14,-14, -9, -7, -8,  0}}, /* 9 */
   {{-16,-16,-16,-16,-16,-16,-16,-16,-15,-14,-14,-14,-14, -9, -7, -8,  0}}, /* 10 */
};
static vp_adjblock _vp_tonemask_adj_otherblock[13]={
   /* 63     125     250     500       1       2       4       8      16 */
   {{-13,-13,-13,-13,-13,-13,-13,-13,-13,-13,-13,-12, -6, -1,  1,  0,  1}}, /* -2(addition) */
   {{-15,-15,-15,-15,-15,-15,-15,-14,-13,-13,-13,-13, -8, -2,  0, -1,  0}}, /* -1 */
   {{-16,-16,-16,-16,-16,-16,-16,-16,-15,-14,-14,-14,-14, -6, -4, -5,  0}}, /* 0 */
   {{-16,-16,-16,-16,-16,-16,-16,-16,-15,-14,-14,-14,-14, -6, -4, -5,  0}}, /* 1 */
   {{-16,-16,-16,-16,-16,-16,-16,-16,-15,-14,-14,-14,-14, -6, -4, -5,  0}}, /* 2 */
   {{-16,-16,-16,-16,-16,-16,-16,-16,-15,-14,-14,-14,-14, -7, -5, -6,  0}}, /* 3 */
   {{-16,-16,-16,-16,-16,-16,-16,-16,-15,-14,-14,-14,-14, -9, -7, -8,  0}}, /* 4 */
   {{-16,-16,-16,-16,-16,-16,-16,-16,-15,-14,-14,-14,-14, -9, -7, -8,  0}}, /* 5 */
   {{-16,-16,-16,-16,-16,-16,-16,-16,-15,-14,-14,-14,-14, -9, -7, -8,  0}}, /* 6 */
   {{-16,-16,-16,-16,-16,-16,-16,-16,-15,-14,-14,-14,-14, -9, -7, -8,  0}}, /* 7 */
   {{-16,-16,-16,-16,-16,-16,-16,-16,-15,-14,-14,-14,-14, -9, -7, -8,  0}}, /* 8 */
   {{-16,-16,-16,-16,-16,-16,-16,-16,-15,-14,-14,-14,-14, -9, -7, -8,  0}}, /* 9 */
   {{-16,-16,-16,-16,-16,-16,-16,-16,-15,-14,-14,-14,-14, -9, -7, -8,  0}}, /* 10 */
};

/* noise bias (transition block) */
static noise3 _psy_noisebias_trans[13]={
  /*  63     125     250     500      1k       2k      4k      8k     16k*/
  /* -2(addition mode) */
  {{{-10,-10,-10,-10,-10, -4,  0,  0,  4,  8,  8,  8,  8, 10, 12, 14, 20},
    {-26,-26,-26,-26,-22,-16,-12, -6, -2,  1,  1,  1,  5,  7,  8,  8, 15},
    {-30,-30,-30,-30,-30,-24,-20,-14,-10, -6, -8, -8, -6, -6, -6, -4, -2}}},
  /* -1 */
  {{{-10,-10,-10,-10,-10, -4,  0,  0,  4,  8,  8,  8,  8, 10, 12, 14, 20},
    {-30,-30,-30,-30,-26,-22,-18,-10, -4,  0,  0,  0,  2,  3,  5,  5, 13},
    {-30,-30,-30,-30,-30,-24,-20,-14,-10, -6, -8, -8, -6, -6, -6, -4, -2}}},
  /* 0 */
  {{{-15,-15,-15,-15,-15,-12, -6, -4,  0,  2,  4,  4,  5,  5,  5,  8, 10},
    {-30,-30,-30,-30,-26,-22,-20,-12, -6,  0,  0,  0,  0,  1,  2,  3,  6},
    {-30,-30,-30,-30,-26,-22,-20,-14,-10, -6, -6, -6, -6, -4, -4, -4, -2}}},
  /* 1 */
  {{{-15,-15,-15,-15,-15,-12,-10, -8,  0,  2,  4,  4,  5,  5,  5,  8, 10},
    {-30,-30,-30,-30,-26,-22,-20,-14,-10, -4, -2, -2, -2, -2, -1,  1,  4},
    {-30,-30,-30,-30,-26,-22,-20,-14,-10, -8, -8, -8, -8, -6, -6, -6, -4}}},
  /* 2 */
  {{{-15,-15,-15,-15,-15,-12,-10, -8,  0,  2,  2,  2,  4,  4,  5,  6, 10},
    {-30,-30,-30,-30,-26,-22,-20,-14,-10, -4, -3, -3, -2, -2, -1,  1,  3},
    {-30,-30,-30,-30,-26,-22,-20,-14,-10,-10,-10,-10,-10, -8, -8, -7, -4}}},
  /* 3 */
  {{{-15,-15,-15,-15,-15,-12,-10, -8,  0,  2,  2,  2,  4,  4,  4,  5,  8},
    {-30,-30,-30,-30,-26,-22,-20,-14,-10, -4, -3, -3, -3, -3, -2,  0,  3},
    {-30,-30,-30,-30,-26,-22,-20,-14,-10,-10,-10,-10,-10, -8, -8, -8, -4}}},
  /* 4 */
  {{{-20,-20,-20,-20,-20,-18,-14, -8, -1,  1,  1,  1,  2,  3,  3,  4,  7},
    {-30,-30,-30,-30,-26,-22,-20,-14,-10, -4, -3, -3, -3, -3, -2,  0,  1},
    {-30,-30,-30,-30,-26,-22,-20,-14,-10,-10,-10,-10,-10, -8, -8, -8, -4}}},
  /* 5 */
  {{{-24,-24,-24,-24,-20,-18,-14, -8, -1,  1,  1,  1,  2,  3,  3,  4,  7},
    {-32,-32,-32,-32,-28,-24,-22,-16,-12, -6, -4, -4, -4, -4, -3, -1,  0},
    {-34,-34,-34,-34,-30,-24,-24,-18,-14,-12,-12,-12,-12,-10,-10, -9, -5}}},
  /* 6 */
  {{{-24,-24,-24,-24,-20,-18,-14, -8, -1,  1,  1,  1,  2,  3,  3,  4,  7},
    {-34,-34,-34,-34,-30,-30,-24,-20,-14, -8, -6, -6, -6, -6, -4, -2,  0},
    {-34,-34,-34,-34,-30,-26,-24,-18,-17,-15,-15,-15,-15,-13,-13,-12, -8}}},
  /* 7 */
  {{{-24,-24,-24,-24,-20,-18,-14, -8, -1,  1,  1,  1,  2,  3,  3,  4,  7},
    {-34,-34,-34,-34,-30,-30,-24,-20,-14,-12,-10, -8, -8, -8, -6, -4,  0},
    {-34,-34,-34,-34,-30,-26,-26,-24,-22,-19,-19,-19,-19,-18,-17,-16,-12}}},
  /* 8 */
  {{{-24,-24,-24,-24,-22,-20,-15,-10, -8, -2,  0,  0,  0,  1,  2,  3,  7},
    {-34,-34,-34,-34,-30,-30,-30,-24,-18,-14,-12,-10,-10,-10, -8, -6, -2},
    {-36,-36,-36,-36,-34,-30,-28,-26,-24,-24,-24,-24,-24,-24,-24,-20,-16}}},
  /* 9 */
  {{{-28,-28,-28,-28,-28,-28,-28,-20,-14, -8, -4, -4, -4, -4, -4, -2,  2},
    {-36,-36,-36,-36,-34,-32,-32,-28,-20,-16,-16,-16,-16,-14,-12,-10, -7},
    {-40,-40,-40,-40,-40,-40,-40,-32,-30,-30,-30,-30,-30,-30,-30,-24,-20}}},
  /* 10 */
  {{{-30,-30,-30,-30,-30,-30,-30,-28,-20,-14,-14,-14,-14,-14,-14,-12,-10},
    {-40,-40,-40,-40,-40,-40,-40,-40,-35,-30,-30,-30,-30,-30,-30,-30,-20},
    {-40,-40,-40,-40,-40,-40,-40,-40,-40,-40,-40,-40,-40,-40,-40,-40,-40}}},
};

/*  noise bias (long block) */
static noise3 _psy_noisebias_long[13]={
  /*  63     125     250     500      1k       2k      4k      8k     16k*/
  /* -2(addition mode) */
  {{{-10,-10,-10,-10,-10, -4,  0,  0,  2,  6,  6,  6,  6, 10, 10, 12, 20},
    {-20,-20,-20,-20,-20,-20,-10, -2,  2,  2,  2,  2,  5,  6,  7,  7, 14},
    {-20,-20,-20,-20,-20,-20,-20,-10, -6, -6, -6, -6, -6, -4, -4, -4, -2}}},
  /* -1 */
  {{{-10,-10,-10,-10,-10, -4,  0,  0,  0,  6,  6,  6,  6, 10, 10, 12, 20},
    {-20,-20,-20,-20,-20,-20,-11, -3,  0,  0,  0,  0,  0,  1,  3,  5, 13},
    {-20,-20,-20,-20,-20,-20,-20,-10, -6, -6, -6, -6, -6, -4, -4, -4, -2}}},
  /* 0 */
  {{{-10,-10,-10,-10,-10,-10, -8,  2,  2,  2,  4,  4,  5,  5,  5,  8, 10},
    {-20,-20,-20,-20,-20,-20,-20,-12, -6,  0,  0,  0,  0,  1,  2,  3,  6},
    {-20,-20,-20,-20,-20,-20,-20,-14, -8, -6, -6, -6, -6, -4, -4, -4, -2}}},
  /* 1 */
  {{{-10,-10,-10,-10,-10,-10, -8, -4,  0,  2,  4,  4,  5,  5,  5,  8, 10},
    {-20,-20,-20,-20,-20,-20,-20,-14,-10, -4, -2, -2, -2, -2, -1,  1,  4},
    {-20,-20,-20,-20,-20,-20,-20,-14,-10, -8, -8, -8, -8, -6, -6, -6, -4}}},
  /* 2 */
  {{{-10,-10,-10,-10,-10,-10,-10, -8,  0,  2,  2,  2,  4,  4,  5,  6, 10},
    {-20,-20,-20,-20,-20,-20,-20,-14,-10, -4, -3, -3, -2, -2, -1,  1,  3},
    {-20,-20,-20,-20,-20,-20,-20,-14,-10,-10,-10,-10,-10, -8, -8, -8, -4}}},
  /* 3 */
  {{{-10,-10,-10,-10,-10,-10,-10, -8,  0,  2,  2,  2,  4,  4,  4,  5,  8},
    {-20,-20,-20,-20,-20,-20,-20,-14,-10, -4, -3, -3, -3, -3, -2,  0,  3},
    {-20,-20,-20,-20,-20,-20,-20,-14,-10,-10,-10,-10,-10, -8, -8, -8, -5}}},
  /* 4 */
  {{{-15,-15,-15,-15,-15,-15,-15,-10, -4,  1,  1,  1,  2,  3,  3,  4,  7},
    {-20,-20,-20,-20,-20,-20,-20,-14,-10, -4, -3, -3, -3, -3, -2,  0,  1},
    {-20,-20,-20,-20,-20,-20,-20,-14,-10,-10,-10,-10,-10, -8, -8, -8, -7}}},
  /* 5 */
  {{{-15,-15,-15,-15,-15,-15,-15,-10, -4,  1,  1,  1,  2,  3,  3,  4,  7},
    {-22,-22,-22,-22,-22,-22,-22,-16,-12, -6, -4, -4, -4, -4, -3, -1,  0},
    {-24,-24,-24,-24,-24,-24,-24,-18,-14,-12,-12,-12,-12,-10,-10, -9, -8}}},
  /* 6 */
  {{{-15,-15,-15,-15,-15,-15,-15,-10, -4,  1,  1,  1,  2,  3,  3,  4,  7},
    {-24,-24,-24,-24,-24,-24,-24,-18,-14, -8, -6, -6, -6, -6, -4, -2,  0},
    {-26,-26,-26,-26,-26,-26,-26,-18,-16,-15,-15,-15,-15,-13,-13,-12, -8}}},
  /* 7 */
  {{{-15,-15,-15,-15,-15,-15,-15,-10, -4,  1,  1,  1,  2,  3,  3,  4,  7},
    {-24,-24,-24,-24,-24,-24,-24,-18,-14,-10, -8, -8, -8, -8, -6, -4,  0},
    {-26,-26,-26,-26,-26,-26,-26,-22,-20,-19,-19,-19,-19,-18,-17,-16,-12}}},
  /* 8 */
  {{{-15,-15,-15,-15,-15,-15,-15,-10, -4,  0,  0,  0,  0,  1,  2,  3,  7},
    {-26,-26,-26,-26,-26,-26,-26,-20,-16,-12,-10,-10,-10,-10, -8, -6, -2},
    {-28,-28,-28,-28,-28,-28,-28,-26,-24,-24,-24,-24,-24,-24,-24,-20,-16}}},
  /* 9 */
  {{{-22,-22,-22,-22,-22,-22,-22,-18,-14, -8, -4, -4, -4, -4, -4, -2,  2},
    {-26,-26,-26,-26,-26,-26,-26,-22,-18,-16,-16,-16,-16,-14,-12,-10, -7},
    {-30,-30,-30,-30,-30,-30,-30,-30,-30,-30,-30,-30,-30,-30,-30,-24,-20}}},
  /* 10 */
  {{{-24,-24,-24,-24,-24,-24,-24,-24,-24,-18,-14,-14,-14,-14,-14,-12,-10},
    {-30,-30,-30,-30,-30,-30,-30,-30,-30,-30,-30,-30,-30,-30,-30,-30,-20},
    {-40,-40,-40,-40,-40,-40,-40,-40,-40,-40,-40,-40,-40,-40,-40,-40,-40}}},
};

/* noise bias (impulse block) */
static noise3 _psy_noisebias_impulse[13]={
  /*  63     125     250     500      1k      2k      4k      8k     16k*/
  /* -2(addition mode) */
  {{{-10,-10,-10,-10,-10, -4,  0,  0,  4,  8,  8,  8,  8, 10, 12, 14, 20},
    {-26,-26,-26,-26,-22,-16,-12, -6, -2,  1,  1,  1,  6,  7,  8,  8, 15},
    {-30,-30,-30,-30,-30,-24,-20,-14,-10, -6, -8, -8, -6, -6, -6, -4, -2}}},
  /* -1 */
  {{{-10,-10,-10,-10,-10, -4,  0,  0,  4,  8,  8,  8,  8, 10, 12, 14, 20},
    {-30,-30,-30,-30,-26,-22,-18,-10, -4,  0,  0,  0,  2,  3,  5,  5, 13},
    {-30,-30,-30,-30,-30,-24,-20,-14,-10, -6, -8, -8, -6, -6, -6, -4, -2}}},
  /* 0 */
  {{{-10,-10,-10,-10,-10, -4,  0,  0,  4,  4,  8,  8,  8, 10, 12, 14, 20},
    {-30,-30,-30,-30,-26,-22,-20,-12, -6,  0,  0,  0,  0,  1,  2,  3,  6},
    {-30,-30,-30,-30,-30,-24,-20,-14,-10, -6, -8, -8, -6, -6, -6, -4, -2}}},
  /* 1 */
  {{{-12,-12,-12,-12,-12, -8, -6, -4,  0,  4,  4,  4,  4, 10, 12, 14, 20},
    {-30,-30,-30,-30,-26,-22,-20,-14,-10, -6, -4, -4, -2, -2, -2,  0,  2},
    {-30,-30,-30,-30,-26,-22,-20,-14,-10, -8,-10,-10, -8, -8, -8, -6, -4}}},
  /* 2 */
  {{{-14,-14,-14,-14,-14,-10, -8, -6, -2,  2,  2,  2,  2,  8, 10, 10, 16},
    {-30,-30,-30,-30,-26,-22,-20,-14,-10, -6, -6, -6, -4, -4, -4, -2,  0},
    {-30,-30,-30,-30,-26,-22,-20,-14,-10,-10,-10,-10,-10,-10,-10, -8, -4}}},
  /* 3 */
  {{{-14,-14,-14,-14,-14,-10, -8, -6, -2,  2,  2,  2,  2,  6,  8,  8, 14},
    {-30,-30,-30,-30,-26,-22,-20,-14,-10, -6, -6, -6, -4, -4, -4, -2,  0},
    {-30,-30,-30,-30,-26,-22,-20,-14,-10,-10,-10,-10,-10,-10,-10, -8, -4}}},
  /* 4 */
  {{{-16,-16,-16,-16,-16,-12,-10, -6, -2,  0,  0,  0,  0,  4,  6,  6, 12},
    {-30,-30,-30,-30,-26,-22,-20,-14,-10, -6, -6, -6, -4, -4, -4, -2,  0},
    {-30,-30,-30,-30,-26,-22,-20,-14,-10,-10,-10,-10,-10,-10,-10, -8, -4}}},
  /* 5 */
  {{{-20,-20,-20,-20,-20,-18,-14,-10, -4,  0,  0,  0,  0,  4,  4,  6, 11},
    {-32,-32,-32,-32,-28,-24,-22,-16,-12, -8, -8, -8, -6, -6, -6, -4, -2},
    {-34,-34,-34,-34,-30,-26,-24,-18,-14,-12,-12,-12,-12,-12,-10, -9, -5}}},
  /* 6 */
  {{{-20,-20,-20,-20,-20,-18,-14,-10, -4,  0,  0,  0,  0,  4,  4,  6, 11},
    {-34,-34,-34,-34,-30,-30,-24,-20,-14,-14,-14,-14,-10, -9, -8, -6, -4},
    {-34,-34,-34,-34,-34,-30,-26,-20,-16,-15,-15,-15,-15,-15,-13,-12, -8}}},
  /* 7 */
  {{{-22,-22,-22,-22,-22,-20,-14,-10, -6,  0,  0,  0,  0,  4,  4,  6, 11},
    {-34,-34,-34,-34,-30,-30,-24,-20,-16,-16,-16,-16,-14,-12,-10,-10,-10},
    {-34,-34,-34,-34,-32,-32,-30,-24,-20,-19,-19,-19,-19,-19,-17,-16,-12}}},
  /* 8 */
  {{{-24,-24,-24,-24,-24,-22,-14,-10, -6, -1, -1, -1, -1,  3,  3,  5, 10},
    {-34,-34,-34,-34,-30,-30,-30,-24,-20,-20,-20,-20,-20,-18,-16,-16,-14},
    {-36,-36,-36,-36,-36,-34,-28,-24,-24,-24,-24,-24,-24,-24,-24,-20,-16}}},
  /* 9 */
  {{{-28,-28,-28,-28,-28,-28,-28,-20,-14, -8, -4, -4, -4, -4, -4, -2,  2},
    {-36,-36,-36,-36,-34,-32,-32,-30,-26,-26,-26,-26,-26,-22,-20,-20,-18},
    {-40,-40,-40,-40,-40,-40,-40,-32,-30,-30,-30,-30,-30,-30,-30,-24,-20}}},
  /* 10 */
  {{{-30,-30,-30,-30,-30,-26,-24,-24,-24,-20,-16,-16,-16,-16,-16,-14,-12},
    {-40,-40,-40,-40,-40,-40,-40,-40,-35,-30,-30,-30,-30,-30,-30,-30,-26},
    {-40,-40,-40,-40,-40,-40,-40,-40,-40,-40,-40,-40,-40,-40,-40,-40,-40}}},
};

/* noise bias (padding block) */
static noise3 _psy_noisebias_padding[13]={
  /*  63     125     250     500      1k       2k      4k      8k     16k*/
  /* -2(addition mode) */
  {{{-10,-10,-10,-10,-10, -4,  0,  0,  4,  8,  8,  8,  8, 10, 12, 14, 20},
    {-26,-26,-26,-26,-22,-16,-12, -4, -2,  1,  1,  2,  7,  8,  8,  8, 15},
    {-30,-30,-30,-30,-30,-24,-20,-14,-10, -6, -8, -8, -6, -6, -6, -4, -2}}},
  /* -1 */
  {{{-10,-10,-10,-10,-10, -4,  0,  0,  4,  8,  8,  8,  8, 10, 12, 14, 20},
    {-30,-30,-30,-30,-26,-20,-16, -8, -4,  0,  0,  1,  3,  6,  6,  8, 15},
    {-30,-30,-30,-30,-30,-24,-20,-14,-10, -4, -4, -4, -4, -4, -2,  0,  2}}},
  /* 0 */
  {{{-10,-10,-10,-10,-10, -4,  0,  0,  4,  8,  8,  8,  8, 10, 12, 14, 20},
    {-30,-30,-30,-30,-26,-22,-20,-12, -6,  0,  0,  0,  2,  4,  4,  6, 10},
    {-30,-30,-30,-30,-26,-22,-20,-14,-10, -4, -4, -4, -4, -4, -2,  0,  2}}},
  /* 1 */
  {{{-12,-12,-12,-12,-12, -8, -6, -4,  0,  4,  4,  4,  4, 10, 12, 14, 20},
    {-30,-30,-30,-30,-26,-22,-20,-14,-10, -4,  0,  0,  0,  2,  2,  4,  8},
    {-30,-30,-30,-30,-26,-22,-20,-14,-10, -6, -6, -6, -6, -6, -4, -2,  0}}},
  /* 2 */
  {{{-14,-14,-14,-14,-14,-10, -8, -6, -2,  2,  2,  2,  2,  8, 10, 10, 16},
    {-30,-30,-30,-30,-26,-22,-20,-14,-10, -4,  0,  0,  0,  2,  2,  4,  8},
    {-30,-30,-30,-30,-26,-22,-20,-14,-10, -8, -8, -8, -8, -8, -6, -4, -2}}},
  /* 3 */
  {{{-14,-14,-14,-14,-14,-10, -8, -6, -2,  2,  2,  2,  2,  6,  8,  8, 14},
    {-30,-30,-30,-30,-26,-22,-20,-14,-10, -6, -1, -1, -1,  0,  0,  2,  6},
    {-30,-30,-30,-30,-26,-22,-20,-14,-10, -8, -8, -8, -8, -8, -6, -4, -2}}},
  /* 4 */
  {{{-16,-16,-16,-16,-16,-12,-10, -6, -2,  0,  0,  0,  0,  4,  6,  6, 12},
    {-30,-30,-30,-30,-26,-22,-20,-14,-10, -6, -1, -1, -1, -1,  0,  2,  6},
    {-30,-30,-30,-30,-26,-22,-20,-14,-10, -8, -8, -8, -8, -8, -6, -4, -2}}},
  /* 5 */
  {{{-20,-20,-20,-20,-20,-18,-14,-10, -4,  0,  0,  0,  0,  4,  6,  6, 12},
    {-32,-32,-32,-32,-28,-24,-22,-16,-12, -6, -3, -3, -3, -3, -2,  0,  4},
    {-34,-34,-34,-34,-30,-26,-24,-18,-14,-10,-10,-10,-10,-10, -8, -5, -3}}},
  /* 6 */
  {{{-20,-20,-20,-20,-20,-18,-14,-10, -4,  0,  0,  0,  0,  4,  6,  6, 12},
    {-34,-34,-34,-34,-30,-30,-24,-20,-14, -8, -4, -4, -4, -4, -3, -1,  4},
    {-34,-34,-34,-34,-34,-30,-26,-20,-16,-13,-13,-13,-13,-13,-11, -8, -6}}},
  /* 7 */
  {{{-20,-20,-20,-20,-20,-18,-14,-10, -4,  0,  0,  0,  0,  4,  6,  6, 12},
    {-34,-34,-34,-34,-30,-30,-24,-20,-14,-10, -8, -6, -6, -6, -5, -3,  1},
    {-34,-34,-34,-34,-32,-32,-28,-22,-18,-16,-16,-16,-16,-16,-14,-12,-10}}},
  /* 8 */
  {{{-22,-22,-22,-22,-22,-20,-14,-10, -4,  0,  0,  0,  0,  3,  5,  5, 11},
    {-34,-34,-34,-34,-30,-30,-30,-24,-16,-12,-10, -8, -8, -8, -7, -5, -2},
    {-36,-36,-36,-36,-36,-34,-28,-22,-20,-20,-20,-20,-20,-20,-20,-16,-14}}},
  /* 9 */
  {{{-28,-28,-28,-28,-28,-28,-28,-20,-14, -8, -2, -2, -2, -2,  0,  2,  6},
    {-36,-36,-36,-36,-34,-32,-32,-24,-16,-12,-12,-12,-12,-12,-10, -8, -5},
    {-40,-40,-40,-40,-40,-40,-40,-32,-26,-24,-24,-24,-24,-24,-24,-20,-18}}},
  /* 10 */
  {{{-30,-30,-30,-30,-30,-26,-24,-24,-24,-20,-12,-12,-12,-12,-12,-10, -8},
    {-40,-40,-40,-40,-40,-40,-40,-40,-35,-30,-25,-25,-25,-25,-25,-25,-15},
    {-40,-40,-40,-40,-40,-40,-40,-40,-40,-40,-40,-40,-40,-40,-40,-40,-40}}},
};


static const noiseguard _psy_noiseguards_44[4]={
  {3,3,15},
  {3,3,15},
  {10,10,100},
  {10,10,100},
};

static int _psy_tone_suppress[13]={
  -20,-20,-20,-20,-20,-20,-24,-30,-40,-40,-45,-45,-45,
};
static int _psy_tone_0dB[13]={
   90,90,90,95,95,95,95,105,105,105,105,105,105,
};
static int _psy_noise_suppress[13]={
  -20,-20,-20,-24,-24,-24,-24,-30,-40,-40,-45,-45,-45,
};

static const vorbis_info_psy _psy_info_template={
  /* blockflag */
  -1,
  /* ath_adjatt, ath_maxatt */
  -999.,-999.,
  /* tonemask att boost/decay,suppr,curves */
  {0.f,0.f,0.f},     0.,0.,    -40.f, {0.},

  /*noisemaskp,supp, low/high window, low/hi guard, minimum */
  1,          -0.f,           .5f, .5f,         0,0,0,
  /* noiseoffset*3, noisecompand, noisecompand-high, flacint, max_curve_dB */
  {{-1},{-1},{-1}},{-1},{-1},0., 999.f,
  /* noise normalization - noise_p, start, partition, thresh. */
  0,-1,-1,0.,
};

/* ath ****************/

static const int _psy_ath_floater[13]={
  -999,-999,-999,-999,-999,-999,-999,-999,-999,-999,-999,-999,-999,
};
static const int _psy_ath_abs[13]={
  -999,-999,-999,-999,-999,-999,-999,-999,-999,-999,-999,-999,-999,
};

/* stereo setup.  These don't map directly to quality level, there's
   an additional indirection as several of the below may be used in a
   single bitmanaged stream

****************/

/* various stereo possibilities */

/* stereo mode by base quality level */
static adj_stereo _psy_stereo_modes_44[13]={
  /*  0   1   2   3   4   5   6   7   8   9  10  11  12  13  14        -2(addition mode)  */
  {{  4,  4,  4,  4,  4,  4,  4,  4,  3,  2,  1,  0,  0,  0,  0},
   {  8,  8,  8,  8,  8,  8,  7,  6,  6,  6,  6,  6,  5,  4,  3},
   {  1,  2,  2,  2,  2,  3,  3,  4,  4,  4,  5,  6,  7,  8,  8},
   { 10,10.5, 11,11.5, 12,12.5, 13, 99, 99, 99, 99, 99, 99, 99, 99}},
  /*  0   1   2   3   4   5   6   7   8   9  10  11  12  13  14        -1  */
  {{  4,  4,  4,  4,  4,  4,  4,  3,  2,  2,  1,  0,  0,  0,  0},
   {  8,  8,  8,  8,  8,  7,  7,  6,  6,  6,  6,  6,  5,  4,  3},
   {  1,  2,  3,  4,  4,  4,  4,  4,  4,  5,  6,  7,  8,  8,  8},
   { 12,12.5, 13,13.5, 14,14.5, 15, 99, 99, 99, 99, 99, 99, 99, 99}},
  /*   0   1   2   3   4   5   6   7   8   9  10  11  12  13  14        0  */
  {{  4,  4,  4,  4,  4,  4,  4,  3,  2,  1,  0,  0,  0,  0,  0},
   {  8,  8,  8,  8,  6,  6,  5,  5,  5,  5,  5,  5,  5,  4,  3},
   {  1,  2,  3,  4,  4,  5,  6,  6,  6,  6,  6,  8,  8,  8,  8},
   { 12,12.5, 13,13.5, 14,14.5, 15, 99, 99, 99, 99, 99, 99, 99, 99}},
  /*  0   1   2   3   4   5   6   7   8   9  10  11  12  13  14        1  */
  {{  3,  3,  3,  3,  3,  3,  3,  3,  2,  1,  0,  0,  0,  0,  0},
   {  8,  8,  8,  8,  6,  6,  5,  4,  4,  4,  4,  4,  4,  3,  3},
   {  1,  2,  3,  4,  4,  5,  6,  6,  6,  6,  6,  8,  8,  8,  8},
   { 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99}},
  /*  0   1   2   3   4   5   6   7   8   9  10  11  12  13  14        2  */
  {{  3,  3,  3,  3,  3,  3,  3,  2,  1,  1,  0,  0,  0,  0,  0},
   {  8,  8,  6,  6,  5,  5,  4,  4,  4,  4,  4,  4,  3,  2,  1},
   {  3,  4,  4,  5,  5,  6,  6,  6,  6,  6,  6,  8,  8,  8,  8},
   { 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99}},
  /*  0   1   2   3   4   5   6   7   8   9  10  11  12  13  14        3  */
  {{  2,  2,  2,  2,  2,  1,  1,  1,  1,  0,  0,  0,  0,  0,  0},
   {  5,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  3,  2,  1},
   {  4,  4,  5,  6,  6,  6,  6,  6,  8,  8, 10, 10, 10, 10, 10},
   { 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99}},
  /*  0   1   2   3   4   5   6   7   8   9  10  11  12  13  14        4  */
  {{  2,  2,  2,  1,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0},
   {  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  3,  3,  2,  1,  0},
   {  6,  6,  6,  8,  8,  8,  8,  8,  8,  8, 10, 10, 10, 10, 10},
   { 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99}},
  /*  0   1   2   3   4   5   6   7   8   9  10  11  12  13  14        5  */
  {{  2,  2,  2,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
   {  3,  3,  3,  3,  3,  2,  2,  2,  2,  2,  2,  0,  0,  0,  0},
   {  6,  7,  8,  8,  8, 10, 10, 12, 12, 12, 12, 12, 12, 12, 12},
   { 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99}},
  /*  0   1   2   3   4   5   6   7   8   9  10  11  12  13  14        6  */
  {{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
   {  3,  3,  3,  2,  2,  2,  0,  0,  0,  0,  0,  0,  0,  0,  0},
   {  8,  8,  8, 10, 10, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12},
   { 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99}},
  /*  0   1   2   3   4   5   6   7   8   9  10  11  12  13  14        7  */
  {{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
   {  3,  3,  3,  2,  2,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
   {  8,  8, 10, 10, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12},
   { 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99}},
  /*  0   1   2   3   4   5   6   7   8   9  10  11  12  13  14        8  */
  {{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
   {  2,  2,  2,  2,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
   {  8, 10, 10, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12},
   { 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99}},
  /*  0   1   2   3   4   5   6   7   8   9  10  11  12  13  14        9  */
  {{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
   {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
   {  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4},
   { 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99}},
  /*  0   1   2   3   4   5   6   7   8   9  10  11  12  13  14       10  */
  {{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
   {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
   {  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4},
   { 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99}},
};

/* tone master attenuation by base quality mode and bitrate tweak */
static att3 _psy_tone_masteratt_44[13]={
  {{ 37,  23,  11},  0,    0}, /* -2 */
  {{ 35,  21,   9},  0,    0}, /* -1 */
  {{ 30,  20,   8},  0,    0}, /* 0 */
  {{ 25,  14,   4},  0,    0}, /* 1 */
  {{ 20,  10,  -2},  0,    0}, /* 2 */
  {{ 21,  10,  -3},  0,    0}, /* 3 */
  {{ 20,   9,  -4},  0,    0}, /* 4 */
  {{ 20,   6,  -6},  0,    0}, /* 5 */
  {{ 20,   3, -10},  0,    0}, /* 6 */
  {{ 18,   1, -14},  0,    0}, /* 7 */
  {{ 18,   0, -16},  0,    0}, /* 8 */
  {{ 18,  -2, -16},  0,    0}, /* 9 */
  {{ 12,  -2, -20},  0,    0}, /* 10 */
};

/* lowpass by mode **************/
static const double _psy_lowpass_44[13]={
  16.5,16.5,16.5,16.5,16.5,999.,999.,999.,999.,999.,999.,999.,999.
};

/* noise normalization **********/

static int _noise_start_short_44[12]={
  8,8,16,16,32,64,9999,9999,9999,9999,9999,9999
};
static int _noise_start_long_44[12]={
  64,64,128,128,256,512,9999,9999,9999,9999,9999,9999
};

static const int _noise_part_short_44[12]={
    8,8,8,8,8,8,8,8,8,8,8,8
};
static const int _noise_part_long_44[12]={
    32,32,32,32,32,32,32,32,32,32,32,32
};

static double _noise_thresh_44[12]={
   .2,.2,.2,.2,.4,.8,9999.,9999.,9999.,9999.,9999.,9999.,
};

/* 0~8kHz */
static const double _noise_thresh_5only[3]={
 .5,.5,.5
};

/* 32kHz only */
static int _noise_start_short_32[12]={
  10,10,20,20,40,80,9999,9999,9999,9999,9999,9999
};
static int _noise_start_long_32[12]={
  80,80,160,160,320,640,9999,9999,9999,9999,9999,9999
};