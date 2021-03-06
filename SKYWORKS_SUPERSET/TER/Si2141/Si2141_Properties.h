/*************************************************************************************************************
Copyright 2021-2022, Skyworks Solutions, Inc.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
 *************************************************************************************************************/
/*************************************************************************************
                  Skyworks Solutions Broadcast Si2141 Layer 1 API


   API properties structures and functions definitions
   FILE: Si2141_Properties.h
   Supported IC : Si2141
   Compiled for ROM 61 firmware 1_1_build_11
   Revision: 0.7
   Date: June 14 2019
**************************************************************************************/
#ifndef   _Si2141_PROPERTIES_H_
#define   _Si2141_PROPERTIES_H_

/* Si2141 CRYSTAL_TRIM property definition */
#define   Si2141_CRYSTAL_TRIM_PROP 0x0402

#ifdef    Si2141_CRYSTAL_TRIM_PROP
  #define Si2141_CRYSTAL_TRIM_PROP_CODE 0x000402


    typedef struct { /* Si2141_CRYSTAL_TRIM_PROP_struct */
      unsigned char   xo_cap;
   } Si2141_CRYSTAL_TRIM_PROP_struct;

   /* CRYSTAL_TRIM property, XO_CAP field definition (NO TITLE)*/
   #define  Si2141_CRYSTAL_TRIM_PROP_XO_CAP_LSB         0
   #define  Si2141_CRYSTAL_TRIM_PROP_XO_CAP_MASK        0x0f
   #define  Si2141_CRYSTAL_TRIM_PROP_XO_CAP_DEFAULT    8
    #define Si2141_CRYSTAL_TRIM_PROP_XO_CAP_4P7PF   0
    #define Si2141_CRYSTAL_TRIM_PROP_XO_CAP_5P2PF   2
    #define Si2141_CRYSTAL_TRIM_PROP_XO_CAP_5P7PF   4
    #define Si2141_CRYSTAL_TRIM_PROP_XO_CAP_6P2PF   6
    #define Si2141_CRYSTAL_TRIM_PROP_XO_CAP_6P7PF   8
    #define Si2141_CRYSTAL_TRIM_PROP_XO_CAP_7P2PF   10
    #define Si2141_CRYSTAL_TRIM_PROP_XO_CAP_7P7PF   12
    #define Si2141_CRYSTAL_TRIM_PROP_XO_CAP_8P2PF   14

#endif /* Si2141_CRYSTAL_TRIM_PROP */

/* Si2141 DTV_AGC_AUTO_FREEZE property definition */
#define   Si2141_DTV_AGC_AUTO_FREEZE_PROP 0x0714

#ifdef    Si2141_DTV_AGC_AUTO_FREEZE_PROP
  #define Si2141_DTV_AGC_AUTO_FREEZE_PROP_CODE 0x000714


    typedef struct { /* Si2141_DTV_AGC_AUTO_FREEZE_PROP_struct */
      unsigned char   thld;
      unsigned char   timeout;
   } Si2141_DTV_AGC_AUTO_FREEZE_PROP_struct;

   /* DTV_AGC_AUTO_FREEZE property, THLD field definition (NO TITLE)*/
   #define  Si2141_DTV_AGC_AUTO_FREEZE_PROP_THLD_LSB         0
   #define  Si2141_DTV_AGC_AUTO_FREEZE_PROP_THLD_MASK        0xff
   #define  Si2141_DTV_AGC_AUTO_FREEZE_PROP_THLD_DEFAULT    255
    #define Si2141_DTV_AGC_AUTO_FREEZE_PROP_THLD_THLD_MIN  0
    #define Si2141_DTV_AGC_AUTO_FREEZE_PROP_THLD_THLD_MAX  255

   /* DTV_AGC_AUTO_FREEZE property, TIMEOUT field definition (NO TITLE)*/
   #define  Si2141_DTV_AGC_AUTO_FREEZE_PROP_TIMEOUT_LSB         8
   #define  Si2141_DTV_AGC_AUTO_FREEZE_PROP_TIMEOUT_MASK        0xff
   #define  Si2141_DTV_AGC_AUTO_FREEZE_PROP_TIMEOUT_DEFAULT    1
    #define Si2141_DTV_AGC_AUTO_FREEZE_PROP_TIMEOUT_TIMEOUT_MIN  1
    #define Si2141_DTV_AGC_AUTO_FREEZE_PROP_TIMEOUT_TIMEOUT_MAX  250

#endif /* Si2141_DTV_AGC_AUTO_FREEZE_PROP */

/* Si2141 DTV_AGC_SPEED property definition */
#define   Si2141_DTV_AGC_SPEED_PROP 0x0708

#ifdef    Si2141_DTV_AGC_SPEED_PROP
  #define Si2141_DTV_AGC_SPEED_PROP_CODE 0x000708


    typedef struct { /* Si2141_DTV_AGC_SPEED_PROP_struct */
      unsigned char   agc_decim;
      unsigned char   if_agc_speed;
   } Si2141_DTV_AGC_SPEED_PROP_struct;

   /* DTV_AGC_SPEED property, AGC_DECIM field definition (NO TITLE)*/
   #define  Si2141_DTV_AGC_SPEED_PROP_AGC_DECIM_LSB         8
   #define  Si2141_DTV_AGC_SPEED_PROP_AGC_DECIM_MASK        0x03
   #define  Si2141_DTV_AGC_SPEED_PROP_AGC_DECIM_DEFAULT    0
    #define Si2141_DTV_AGC_SPEED_PROP_AGC_DECIM_OFF  0
    #define Si2141_DTV_AGC_SPEED_PROP_AGC_DECIM_2    1
    #define Si2141_DTV_AGC_SPEED_PROP_AGC_DECIM_4    2
    #define Si2141_DTV_AGC_SPEED_PROP_AGC_DECIM_8    3

   /* DTV_AGC_SPEED property, IF_AGC_SPEED field definition (NO TITLE)*/
   #define  Si2141_DTV_AGC_SPEED_PROP_IF_AGC_SPEED_LSB         0
   #define  Si2141_DTV_AGC_SPEED_PROP_IF_AGC_SPEED_MASK        0xff
   #define  Si2141_DTV_AGC_SPEED_PROP_IF_AGC_SPEED_DEFAULT    0
    #define Si2141_DTV_AGC_SPEED_PROP_IF_AGC_SPEED_AUTO  0
    #define Si2141_DTV_AGC_SPEED_PROP_IF_AGC_SPEED_39    39
    #define Si2141_DTV_AGC_SPEED_PROP_IF_AGC_SPEED_54    54
    #define Si2141_DTV_AGC_SPEED_PROP_IF_AGC_SPEED_63    63
    #define Si2141_DTV_AGC_SPEED_PROP_IF_AGC_SPEED_89    89
    #define Si2141_DTV_AGC_SPEED_PROP_IF_AGC_SPEED_105   105
    #define Si2141_DTV_AGC_SPEED_PROP_IF_AGC_SPEED_121   121
    #define Si2141_DTV_AGC_SPEED_PROP_IF_AGC_SPEED_137   137
    #define Si2141_DTV_AGC_SPEED_PROP_IF_AGC_SPEED_158   158
    #define Si2141_DTV_AGC_SPEED_PROP_IF_AGC_SPEED_172   172
    #define Si2141_DTV_AGC_SPEED_PROP_IF_AGC_SPEED_185   185
    #define Si2141_DTV_AGC_SPEED_PROP_IF_AGC_SPEED_196   196
    #define Si2141_DTV_AGC_SPEED_PROP_IF_AGC_SPEED_206   206
    #define Si2141_DTV_AGC_SPEED_PROP_IF_AGC_SPEED_216   216
    #define Si2141_DTV_AGC_SPEED_PROP_IF_AGC_SPEED_219   219
    #define Si2141_DTV_AGC_SPEED_PROP_IF_AGC_SPEED_222   222

