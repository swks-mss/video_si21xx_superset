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
                  Skyworks Solutions Broadcast Si2177 Layer 1 API


   API functions prototypes used by commands and properties
   FILE: Si2177_Commands_Prototypes.h
   Supported IC : Si2177
   Compiled for ROM 50 firmware 3_1_build_3
   Revision: 0.1
   Date: June 30 2015
**************************************************************************************/
#ifndef    Si2177_COMMANDS_PROTOTYPES_H
#define    Si2177_COMMANDS_PROTOTYPES_H

unsigned char Si2177_CurrentResponseStatus (L1_Si2177_Context *api, unsigned char ptDataBuffer);
unsigned char Si2177_pollForResetState     (L1_Si2177_Context *api);
unsigned char Si2177_pollForCTS            (L1_Si2177_Context *api);
unsigned char Si2177_pollForResponse       (L1_Si2177_Context *api, unsigned int nbBytes, unsigned char *pByteBuffer);
unsigned char Si2177_L1_SendCommand2       (L1_Si2177_Context *api, unsigned int cmd_code);
unsigned char Si2177_L1_SetProperty        (L1_Si2177_Context *api, unsigned int prop_code, int  data);
unsigned char Si2177_L1_GetProperty        (L1_Si2177_Context *api, unsigned int prop_code, int *data);
unsigned char Si2177_L1_SetProperty2       (L1_Si2177_Context *api, unsigned int prop_code);
unsigned char Si2177_L1_GetProperty2       (L1_Si2177_Context *api, unsigned int prop_code);


#ifdef    Si2177_GET_PROPERTY_STRING
unsigned char Si2177_L1_GetPropertyString  (L1_Si2177_Context *api, unsigned int prop_code, const char *separator, char *msg);
unsigned char Si2177_L1_PropertyText       (Si2177_PropObj   *prop, unsigned int prop_code, const char *separator, char *msg);
#endif /* Si2177_GET_PROPERTY_STRING */

#ifdef    Si2177_GET_COMMAND_STRINGS
  unsigned char   Si2177_L1_GetCommandResponseString(L1_Si2177_Context *api, unsigned int cmd_code, const char *separator, char *msg);
#endif /* Si2177_GET_COMMAND_STRINGS */

#ifdef    Si2177_AGC_OVERRIDE_CMD
unsigned char Si2177_L1_AGC_OVERRIDE    (L1_Si2177_Context *api,
                                         unsigned char   force_max_gain,
                                         unsigned char   force_top_gain);
#endif /* Si2177_AGC_OVERRIDE_CMD */
#ifdef    Si2177_ATV_RESTART_CMD
unsigned char Si2177_L1_ATV_RESTART     (L1_Si2177_Context *api,
                                         unsigned char   mode);
#endif /* Si2177_ATV_RESTART_CMD */
#ifdef    Si2177_ATV_STATUS_CMD
unsigned char Si2177_L1_ATV_STATUS      (L1_Si2177_Context *api,
                                         unsigned char   intack);
#endif /* Si2177_ATV_STATUS_CMD */
#ifdef    Si2177_CONFIG_CLOCKS_CMD
unsigned char Si2177_L1_CONFIG_CLOCKS   (L1_Si2177_Context *api,
                                         unsigned char   subcode,
                                         unsigned char   clock_mode,
                                         unsigned char   en_xout);
#endif /* Si2177_CONFIG_CLOCKS_CMD */
#ifdef    Si2177_CONFIG_I2C_CMD
unsigned char Si2177_L1_CONFIG_I2C      (L1_Si2177_Context *api,
                                         unsigned char   subcode,
                                         unsigned char   i2c_broadcast);
#endif /* Si2177_CONFIG_I2C_CMD */
#ifdef    Si2177_CONFIG_PINS_CMD
unsigned char Si2177_L1_CONFIG_PINS     (L1_Si2177_Context *api,
                                         unsigned char   gpio1_mode,
                                         unsigned char   gpio1_read,
                                         unsigned char   gpio2_mode,
                                         unsigned char   gpio2_read,
                                         unsigned char   reserved1,
                                         unsigned char   reserved2,
                                         unsigned char   reserved3);
#endif /* Si2177_CONFIG_PINS_CMD */
#ifdef    Si2177_DTV_RESTART_CMD
unsigned char Si2177_L1_DTV_RESTART     (L1_Si2177_Context *api);
#endif /* Si2177_DTV_RESTART_CMD */
#ifdef    Si2177_DTV_STATUS_CMD
unsigned char Si2177_L1_DTV_STATUS      (L1_Si2177_Context *api,
                                         unsigned char   intack);
