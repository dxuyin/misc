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

 function: 8kHz settings

 ********************************************************************/

#include "psych_8.h"
#include "residue_8.h"

static const float preamp_8[4]={
1.f, 1.f, 1.f, 1.f
};

static const int blocksize_8[3]={
  512,512,512
};

static const int _floor_mapping_8a[]={
  6,6,6
};

static const int *_floor_mapping_8[]={
  _floor_mapping_8a
};

static const double rate_mapping_8[4]={
  4000.,6000.,8000.,32000.,
};

static const double rate_mapping_8_uncoupled[4]={
  8000.,12000.,16000.,48000.,
};

static const double quality_mapping_8[4]={
  -.2,-.1,.0,1.
};

static const double _psy_compand_8_mapping[4]={ 0., 1., 2., 2.};

static const double _global_mapping_8[4]={ 1., 2., 3., 4. };

static const ve_setup_data_template ve_setup_8_stereo={
  3,
  rate_mapping_8,
  quality_mapping_8,
  preamp_8,
  2,
  8000,
  9000,

  blocksize_8,
  blocksize_8,

  _psy_tone_masteratt_8,
  _psy_tone_0dB,
  _psy_tone_suppress,

  _vp_tonemask_adj_8,
  NULL,
  _vp_tonemask_adj_8,

  _psy_noiseguards_8,
  _psy_noisebias_8,
  _psy_noisebias_8,
  NULL,
  NULL,
  _psy_noise_suppress,

  _psy_compand_8,
  _psy_compand_8_mapping,
  NULL,

  {_noise_start_8,_noise_start_8},
  {_noise_part_8,_noise_part_8},
  _noise_thresh_5only,

  _psy_ath_floater_8,
  _psy_ath_abs_8,

  _psy_lowpass_8,

  _psy_global_44,
  _global_mapping_8,
  _psy_stereo_modes_8,

  _floor_books,
  _floor,
  1,
  _floor_mapping_8,

  _mapres_template_8_stereo
};

static const ve_setup_data_template ve_setup_8_uncoupled={
  3,
  rate_mapping_8_uncoupled,
  quality_mapping_8,
  preamp_8,
  -1,
  8000,
  9000,

  blocksize_8,
  blocksize_8,

  _psy_tone_masteratt_8,
  _psy_tone_0dB,
  _psy_tone_suppress,

  _vp_tonemask_adj_8,
  NULL,
  _vp_tonemask_adj_8,

  _psy_noiseguards_8,
  _psy_noisebias_8,
  _psy_noisebias_8,
  NULL,
  NULL,
  _psy_noise_suppress,

  _psy_compand_8,
  _psy_compand_8_mapping,
  NULL,

  {_noise_start_8,_noise_start_8},
  {_noise_part_8,_noise_part_8},
  _noise_thresh_5only,

  _psy_ath_floater_8,
  _psy_ath_abs_8,

  _psy_lowpass_8,

  _psy_global_44,
  _global_mapping_8,
  _psy_stereo_modes_8,

  _floor_books,
  _floor,
  1,
  _floor_mapping_8,

  _mapres_template_8_uncoupled
};