#endif /* Si2141_DTV_AGC_SPEED_PROP */

/* Si2141 DTV_CONFIG_IF_PORT property definition */
#define   Si2141_DTV_CONFIG_IF_PORT_PROP 0x0702

#ifdef    Si2141_DTV_CONFIG_IF_PORT_PROP
  #define Si2141_DTV_CONFIG_IF_PORT_PROP_CODE 0x000702


    typedef struct { /* Si2141_DTV_CONFIG_IF_PORT_PROP_struct */
      unsigned char   dtv_out_type;
   } Si2141_DTV_CONFIG_IF_PORT_PROP_struct;

   /* DTV_CONFIG_IF_PORT property, DTV_OUT_TYPE field definition (NO TITLE)*/
   #define  Si2141_DTV_CONFIG_IF_PORT_PROP_DTV_OUT_TYPE_LSB         0
   #define  Si2141_DTV_CONFIG_IF_PORT_PROP_DTV_OUT_TYPE_MASK        0x0f
   #define  Si2141_DTV_CONFIG_IF_PORT_PROP_DTV_OUT_TYPE_DEFAULT    0
    #define Si2141_DTV_CONFIG_IF_PORT_PROP_DTV_OUT_TYPE_LIF_IF      0
    #define Si2141_DTV_CONFIG_IF_PORT_PROP_DTV_OUT_TYPE_LIF_SE_IFA  4

#endif /* Si2141_DTV_CONFIG_IF_PORT_PROP */

/* Si2141 DTV_EXT_AGC property definition */
#define   Si2141_DTV_EXT_AGC_PROP 0x0705

#ifdef    Si2141_DTV_EXT_AGC_PROP
  #define Si2141_DTV_EXT_AGC_PROP_CODE 0x000705


    typedef struct { /* Si2141_DTV_EXT_AGC_PROP_struct */
      unsigned char   max_10mv;
      unsigned char   min_10mv;
   } Si2141_DTV_EXT_AGC_PROP_struct;

   /* DTV_EXT_AGC property, MAX_10MV field definition (NO TITLE)*/
   #define  Si2141_DTV_EXT_AGC_PROP_MAX_10MV_LSB         8
   #define  Si2141_DTV_EXT_AGC_PROP_MAX_10MV_MASK        0xff
   #define  Si2141_DTV_EXT_AGC_PROP_MAX_10MV_DEFAULT    200
    #define Si2141_DTV_EXT_AGC_PROP_MAX_10MV_MAX_10MV_MIN  0
    #define Si2141_DTV_EXT_AGC_PROP_MAX_10MV_MAX_10MV_MAX  255

   /* DTV_EXT_AGC property, MIN_10MV field definition (NO TITLE)*/
   #define  Si2141_DTV_EXT_AGC_PROP_MIN_10MV_LSB         0
   #define  Si2141_DTV_EXT_AGC_PROP_MIN_10MV_MASK        0xff
   #define  Si2141_DTV_EXT_AGC_PROP_MIN_10MV_DEFAULT    50
    #define Si2141_DTV_EXT_AGC_PROP_MIN_10MV_MIN_10MV_MIN  0
    #define Si2141_DTV_EXT_AGC_PROP_MIN_10MV_MIN_10MV_MAX  255

#endif /* Si2141_DTV_EXT_AGC_PROP */

/* Si2141 DTV_IF_AGC_SPEED property definition */
#define   Si2141_DTV_IF_AGC_SPEED_PROP 0x0716

#ifdef    Si2141_DTV_IF_AGC_SPEED_PROP
  #define Si2141_DTV_IF_AGC_SPEED_PROP_CODE 0x000716


    typedef struct { /* Si2141_DTV_IF_AGC_SPEED_PROP_struct */
      unsigned char   attack;
      unsigned char   decay;
   } Si2141_DTV_IF_AGC_SPEED_PROP_struct;

   /* DTV_IF_AGC_SPEED property, ATTACK field definition (NO TITLE)*/
   #define  Si2141_DTV_IF_AGC_SPEED_PROP_ATTACK_LSB         0
   #define  Si2141_DTV_IF_AGC_SPEED_PROP_ATTACK_MASK        0xff
   #define  Si2141_DTV_IF_AGC_SPEED_PROP_ATTACK_DEFAULT    0
    #define Si2141_DTV_IF_AGC_SPEED_PROP_ATTACK_AUTO  0

    #define Si2141_DTV_IF_AGC_SPEED_PROP_ATTACK_ATTACK_MIN  0
    #define Si2141_DTV_IF_AGC_SPEED_PROP_ATTACK_ATTACK_MAX  231

   /* DTV_IF_AGC_SPEED property, DECAY field definition (NO TITLE)*/
   #define  Si2141_DTV_IF_AGC_SPEED_PROP_DECAY_LSB         8
   #define  Si2141_DTV_IF_AGC_SPEED_PROP_DECAY_MASK        0xff
   #define  Si2141_DTV_IF_AGC_SPEED_PROP_DECAY_DEFAULT    0
    #define Si2141_DTV_IF_AGC_SPEED_PROP_DECAY_AUTO  0

    #define Si2141_DTV_IF_AGC_SPEED_PROP_DECAY_DECAY_MIN  0
    #define Si2141_DTV_IF_AGC_SPEED_PROP_DECAY_DECAY_MAX  231

#endif /* Si2141_DTV_IF_AGC_SPEED_PROP */

/* Si2141 DTV_INITIAL_AGC_SPEED property definition */
#define   Si2141_DTV_INITIAL_AGC_SPEED_PROP 0x070d