#endif /* Si2177_DTV_STATUS_CMD */
#ifdef    Si2177_EXIT_BOOTLOADER_CMD
unsigned char Si2177_L1_EXIT_BOOTLOADER (L1_Si2177_Context *api,
                                         unsigned char   func,
                                         unsigned char   ctsien);
#endif /* Si2177_EXIT_BOOTLOADER_CMD */
#ifdef    Si2177_FINE_TUNE_CMD
unsigned char Si2177_L1_FINE_TUNE       (L1_Si2177_Context *api,
                                         unsigned char   persistence,
                                         unsigned char   apply_to_lif,
                                                   int   offset_500hz);
#endif /* Si2177_FINE_TUNE_CMD */
#ifdef    Si2177_GET_PROPERTY_CMD
unsigned char Si2177_L1_GET_PROPERTY    (L1_Si2177_Context *api,
                                         unsigned char   reserved,
                                         unsigned int    prop);
#endif /* Si2177_GET_PROPERTY_CMD */
#ifdef    Si2177_GET_REV_CMD
unsigned char Si2177_L1_GET_REV         (L1_Si2177_Context *api);
#endif /* Si2177_GET_REV_CMD */
#ifdef    Si2177_PART_INFO_CMD
unsigned char Si2177_L1_PART_INFO       (L1_Si2177_Context *api);
#endif /* Si2177_PART_INFO_CMD */
#ifdef    Si2177_POWER_DOWN_CMD
unsigned char Si2177_L1_POWER_DOWN      (L1_Si2177_Context *api);
#endif /* Si2177_POWER_DOWN_CMD */
#ifdef    Si2177_POWER_DOWN_HW_CMD
unsigned char Si2177_L1_POWER_DOWN_HW   (L1_Si2177_Context *api,
                                         unsigned char   subcode,
                                         unsigned char   pd_xo_osc,
                                         unsigned char   reserved1,
                                         unsigned char   en_xout,
                                         unsigned char   reserved2,
                                         unsigned char   pd_ldo,
                                         unsigned char   reserved3,
                                         unsigned char   reserved4,
                                         unsigned char   reserved5,
                                         unsigned char   reserved6,
                                         unsigned char   reserved7,
                                         unsigned char   reserved8);
#endif /* Si2177_POWER_DOWN_HW_CMD */
#ifdef    Si2177_POWER_UP_CMD
unsigned char Si2177_L1_POWER_UP        (L1_Si2177_Context *api,
                                         unsigned char   subcode,
                                         unsigned char   clock_mode,
                                         unsigned char   en_xout,
                                         unsigned char   pd_ldo,
                                         unsigned char   reserved2,
                                         unsigned char   reserved3,
                                         unsigned char   reserved4,
                                         unsigned char   reserved5,
                                         unsigned char   reserved6,
                                         unsigned char   reserved7,
                                         unsigned char   reset,
                                         unsigned char   clock_freq,
                                         unsigned char   reserved8,
                                         unsigned char   func,
                                         unsigned char   reserved9,
                                         unsigned char   ctsien,
                                         unsigned char   wake_up);
#endif /* Si2177_POWER_UP_CMD */
#ifdef    Si2177_SET_PROPERTY_CMD
unsigned char Si2177_L1_SET_PROPERTY    (L1_Si2177_Context *api,
                                         unsigned char   reserved,
                                         unsigned int    prop,
                                         unsigned int    data);
#endif /* Si2177_SET_PROPERTY_CMD */
#ifdef    Si2177_STANDBY_CMD
unsigned char Si2177_L1_STANDBY         (L1_Si2177_Context *api,
                                         unsigned char   type);
#endif /* Si2177_STANDBY_CMD */
#ifdef    Si2177_TUNER_STATUS_CMD
unsigned char Si2177_L1_TUNER_STATUS    (L1_Si2177_Context *api,
                                         unsigned char   intack);
#endif /* Si2177_TUNER_STATUS_CMD */
#ifdef    Si2177_TUNER_TUNE_FREQ_CMD
unsigned char Si2177_L1_TUNER_TUNE_FREQ (L1_Si2177_Context *api,
                                         unsigned char   mode,
                                         unsigned long   freq);
#endif /* Si2177_TUNER_TUNE_FREQ_CMD */

#endif /* Si2177_COMMANDS_PROTOTYPES_H */













