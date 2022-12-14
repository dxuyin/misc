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

 function: toplevel settings for 32kHz

 ********************************************************************/

static const float preamp_32[13]={
1.f, 1.f,
1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f
};

static const double rate_mapping_32[13]={
  16000.,24000.,28000.,32000.,48000.,56000.,64000.,
  80000.,96000.,100000.,112000.,150000.,192000.,
};

static const double rate_mapping_32_un[13]={
  24000.,32000.,40000.,48000.,56000.,64000.,72000.,
  80000.,96000.,112000.,128000.,160000.,192000.,
};

static const double _psy_lowpass_32[13]={
  99.,99.,99.,99.,99.,99.,99.,99.,99.,99.,99.,99.,99.
};

/* short */
static const int _floor_mapping_32a[12]={
  0,0,0,0,2,2,4,5,5,5,5,5
};
/* long */
static const int _floor_mapping_32b[12]={
  7,7,7,7,7,7,7,7,7,7,7,7
};
/* LFE only */
static const int _floor_mapping_32c[12]={
  10,10,10,10,10,10,10,10,10,10,10,10
};
static const int *_floor_mapping_32[]={
  _floor_mapping_32a,
  _floor_mapping_32b,
  _floor_mapping_32c,
};

static const ve_setup_data_template ve_setup_32_stereo={
  12,
  rate_mapping_32,
  quality_mapping_44,
  preamp_32,
  2,
  26000,
  40000,

  blocksize_short_44,
  blocksize_long_44,

  _psy_tone_masteratt_44,
  _psy_tone_0dB,
  _psy_tone_suppress,

  _vp_tonemask_adj_otherblock,
  _vp_tonemask_adj_longblock,
  _vp_tonemask_adj_otherblock,

  _psy_noiseguards_44,
  _psy_noisebias_impulse,
  _psy_noisebias_padding,
  _psy_noisebias_trans,
  _psy_noisebias_long,
  _psy_noise_suppress,

  _psy_compand_44,
  _psy_compand_short_mapping,
  _psy_compand_long_mapping,

  {_noise_start_short_32,_noise_start_long_32},
  {_noise_part_short_44,_noise_part_long_44},
  _noise_thresh_44,

  _psy_ath_floater,
  _psy_ath_abs,

  _psy_lowpass_32,

  _psy_global_44,
  _global_mapping_44,
  _psy_stereo_modes_44,

  _floor_books,
  _floor,
  2,
  _floor_mapping_32,

  _mapres_template_44_stereo
};

static const ve_setup_data_template ve_setup_32_uncoupled={
  12,
  rate_mapping_32_un,
  quality_mapping_44,
  preamp_32,
  -1,
  26000,
  40000,

  blocksize_short_44,
  blocksize_long_44,

  _psy_tone_masteratt_44,
  _psy_tone_0dB,
  _psy_tone_suppress,

  _vp_tonemask_adj_otherblock,
  _vp_tonemask_adj_longblock,
  _vp_tonemask_adj_otherblock,

  _psy_noiseguards_44,
  _psy_noisebias_impulse,
  _psy_noisebias_padding,
  _psy_noisebias_trans,
  _psy_noisebias_long,
  _psy_noise_suppress,

  _psy_compand_44,
  _psy_compand_short_mapping,
  _psy_compand_long_mapping,

  {_noise_start_short_32,_noise_start_long_32},
  {_noise_part_short_44,_noise_part_long_44},
  _noise_thresh_44,

  _psy_ath_floater,
  _psy_ath_abs,

  _psy_lowpass_32,

  _psy_global_44,
  _global_mapping_44,
  NULL,

  _floor_books,
  _floor,
  2,
  _floor_mapping_32,

  _mapres_template_44_uncoupled
};