#ifdef    Si2141_DTV_INITIAL_AGC_SPEED_PROP
  #define Si2141_DTV_INITIAL_AGC_SPEED_PROP_CODE 0x00070d


    typedef struct { /* Si2141_DTV_INITIAL_AGC_SPEED_PROP_struct */
      unsigned char   agc_decim;
      unsigned char   if_agc_speed;
   } Si2141_DTV_INITIAL_AGC_SPEED_PROP_struct;

   /* DTV_INITIAL_AGC_SPEED property, AGC_DECIM field definition (NO TITLE)*/
   #define  Si2141_DTV_INITIAL_AGC_SPEED_PROP_AGC_DECIM_LSB         8
   #define  Si2141_DTV_INITIAL_AGC_SPEED_PROP_AGC_DECIM_MASK        0x03
   #define  Si2141_DTV_INITIAL_AGC_SPEED_PROP_AGC_DECIM_DEFAULT    0
    #define Si2141_DTV_INITIAL_AGC_SPEED_PROP_AGC_DECIM_OFF  0
    #define Si2141_DTV_INITIAL_AGC_SPEED_PROP_AGC_DECIM_2    1
    #define Si2141_DTV_INITIAL_AGC_SPEED_PROP_AGC_DECIM_4    2
    #define Si2141_DTV_INITIAL_AGC_SPEED_PROP_AGC_DECIM_8    3

   /* DTV_INITIAL_AGC_SPEED property, IF_AGC_SPEED field definition (NO TITLE)*/
   #define  Si2141_DTV_INITIAL_AGC_SPEED_PROP_IF_AGC_SPEED_LSB         0
   #define  Si2141_DTV_INITIAL_AGC_SPEED_PROP_IF_AGC_SPEED_MASK        0xff
   #define  Si2141_DTV_INITIAL_AGC_SPEED_PROP_IF_AGC_SPEED_DEFAULT    0
    #define Si2141_DTV_INITIAL_AGC_SPEED_PROP_IF_AGC_SPEED_AUTO  0
    #define Si2141_DTV_INITIAL_AGC_SPEED_PROP_IF_AGC_SPEED_39    39
    #define Si2141_DTV_INITIAL_AGC_SPEED_PROP_IF_AGC_SPEED_54    54
    #define Si2141_DTV_INITIAL_AGC_SPEED_PROP_IF_AGC_SPEED_63    63
    #define Si2141_DTV_INITIAL_AGC_SPEED_PROP_IF_AGC_SPEED_89    89
    #define Si2141_DTV_INITIAL_AGC_SPEED_PROP_IF_AGC_SPEED_105   105
    #define Si2141_DTV_INITIAL_AGC_SPEED_PROP_IF_AGC_SPEED_121   121
    #define Si2141_DTV_INITIAL_AGC_SPEED_PROP_IF_AGC_SPEED_137   137
    #define Si2141_DTV_INITIAL_AGC_SPEED_PROP_IF_AGC_SPEED_158   158
    #define Si2141_DTV_INITIAL_AGC_SPEED_PROP_IF_AGC_SPEED_172   172
    #define Si2141_DTV_INITIAL_AGC_SPEED_PROP_IF_AGC_SPEED_185   185
    #define Si2141_DTV_INITIAL_AGC_SPEED_PROP_IF_AGC_SPEED_196   196
    #define Si2141_DTV_INITIAL_AGC_SPEED_PROP_IF_AGC_SPEED_206   206
    #define Si2141_DTV_INITIAL_AGC_SPEED_PROP_IF_AGC_SPEED_216   216
    #define Si2141_DTV_INITIAL_AGC_SPEED_PROP_IF_AGC_SPEED_219   219
    #define Si2141_DTV_INITIAL_AGC_SPEED_PROP_IF_AGC_SPEED_222   222

#endif /* Si2141_DTV_INITIAL_AGC_SPEED_PROP */

/* Si2141 DTV_INITIAL_AGC_SPEED_PERIOD property definition */
#define   Si2141_DTV_INITIAL_AGC_SPEED_PERIOD_PROP 0x070e

#ifdef    Si2141_DTV_INITIAL_AGC_SPEED_PERIOD_PROP
  #define Si2141_DTV_INITIAL_AGC_SPEED_PERIOD_PROP_CODE 0x00070e


    typedef struct { /* Si2141_DTV_INITIAL_AGC_SPEED_PERIOD_PROP_struct */
      unsigned int    period;
   } Si2141_DTV_INITIAL_AGC_SPEED_PERIOD_PROP_struct;

   /* DTV_INITIAL_AGC_SPEED_PERIOD property, PERIOD field definition (NO TITLE)*/
   #define  Si2141_DTV_INITIAL_AGC_SPEED_PERIOD_PROP_PERIOD_LSB         0
   #define  Si2141_DTV_INITIAL_AGC_SPEED_PERIOD_PROP_PERIOD_MASK        0xffff
   #define  Si2141_DTV_INITIAL_AGC_SPEED_PERIOD_PROP_PERIOD_DEFAULT    0
    #define Si2141_DTV_INITIAL_AGC_SPEED_PERIOD_PROP_PERIOD_PERIOD_MIN  0
    #define Si2141_DTV_INITIAL_AGC_SPEED_PERIOD_PROP_PERIOD_PERIOD_MAX  65535

#endif /* Si2141_DTV_INITIAL_AGC_SPEED_PERIOD_PROP */

/* Si2141 DTV_INTERNAL_ZIF property definition */
#define   Si2141_DTV_INTERNAL_ZIF_PROP 0x0710

#ifdef    Si2141_DTV_INTERNAL_ZIF_PROP
  #define Si2141_DTV_INTERNAL_ZIF_PROP_CODE 0x000710


    typedef struct { /* Si2141_DTV_INTERNAL_ZIF_PROP_struct */
      unsigned char   atsc;
      unsigned char   dtmb;
      unsigned char   dvbc;
      unsigned char   dvbt;
      unsigned char   isdbc;
      unsigned char   isdbt;
      unsigned char   qam_us;
   } Si2141_DTV_INTERNAL_ZIF_PROP_struct;

   /* DTV_INTERNAL_ZIF property, ATSC field definition (NO TITLE)*/
   #define  Si2141_DTV_INTERNAL_ZIF_PROP_ATSC_LSB         0
   #define  Si2141_DTV_INTERNAL_ZIF_PROP_ATSC_MASK        0x01
   #define  Si2141_DTV_INTERNAL_ZIF_PROP_ATSC_DEFAULT    1
    #define Si2141_DTV_INTERNAL_ZIF_PROP_ATSC_LIF  0
    #define Si2141_DTV_INTERNAL_ZIF_PROP_ATSC_ZIF  1

   /* DTV_INTERNAL_ZIF property, DTMB field definition (NO TITLE)*/
   #define  Si2141_DTV_INTERNAL_ZIF_PROP_DTMB_LSB         6
   #define  Si2141_DTV_INTERNAL_ZIF_PROP_DTMB_MASK        0x01
   #define  Si2141_DTV_INTERNAL_ZIF_PROP_DTMB_DEFAULT    0
    #define Si2141_DTV_INTERNAL_ZIF_PROP_DTMB_LIF  0
    #define Si2141_DTV_INTERNAL_ZIF_PROP_DTMB_ZIF  1

   /* DTV_INTERNAL_ZIF property, DVBC field definition (NO TITLE)*/
   #define  Si2141_DTV_INTERNAL_ZIF_PROP_DVBC_LSB         3
   #define  Si2141_DTV_INTERNAL_ZIF_PROP_DVBC_MASK        0x01
   #define  Si2141_DTV_INTERNAL_ZIF_PROP_DVBC_DEFAULT    1
    #define Si2141_DTV_INTERNAL_ZIF_PROP_DVBC_LIF  0
    #define Si2141_DTV_INTERNAL_ZIF_PROP_DVBC_ZIF  1

   /* DTV_INTERNAL_ZIF property, DVBT field definition (NO TITLE)*/
   #define  Si2141_DTV_INTERNAL_ZIF_PROP_DVBT_LSB         2
   #define  Si2141_DTV_INTERNAL_ZIF_PROP_DVBT_MASK        0x01
   #define  Si2141_DTV_INTERNAL_ZIF_PROP_DVBT_DEFAULT    1
    #define Si2141_DTV_INTERNAL_ZIF_PROP_DVBT_LIF  0
    #define Si2141_DTV_INTERNAL_ZIF_PROP_DVBT_ZIF  1

   /* DTV_INTERNAL_ZIF property, ISDBC field definition (NO TITLE)*/
   #define  Si2141_DTV_INTERNAL_ZIF_PROP_ISDBC_LSB         5
   #define  Si2141_DTV_INTERNAL_ZIF_PROP_ISDBC_MASK        0x01
   #define  Si2141_DTV_INTERNAL_ZIF_PROP_ISDBC_DEFAULT    1
    #define Si2141_DTV_INTERNAL_ZIF_PROP_ISDBC_LIF  0
    #define Si2141_DTV_INTERNAL_ZIF_PROP_ISDBC_ZIF  1

   /* DTV_INTERNAL_ZIF property, ISDBT field definition (NO TITLE)*/
   #define  Si2141_DTV_INTERNAL_ZIF_PROP_ISDBT_LSB         4
   #define  Si2141_DTV_INTERNAL_ZIF_PROP_ISDBT_MASK        0x01
   #define  Si2141_DTV_INTERNAL_ZIF_PROP_ISDBT_DEFAULT    1
    #define Si2141_DTV_INTERNAL_ZIF_PROP_ISDBT_LIF  0
    #define Si2141_DTV_INTERNAL_ZIF_PROP_ISDBT_ZIF  1

   /* DTV_INTERNAL_ZIF property, QAM_US field definition (NO TITLE)*/
   #define  Si2141_DTV_INTERNAL_ZIF_PROP_QAM_US_LSB         1
   #define  Si2141_DTV_INTERNAL_ZIF_PROP_QAM_US_MASK        0x01
   #define  Si2141_DTV_INTERNAL_ZIF_PROP_QAM_US_DEFAULT    1
    #define Si2141_DTV_INTERNAL_ZIF_PROP_QAM_US_LIF  0
    #define Si2141_DTV_INTERNAL_ZIF_PROP_QAM_US_ZIF  1

