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
                  Skyworks Solutions Broadcast Si2144 Layer 1 API


   API types used by commands and properties
   FILE: Si2144_typedefs.h
   Supported IC : Si2144
   Compiled for ROM 62 firmware 2_1_build_5
   Revision: 0.1
   Date: July 07 2017
**************************************************************************************/
#ifndef   Si2144_TYPEDEFS_H
#define   Si2144_TYPEDEFS_H

 #define BUF_SIZE 1000
/* define the maximum possible channels (1002MHz - 43MHz) / 6MHz  (required for the channelscan array)*/
#define MAX_POSSIBLE_CHANNELS 160
/* _additional_defines_point */
#define MAX_LENGTH         80

#define DOWNLOAD_ON_CHANGE 1
#define DOWNLOAD_ALWAYS    0

/* The following defines are to allow use of PowerUpWithPatch function with the powerUpUsingBroadcastI2C function. */
#define SKIP_NONE 0x00
#define SKIP_POWERUP 0x01
#define SKIP_LOADFIRMWARE 0x02
#define SKIP_STARTFIRMWARE 0x04
/* define the tuner broadcast address for common patch download. */
#define Si2144_BROADCAST_ADDRESS 0xc4

typedef struct L1_Si2144_Context {
  L0_Context                 *i2c;
  L0_Context                  i2cObj;
  Si2144_CmdObj              *cmd;
  Si2144_CmdObj               cmdObj;
  Si2144_CmdReplyObj         *rsp;
  Si2144_CmdReplyObj          rspObj;
  Si2144_PropObj             *prop;
  Si2144_PropObj              propObj;
  Si2144_PropObj             *propShadow;
  Si2144_PropObj              propShadowObj;
  Si2144_COMMON_REPLY_struct *status;
  Si2144_COMMON_REPLY_struct  statusObj;
  /* global variable for property settings mode
     Possible values:
         Si2144_DOWNLOAD_ON_CHANGE (recommended)
      or Si2144_DOWNLOAD_ALWAYS.                 */
  signed   int propertyWriteMode;
  /* allows reuse of PowerUpWithPatch function by PowerUpUsingBroadcastI2C function */
  signed   char load_control;
 /* Channel Scan Globals */
  /* Global array to store the list of found channels */
  unsigned long ChannelList[MAX_POSSIBLE_CHANNELS];
  /* ChannelScanPal needs to store the PAL type also so allocate 4 chars each for that */
  signed   char ChannelType[MAX_POSSIBLE_CHANNELS][4];
  /* Number of found channels from a channel scan */
  signed   int ChannelListSize;

  /* _additional_struct_members_point */
} L1_Si2144_Context;

/* _additional_definitions_start */
#ifndef __VID_FILT_STRUCT__
#define __VID_FILT_STRUCT__
/* struct to read video filter file with varying line lengths */
typedef struct  {
  signed   char vid_filt_len;
  unsigned char vid_filt_table [16];
} vid_filt_struct;
#endif /* __VID_FILT_STRUCT__ */

#ifndef __FIRMWARE_STRUCT__
#define __FIRMWARE_STRUCT__
typedef struct  {
  unsigned char firmware_len;
  unsigned char firmware_table[16];
} firmware_struct;
#endif /* __FIRMWARE_STRUCT__ */

/* _additional_definitions_point */

#endif /* Si2144_TYPEDEFS_H */