#endif /* Si2141_DTV_INTERNAL_ZIF_PROP */

/* Si2141 DTV_LIF_FREQ property definition */
#define   Si2141_DTV_LIF_FREQ_PROP 0x0706

#ifdef    Si2141_DTV_LIF_FREQ_PROP
  #define Si2141_DTV_LIF_FREQ_PROP_CODE 0x000706


    typedef struct { /* Si2141_DTV_LIF_FREQ_PROP_struct */
      unsigned int    offset;
   } Si2141_DTV_LIF_FREQ_PROP_struct;

   /* DTV_LIF_FREQ property, OFFSET field definition (NO TITLE)*/
   #define  Si2141_DTV_LIF_FREQ_PROP_OFFSET_LSB         0
   #define  Si2141_DTV_LIF_FREQ_PROP_OFFSET_MASK        0xffff
   #define  Si2141_DTV_LIF_FREQ_PROP_OFFSET_DEFAULT    5000
    #define Si2141_DTV_LIF_FREQ_PROP_OFFSET_OFFSET_MIN  0
    #define Si2141_DTV_LIF_FREQ_PROP_OFFSET_OFFSET_MAX  7000

#endif /* Si2141_DTV_LIF_FREQ_PROP */

/* Si2141 DTV_LIF_OUT property definition */
#define   Si2141_DTV_LIF_OUT_PROP 0x0707

#ifdef    Si2141_DTV_LIF_OUT_PROP
  #define Si2141_DTV_LIF_OUT_PROP_CODE 0x000707


    typedef struct { /* Si2141_DTV_LIF_OUT_PROP_struct */
      unsigned char   amp;
      unsigned char   offset;
   } Si2141_DTV_LIF_OUT_PROP_struct;

   /* DTV_LIF_OUT property, AMP field definition (NO TITLE)*/
   #define  Si2141_DTV_LIF_OUT_PROP_AMP_LSB         8
   #define  Si2141_DTV_LIF_OUT_PROP_AMP_MASK        0xff
   #define  Si2141_DTV_LIF_OUT_PROP_AMP_DEFAULT    27
    #define Si2141_DTV_LIF_OUT_PROP_AMP_AMP_MIN  0
    #define Si2141_DTV_LIF_OUT_PROP_AMP_AMP_MAX  255

   /* DTV_LIF_OUT property, OFFSET field definition (NO TITLE)*/
   #define  Si2141_DTV_LIF_OUT_PROP_OFFSET_LSB         0
   #define  Si2141_DTV_LIF_OUT_PROP_OFFSET_MASK        0xff
   #define  Si2141_DTV_LIF_OUT_PROP_OFFSET_DEFAULT    148
    #define Si2141_DTV_LIF_OUT_PROP_OFFSET_OFFSET_MIN  0
    #define Si2141_DTV_LIF_OUT_PROP_OFFSET_OFFSET_MAX  255

#endif /* Si2141_DTV_LIF_OUT_PROP */

/* Si2141 DTV_MODE property definition */
#define   Si2141_DTV_MODE_PROP 0x0703

#ifdef    Si2141_DTV_MODE_PROP
  #define Si2141_DTV_MODE_PROP_CODE 0x000703


    typedef struct { /* Si2141_DTV_MODE_PROP_struct */
      unsigned char   bw;
      unsigned char   invert_spectrum;
      unsigned char   modulation;
   } Si2141_DTV_MODE_PROP_struct;

   /* DTV_MODE property, BW field definition (NO TITLE)*/
   #define  Si2141_DTV_MODE_PROP_BW_LSB         0
   #define  Si2141_DTV_MODE_PROP_BW_MASK        0x0f
   #define  Si2141_DTV_MODE_PROP_BW_DEFAULT    8
    #define Si2141_DTV_MODE_PROP_BW_BW_6MHZ    6
    #define Si2141_DTV_MODE_PROP_BW_BW_7MHZ    7
    #define Si2141_DTV_MODE_PROP_BW_BW_8MHZ    8
    #define Si2141_DTV_MODE_PROP_BW_BW_1P7MHZ  9
    #define Si2141_DTV_MODE_PROP_BW_BW_6P1MHZ  10

   /* DTV_MODE property, INVERT_SPECTRUM field definition (NO TITLE)*/
   #define  Si2141_DTV_MODE_PROP_INVERT_SPECTRUM_LSB         8
   #define  Si2141_DTV_MODE_PROP_INVERT_SPECTRUM_MASK        0x01
   #define  Si2141_DTV_MODE_PROP_INVERT_SPECTRUM_DEFAULT    0
    #define Si2141_DTV_MODE_PROP_INVERT_SPECTRUM_NORMAL    0
    #define Si2141_DTV_MODE_PROP_INVERT_SPECTRUM_INVERTED  1

   /* DTV_MODE property, MODULATION field definition (NO TITLE)*/
   #define  Si2141_DTV_MODE_PROP_MODULATION_LSB         4
   #define  Si2141_DTV_MODE_PROP_MODULATION_MASK        0x0f
   #define  Si2141_DTV_MODE_PROP_MODULATION_DEFAULT    2
    #define Si2141_DTV_MODE_PROP_MODULATION_ATSC       0
    #define Si2141_DTV_MODE_PROP_MODULATION_QAM_US     1
    #define Si2141_DTV_MODE_PROP_MODULATION_DVBT       2
    #define Si2141_DTV_MODE_PROP_MODULATION_DVBC       3
    #define Si2141_DTV_MODE_PROP_MODULATION_ISDBT      4
    #define Si2141_DTV_MODE_PROP_MODULATION_ISDBC      5
    #define Si2141_DTV_MODE_PROP_MODULATION_DTMB       6

#endif /* Si2141_DTV_MODE_PROP */

/* Si2141 DTV_PGA_LIMITS property definition */
#define   Si2141_DTV_PGA_LIMITS_PROP 0x0713

#ifdef    Si2141_DTV_PGA_LIMITS_PROP
  #define Si2141_DTV_PGA_LIMITS_PROP_CODE 0x000713


    typedef struct { /* Si2141_DTV_PGA_LIMITS_PROP_struct */
               char   max;
               char   min;
   } Si2141_DTV_PGA_LIMITS_PROP_struct;

   /* DTV_PGA_LIMITS property, MAX field definition (NO TITLE)*/
   #define  Si2141_DTV_PGA_LIMITS_PROP_MAX_LSB         8
   #define  Si2141_DTV_PGA_LIMITS_PROP_MAX_MASK        0xff
   #define  Si2141_DTV_PGA_LIMITS_PROP_MAX_DEFAULT    -1
    #define Si2141_DTV_PGA_LIMITS_PROP_MAX_MAX_MIN  -1
    #define Si2141_DTV_PGA_LIMITS_PROP_MAX_MAX_MAX  56

   /* DTV_PGA_LIMITS property, MIN field definition (NO TITLE)*/
   #define  Si2141_DTV_PGA_LIMITS_PROP_MIN_LSB         0
   #define  Si2141_DTV_PGA_LIMITS_PROP_MIN_MASK        0xff
   #define  Si2141_DTV_PGA_LIMITS_PROP_MIN_DEFAULT    -1
    #define Si2141_DTV_PGA_LIMITS_PROP_MIN_MIN_MIN  -1
    #define Si2141_DTV_PGA_LIMITS_PROP_MIN_MIN_MAX  56

#endif /* Si2141_DTV_PGA_LIMITS_PROP */

/* Si2141 DTV_PGA_TARGET property definition */
#define   Si2141_DTV_PGA_TARGET_PROP 0x070f

#ifdef    Si2141_DTV_PGA_TARGET_PROP
  #define Si2141_DTV_PGA_TARGET_PROP_CODE 0x00070f


    typedef struct { /* Si2141_DTV_PGA_TARGET_PROP_struct */
      unsigned char   override_enable;
               char   pga_target;
   } Si2141_DTV_PGA_TARGET_PROP_struct;

   /* DTV_PGA_TARGET property, OVERRIDE_ENABLE field definition (NO TITLE)*/
   #define  Si2141_DTV_PGA_TARGET_PROP_OVERRIDE_ENABLE_LSB         8
   #define  Si2141_DTV_PGA_TARGET_PROP_OVERRIDE_ENABLE_MASK        0x01
   #define  Si2141_DTV_PGA_TARGET_PROP_OVERRIDE_ENABLE_DEFAULT    0
    #define Si2141_DTV_PGA_TARGET_PROP_OVERRIDE_ENABLE_DISABLE  0
    #define Si2141_DTV_PGA_TARGET_PROP_OVERRIDE_ENABLE_ENABLE   1

   /* DTV_PGA_TARGET property, PGA_TARGET field definition (NO TITLE)*/
   #define  Si2141_DTV_PGA_TARGET_PROP_PGA_TARGET_LSB         0
   #define  Si2141_DTV_PGA_TARGET_PROP_PGA_TARGET_MASK        0xff
   #define  Si2141_DTV_PGA_TARGET_PROP_PGA_TARGET_DEFAULT    0
    #define Si2141_DTV_PGA_TARGET_PROP_PGA_TARGET_PGA_TARGET_MIN  -13
    #define Si2141_DTV_PGA_TARGET_PROP_PGA_TARGET_PGA_TARGET_MAX  7

#endif /* Si2141_DTV_PGA_TARGET_PROP */

/* Si2141 DTV_RF_AGC_SPEED property definition */
#define   Si2141_DTV_RF_AGC_SPEED_PROP 0x0715

#ifdef    Si2141_DTV_RF_AGC_SPEED_PROP
  #define Si2141_DTV_RF_AGC_SPEED_PROP_CODE 0x000715


    typedef struct { /* Si2141_DTV_RF_AGC_SPEED_PROP_struct */
      unsigned char   attack;
      unsigned char   decay;
   } Si2141_DTV_RF_AGC_SPEED_PROP_struct;

   /* DTV_RF_AGC_SPEED property, ATTACK field definition (NO TITLE)*/
   #define  Si2141_DTV_RF_AGC_SPEED_PROP_ATTACK_LSB         0
   #define  Si2141_DTV_RF_AGC_SPEED_PROP_ATTACK_MASK        0xff
   #define  Si2141_DTV_RF_AGC_SPEED_PROP_ATTACK_DEFAULT    0
    #define Si2141_DTV_RF_AGC_SPEED_PROP_ATTACK_AUTO  0

    #define Si2141_DTV_RF_AGC_SPEED_PROP_ATTACK_ATTACK_MIN  0
    #define Si2141_DTV_RF_AGC_SPEED_PROP_ATTACK_ATTACK_MAX  231

   /* DTV_RF_AGC_SPEED property, DECAY field definition (NO TITLE)*/
   #define  Si2141_DTV_RF_AGC_SPEED_PROP_DECAY_LSB         8
   #define  Si2141_DTV_RF_AGC_SPEED_PROP_DECAY_MASK        0xff
   #define  Si2141_DTV_RF_AGC_SPEED_PROP_DECAY_DEFAULT    0
    #define Si2141_DTV_RF_AGC_SPEED_PROP_DECAY_AUTO  0

    #define Si2141_DTV_RF_AGC_SPEED_PROP_DECAY_DECAY_MIN  0
    #define Si2141_DTV_RF_AGC_SPEED_PROP_DECAY_DECAY_MAX  231

#endif /* Si2141_DTV_RF_AGC_SPEED_PROP */

/* Si2141 DTV_RF_TOP property definition */
#define   Si2141_DTV_RF_TOP_PROP 0x0709

#ifdef    Si2141_DTV_RF_TOP_PROP
  #define Si2141_DTV_RF_TOP_PROP_CODE 0x000709


    typedef struct { /* Si2141_DTV_RF_TOP_PROP_struct */
      unsigned char   dtv_rf_top;
   } Si2141_DTV_RF_TOP_PROP_struct;

   /* DTV_RF_TOP property, DTV_RF_TOP field definition (NO TITLE)*/
   #define  Si2141_DTV_RF_TOP_PROP_DTV_RF_TOP_LSB         0
   #define  Si2141_DTV_RF_TOP_PROP_DTV_RF_TOP_MASK        0xff
   #define  Si2141_DTV_RF_TOP_PROP_DTV_RF_TOP_DEFAULT    0
    #define Si2141_DTV_RF_TOP_PROP_DTV_RF_TOP_AUTO     0
    #define Si2141_DTV_RF_TOP_PROP_DTV_RF_TOP_P6DB     9
    #define Si2141_DTV_RF_TOP_PROP_DTV_RF_TOP_P5P5DB   10
    #define Si2141_DTV_RF_TOP_PROP_DTV_RF_TOP_P5DB     11
    #define Si2141_DTV_RF_TOP_PROP_DTV_RF_TOP_P4P5DB   12
    #define Si2141_DTV_RF_TOP_PROP_DTV_RF_TOP_P4DB     13
    #define Si2141_DTV_RF_TOP_PROP_DTV_RF_TOP_P3P5DB   14
    #define Si2141_DTV_RF_TOP_PROP_DTV_RF_TOP_P3DB     15
    #define Si2141_DTV_RF_TOP_PROP_DTV_RF_TOP_P2P5DB   16
    #define Si2141_DTV_RF_TOP_PROP_DTV_RF_TOP_P2DB     17
    #define Si2141_DTV_RF_TOP_PROP_DTV_RF_TOP_P1P5DB   18
    #define Si2141_DTV_RF_TOP_PROP_DTV_RF_TOP_P1DB     19
    #define Si2141_DTV_RF_TOP_PROP_DTV_RF_TOP_P0P5DB   20
    #define Si2141_DTV_RF_TOP_PROP_DTV_RF_TOP_0DB      21
    #define Si2141_DTV_RF_TOP_PROP_DTV_RF_TOP_M0P5DB   22
    #define Si2141_DTV_RF_TOP_PROP_DTV_RF_TOP_M1DB     23
    #define Si2141_DTV_RF_TOP_PROP_DTV_RF_TOP_M1P5DB   24
    #define Si2141_DTV_RF_TOP_PROP_DTV_RF_TOP_M2DB     25
    #define Si2141_DTV_RF_TOP_PROP_DTV_RF_TOP_M2P5DB   26
    #define Si2141_DTV_RF_TOP_PROP_DTV_RF_TOP_M3DB     27
    #define Si2141_DTV_RF_TOP_PROP_DTV_RF_TOP_M3P5DB   28
    #define Si2141_DTV_RF_TOP_PROP_DTV_RF_TOP_M4DB     29
    #define Si2141_DTV_RF_TOP_PROP_DTV_RF_TOP_M4P5DB   30
    #define Si2141_DTV_RF_TOP_PROP_DTV_RF_TOP_M5DB     31
    #define Si2141_DTV_RF_TOP_PROP_DTV_RF_TOP_M5P5DB   32
    #define Si2141_DTV_RF_TOP_PROP_DTV_RF_TOP_M6DB     33
    #define Si2141_DTV_RF_TOP_PROP_DTV_RF_TOP_M6P5DB   34
    #define Si2141_DTV_RF_TOP_PROP_DTV_RF_TOP_M7DB     35
    #define Si2141_DTV_RF_TOP_PROP_DTV_RF_TOP_M7P5DB   36
    #define Si2141_DTV_RF_TOP_PROP_DTV_RF_TOP_M8DB     37
    #define Si2141_DTV_RF_TOP_PROP_DTV_RF_TOP_M8P5DB   38
    #define Si2141_DTV_RF_TOP_PROP_DTV_RF_TOP_M9DB     39
    #define Si2141_DTV_RF_TOP_PROP_DTV_RF_TOP_M9P5DB   40
    #define Si2141_DTV_RF_TOP_PROP_DTV_RF_TOP_M10DB    41
    #define Si2141_DTV_RF_TOP_PROP_DTV_RF_TOP_M10P5DB  42
    #define Si2141_DTV_RF_TOP_PROP_DTV_RF_TOP_M11DB    43

#endif /* Si2141_DTV_RF_TOP_PROP */

/* Si2141 DTV_RSQ_RSSI_THRESHOLD property definition */
#define   Si2141_DTV_RSQ_RSSI_THRESHOLD_PROP 0x0704

#ifdef    Si2141_DTV_RSQ_RSSI_THRESHOLD_PROP
  #define Si2141_DTV_RSQ_RSSI_THRESHOLD_PROP_CODE 0x000704


    typedef struct { /* Si2141_DTV_RSQ_RSSI_THRESHOLD_PROP_struct */
               char   lo;
   } Si2141_DTV_RSQ_RSSI_THRESHOLD_PROP_struct;

   /* DTV_RSQ_RSSI_THRESHOLD property, LO field definition (NO TITLE)*/
   #define  Si2141_DTV_RSQ_RSSI_THRESHOLD_PROP_LO_LSB         0
   #define  Si2141_DTV_RSQ_RSSI_THRESHOLD_PROP_LO_MASK        0xff
   #define  Si2141_DTV_RSQ_RSSI_THRESHOLD_PROP_LO_DEFAULT    -80
    #define Si2141_DTV_RSQ_RSSI_THRESHOLD_PROP_LO_LO_MIN  -128
    #define Si2141_DTV_RSQ_RSSI_THRESHOLD_PROP_LO_LO_MAX  127

#endif /* Si2141_DTV_RSQ_RSSI_THRESHOLD_PROP */

/* Si2141 DTV_WB_AGC_SPEED property definition */
#define   Si2141_DTV_WB_AGC_SPEED_PROP 0x0717

#ifdef    Si2141_DTV_WB_AGC_SPEED_PROP
  #define Si2141_DTV_WB_AGC_SPEED_PROP_CODE 0x000717


    typedef struct { /* Si2141_DTV_WB_AGC_SPEED_PROP_struct */
      unsigned char   attack;
      unsigned char   decay;
   } Si2141_DTV_WB_AGC_SPEED_PROP_struct;

   /* DTV_WB_AGC_SPEED property, ATTACK field definition (NO TITLE)*/
   #define  Si2141_DTV_WB_AGC_SPEED_PROP_ATTACK_LSB         0
   #define  Si2141_DTV_WB_AGC_SPEED_PROP_ATTACK_MASK        0xff
   #define  Si2141_DTV_WB_AGC_SPEED_PROP_ATTACK_DEFAULT    0
    #define Si2141_DTV_WB_AGC_SPEED_PROP_ATTACK_AUTO  0

    #define Si2141_DTV_WB_AGC_SPEED_PROP_ATTACK_ATTACK_MIN  0
    #define Si2141_DTV_WB_AGC_SPEED_PROP_ATTACK_ATTACK_MAX  231

   /* DTV_WB_AGC_SPEED property, DECAY field definition (NO TITLE)*/
   #define  Si2141_DTV_WB_AGC_SPEED_PROP_DECAY_LSB         8
   #define  Si2141_DTV_WB_AGC_SPEED_PROP_DECAY_MASK        0xff
   #define  Si2141_DTV_WB_AGC_SPEED_PROP_DECAY_DEFAULT    0
    #define Si2141_DTV_WB_AGC_SPEED_PROP_DECAY_AUTO  0

    #define Si2141_DTV_WB_AGC_SPEED_PROP_DECAY_DECAY_MIN  0
    #define Si2141_DTV_WB_AGC_SPEED_PROP_DECAY_DECAY_MAX  231

#endif /* Si2141_DTV_WB_AGC_SPEED_PROP */

/* Si2141 TUNER_BLOCKED_VCO property definition */
#define   Si2141_TUNER_BLOCKED_VCO_PROP 0x0504

#ifdef    Si2141_TUNER_BLOCKED_VCO_PROP
  #define Si2141_TUNER_BLOCKED_VCO_PROP_CODE 0x000504


    typedef struct { /* Si2141_TUNER_BLOCKED_VCO_PROP_struct */
               int    vco_code;
   } Si2141_TUNER_BLOCKED_VCO_PROP_struct;

   /* TUNER_BLOCKED_VCO property, VCO_CODE field definition (NO TITLE)*/
   #define  Si2141_TUNER_BLOCKED_VCO_PROP_VCO_CODE_LSB         0
   #define  Si2141_TUNER_BLOCKED_VCO_PROP_VCO_CODE_MASK        0xffff
   #define  Si2141_TUNER_BLOCKED_VCO_PROP_VCO_CODE_DEFAULT    0x8000
    #define Si2141_TUNER_BLOCKED_VCO_PROP_VCO_CODE_VCO_CODE_MIN  -32768
    #define Si2141_TUNER_BLOCKED_VCO_PROP_VCO_CODE_VCO_CODE_MAX  32767

#endif /* Si2141_TUNER_BLOCKED_VCO_PROP */

/* Si2141 TUNER_BLOCKED_VCO2 property definition */
#define   Si2141_TUNER_BLOCKED_VCO2_PROP 0x0508

#ifdef    Si2141_TUNER_BLOCKED_VCO2_PROP
  #define Si2141_TUNER_BLOCKED_VCO2_PROP_CODE 0x000508


    typedef struct { /* Si2141_TUNER_BLOCKED_VCO2_PROP_struct */
               int    vco_code;
   } Si2141_TUNER_BLOCKED_VCO2_PROP_struct;

   /* TUNER_BLOCKED_VCO2 property, VCO_CODE field definition (NO TITLE)*/
   #define  Si2141_TUNER_BLOCKED_VCO2_PROP_VCO_CODE_LSB         0
   #define  Si2141_TUNER_BLOCKED_VCO2_PROP_VCO_CODE_MASK        0xffff
   #define  Si2141_TUNER_BLOCKED_VCO2_PROP_VCO_CODE_DEFAULT    0x8000
    #define Si2141_TUNER_BLOCKED_VCO2_PROP_VCO_CODE_VCO_CODE_MIN  -32768
    #define Si2141_TUNER_BLOCKED_VCO2_PROP_VCO_CODE_VCO_CODE_MAX  32767

#endif /* Si2141_TUNER_BLOCKED_VCO2_PROP */

/* Si2141 TUNER_BLOCKED_VCO3 property definition */
#define   Si2141_TUNER_BLOCKED_VCO3_PROP 0x0509

#ifdef    Si2141_TUNER_BLOCKED_VCO3_PROP
  #define Si2141_TUNER_BLOCKED_VCO3_PROP_CODE 0x000509


    typedef struct { /* Si2141_TUNER_BLOCKED_VCO3_PROP_struct */
               int    vco_code;
   } Si2141_TUNER_BLOCKED_VCO3_PROP_struct;

   /* TUNER_BLOCKED_VCO3 property, VCO_CODE field definition (NO TITLE)*/
   #define  Si2141_TUNER_BLOCKED_VCO3_PROP_VCO_CODE_LSB         0
   #define  Si2141_TUNER_BLOCKED_VCO3_PROP_VCO_CODE_MASK        0xffff
   #define  Si2141_TUNER_BLOCKED_VCO3_PROP_VCO_CODE_DEFAULT    0x8000
    #define Si2141_TUNER_BLOCKED_VCO3_PROP_VCO_CODE_VCO_CODE_MIN  -32768
    #define Si2141_TUNER_BLOCKED_VCO3_PROP_VCO_CODE_VCO_CODE_MAX  32767

#endif /* Si2141_TUNER_BLOCKED_VCO3_PROP */

/* Si2141 TUNER_LO_INJECTION property definition */
#define   Si2141_TUNER_LO_INJECTION_PROP 0x0506

#ifdef    Si2141_TUNER_LO_INJECTION_PROP
  #define Si2141_TUNER_LO_INJECTION_PROP_CODE 0x000506


    typedef struct { /* Si2141_TUNER_LO_INJECTION_PROP_struct */
      unsigned char   band_1;
      unsigned char   band_2;
      unsigned char   band_3;
   } Si2141_TUNER_LO_INJECTION_PROP_struct;

   /* TUNER_LO_INJECTION property, BAND_1 field definition (NO TITLE)*/
   #define  Si2141_TUNER_LO_INJECTION_PROP_BAND_1_LSB         0
   #define  Si2141_TUNER_LO_INJECTION_PROP_BAND_1_MASK        0x01
   #define  Si2141_TUNER_LO_INJECTION_PROP_BAND_1_DEFAULT    1
    #define Si2141_TUNER_LO_INJECTION_PROP_BAND_1_LOW_SIDE   0
    #define Si2141_TUNER_LO_INJECTION_PROP_BAND_1_HIGH_SIDE  1

   /* TUNER_LO_INJECTION property, BAND_2 field definition (NO TITLE)*/
   #define  Si2141_TUNER_LO_INJECTION_PROP_BAND_2_LSB         1
   #define  Si2141_TUNER_LO_INJECTION_PROP_BAND_2_MASK        0x01
   #define  Si2141_TUNER_LO_INJECTION_PROP_BAND_2_DEFAULT    0
    #define Si2141_TUNER_LO_INJECTION_PROP_BAND_2_LOW_SIDE   0
    #define Si2141_TUNER_LO_INJECTION_PROP_BAND_2_HIGH_SIDE  1

   /* TUNER_LO_INJECTION property, BAND_3 field definition (NO TITLE)*/
   #define  Si2141_TUNER_LO_INJECTION_PROP_BAND_3_LSB         2
   #define  Si2141_TUNER_LO_INJECTION_PROP_BAND_3_MASK        0x01
   #define  Si2141_TUNER_LO_INJECTION_PROP_BAND_3_DEFAULT    0
    #define Si2141_TUNER_LO_INJECTION_PROP_BAND_3_LOW_SIDE   0
    #define Si2141_TUNER_LO_INJECTION_PROP_BAND_3_HIGH_SIDE  1

#endif /* Si2141_TUNER_LO_INJECTION_PROP */

/* Si2141 TUNER_RETURN_LOSS property definition */
#define   Si2141_TUNER_RETURN_LOSS_PROP 0x0507

#ifdef    Si2141_TUNER_RETURN_LOSS_PROP
  #define Si2141_TUNER_RETURN_LOSS_PROP_CODE 0x000507


    typedef struct { /* Si2141_TUNER_RETURN_LOSS_PROP_struct */
      unsigned char   config;
      unsigned char   mode;
      unsigned char   reserved;
   } Si2141_TUNER_RETURN_LOSS_PROP_struct;

   /* TUNER_RETURN_LOSS property, CONFIG field definition (NO TITLE)*/
   #define  Si2141_TUNER_RETURN_LOSS_PROP_CONFIG_LSB         0
   #define  Si2141_TUNER_RETURN_LOSS_PROP_CONFIG_MASK        0xff
   #define  Si2141_TUNER_RETURN_LOSS_PROP_CONFIG_DEFAULT    127
    #define Si2141_TUNER_RETURN_LOSS_PROP_CONFIG_75   75
    #define Si2141_TUNER_RETURN_LOSS_PROP_CONFIG_83   83
    #define Si2141_TUNER_RETURN_LOSS_PROP_CONFIG_91   91
    #define Si2141_TUNER_RETURN_LOSS_PROP_CONFIG_103  103
    #define Si2141_TUNER_RETURN_LOSS_PROP_CONFIG_115  115
    #define Si2141_TUNER_RETURN_LOSS_PROP_CONFIG_127  127

   /* TUNER_RETURN_LOSS property, MODE field definition (NO TITLE)*/
   #define  Si2141_TUNER_RETURN_LOSS_PROP_MODE_LSB         8
   #define  Si2141_TUNER_RETURN_LOSS_PROP_MODE_MASK        0x01
   #define  Si2141_TUNER_RETURN_LOSS_PROP_MODE_DEFAULT    0
    #define Si2141_TUNER_RETURN_LOSS_PROP_MODE_TERRESTRIAL  0
    #define Si2141_TUNER_RETURN_LOSS_PROP_MODE_CABLE        1

   /* TUNER_RETURN_LOSS property, RESERVED field definition (NO TITLE)*/
   #define  Si2141_TUNER_RETURN_LOSS_PROP_RESERVED_LSB         9
   #define  Si2141_TUNER_RETURN_LOSS_PROP_RESERVED_MASK        0x7f
   #define  Si2141_TUNER_RETURN_LOSS_PROP_RESERVED_DEFAULT    74
    #define Si2141_TUNER_RETURN_LOSS_PROP_RESERVED_RESERVED  74

#endif /* Si2141_TUNER_RETURN_LOSS_PROP */

/* Si2141 XOUT property definition */
#define   Si2141_XOUT_PROP 0x0404

#ifdef    Si2141_XOUT_PROP
  #define Si2141_XOUT_PROP_CODE 0x000404


    typedef struct { /* Si2141_XOUT_PROP_struct */
      unsigned char   amp;
   } Si2141_XOUT_PROP_struct;

   /* XOUT property, AMP field definition (NO TITLE)*/
   #define  Si2141_XOUT_PROP_AMP_LSB         0
   #define  Si2141_XOUT_PROP_AMP_MASK        0x01
   #define  Si2141_XOUT_PROP_AMP_DEFAULT    0
    #define Si2141_XOUT_PROP_AMP_HIGH  0
    #define Si2141_XOUT_PROP_AMP_LOW   1

#endif /* Si2141_XOUT_PROP */



  /* --------------------------------------------*/
  /* PROPERTIES STRUCT                           */
  /* This stores all property fields             */
  /* --------------------------------------------*/
  typedef struct {
    #ifdef    Si2141_CRYSTAL_TRIM_PROP
              Si2141_CRYSTAL_TRIM_PROP_struct                  crystal_trim;
    #endif /* Si2141_CRYSTAL_TRIM_PROP */
    #ifdef    Si2141_DTV_AGC_AUTO_FREEZE_PROP
              Si2141_DTV_AGC_AUTO_FREEZE_PROP_struct           dtv_agc_auto_freeze;
    #endif /* Si2141_DTV_AGC_AUTO_FREEZE_PROP */
    #ifdef    Si2141_DTV_AGC_SPEED_PROP
              Si2141_DTV_AGC_SPEED_PROP_struct                 dtv_agc_speed;
    #endif /* Si2141_DTV_AGC_SPEED_PROP */
    #ifdef    Si2141_DTV_CONFIG_IF_PORT_PROP
              Si2141_DTV_CONFIG_IF_PORT_PROP_struct            dtv_config_if_port;
    #endif /* Si2141_DTV_CONFIG_IF_PORT_PROP */
    #ifdef    Si2141_DTV_EXT_AGC_PROP
              Si2141_DTV_EXT_AGC_PROP_struct                   dtv_ext_agc;
    #endif /* Si2141_DTV_EXT_AGC_PROP */
    #ifdef    Si2141_DTV_IF_AGC_SPEED_PROP
              Si2141_DTV_IF_AGC_SPEED_PROP_struct              dtv_if_agc_speed;
    #endif /* Si2141_DTV_IF_AGC_SPEED_PROP */
    #ifdef    Si2141_DTV_INITIAL_AGC_SPEED_PROP
              Si2141_DTV_INITIAL_AGC_SPEED_PROP_struct         dtv_initial_agc_speed;
    #endif /* Si2141_DTV_INITIAL_AGC_SPEED_PROP */
    #ifdef    Si2141_DTV_INITIAL_AGC_SPEED_PERIOD_PROP
              Si2141_DTV_INITIAL_AGC_SPEED_PERIOD_PROP_struct  dtv_initial_agc_speed_period;
    #endif /* Si2141_DTV_INITIAL_AGC_SPEED_PERIOD_PROP */
    #ifdef    Si2141_DTV_INTERNAL_ZIF_PROP
              Si2141_DTV_INTERNAL_ZIF_PROP_struct              dtv_internal_zif;
    #endif /* Si2141_DTV_INTERNAL_ZIF_PROP */
    #ifdef    Si2141_DTV_LIF_FREQ_PROP
              Si2141_DTV_LIF_FREQ_PROP_struct                  dtv_lif_freq;
    #endif /* Si2141_DTV_LIF_FREQ_PROP */
    #ifdef    Si2141_DTV_LIF_OUT_PROP
              Si2141_DTV_LIF_OUT_PROP_struct                   dtv_lif_out;
    #endif /* Si2141_DTV_LIF_OUT_PROP */
    #ifdef    Si2141_DTV_MODE_PROP
              Si2141_DTV_MODE_PROP_struct                      dtv_mode;
    #endif /* Si2141_DTV_MODE_PROP */
    #ifdef    Si2141_DTV_PGA_LIMITS_PROP
              Si2141_DTV_PGA_LIMITS_PROP_struct                dtv_pga_limits;
    #endif /* Si2141_DTV_PGA_LIMITS_PROP */
    #ifdef    Si2141_DTV_PGA_TARGET_PROP
              Si2141_DTV_PGA_TARGET_PROP_struct                dtv_pga_target;
    #endif /* Si2141_DTV_PGA_TARGET_PROP */
    #ifdef    Si2141_DTV_RF_AGC_SPEED_PROP
              Si2141_DTV_RF_AGC_SPEED_PROP_struct              dtv_rf_agc_speed;
    #endif /* Si2141_DTV_RF_AGC_SPEED_PROP */
    #ifdef    Si2141_DTV_RF_TOP_PROP
              Si2141_DTV_RF_TOP_PROP_struct                    dtv_rf_top;
    #endif /* Si2141_DTV_RF_TOP_PROP */
    #ifdef    Si2141_DTV_RSQ_RSSI_THRESHOLD_PROP
              Si2141_DTV_RSQ_RSSI_THRESHOLD_PROP_struct        dtv_rsq_rssi_threshold;
    #endif /* Si2141_DTV_RSQ_RSSI_THRESHOLD_PROP */
    #ifdef    Si2141_DTV_WB_AGC_SPEED_PROP
              Si2141_DTV_WB_AGC_SPEED_PROP_struct              dtv_wb_agc_speed;
    #endif /* Si2141_DTV_WB_AGC_SPEED_PROP */
    #ifdef    Si2141_TUNER_BLOCKED_VCO_PROP
              Si2141_TUNER_BLOCKED_VCO_PROP_struct             tuner_blocked_vco;
    #endif /* Si2141_TUNER_BLOCKED_VCO_PROP */
    #ifdef    Si2141_TUNER_BLOCKED_VCO2_PROP
              Si2141_TUNER_BLOCKED_VCO2_PROP_struct            tuner_blocked_vco2;
    #endif /* Si2141_TUNER_BLOCKED_VCO2_PROP */
    #ifdef    Si2141_TUNER_BLOCKED_VCO3_PROP
              Si2141_TUNER_BLOCKED_VCO3_PROP_struct            tuner_blocked_vco3;
    #endif /* Si2141_TUNER_BLOCKED_VCO3_PROP */
    #ifdef    Si2141_TUNER_LO_INJECTION_PROP
              Si2141_TUNER_LO_INJECTION_PROP_struct            tuner_lo_injection;
    #endif /* Si2141_TUNER_LO_INJECTION_PROP */
    #ifdef    Si2141_TUNER_RETURN_LOSS_PROP
              Si2141_TUNER_RETURN_LOSS_PROP_struct             tuner_return_loss;
    #endif /* Si2141_TUNER_RETURN_LOSS_PROP */
    #ifdef    Si2141_XOUT_PROP
              Si2141_XOUT_PROP_struct                          xout;
    #endif /* Si2141_XOUT_PROP */
  } Si2141_PropObj;

/* #define   Si2141_GET_PROPERTY_STRING */

#endif /* _Si2141_PROPERTIES_H_ */







