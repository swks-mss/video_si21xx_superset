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


   API properties definitions
   FILE: Si2141_L1_Properties.c
   Supported IC : Si2141
   Compiled for ROM 61 firmware 1_1_build_11
   Revision: 0.7
   Tag:  ROM61_1_1_build_11_V0.7
   Date: June 14 2019

 |---------------------------------------------------------------------------------------------------------------------|
 | Do NOT change this code unless you really know what you're doing!                                                   |
 | To customize properties for your application please edit the settings in Si2141_User_Properties.c
 |---------------------------------------------------------------------------------------------------------------------|

**************************************************************************************/
#define   Si2141_COMMAND_PROTOTYPES

#include "Si2141_L1_API.h"

/***********************************************************************************************************************
  Si2141_L1_SetProperty function
  Use:        property set function
              Used to call L1_SET_PROPERTY with the property Id and data provided.
  Parameter: *api          the Si2141 context
  Parameter: prop_code     the property Id
  Parameter: data          the property bytes
  Behavior:  This function will only download the property if required.
               Conditions to download the property are:
                - The property changes
                - The propertyWriteMode is set to Si2141_DOWNLOAD_ALWAYS
                - The property is unknown to Si2141_PackProperty (this may be useful for debug purpose)
  Returns:    0 if no error, an error code otherwise
 ***********************************************************************************************************************/
unsigned char Si2141_L1_SetProperty         (L1_Si2141_Context *api, unsigned int prop_code, int  data) {
    unsigned char  reserved=0;
    return Si2141_L1_SET_PROPERTY (api, reserved, prop_code, data);
}
/***********************************************************************************************************************
  Si2141_L1_GetProperty function
  Use:        property get function
              Used to call L1_GET_PROPERTY with the property Id provided.
  Parameter: *api      the Si2141 context
  Parameter: prop_code the property Id
  Parameter: *data     a buffer to store the property bytes into
  Returns:    0 if no error, an error code otherwise
 ***********************************************************************************************************************/
unsigned char Si2141_L1_GetProperty         (L1_Si2141_Context *api, unsigned int prop_code, int *data) {
    unsigned char  reserved          = 0;
    unsigned char res;
    res = Si2141_L1_GET_PROPERTY (api, reserved, prop_code);
    *data = api->rsp->get_property.data;
    return res;
}
 /***********************************************************************************************************************
  Si2141_L1_SetProperty2 function
  Use:        Sets the property given the property code.
  Parameter: *api          the Si2141 context
  Parameter: prop_code     the property Id

  Returns:    NO_Si2141_ERROR if successful.
 ***********************************************************************************************************************/
unsigned char Si2141_L1_SetProperty2        (L1_Si2141_Context *api, unsigned int prop_code) {
    int data, res;
    char msg[1000];
    res = Si2141_PackProperty(api->prop, prop_code, &data);
    if (res != NO_Si2141_ERROR) {
      sprintf(msg, "\nSi2141_L1_SetProperty2: %s 0x%04x!\n\n", Si2141_L1_API_ERROR_TEXT(res), prop_code);
      SiTRACE(msg);
      SiERROR(msg);
      return res;
    }
    return Si2141_L1_SetProperty (api, prop_code & 0xffff, data);
  }
 /***********************************************************************************************************************
  Si2141_L1_GetProperty2 function
  Use:        property get function
              Used to call L1_GET_PROPERTY with the property Id provided.
  Parameter: *api          the Si2141 context
  Parameter: prop_code     the property Id

  Returns:    NO_Si2141_ERROR if successful.
 ***********************************************************************************************************************/
unsigned char Si2141_L1_GetProperty2        (L1_Si2141_Context *api, unsigned int prop_code) {
  int data, res;
  res = Si2141_L1_GetProperty(api, prop_code & 0xffff, &data);
  if (res != NO_Si2141_ERROR) {
    SiTRACE("Si2141_L1_GetProperty2: %s 0x%04x\n", Si2141_L1_API_ERROR_TEXT(res), prop_code);
    SiERROR(Si2141_L1_API_ERROR_TEXT(res));
    return res;
  }
  return Si2141_UnpackProperty(api->prop, prop_code, data);
}
/*****************************************************************************************
 NAME: Si2141_downloadCOMMONProperties
  DESCRIPTION: Setup Si2141 COMMON properties configuration
  This function will download all the COMMON configuration properties.
  The function Si2141_storeUserProperties should be called before the first call to this function.
  Parameter:  Pointer to Si2141 Context
  Returns:    I2C transaction error code, NO_Si2141_ERROR if successful
  Programming Guide Reference:    COMMON setup flowchart
******************************************************************************************/
int  Si2141_downloadCOMMONProperties      (L1_Si2141_Context *api) {
  SiTRACE("Si2141_downloadCOMMONProperties\n");
#ifdef    Si2141_CRYSTAL_TRIM_PROP
  if (Si2141_L1_SetProperty2(api, Si2141_CRYSTAL_TRIM_PROP_CODE                ) != NO_Si2141_ERROR) {return ERROR_Si2141_SENDING_COMMAND;}
#endif /* Si2141_CRYSTAL_TRIM_PROP */
#ifdef    Si2141_XOUT_PROP
  if (Si2141_L1_SetProperty2(api, Si2141_XOUT_PROP_CODE                        ) != NO_Si2141_ERROR) {return ERROR_Si2141_SENDING_COMMAND;}
#endif /* Si2141_XOUT_PROP */
return NO_Si2141_ERROR;
}
/*****************************************************************************************
 NAME: Si2141_downloadDTVProperties
  DESCRIPTION: Setup Si2141 DTV properties configuration
  This function will download all the DTV configuration properties.
  The function Si2141_storeUserProperties should be called before the first call to this function.
  Parameter:  Pointer to Si2141 Context
  Returns:    I2C transaction error code, NO_Si2141_ERROR if successful
  Programming Guide Reference:    DTV setup flowchart
******************************************************************************************/
int  Si2141_downloadDTVProperties         (L1_Si2141_Context *api) {
  SiTRACE("Si2141_downloadDTVProperties\n");
#ifdef    Si2141_DTV_AGC_AUTO_FREEZE_PROP
  if (Si2141_L1_SetProperty2(api, Si2141_DTV_AGC_AUTO_FREEZE_PROP_CODE         ) != NO_Si2141_ERROR) {return ERROR_Si2141_SENDING_COMMAND;}
#endif /* Si2141_DTV_AGC_AUTO_FREEZE_PROP */
#ifdef    Si2141_DTV_AGC_SPEED_PROP
  if (Si2141_L1_SetProperty2(api, Si2141_DTV_AGC_SPEED_PROP_CODE               ) != NO_Si2141_ERROR) {return ERROR_Si2141_SENDING_COMMAND;}
#endif /* Si2141_DTV_AGC_SPEED_PROP */
#ifdef    Si2141_DTV_CONFIG_IF_PORT_PROP
  if (Si2141_L1_SetProperty2(api, Si2141_DTV_CONFIG_IF_PORT_PROP_CODE          ) != NO_Si2141_ERROR) {return ERROR_Si2141_SENDING_COMMAND;}
#endif /* Si2141_DTV_CONFIG_IF_PORT_PROP */
#ifdef    Si2141_DTV_EXT_AGC_PROP
  if (Si2141_L1_SetProperty2(api, Si2141_DTV_EXT_AGC_PROP_CODE                 ) != NO_Si2141_ERROR) {return ERROR_Si2141_SENDING_COMMAND;}
#endif /* Si2141_DTV_EXT_AGC_PROP */
#ifdef    Si2141_DTV_IF_AGC_SPEED_PROP
  if (Si2141_L1_SetProperty2(api, Si2141_DTV_IF_AGC_SPEED_PROP_CODE            ) != NO_Si2141_ERROR) {return ERROR_Si2141_SENDING_COMMAND;}
#endif /* Si2141_DTV_IF_AGC_SPEED_PROP */
#ifdef    Si2141_DTV_INITIAL_AGC_SPEED_PROP
  if (Si2141_L1_SetProperty2(api, Si2141_DTV_INITIAL_AGC_SPEED_PROP_CODE       ) != NO_Si2141_ERROR) {return ERROR_Si2141_SENDING_COMMAND;}
#endif /* Si2141_DTV_INITIAL_AGC_SPEED_PROP */
#ifdef    Si2141_DTV_INITIAL_AGC_SPEED_PERIOD_PROP
  if (Si2141_L1_SetProperty2(api, Si2141_DTV_INITIAL_AGC_SPEED_PERIOD_PROP_CODE) != NO_Si2141_ERROR) {return ERROR_Si2141_SENDING_COMMAND;}
#endif /* Si2141_DTV_INITIAL_AGC_SPEED_PERIOD_PROP */
#ifdef    Si2141_DTV_INTERNAL_ZIF_PROP
  if (Si2141_L1_SetProperty2(api, Si2141_DTV_INTERNAL_ZIF_PROP_CODE            ) != NO_Si2141_ERROR) {return ERROR_Si2141_SENDING_COMMAND;}
#endif /* Si2141_DTV_INTERNAL_ZIF_PROP */
#ifdef    Si2141_DTV_LIF_FREQ_PROP
  if (Si2141_L1_SetProperty2(api, Si2141_DTV_LIF_FREQ_PROP_CODE                ) != NO_Si2141_ERROR) {return ERROR_Si2141_SENDING_COMMAND;}
#endif /* Si2141_DTV_LIF_FREQ_PROP */
#ifdef    Si2141_DTV_LIF_OUT_PROP
  if (Si2141_L1_SetProperty2(api, Si2141_DTV_LIF_OUT_PROP_CODE                 ) != NO_Si2141_ERROR) {return ERROR_Si2141_SENDING_COMMAND;}
#endif /* Si2141_DTV_LIF_OUT_PROP */
#ifdef    Si2141_DTV_MODE_PROP
  if (Si2141_L1_SetProperty2(api, Si2141_DTV_MODE_PROP_CODE                    ) != NO_Si2141_ERROR) {return ERROR_Si2141_SENDING_COMMAND;}
#endif /* Si2141_DTV_MODE_PROP */
#ifdef    Si2141_DTV_PGA_LIMITS_PROP
  if (Si2141_L1_SetProperty2(api, Si2141_DTV_PGA_LIMITS_PROP_CODE              ) != NO_Si2141_ERROR) {return ERROR_Si2141_SENDING_COMMAND;}
#endif /* Si2141_DTV_PGA_LIMITS_PROP */
#ifdef    Si2141_DTV_PGA_TARGET_PROP
  if (Si2141_L1_SetProperty2(api, Si2141_DTV_PGA_TARGET_PROP_CODE              ) != NO_Si2141_ERROR) {return ERROR_Si2141_SENDING_COMMAND;}
#endif /* Si2141_DTV_PGA_TARGET_PROP */
#ifdef    Si2141_DTV_RF_AGC_SPEED_PROP
  if (Si2141_L1_SetProperty2(api, Si2141_DTV_RF_AGC_SPEED_PROP_CODE            ) != NO_Si2141_ERROR) {return ERROR_Si2141_SENDING_COMMAND;}
#endif /* Si2141_DTV_RF_AGC_SPEED_PROP */
#ifdef    Si2141_DTV_RF_TOP_PROP
  if (Si2141_L1_SetProperty2(api, Si2141_DTV_RF_TOP_PROP_CODE                  ) != NO_Si2141_ERROR) {return ERROR_Si2141_SENDING_COMMAND;}
#endif /* Si2141_DTV_RF_TOP_PROP */
#ifdef    Si2141_DTV_RSQ_RSSI_THRESHOLD_PROP
  if (Si2141_L1_SetProperty2(api, Si2141_DTV_RSQ_RSSI_THRESHOLD_PROP_CODE      ) != NO_Si2141_ERROR) {return ERROR_Si2141_SENDING_COMMAND;}
#endif /* Si2141_DTV_RSQ_RSSI_THRESHOLD_PROP */
#ifdef    Si2141_DTV_WB_AGC_SPEED_PROP
  if (Si2141_L1_SetProperty2(api, Si2141_DTV_WB_AGC_SPEED_PROP_CODE            ) != NO_Si2141_ERROR) {return ERROR_Si2141_SENDING_COMMAND;}
#endif /* Si2141_DTV_WB_AGC_SPEED_PROP */
return NO_Si2141_ERROR;
}
/*****************************************************************************************
 NAME: Si2141_downloadTUNERProperties
  DESCRIPTION: Setup Si2141 TUNER properties configuration
  This function will download all the TUNER configuration properties.
  The function Si2141_storeUserProperties should be called before the first call to this function.
  Parameter:  Pointer to Si2141 Context
  Returns:    I2C transaction error code, NO_Si2141_ERROR if successful
  Programming Guide Reference:    TUNER setup flowchart
******************************************************************************************/
int  Si2141_downloadTUNERProperties       (L1_Si2141_Context *api) {
  SiTRACE("Si2141_downloadTUNERProperties\n");
#ifdef    Si2141_TUNER_BLOCKED_VCO_PROP
  if (Si2141_L1_SetProperty2(api, Si2141_TUNER_BLOCKED_VCO_PROP_CODE           ) != NO_Si2141_ERROR) {return ERROR_Si2141_SENDING_COMMAND;}
#endif /* Si2141_TUNER_BLOCKED_VCO_PROP */
#ifdef    Si2141_TUNER_BLOCKED_VCO2_PROP
  if (Si2141_L1_SetProperty2(api, Si2141_TUNER_BLOCKED_VCO2_PROP_CODE          ) != NO_Si2141_ERROR) {return ERROR_Si2141_SENDING_COMMAND;}
#endif /* Si2141_TUNER_BLOCKED_VCO2_PROP */
#ifdef    Si2141_TUNER_BLOCKED_VCO3_PROP
  if (Si2141_L1_SetProperty2(api, Si2141_TUNER_BLOCKED_VCO3_PROP_CODE          ) != NO_Si2141_ERROR) {return ERROR_Si2141_SENDING_COMMAND;}
#endif /* Si2141_TUNER_BLOCKED_VCO3_PROP */
#ifdef    Si2141_TUNER_LO_INJECTION_PROP
  if (Si2141_L1_SetProperty2(api, Si2141_TUNER_LO_INJECTION_PROP_CODE          ) != NO_Si2141_ERROR) {return ERROR_Si2141_SENDING_COMMAND;}
#endif /* Si2141_TUNER_LO_INJECTION_PROP */
#ifdef    Si2141_TUNER_RETURN_LOSS_PROP
  if (Si2141_L1_SetProperty2(api, Si2141_TUNER_RETURN_LOSS_PROP_CODE           ) != NO_Si2141_ERROR) {return ERROR_Si2141_SENDING_COMMAND;}
#endif /* Si2141_TUNER_RETURN_LOSS_PROP */
return NO_Si2141_ERROR;
}
int  Si2141_downloadAllProperties         (L1_Si2141_Context *api) {
  Si2141_downloadCOMMONProperties      (api);
  Si2141_downloadDTVProperties         (api);
  Si2141_downloadTUNERProperties       (api);
  return 0;
}

/***********************************************************************************************************************
  Si2141_PackProperty function
  Use:        This function will pack all the members of a property into an integer for the SetProperty function.

  Parameter: *prop          the Si2141 property context
  Parameter:  prop_code     the property Id
  Parameter:  *data         an int to store the property data

  Returns:    NO_Si2141_ERROR if the property exists.
 ***********************************************************************************************************************/
unsigned char Si2141_PackProperty            (Si2141_PropObj   *prop, unsigned int prop_code, int *data) {
    switch (prop_code) {
    #ifdef        Si2141_CRYSTAL_TRIM_PROP
     case         Si2141_CRYSTAL_TRIM_PROP_CODE:
      *data = (prop->crystal_trim.xo_cap & Si2141_CRYSTAL_TRIM_PROP_XO_CAP_MASK) << Si2141_CRYSTAL_TRIM_PROP_XO_CAP_LSB ;
     break;
    #endif /*     Si2141_CRYSTAL_TRIM_PROP */
    #ifdef        Si2141_DTV_AGC_AUTO_FREEZE_PROP
     case         Si2141_DTV_AGC_AUTO_FREEZE_PROP_CODE:
      *data = (prop->dtv_agc_auto_freeze.thld    & Si2141_DTV_AGC_AUTO_FREEZE_PROP_THLD_MASK   ) << Si2141_DTV_AGC_AUTO_FREEZE_PROP_THLD_LSB  |
              (prop->dtv_agc_auto_freeze.timeout & Si2141_DTV_AGC_AUTO_FREEZE_PROP_TIMEOUT_MASK) << Si2141_DTV_AGC_AUTO_FREEZE_PROP_TIMEOUT_LSB ;
     break;
    #endif /*     Si2141_DTV_AGC_AUTO_FREEZE_PROP */
    #ifdef        Si2141_DTV_AGC_SPEED_PROP
     case         Si2141_DTV_AGC_SPEED_PROP_CODE:
      *data = (prop->dtv_agc_speed.if_agc_speed & Si2141_DTV_AGC_SPEED_PROP_IF_AGC_SPEED_MASK) << Si2141_DTV_AGC_SPEED_PROP_IF_AGC_SPEED_LSB  |
              (prop->dtv_agc_speed.agc_decim    & Si2141_DTV_AGC_SPEED_PROP_AGC_DECIM_MASK   ) << Si2141_DTV_AGC_SPEED_PROP_AGC_DECIM_LSB ;
     break;
    #endif /*     Si2141_DTV_AGC_SPEED_PROP */
    #ifdef        Si2141_DTV_CONFIG_IF_PORT_PROP
     case         Si2141_DTV_CONFIG_IF_PORT_PROP_CODE:
      *data = (prop->dtv_config_if_port.dtv_out_type & Si2141_DTV_CONFIG_IF_PORT_PROP_DTV_OUT_TYPE_MASK) << Si2141_DTV_CONFIG_IF_PORT_PROP_DTV_OUT_TYPE_LSB ;
     break;
    #endif /*     Si2141_DTV_CONFIG_IF_PORT_PROP */
    #ifdef        Si2141_DTV_EXT_AGC_PROP
     case         Si2141_DTV_EXT_AGC_PROP_CODE:
      *data = (prop->dtv_ext_agc.min_10mv & Si2141_DTV_EXT_AGC_PROP_MIN_10MV_MASK) << Si2141_DTV_EXT_AGC_PROP_MIN_10MV_LSB  |
              (prop->dtv_ext_agc.max_10mv & Si2141_DTV_EXT_AGC_PROP_MAX_10MV_MASK) << Si2141_DTV_EXT_AGC_PROP_MAX_10MV_LSB ;
     break;
    #endif /*     Si2141_DTV_EXT_AGC_PROP */
    #ifdef        Si2141_DTV_IF_AGC_SPEED_PROP
     case         Si2141_DTV_IF_AGC_SPEED_PROP_CODE:
      *data = (prop->dtv_if_agc_speed.attack & Si2141_DTV_IF_AGC_SPEED_PROP_ATTACK_MASK) << Si2141_DTV_IF_AGC_SPEED_PROP_ATTACK_LSB  |
              (prop->dtv_if_agc_speed.decay  & Si2141_DTV_IF_AGC_SPEED_PROP_DECAY_MASK ) << Si2141_DTV_IF_AGC_SPEED_PROP_DECAY_LSB ;
     break;
    #endif /*     Si2141_DTV_IF_AGC_SPEED_PROP */
    #ifdef        Si2141_DTV_INITIAL_AGC_SPEED_PROP
     case         Si2141_DTV_INITIAL_AGC_SPEED_PROP_CODE:
      *data = (prop->dtv_initial_agc_speed.if_agc_speed & Si2141_DTV_INITIAL_AGC_SPEED_PROP_IF_AGC_SPEED_MASK) << Si2141_DTV_INITIAL_AGC_SPEED_PROP_IF_AGC_SPEED_LSB  |
              (prop->dtv_initial_agc_speed.agc_decim    & Si2141_DTV_INITIAL_AGC_SPEED_PROP_AGC_DECIM_MASK   ) << Si2141_DTV_INITIAL_AGC_SPEED_PROP_AGC_DECIM_LSB ;
     break;
    #endif /*     Si2141_DTV_INITIAL_AGC_SPEED_PROP */
    #ifdef        Si2141_DTV_INITIAL_AGC_SPEED_PERIOD_PROP
     case         Si2141_DTV_INITIAL_AGC_SPEED_PERIOD_PROP_CODE:
      *data = (prop->dtv_initial_agc_speed_period.period & Si2141_DTV_INITIAL_AGC_SPEED_PERIOD_PROP_PERIOD_MASK) << Si2141_DTV_INITIAL_AGC_SPEED_PERIOD_PROP_PERIOD_LSB ;
     break;
    #endif /*     Si2141_DTV_INITIAL_AGC_SPEED_PERIOD_PROP */
    #ifdef        Si2141_DTV_INTERNAL_ZIF_PROP
     case         Si2141_DTV_INTERNAL_ZIF_PROP_CODE:
      *data = (prop->dtv_internal_zif.atsc   & Si2141_DTV_INTERNAL_ZIF_PROP_ATSC_MASK  ) << Si2141_DTV_INTERNAL_ZIF_PROP_ATSC_LSB  |
              (prop->dtv_internal_zif.qam_us & Si2141_DTV_INTERNAL_ZIF_PROP_QAM_US_MASK) << Si2141_DTV_INTERNAL_ZIF_PROP_QAM_US_LSB  |
              (prop->dtv_internal_zif.dvbt   & Si2141_DTV_INTERNAL_ZIF_PROP_DVBT_MASK  ) << Si2141_DTV_INTERNAL_ZIF_PROP_DVBT_LSB  |
              (prop->dtv_internal_zif.dvbc   & Si2141_DTV_INTERNAL_ZIF_PROP_DVBC_MASK  ) << Si2141_DTV_INTERNAL_ZIF_PROP_DVBC_LSB  |
              (prop->dtv_internal_zif.isdbt  & Si2141_DTV_INTERNAL_ZIF_PROP_ISDBT_MASK ) << Si2141_DTV_INTERNAL_ZIF_PROP_ISDBT_LSB  |
              (prop->dtv_internal_zif.isdbc  & Si2141_DTV_INTERNAL_ZIF_PROP_ISDBC_MASK ) << Si2141_DTV_INTERNAL_ZIF_PROP_ISDBC_LSB  |
              (prop->dtv_internal_zif.dtmb   & Si2141_DTV_INTERNAL_ZIF_PROP_DTMB_MASK  ) << Si2141_DTV_INTERNAL_ZIF_PROP_DTMB_LSB ;
     break;
    #endif /*     Si2141_DTV_INTERNAL_ZIF_PROP */
    #ifdef        Si2141_DTV_LIF_FREQ_PROP
     case         Si2141_DTV_LIF_FREQ_PROP_CODE:
      *data = (prop->dtv_lif_freq.offset & Si2141_DTV_LIF_FREQ_PROP_OFFSET_MASK) << Si2141_DTV_LIF_FREQ_PROP_OFFSET_LSB ;
     break;
    #endif /*     Si2141_DTV_LIF_FREQ_PROP */
    #ifdef        Si2141_DTV_LIF_OUT_PROP
     case         Si2141_DTV_LIF_OUT_PROP_CODE:
      *data = (prop->dtv_lif_out.offset & Si2141_DTV_LIF_OUT_PROP_OFFSET_MASK) << Si2141_DTV_LIF_OUT_PROP_OFFSET_LSB  |
              (prop->dtv_lif_out.amp    & Si2141_DTV_LIF_OUT_PROP_AMP_MASK   ) << Si2141_DTV_LIF_OUT_PROP_AMP_LSB ;
     break;
    #endif /*     Si2141_DTV_LIF_OUT_PROP */
    #ifdef        Si2141_DTV_MODE_PROP
     case         Si2141_DTV_MODE_PROP_CODE:
      *data = (prop->dtv_mode.bw              & Si2141_DTV_MODE_PROP_BW_MASK             ) << Si2141_DTV_MODE_PROP_BW_LSB  |
              (prop->dtv_mode.modulation      & Si2141_DTV_MODE_PROP_MODULATION_MASK     ) << Si2141_DTV_MODE_PROP_MODULATION_LSB  |
              (prop->dtv_mode.invert_spectrum & Si2141_DTV_MODE_PROP_INVERT_SPECTRUM_MASK) << Si2141_DTV_MODE_PROP_INVERT_SPECTRUM_LSB ;
     break;
    #endif /*     Si2141_DTV_MODE_PROP */
    #ifdef        Si2141_DTV_PGA_LIMITS_PROP
     case         Si2141_DTV_PGA_LIMITS_PROP_CODE:
      *data = (prop->dtv_pga_limits.min & Si2141_DTV_PGA_LIMITS_PROP_MIN_MASK) << Si2141_DTV_PGA_LIMITS_PROP_MIN_LSB  |
              (prop->dtv_pga_limits.max & Si2141_DTV_PGA_LIMITS_PROP_MAX_MASK) << Si2141_DTV_PGA_LIMITS_PROP_MAX_LSB ;
     break;
    #endif /*     Si2141_DTV_PGA_LIMITS_PROP */
    #ifdef        Si2141_DTV_PGA_TARGET_PROP
     case         Si2141_DTV_PGA_TARGET_PROP_CODE:
      *data = (prop->dtv_pga_target.pga_target      & Si2141_DTV_PGA_TARGET_PROP_PGA_TARGET_MASK     ) << Si2141_DTV_PGA_TARGET_PROP_PGA_TARGET_LSB  |
              (prop->dtv_pga_target.override_enable & Si2141_DTV_PGA_TARGET_PROP_OVERRIDE_ENABLE_MASK) << Si2141_DTV_PGA_TARGET_PROP_OVERRIDE_ENABLE_LSB ;
     break;
    #endif /*     Si2141_DTV_PGA_TARGET_PROP */
    #ifdef        Si2141_DTV_RF_AGC_SPEED_PROP
     case         Si2141_DTV_RF_AGC_SPEED_PROP_CODE:
      *data = (prop->dtv_rf_agc_speed.attack & Si2141_DTV_RF_AGC_SPEED_PROP_ATTACK_MASK) << Si2141_DTV_RF_AGC_SPEED_PROP_ATTACK_LSB  |
              (prop->dtv_rf_agc_speed.decay  & Si2141_DTV_RF_AGC_SPEED_PROP_DECAY_MASK ) << Si2141_DTV_RF_AGC_SPEED_PROP_DECAY_LSB ;
     break;
    #endif /*     Si2141_DTV_RF_AGC_SPEED_PROP */
    #ifdef        Si2141_DTV_RF_TOP_PROP
     case         Si2141_DTV_RF_TOP_PROP_CODE:
      *data = (prop->dtv_rf_top.dtv_rf_top & Si2141_DTV_RF_TOP_PROP_DTV_RF_TOP_MASK) << Si2141_DTV_RF_TOP_PROP_DTV_RF_TOP_LSB ;
     break;
    #endif /*     Si2141_DTV_RF_TOP_PROP */
    #ifdef        Si2141_DTV_RSQ_RSSI_THRESHOLD_PROP
     case         Si2141_DTV_RSQ_RSSI_THRESHOLD_PROP_CODE:
      *data = (prop->dtv_rsq_rssi_threshold.lo & Si2141_DTV_RSQ_RSSI_THRESHOLD_PROP_LO_MASK) << Si2141_DTV_RSQ_RSSI_THRESHOLD_PROP_LO_LSB ;
     break;
    #endif /*     Si2141_DTV_RSQ_RSSI_THRESHOLD_PROP */
    #ifdef        Si2141_DTV_WB_AGC_SPEED_PROP
     case         Si2141_DTV_WB_AGC_SPEED_PROP_CODE:
      *data = (prop->dtv_wb_agc_speed.attack & Si2141_DTV_WB_AGC_SPEED_PROP_ATTACK_MASK) << Si2141_DTV_WB_AGC_SPEED_PROP_ATTACK_LSB  |
              (prop->dtv_wb_agc_speed.decay  & Si2141_DTV_WB_AGC_SPEED_PROP_DECAY_MASK ) << Si2141_DTV_WB_AGC_SPEED_PROP_DECAY_LSB ;
     break;
    #endif /*     Si2141_DTV_WB_AGC_SPEED_PROP */
    #ifdef        Si2141_TUNER_BLOCKED_VCO_PROP
     case         Si2141_TUNER_BLOCKED_VCO_PROP_CODE:
      *data = (prop->tuner_blocked_vco.vco_code & Si2141_TUNER_BLOCKED_VCO_PROP_VCO_CODE_MASK) << Si2141_TUNER_BLOCKED_VCO_PROP_VCO_CODE_LSB ;
     break;
    #endif /*     Si2141_TUNER_BLOCKED_VCO_PROP */
    #ifdef        Si2141_TUNER_BLOCKED_VCO2_PROP
     case         Si2141_TUNER_BLOCKED_VCO2_PROP_CODE:
      *data = (prop->tuner_blocked_vco2.vco_code & Si2141_TUNER_BLOCKED_VCO2_PROP_VCO_CODE_MASK) << Si2141_TUNER_BLOCKED_VCO2_PROP_VCO_CODE_LSB ;
     break;
    #endif /*     Si2141_TUNER_BLOCKED_VCO2_PROP */
    #ifdef        Si2141_TUNER_BLOCKED_VCO3_PROP
     case         Si2141_TUNER_BLOCKED_VCO3_PROP_CODE:
      *data = (prop->tuner_blocked_vco3.vco_code & Si2141_TUNER_BLOCKED_VCO3_PROP_VCO_CODE_MASK) << Si2141_TUNER_BLOCKED_VCO3_PROP_VCO_CODE_LSB ;
     break;
    #endif /*     Si2141_TUNER_BLOCKED_VCO3_PROP */
    #ifdef        Si2141_TUNER_LO_INJECTION_PROP
     case         Si2141_TUNER_LO_INJECTION_PROP_CODE:
      *data = (prop->tuner_lo_injection.band_1 & Si2141_TUNER_LO_INJECTION_PROP_BAND_1_MASK) << Si2141_TUNER_LO_INJECTION_PROP_BAND_1_LSB  |
              (prop->tuner_lo_injection.band_2 & Si2141_TUNER_LO_INJECTION_PROP_BAND_2_MASK) << Si2141_TUNER_LO_INJECTION_PROP_BAND_2_LSB  |
              (prop->tuner_lo_injection.band_3 & Si2141_TUNER_LO_INJECTION_PROP_BAND_3_MASK) << Si2141_TUNER_LO_INJECTION_PROP_BAND_3_LSB ;
     break;
    #endif /*     Si2141_TUNER_LO_INJECTION_PROP */
    #ifdef        Si2141_TUNER_RETURN_LOSS_PROP
     case         Si2141_TUNER_RETURN_LOSS_PROP_CODE:
      *data = (prop->tuner_return_loss.config   & Si2141_TUNER_RETURN_LOSS_PROP_CONFIG_MASK  ) << Si2141_TUNER_RETURN_LOSS_PROP_CONFIG_LSB  |
              (prop->tuner_return_loss.mode     & Si2141_TUNER_RETURN_LOSS_PROP_MODE_MASK    ) << Si2141_TUNER_RETURN_LOSS_PROP_MODE_LSB  |
              (prop->tuner_return_loss.reserved & Si2141_TUNER_RETURN_LOSS_PROP_RESERVED_MASK) << Si2141_TUNER_RETURN_LOSS_PROP_RESERVED_LSB ;
     break;
    #endif /*     Si2141_TUNER_RETURN_LOSS_PROP */
    #ifdef        Si2141_XOUT_PROP
     case         Si2141_XOUT_PROP_CODE:
      *data = (prop->xout.amp & Si2141_XOUT_PROP_AMP_MASK) << Si2141_XOUT_PROP_AMP_LSB ;
     break;
    #endif /*     Si2141_XOUT_PROP */
     default : return ERROR_Si2141_UNKNOWN_PROPERTY; break;
    }
    return NO_Si2141_ERROR;
}


/***********************************************************************************************************************
  Si2141_UnpackProperty function
  Use:        This function will unpack all the members of a property from an integer from the GetProperty function.

  Parameter: *prop          the Si2141 property context
  Parameter:  prop_code     the property Id
  Parameter:  data          the property data

  Returns:    NO_Si2141_ERROR if the property exists.
 ***********************************************************************************************************************/
unsigned char Si2141_UnpackProperty          (Si2141_PropObj   *prop, unsigned int prop_code, int  data) {
    switch (prop_code) {
    #ifdef        Si2141_CRYSTAL_TRIM_PROP
     case         Si2141_CRYSTAL_TRIM_PROP_CODE:
               prop->crystal_trim.xo_cap = (data >> Si2141_CRYSTAL_TRIM_PROP_XO_CAP_LSB) & Si2141_CRYSTAL_TRIM_PROP_XO_CAP_MASK;
     break;
    #endif /*     Si2141_CRYSTAL_TRIM_PROP */
    #ifdef        Si2141_DTV_AGC_AUTO_FREEZE_PROP
     case         Si2141_DTV_AGC_AUTO_FREEZE_PROP_CODE:
               prop->dtv_agc_auto_freeze.thld    = (data >> Si2141_DTV_AGC_AUTO_FREEZE_PROP_THLD_LSB   ) & Si2141_DTV_AGC_AUTO_FREEZE_PROP_THLD_MASK;
               prop->dtv_agc_auto_freeze.timeout = (data >> Si2141_DTV_AGC_AUTO_FREEZE_PROP_TIMEOUT_LSB) & Si2141_DTV_AGC_AUTO_FREEZE_PROP_TIMEOUT_MASK;
     break;
    #endif /*     Si2141_DTV_AGC_AUTO_FREEZE_PROP */
    #ifdef        Si2141_DTV_AGC_SPEED_PROP
     case         Si2141_DTV_AGC_SPEED_PROP_CODE:
               prop->dtv_agc_speed.if_agc_speed = (data >> Si2141_DTV_AGC_SPEED_PROP_IF_AGC_SPEED_LSB) & Si2141_DTV_AGC_SPEED_PROP_IF_AGC_SPEED_MASK;
               prop->dtv_agc_speed.agc_decim    = (data >> Si2141_DTV_AGC_SPEED_PROP_AGC_DECIM_LSB   ) & Si2141_DTV_AGC_SPEED_PROP_AGC_DECIM_MASK;
     break;
    #endif /*     Si2141_DTV_AGC_SPEED_PROP */
    #ifdef        Si2141_DTV_CONFIG_IF_PORT_PROP
     case         Si2141_DTV_CONFIG_IF_PORT_PROP_CODE:
               prop->dtv_config_if_port.dtv_out_type = (data >> Si2141_DTV_CONFIG_IF_PORT_PROP_DTV_OUT_TYPE_LSB) & Si2141_DTV_CONFIG_IF_PORT_PROP_DTV_OUT_TYPE_MASK;
     break;
    #endif /*     Si2141_DTV_CONFIG_IF_PORT_PROP */
    #ifdef        Si2141_DTV_EXT_AGC_PROP
     case         Si2141_DTV_EXT_AGC_PROP_CODE:
               prop->dtv_ext_agc.min_10mv = (data >> Si2141_DTV_EXT_AGC_PROP_MIN_10MV_LSB) & Si2141_DTV_EXT_AGC_PROP_MIN_10MV_MASK;
               prop->dtv_ext_agc.max_10mv = (data >> Si2141_DTV_EXT_AGC_PROP_MAX_10MV_LSB) & Si2141_DTV_EXT_AGC_PROP_MAX_10MV_MASK;
     break;
    #endif /*     Si2141_DTV_EXT_AGC_PROP */
    #ifdef        Si2141_DTV_IF_AGC_SPEED_PROP
     case         Si2141_DTV_IF_AGC_SPEED_PROP_CODE:
               prop->dtv_if_agc_speed.attack = (data >> Si2141_DTV_IF_AGC_SPEED_PROP_ATTACK_LSB) & Si2141_DTV_IF_AGC_SPEED_PROP_ATTACK_MASK;
               prop->dtv_if_agc_speed.decay  = (data >> Si2141_DTV_IF_AGC_SPEED_PROP_DECAY_LSB ) & Si2141_DTV_IF_AGC_SPEED_PROP_DECAY_MASK;
     break;
    #endif /*     Si2141_DTV_IF_AGC_SPEED_PROP */
    #ifdef        Si2141_DTV_INITIAL_AGC_SPEED_PROP
     case         Si2141_DTV_INITIAL_AGC_SPEED_PROP_CODE:
               prop->dtv_initial_agc_speed.if_agc_speed = (data >> Si2141_DTV_INITIAL_AGC_SPEED_PROP_IF_AGC_SPEED_LSB) & Si2141_DTV_INITIAL_AGC_SPEED_PROP_IF_AGC_SPEED_MASK;
               prop->dtv_initial_agc_speed.agc_decim    = (data >> Si2141_DTV_INITIAL_AGC_SPEED_PROP_AGC_DECIM_LSB   ) & Si2141_DTV_INITIAL_AGC_SPEED_PROP_AGC_DECIM_MASK;
     break;
    #endif /*     Si2141_DTV_INITIAL_AGC_SPEED_PROP */
    #ifdef        Si2141_DTV_INITIAL_AGC_SPEED_PERIOD_PROP
     case         Si2141_DTV_INITIAL_AGC_SPEED_PERIOD_PROP_CODE:
               prop->dtv_initial_agc_speed_period.period = (data >> Si2141_DTV_INITIAL_AGC_SPEED_PERIOD_PROP_PERIOD_LSB) & Si2141_DTV_INITIAL_AGC_SPEED_PERIOD_PROP_PERIOD_MASK;
     break;
    #endif /*     Si2141_DTV_INITIAL_AGC_SPEED_PERIOD_PROP */
    #ifdef        Si2141_DTV_INTERNAL_ZIF_PROP
     case         Si2141_DTV_INTERNAL_ZIF_PROP_CODE:
               prop->dtv_internal_zif.atsc   = (data >> Si2141_DTV_INTERNAL_ZIF_PROP_ATSC_LSB  ) & Si2141_DTV_INTERNAL_ZIF_PROP_ATSC_MASK;
               prop->dtv_internal_zif.qam_us = (data >> Si2141_DTV_INTERNAL_ZIF_PROP_QAM_US_LSB) & Si2141_DTV_INTERNAL_ZIF_PROP_QAM_US_MASK;
               prop->dtv_internal_zif.dvbt   = (data >> Si2141_DTV_INTERNAL_ZIF_PROP_DVBT_LSB  ) & Si2141_DTV_INTERNAL_ZIF_PROP_DVBT_MASK;
               prop->dtv_internal_zif.dvbc   = (data >> Si2141_DTV_INTERNAL_ZIF_PROP_DVBC_LSB  ) & Si2141_DTV_INTERNAL_ZIF_PROP_DVBC_MASK;
               prop->dtv_internal_zif.isdbt  = (data >> Si2141_DTV_INTERNAL_ZIF_PROP_ISDBT_LSB ) & Si2141_DTV_INTERNAL_ZIF_PROP_ISDBT_MASK;
               prop->dtv_internal_zif.isdbc  = (data >> Si2141_DTV_INTERNAL_ZIF_PROP_ISDBC_LSB ) & Si2141_DTV_INTERNAL_ZIF_PROP_ISDBC_MASK;
               prop->dtv_internal_zif.dtmb   = (data >> Si2141_DTV_INTERNAL_ZIF_PROP_DTMB_LSB  ) & Si2141_DTV_INTERNAL_ZIF_PROP_DTMB_MASK;
     break;
    #endif /*     Si2141_DTV_INTERNAL_ZIF_PROP */
    #ifdef        Si2141_DTV_LIF_FREQ_PROP
     case         Si2141_DTV_LIF_FREQ_PROP_CODE:
               prop->dtv_lif_freq.offset = (data >> Si2141_DTV_LIF_FREQ_PROP_OFFSET_LSB) & Si2141_DTV_LIF_FREQ_PROP_OFFSET_MASK;
     break;
    #endif /*     Si2141_DTV_LIF_FREQ_PROP */
    #ifdef        Si2141_DTV_LIF_OUT_PROP
     case         Si2141_DTV_LIF_OUT_PROP_CODE:
               prop->dtv_lif_out.offset = (data >> Si2141_DTV_LIF_OUT_PROP_OFFSET_LSB) & Si2141_DTV_LIF_OUT_PROP_OFFSET_MASK;
               prop->dtv_lif_out.amp    = (data >> Si2141_DTV_LIF_OUT_PROP_AMP_LSB   ) & Si2141_DTV_LIF_OUT_PROP_AMP_MASK;
     break;
    #endif /*     Si2141_DTV_LIF_OUT_PROP */
    #ifdef        Si2141_DTV_MODE_PROP
     case         Si2141_DTV_MODE_PROP_CODE:
               prop->dtv_mode.bw              = (data >> Si2141_DTV_MODE_PROP_BW_LSB             ) & Si2141_DTV_MODE_PROP_BW_MASK;
               prop->dtv_mode.modulation      = (data >> Si2141_DTV_MODE_PROP_MODULATION_LSB     ) & Si2141_DTV_MODE_PROP_MODULATION_MASK;
               prop->dtv_mode.invert_spectrum = (data >> Si2141_DTV_MODE_PROP_INVERT_SPECTRUM_LSB) & Si2141_DTV_MODE_PROP_INVERT_SPECTRUM_MASK;
     break;
    #endif /*     Si2141_DTV_MODE_PROP */
    #ifdef        Si2141_DTV_PGA_LIMITS_PROP
     case         Si2141_DTV_PGA_LIMITS_PROP_CODE:
               prop->dtv_pga_limits.min = (data >> Si2141_DTV_PGA_LIMITS_PROP_MIN_LSB) & Si2141_DTV_PGA_LIMITS_PROP_MIN_MASK;
               prop->dtv_pga_limits.max = (data >> Si2141_DTV_PGA_LIMITS_PROP_MAX_LSB) & Si2141_DTV_PGA_LIMITS_PROP_MAX_MASK;
     break;
    #endif /*     Si2141_DTV_PGA_LIMITS_PROP */
    #ifdef        Si2141_DTV_PGA_TARGET_PROP
     case         Si2141_DTV_PGA_TARGET_PROP_CODE:
               prop->dtv_pga_target.pga_target      = (data >> Si2141_DTV_PGA_TARGET_PROP_PGA_TARGET_LSB     ) & Si2141_DTV_PGA_TARGET_PROP_PGA_TARGET_MASK;
               prop->dtv_pga_target.override_enable = (data >> Si2141_DTV_PGA_TARGET_PROP_OVERRIDE_ENABLE_LSB) & Si2141_DTV_PGA_TARGET_PROP_OVERRIDE_ENABLE_MASK;
     break;
    #endif /*     Si2141_DTV_PGA_TARGET_PROP */
    #ifdef        Si2141_DTV_RF_AGC_SPEED_PROP
     case         Si2141_DTV_RF_AGC_SPEED_PROP_CODE:
               prop->dtv_rf_agc_speed.attack = (data >> Si2141_DTV_RF_AGC_SPEED_PROP_ATTACK_LSB) & Si2141_DTV_RF_AGC_SPEED_PROP_ATTACK_MASK;
               prop->dtv_rf_agc_speed.decay  = (data >> Si2141_DTV_RF_AGC_SPEED_PROP_DECAY_LSB ) & Si2141_DTV_RF_AGC_SPEED_PROP_DECAY_MASK;
     break;
    #endif /*     Si2141_DTV_RF_AGC_SPEED_PROP */
    #ifdef        Si2141_DTV_RF_TOP_PROP
     case         Si2141_DTV_RF_TOP_PROP_CODE:
               prop->dtv_rf_top.dtv_rf_top = (data >> Si2141_DTV_RF_TOP_PROP_DTV_RF_TOP_LSB) & Si2141_DTV_RF_TOP_PROP_DTV_RF_TOP_MASK;
     break;
    #endif /*     Si2141_DTV_RF_TOP_PROP */
    #ifdef        Si2141_DTV_RSQ_RSSI_THRESHOLD_PROP
     case         Si2141_DTV_RSQ_RSSI_THRESHOLD_PROP_CODE:
               prop->dtv_rsq_rssi_threshold.lo = (data >> Si2141_DTV_RSQ_RSSI_THRESHOLD_PROP_LO_LSB) & Si2141_DTV_RSQ_RSSI_THRESHOLD_PROP_LO_MASK;
     break;
    #endif /*     Si2141_DTV_RSQ_RSSI_THRESHOLD_PROP */
    #ifdef        Si2141_DTV_WB_AGC_SPEED_PROP
     case         Si2141_DTV_WB_AGC_SPEED_PROP_CODE:
               prop->dtv_wb_agc_speed.attack = (data >> Si2141_DTV_WB_AGC_SPEED_PROP_ATTACK_LSB) & Si2141_DTV_WB_AGC_SPEED_PROP_ATTACK_MASK;
               prop->dtv_wb_agc_speed.decay  = (data >> Si2141_DTV_WB_AGC_SPEED_PROP_DECAY_LSB ) & Si2141_DTV_WB_AGC_SPEED_PROP_DECAY_MASK;
     break;
    #endif /*     Si2141_DTV_WB_AGC_SPEED_PROP */
    #ifdef        Si2141_TUNER_BLOCKED_VCO_PROP
     case         Si2141_TUNER_BLOCKED_VCO_PROP_CODE:
               prop->tuner_blocked_vco.vco_code = (data >> Si2141_TUNER_BLOCKED_VCO_PROP_VCO_CODE_LSB) & Si2141_TUNER_BLOCKED_VCO_PROP_VCO_CODE_MASK;
     break;
    #endif /*     Si2141_TUNER_BLOCKED_VCO_PROP */
    #ifdef        Si2141_TUNER_BLOCKED_VCO2_PROP
     case         Si2141_TUNER_BLOCKED_VCO2_PROP_CODE:
               prop->tuner_blocked_vco2.vco_code = (data >> Si2141_TUNER_BLOCKED_VCO2_PROP_VCO_CODE_LSB) & Si2141_TUNER_BLOCKED_VCO2_PROP_VCO_CODE_MASK;
     break;
    #endif /*     Si2141_TUNER_BLOCKED_VCO2_PROP */
    #ifdef        Si2141_TUNER_BLOCKED_VCO3_PROP
     case         Si2141_TUNER_BLOCKED_VCO3_PROP_CODE:
               prop->tuner_blocked_vco3.vco_code = (data >> Si2141_TUNER_BLOCKED_VCO3_PROP_VCO_CODE_LSB) & Si2141_TUNER_BLOCKED_VCO3_PROP_VCO_CODE_MASK;
     break;
    #endif /*     Si2141_TUNER_BLOCKED_VCO3_PROP */
    #ifdef        Si2141_TUNER_LO_INJECTION_PROP
     case         Si2141_TUNER_LO_INJECTION_PROP_CODE:
               prop->tuner_lo_injection.band_1 = (data >> Si2141_TUNER_LO_INJECTION_PROP_BAND_1_LSB) & Si2141_TUNER_LO_INJECTION_PROP_BAND_1_MASK;
               prop->tuner_lo_injection.band_2 = (data >> Si2141_TUNER_LO_INJECTION_PROP_BAND_2_LSB) & Si2141_TUNER_LO_INJECTION_PROP_BAND_2_MASK;
               prop->tuner_lo_injection.band_3 = (data >> Si2141_TUNER_LO_INJECTION_PROP_BAND_3_LSB) & Si2141_TUNER_LO_INJECTION_PROP_BAND_3_MASK;
     break;
    #endif /*     Si2141_TUNER_LO_INJECTION_PROP */
    #ifdef        Si2141_TUNER_RETURN_LOSS_PROP
     case         Si2141_TUNER_RETURN_LOSS_PROP_CODE:
               prop->tuner_return_loss.config   = (data >> Si2141_TUNER_RETURN_LOSS_PROP_CONFIG_LSB  ) & Si2141_TUNER_RETURN_LOSS_PROP_CONFIG_MASK;
               prop->tuner_return_loss.mode     = (data >> Si2141_TUNER_RETURN_LOSS_PROP_MODE_LSB    ) & Si2141_TUNER_RETURN_LOSS_PROP_MODE_MASK;
               prop->tuner_return_loss.reserved = (data >> Si2141_TUNER_RETURN_LOSS_PROP_RESERVED_LSB) & Si2141_TUNER_RETURN_LOSS_PROP_RESERVED_MASK;
     break;
    #endif /*     Si2141_TUNER_RETURN_LOSS_PROP */
    #ifdef        Si2141_XOUT_PROP
     case         Si2141_XOUT_PROP_CODE:
               prop->xout.amp = (data >> Si2141_XOUT_PROP_AMP_LSB) & Si2141_XOUT_PROP_AMP_MASK;
     break;
    #endif /*     Si2141_XOUT_PROP */
     default : return ERROR_Si2141_UNKNOWN_PROPERTY; break;
    }
    return NO_Si2141_ERROR;
}
/***********************************************************************************************************************
  Si2141_storePropertiesDefaults function
  Use:        property defaults function
              Used to fill the propShadow structure with startup values.
  Parameter: *prop     the Si2141_PropObject structure

 |---------------------------------------------------------------------------------------------------------------------|
 | Do NOT change this code unless you really know what you're doing!                                                   |
 | It should reflect the part internal property settings after firmware download                                       |
 |---------------------------------------------------------------------------------------------------------------------|

 Returns:    void
 ***********************************************************************************************************************/
void          Si2141_storePropertiesDefaults (Si2141_PropObj   *prop) {
  SiTRACE("Si2141_storePropertiesDefaults\n");
#ifdef    Si2141_CRYSTAL_TRIM_PROP
  prop->crystal_trim.xo_cap                            = Si2141_CRYSTAL_TRIM_PROP_XO_CAP_6P7PF ; /* (default '6p7pF') */
#endif /* Si2141_CRYSTAL_TRIM_PROP */

#ifdef    Si2141_XOUT_PROP
  prop->xout.amp                                       = Si2141_XOUT_PROP_AMP_HIGH ; /* (default 'HIGH') */
#endif /* Si2141_XOUT_PROP */

#ifdef    Si2141_DTV_AGC_AUTO_FREEZE_PROP
  prop->dtv_agc_auto_freeze.thld                       =   255; /* (default   255) */
  prop->dtv_agc_auto_freeze.timeout                    =     1; /* (default     1) */
#endif /* Si2141_DTV_AGC_AUTO_FREEZE_PROP */

#ifdef    Si2141_DTV_AGC_SPEED_PROP
  prop->dtv_agc_speed.if_agc_speed                     = Si2141_DTV_AGC_SPEED_PROP_IF_AGC_SPEED_AUTO ; /* (default 'AUTO') */
  prop->dtv_agc_speed.agc_decim                        = Si2141_DTV_AGC_SPEED_PROP_AGC_DECIM_OFF     ; /* (default 'OFF') */
#endif /* Si2141_DTV_AGC_SPEED_PROP */

#ifdef    Si2141_DTV_CONFIG_IF_PORT_PROP
  prop->dtv_config_if_port.dtv_out_type                = Si2141_DTV_CONFIG_IF_PORT_PROP_DTV_OUT_TYPE_LIF_IF ; /* (default 'LIF_IF') */
#endif /* Si2141_DTV_CONFIG_IF_PORT_PROP */

#ifdef    Si2141_DTV_EXT_AGC_PROP
  prop->dtv_ext_agc.min_10mv                           =    50; /* (default    50) */
  prop->dtv_ext_agc.max_10mv                           =   200; /* (default   200) */
#endif /* Si2141_DTV_EXT_AGC_PROP */

#ifdef    Si2141_DTV_IF_AGC_SPEED_PROP
  prop->dtv_if_agc_speed.attack                        = Si2141_DTV_IF_AGC_SPEED_PROP_ATTACK_AUTO ; /* (default 'AUTO') */
  prop->dtv_if_agc_speed.decay                         = Si2141_DTV_IF_AGC_SPEED_PROP_DECAY_AUTO  ; /* (default 'AUTO') */
#endif /* Si2141_DTV_IF_AGC_SPEED_PROP */

#ifdef    Si2141_DTV_INITIAL_AGC_SPEED_PROP
  prop->dtv_initial_agc_speed.if_agc_speed             = Si2141_DTV_INITIAL_AGC_SPEED_PROP_IF_AGC_SPEED_AUTO ; /* (default 'AUTO') */
  prop->dtv_initial_agc_speed.agc_decim                = Si2141_DTV_INITIAL_AGC_SPEED_PROP_AGC_DECIM_OFF     ; /* (default 'OFF') */
#endif /* Si2141_DTV_INITIAL_AGC_SPEED_PROP */

#ifdef    Si2141_DTV_INITIAL_AGC_SPEED_PERIOD_PROP
  prop->dtv_initial_agc_speed_period.period            =     0; /* (default     0) */
#endif /* Si2141_DTV_INITIAL_AGC_SPEED_PERIOD_PROP */

#ifdef    Si2141_DTV_INTERNAL_ZIF_PROP
  prop->dtv_internal_zif.atsc                          = Si2141_DTV_INTERNAL_ZIF_PROP_ATSC_ZIF   ; /* (default 'ZIF') */
  prop->dtv_internal_zif.qam_us                        = Si2141_DTV_INTERNAL_ZIF_PROP_QAM_US_ZIF ; /* (default 'ZIF') */
  prop->dtv_internal_zif.dvbt                          = Si2141_DTV_INTERNAL_ZIF_PROP_DVBT_ZIF   ; /* (default 'ZIF') */
  prop->dtv_internal_zif.dvbc                          = Si2141_DTV_INTERNAL_ZIF_PROP_DVBC_ZIF   ; /* (default 'ZIF') */
  prop->dtv_internal_zif.isdbt                         = Si2141_DTV_INTERNAL_ZIF_PROP_ISDBT_ZIF  ; /* (default 'ZIF') */
  prop->dtv_internal_zif.isdbc                         = Si2141_DTV_INTERNAL_ZIF_PROP_ISDBC_ZIF  ; /* (default 'ZIF') */
  prop->dtv_internal_zif.dtmb                          = Si2141_DTV_INTERNAL_ZIF_PROP_DTMB_LIF   ; /* (default 'LIF') */
#endif /* Si2141_DTV_INTERNAL_ZIF_PROP */

#ifdef    Si2141_DTV_LIF_FREQ_PROP
  prop->dtv_lif_freq.offset                            =  5000; /* (default  5000) */
#endif /* Si2141_DTV_LIF_FREQ_PROP */

#ifdef    Si2141_DTV_LIF_OUT_PROP
  prop->dtv_lif_out.offset                             =   148; /* (default   148) */
  prop->dtv_lif_out.amp                                =    27; /* (default    27) */
#endif /* Si2141_DTV_LIF_OUT_PROP */

#ifdef    Si2141_DTV_MODE_PROP
  prop->dtv_mode.bw                                    = Si2141_DTV_MODE_PROP_BW_BW_8MHZ              ; /* (default 'BW_8MHZ') */
  prop->dtv_mode.modulation                            = Si2141_DTV_MODE_PROP_MODULATION_DVBT         ; /* (default 'DVBT') */
  prop->dtv_mode.invert_spectrum                       = Si2141_DTV_MODE_PROP_INVERT_SPECTRUM_NORMAL  ; /* (default 'NORMAL') */
#endif /* Si2141_DTV_MODE_PROP */

#ifdef    Si2141_DTV_PGA_LIMITS_PROP
  prop->dtv_pga_limits.min                             =    -1; /* (default    -1) */
  prop->dtv_pga_limits.max                             =    -1; /* (default    -1) */
#endif /* Si2141_DTV_PGA_LIMITS_PROP */

#ifdef    Si2141_DTV_PGA_TARGET_PROP
  prop->dtv_pga_target.pga_target                      =     0; /* (default     0) */
  prop->dtv_pga_target.override_enable                 = Si2141_DTV_PGA_TARGET_PROP_OVERRIDE_ENABLE_DISABLE ; /* (default 'DISABLE') */
#endif /* Si2141_DTV_PGA_TARGET_PROP */

#ifdef    Si2141_DTV_RF_AGC_SPEED_PROP
  prop->dtv_rf_agc_speed.attack                        = Si2141_DTV_RF_AGC_SPEED_PROP_ATTACK_AUTO ; /* (default 'AUTO') */
  prop->dtv_rf_agc_speed.decay                         = Si2141_DTV_RF_AGC_SPEED_PROP_DECAY_AUTO  ; /* (default 'AUTO') */
#endif /* Si2141_DTV_RF_AGC_SPEED_PROP */

#ifdef    Si2141_DTV_RF_TOP_PROP
  prop->dtv_rf_top.dtv_rf_top                          = Si2141_DTV_RF_TOP_PROP_DTV_RF_TOP_AUTO ; /* (default 'AUTO') */
#endif /* Si2141_DTV_RF_TOP_PROP */

#ifdef    Si2141_DTV_RSQ_RSSI_THRESHOLD_PROP
  prop->dtv_rsq_rssi_threshold.lo                      =   -80; /* (default   -80) */
#endif /* Si2141_DTV_RSQ_RSSI_THRESHOLD_PROP */

#ifdef    Si2141_DTV_WB_AGC_SPEED_PROP
  prop->dtv_wb_agc_speed.attack                        = Si2141_DTV_WB_AGC_SPEED_PROP_ATTACK_AUTO ; /* (default 'AUTO') */
  prop->dtv_wb_agc_speed.decay                         = Si2141_DTV_WB_AGC_SPEED_PROP_DECAY_AUTO  ; /* (default 'AUTO') */
#endif /* Si2141_DTV_WB_AGC_SPEED_PROP */

#ifdef    Si2141_TUNER_BLOCKED_VCO_PROP
  prop->tuner_blocked_vco.vco_code                     = 0x8000; /* (default 0x8000) */
#endif /* Si2141_TUNER_BLOCKED_VCO_PROP */

#ifdef    Si2141_TUNER_BLOCKED_VCO2_PROP
  prop->tuner_blocked_vco2.vco_code                    = 0x8000; /* (default 0x8000) */
#endif /* Si2141_TUNER_BLOCKED_VCO2_PROP */

#ifdef    Si2141_TUNER_BLOCKED_VCO3_PROP
  prop->tuner_blocked_vco3.vco_code                    = 0x8000; /* (default 0x8000) */
#endif /* Si2141_TUNER_BLOCKED_VCO3_PROP */

#ifdef    Si2141_TUNER_LO_INJECTION_PROP
  prop->tuner_lo_injection.band_1                      = Si2141_TUNER_LO_INJECTION_PROP_BAND_1_HIGH_SIDE ; /* (default 'HIGH_SIDE') */
  prop->tuner_lo_injection.band_2                      = Si2141_TUNER_LO_INJECTION_PROP_BAND_2_LOW_SIDE  ; /* (default 'LOW_SIDE') */
  prop->tuner_lo_injection.band_3                      = Si2141_TUNER_LO_INJECTION_PROP_BAND_3_LOW_SIDE  ; /* (default 'LOW_SIDE') */
#endif /* Si2141_TUNER_LO_INJECTION_PROP */

#ifdef    Si2141_TUNER_RETURN_LOSS_PROP
  prop->tuner_return_loss.config                       = Si2141_TUNER_RETURN_LOSS_PROP_CONFIG_127           ; /* (default '127') */
  prop->tuner_return_loss.mode                         = Si2141_TUNER_RETURN_LOSS_PROP_MODE_TERRESTRIAL     ; /* (default 'TERRESTRIAL') */
  prop->tuner_return_loss.reserved                     = Si2141_TUNER_RETURN_LOSS_PROP_RESERVED_RESERVED    ; /* (default 'RESERVED') */
#endif /* Si2141_TUNER_RETURN_LOSS_PROP */

}
#ifdef    Si2141_GET_PROPERTY_STRING
/***********************************************************************************************************************
  Si2141_L1_PropertyText function
  Use:        property text function
              Used to turn the property data into clear text.
  Parameter: *prop     the Si2141 property structure (containing all properties)
  Parameter: prop_code the property Id (used to know which property to use)
  Parameter: separator the string to use between fields (often either a blank or a newline character)
  Parameter: msg       the string used to store the resulting string
  Returns:    NO_Si2141_ERROR if successful.
 ***********************************************************************************************************************/
unsigned char Si2141_L1_PropertyText          (Si2141_PropObj   *prop, unsigned int prop_code, const char *separator, char *msg) {
    switch (prop_code) {
    #ifdef        Si2141_CRYSTAL_TRIM_PROP
     case         Si2141_CRYSTAL_TRIM_PROP_CODE:
      sprintf(msg,"CRYSTAL_TRIM");
       strcat(msg,separator); strcat(msg,"-XO_CAP ");
           if  (prop->crystal_trim.xo_cap ==     0) strcat(msg,"4p7pF  ");
      else if  (prop->crystal_trim.xo_cap ==     1) strcat(msg,"4p95pF ");
      else if  (prop->crystal_trim.xo_cap ==     2) strcat(msg,"5p2pF  ");
      else if  (prop->crystal_trim.xo_cap ==     3) strcat(msg,"5p45pF ");
      else if  (prop->crystal_trim.xo_cap ==     4) strcat(msg,"5p7pF  ");
      else if  (prop->crystal_trim.xo_cap ==     5) strcat(msg,"5p95pF ");
      else if  (prop->crystal_trim.xo_cap ==     6) strcat(msg,"6p2pF  ");
      else if  (prop->crystal_trim.xo_cap ==     7) strcat(msg,"6p45pF ");
      else if  (prop->crystal_trim.xo_cap ==     8) strcat(msg,"6p7pF  ");
      else if  (prop->crystal_trim.xo_cap ==     9) strcat(msg,"6p95pF ");
      else if  (prop->crystal_trim.xo_cap ==    10) strcat(msg,"7p2pF  ");
      else if  (prop->crystal_trim.xo_cap ==    11) strcat(msg,"7p45pF ");
      else if  (prop->crystal_trim.xo_cap ==    12) strcat(msg,"7p7pF  ");
      else if  (prop->crystal_trim.xo_cap ==    13) strcat(msg,"7p95pF ");
      else if  (prop->crystal_trim.xo_cap ==    14) strcat(msg,"8p2pF  ");
      else if  (prop->crystal_trim.xo_cap ==    15) strcat(msg,"8p45pF ");
      else                                         sprintf(msg,"%s%d", msg, prop->crystal_trim.xo_cap);
     break;
    #endif /*     Si2141_CRYSTAL_TRIM_PROP */
    #ifdef        Si2141_DTV_AGC_AUTO_FREEZE_PROP
     case         Si2141_DTV_AGC_AUTO_FREEZE_PROP_CODE:
      sprintf(msg,"DTV_AGC_AUTO_FREEZE");
       strcat(msg,separator); strcat(msg,"-THLD "); sprintf(msg,"%s%d", msg, prop->dtv_agc_auto_freeze.thld);
       strcat(msg,separator); strcat(msg,"-TIMEOUT "); sprintf(msg,"%s%d", msg, prop->dtv_agc_auto_freeze.timeout);
     break;
    #endif /*     Si2141_DTV_AGC_AUTO_FREEZE_PROP */
    #ifdef        Si2141_DTV_AGC_SPEED_PROP
     case         Si2141_DTV_AGC_SPEED_PROP_CODE:
      sprintf(msg,"DTV_AGC_SPEED");
       strcat(msg,separator); strcat(msg,"-IF_AGC_SPEED ");
           if  (prop->dtv_agc_speed.if_agc_speed ==     0) strcat(msg,"AUTO ");
      else if  (prop->dtv_agc_speed.if_agc_speed ==    39) strcat(msg,"39   ");
      else if  (prop->dtv_agc_speed.if_agc_speed ==    54) strcat(msg,"54   ");
      else if  (prop->dtv_agc_speed.if_agc_speed ==    63) strcat(msg,"63   ");
      else if  (prop->dtv_agc_speed.if_agc_speed ==    89) strcat(msg,"89   ");
      else if  (prop->dtv_agc_speed.if_agc_speed ==   105) strcat(msg,"105  ");
      else if  (prop->dtv_agc_speed.if_agc_speed ==   121) strcat(msg,"121  ");
      else if  (prop->dtv_agc_speed.if_agc_speed ==   137) strcat(msg,"137  ");
      else if  (prop->dtv_agc_speed.if_agc_speed ==   158) strcat(msg,"158  ");
      else if  (prop->dtv_agc_speed.if_agc_speed ==   172) strcat(msg,"172  ");
      else if  (prop->dtv_agc_speed.if_agc_speed ==   185) strcat(msg,"185  ");
      else if  (prop->dtv_agc_speed.if_agc_speed ==   196) strcat(msg,"196  ");
      else if  (prop->dtv_agc_speed.if_agc_speed ==   206) strcat(msg,"206  ");
      else if  (prop->dtv_agc_speed.if_agc_speed ==   216) strcat(msg,"216  ");
      else if  (prop->dtv_agc_speed.if_agc_speed ==   219) strcat(msg,"219  ");
      else if  (prop->dtv_agc_speed.if_agc_speed ==   222) strcat(msg,"222  ");
      else                                                sprintf(msg,"%s%d", msg, prop->dtv_agc_speed.if_agc_speed);
       strcat(msg,separator); strcat(msg,"-AGC_DECIM ");
           if  (prop->dtv_agc_speed.agc_decim    ==     0) strcat(msg,"OFF ");
      else if  (prop->dtv_agc_speed.agc_decim    ==     1) strcat(msg,"2   ");
      else if  (prop->dtv_agc_speed.agc_decim    ==     2) strcat(msg,"4   ");
      else if  (prop->dtv_agc_speed.agc_decim    ==     3) strcat(msg,"8   ");
      else                                                sprintf(msg,"%s%d", msg, prop->dtv_agc_speed.agc_decim);
     break;
    #endif /*     Si2141_DTV_AGC_SPEED_PROP */
    #ifdef        Si2141_DTV_CONFIG_IF_PORT_PROP
     case         Si2141_DTV_CONFIG_IF_PORT_PROP_CODE:
      sprintf(msg,"DTV_CONFIG_IF_PORT");
       strcat(msg,separator); strcat(msg,"-DTV_OUT_TYPE ");
           if  (prop->dtv_config_if_port.dtv_out_type ==     0) strcat(msg,"LIF_IF     ");
      else if  (prop->dtv_config_if_port.dtv_out_type ==     4) strcat(msg,"LIF_SE_IFA ");
      else                                                     sprintf(msg,"%s%d", msg, prop->dtv_config_if_port.dtv_out_type);
     break;
    #endif /*     Si2141_DTV_CONFIG_IF_PORT_PROP */
    #ifdef        Si2141_DTV_EXT_AGC_PROP
     case         Si2141_DTV_EXT_AGC_PROP_CODE:
      sprintf(msg,"DTV_EXT_AGC");
       strcat(msg,separator); strcat(msg,"-MIN_10MV "); sprintf(msg,"%s%d", msg, prop->dtv_ext_agc.min_10mv);
       strcat(msg,separator); strcat(msg,"-MAX_10MV "); sprintf(msg,"%s%d", msg, prop->dtv_ext_agc.max_10mv);
     break;
    #endif /*     Si2141_DTV_EXT_AGC_PROP */
    #ifdef        Si2141_DTV_IF_AGC_SPEED_PROP
     case         Si2141_DTV_IF_AGC_SPEED_PROP_CODE:
      sprintf(msg,"DTV_IF_AGC_SPEED");
       strcat(msg,separator); strcat(msg,"-ATTACK ");
           if  (prop->dtv_if_agc_speed.attack ==     0) strcat(msg,"AUTO ");
      else                                             sprintf(msg,"%s%d", prop->dtv_if_agc_speed.attack);
       strcat(msg,separator); strcat(msg,"-DECAY ");
           if  (prop->dtv_if_agc_speed.decay  ==     0) strcat(msg,"AUTO ");
      else                                             sprintf(msg,"%s%d", prop->dtv_if_agc_speed.decay);
     break;
    #endif /*     Si2141_DTV_IF_AGC_SPEED_PROP */
    #ifdef        Si2141_DTV_INITIAL_AGC_SPEED_PROP
     case         Si2141_DTV_INITIAL_AGC_SPEED_PROP_CODE:
      sprintf(msg,"DTV_INITIAL_AGC_SPEED");
       strcat(msg,separator); strcat(msg,"-IF_AGC_SPEED ");
           if  (prop->dtv_initial_agc_speed.if_agc_speed ==     0) strcat(msg,"AUTO ");
      else if  (prop->dtv_initial_agc_speed.if_agc_speed ==    39) strcat(msg,"39   ");
      else if  (prop->dtv_initial_agc_speed.if_agc_speed ==    54) strcat(msg,"54   ");
      else if  (prop->dtv_initial_agc_speed.if_agc_speed ==    63) strcat(msg,"63   ");
      else if  (prop->dtv_initial_agc_speed.if_agc_speed ==    89) strcat(msg,"89   ");
      else if  (prop->dtv_initial_agc_speed.if_agc_speed ==   105) strcat(msg,"105  ");
      else if  (prop->dtv_initial_agc_speed.if_agc_speed ==   121) strcat(msg,"121  ");
      else if  (prop->dtv_initial_agc_speed.if_agc_speed ==   137) strcat(msg,"137  ");
      else if  (prop->dtv_initial_agc_speed.if_agc_speed ==   158) strcat(msg,"158  ");
      else if  (prop->dtv_initial_agc_speed.if_agc_speed ==   172) strcat(msg,"172  ");
      else if  (prop->dtv_initial_agc_speed.if_agc_speed ==   185) strcat(msg,"185  ");
      else if  (prop->dtv_initial_agc_speed.if_agc_speed ==   196) strcat(msg,"196  ");
      else if  (prop->dtv_initial_agc_speed.if_agc_speed ==   206) strcat(msg,"206  ");
      else if  (prop->dtv_initial_agc_speed.if_agc_speed ==   216) strcat(msg,"216  ");
      else if  (prop->dtv_initial_agc_speed.if_agc_speed ==   219) strcat(msg,"219  ");
      else if  (prop->dtv_initial_agc_speed.if_agc_speed ==   222) strcat(msg,"222  ");
      else                                                        sprintf(msg,"%s%d", msg, prop->dtv_initial_agc_speed.if_agc_speed);
       strcat(msg,separator); strcat(msg,"-AGC_DECIM ");
           if  (prop->dtv_initial_agc_speed.agc_decim    ==     0) strcat(msg,"OFF ");
      else if  (prop->dtv_initial_agc_speed.agc_decim    ==     1) strcat(msg,"2   ");
      else if  (prop->dtv_initial_agc_speed.agc_decim    ==     2) strcat(msg,"4   ");
      else if  (prop->dtv_initial_agc_speed.agc_decim    ==     3) strcat(msg,"8   ");
      else                                                        sprintf(msg,"%s%d", msg, prop->dtv_initial_agc_speed.agc_decim);
     break;
    #endif /*     Si2141_DTV_INITIAL_AGC_SPEED_PROP */
    #ifdef        Si2141_DTV_INITIAL_AGC_SPEED_PERIOD_PROP
     case         Si2141_DTV_INITIAL_AGC_SPEED_PERIOD_PROP_CODE:
      sprintf(msg,"DTV_INITIAL_AGC_SPEED_PERIOD");
       strcat(msg,separator); strcat(msg,"-PERIOD "); sprintf(msg,"%s%d", msg, prop->dtv_initial_agc_speed_period.period);
     break;
    #endif /*     Si2141_DTV_INITIAL_AGC_SPEED_PERIOD_PROP */
    #ifdef        Si2141_DTV_INTERNAL_ZIF_PROP
     case         Si2141_DTV_INTERNAL_ZIF_PROP_CODE:
      sprintf(msg,"DTV_INTERNAL_ZIF");
       strcat(msg,separator); strcat(msg,"-ATSC ");
           if  (prop->dtv_internal_zif.atsc   ==     0) strcat(msg,"LIF ");
      else if  (prop->dtv_internal_zif.atsc   ==     1) strcat(msg,"ZIF ");
      else                                             sprintf(msg,"%s%d", msg, prop->dtv_internal_zif.atsc);
       strcat(msg,separator); strcat(msg,"-QAM_US ");
           if  (prop->dtv_internal_zif.qam_us ==     0) strcat(msg,"LIF ");
      else if  (prop->dtv_internal_zif.qam_us ==     1) strcat(msg,"ZIF ");
      else                                             sprintf(msg,"%s%d", msg, prop->dtv_internal_zif.qam_us);
       strcat(msg,separator); strcat(msg,"-DVBT ");
           if  (prop->dtv_internal_zif.dvbt   ==     0) strcat(msg,"LIF ");
      else if  (prop->dtv_internal_zif.dvbt   ==     1) strcat(msg,"ZIF ");
      else                                             sprintf(msg,"%s%d", msg, prop->dtv_internal_zif.dvbt);
       strcat(msg,separator); strcat(msg,"-DVBC ");
           if  (prop->dtv_internal_zif.dvbc   ==     0) strcat(msg,"LIF ");
      else if  (prop->dtv_internal_zif.dvbc   ==     1) strcat(msg,"ZIF ");
      else                                             sprintf(msg,"%s%d", msg, prop->dtv_internal_zif.dvbc);
       strcat(msg,separator); strcat(msg,"-ISDBT ");
           if  (prop->dtv_internal_zif.isdbt  ==     0) strcat(msg,"LIF ");
      else if  (prop->dtv_internal_zif.isdbt  ==     1) strcat(msg,"ZIF ");
      else                                             sprintf(msg,"%s%d", msg, prop->dtv_internal_zif.isdbt);
       strcat(msg,separator); strcat(msg,"-ISDBC ");
           if  (prop->dtv_internal_zif.isdbc  ==     0) strcat(msg,"LIF ");
      else if  (prop->dtv_internal_zif.isdbc  ==     1) strcat(msg,"ZIF ");
      else                                             sprintf(msg,"%s%d", msg, prop->dtv_internal_zif.isdbc);
       strcat(msg,separator); strcat(msg,"-DTMB ");
           if  (prop->dtv_internal_zif.dtmb   ==     0) strcat(msg,"LIF ");
      else if  (prop->dtv_internal_zif.dtmb   ==     1) strcat(msg,"ZIF ");
      else                                             sprintf(msg,"%s%d", msg, prop->dtv_internal_zif.dtmb);
     break;
    #endif /*     Si2141_DTV_INTERNAL_ZIF_PROP */
    #ifdef        Si2141_DTV_LIF_FREQ_PROP
     case         Si2141_DTV_LIF_FREQ_PROP_CODE:
      sprintf(msg,"DTV_LIF_FREQ");
       strcat(msg,separator); strcat(msg,"-OFFSET "); sprintf(msg,"%s%d", msg, prop->dtv_lif_freq.offset);
     break;
    #endif /*     Si2141_DTV_LIF_FREQ_PROP */
    #ifdef        Si2141_DTV_LIF_OUT_PROP
     case         Si2141_DTV_LIF_OUT_PROP_CODE:
      sprintf(msg,"DTV_LIF_OUT");
       strcat(msg,separator); strcat(msg,"-OFFSET "); sprintf(msg,"%s%d", msg, prop->dtv_lif_out.offset);
       strcat(msg,separator); strcat(msg,"-AMP "); sprintf(msg,"%s%d", msg, prop->dtv_lif_out.amp);
     break;
    #endif /*     Si2141_DTV_LIF_OUT_PROP */
    #ifdef        Si2141_DTV_MODE_PROP
     case         Si2141_DTV_MODE_PROP_CODE:
      sprintf(msg,"DTV_MODE");
       strcat(msg,separator); strcat(msg,"-BW ");
           if  (prop->dtv_mode.bw              ==     6) strcat(msg,"BW_6MHZ   ");
      else if  (prop->dtv_mode.bw              ==     7) strcat(msg,"BW_7MHZ   ");
      else if  (prop->dtv_mode.bw              ==     8) strcat(msg,"BW_8MHZ   ");
      else if  (prop->dtv_mode.bw              ==     9) strcat(msg,"BW_1P7MHZ ");
      else if  (prop->dtv_mode.bw              ==    10) strcat(msg,"BW_6P1MHZ ");
      else                                              sprintf(msg,"%s%d", msg, prop->dtv_mode.bw);
       strcat(msg,separator); strcat(msg,"-MODULATION ");
           if  (prop->dtv_mode.modulation      ==     0) strcat(msg,"ATSC      ");
      else if  (prop->dtv_mode.modulation      ==     1) strcat(msg,"QAM_US    ");
      else if  (prop->dtv_mode.modulation      ==     2) strcat(msg,"DVBT      ");
      else if  (prop->dtv_mode.modulation      ==     3) strcat(msg,"DVBC      ");
      else if  (prop->dtv_mode.modulation      ==     4) strcat(msg,"ISDBT     ");
      else if  (prop->dtv_mode.modulation      ==     5) strcat(msg,"ISDBC     ");
      else if  (prop->dtv_mode.modulation      ==     6) strcat(msg,"DTMB      ");
      else                                              sprintf(msg,"%s%d", msg, prop->dtv_mode.modulation);
       strcat(msg,separator); strcat(msg,"-INVERT_SPECTRUM ");
           if  (prop->dtv_mode.invert_spectrum ==     0) strcat(msg,"NORMAL   ");
      else if  (prop->dtv_mode.invert_spectrum ==     1) strcat(msg,"INVERTED ");
      else                                              sprintf(msg,"%s%d", msg, prop->dtv_mode.invert_spectrum);
     break;
    #endif /*     Si2141_DTV_MODE_PROP */
    #ifdef        Si2141_DTV_PGA_LIMITS_PROP
     case         Si2141_DTV_PGA_LIMITS_PROP_CODE:
      sprintf(msg,"DTV_PGA_LIMITS");
       strcat(msg,separator); strcat(msg,"-MIN "); sprintf(msg,"%s%d", msg, prop->dtv_pga_limits.min);
       strcat(msg,separator); strcat(msg,"-MAX "); sprintf(msg,"%s%d", msg, prop->dtv_pga_limits.max);
     break;
    #endif /*     Si2141_DTV_PGA_LIMITS_PROP */
    #ifdef        Si2141_DTV_PGA_TARGET_PROP
     case         Si2141_DTV_PGA_TARGET_PROP_CODE:
      sprintf(msg,"DTV_PGA_TARGET");
       strcat(msg,separator); strcat(msg,"-PGA_TARGET "); sprintf(msg,"%s%d", msg, prop->dtv_pga_target.pga_target);
       strcat(msg,separator); strcat(msg,"-OVERRIDE_ENABLE ");
           if  (prop->dtv_pga_target.override_enable ==     0) strcat(msg,"DISABLE ");
      else if  (prop->dtv_pga_target.override_enable ==     1) strcat(msg,"ENABLE  ");
      else                                                    sprintf(msg,"%s%d", msg, prop->dtv_pga_target.override_enable);
     break;
    #endif /*     Si2141_DTV_PGA_TARGET_PROP */
    #ifdef        Si2141_DTV_RF_AGC_SPEED_PROP
     case         Si2141_DTV_RF_AGC_SPEED_PROP_CODE:
      sprintf(msg,"DTV_RF_AGC_SPEED");
       strcat(msg,separator); strcat(msg,"-ATTACK ");
           if  (prop->dtv_rf_agc_speed.attack ==     0) strcat(msg,"AUTO ");
       else                                            sprintf(msg,"%s%d", msg, prop->dtv_rf_agc_speed.attack);
       strcat(msg,separator); strcat(msg,"-DECAY ");
           if  (prop->dtv_rf_agc_speed.decay  ==     0) strcat(msg,"AUTO ");
       else                                            sprintf(msg,"%s%d", msg, prop->dtv_rf_agc_speed.decay);
     break;
    #endif /*     Si2141_DTV_RF_AGC_SPEED_PROP */
    #ifdef        Si2141_DTV_RF_TOP_PROP
     case         Si2141_DTV_RF_TOP_PROP_CODE:
      sprintf(msg,"DTV_RF_TOP");
       strcat(msg,separator); strcat(msg,"-DTV_RF_TOP ");
           if  (prop->dtv_rf_top.dtv_rf_top ==     0) strcat(msg,"AUTO    ");
      else if  (prop->dtv_rf_top.dtv_rf_top ==     1) strcat(msg,"P10DB   ");
      else if  (prop->dtv_rf_top.dtv_rf_top ==     2) strcat(msg,"P9P5DB  ");
      else if  (prop->dtv_rf_top.dtv_rf_top ==     3) strcat(msg,"P9DB    ");
      else if  (prop->dtv_rf_top.dtv_rf_top ==     4) strcat(msg,"P8P5DB  ");
      else if  (prop->dtv_rf_top.dtv_rf_top ==     5) strcat(msg,"P8DB    ");
      else if  (prop->dtv_rf_top.dtv_rf_top ==     6) strcat(msg,"P7P5DB  ");
      else if  (prop->dtv_rf_top.dtv_rf_top ==     7) strcat(msg,"P7DB    ");
      else if  (prop->dtv_rf_top.dtv_rf_top ==     8) strcat(msg,"P6P5DB  ");
      else if  (prop->dtv_rf_top.dtv_rf_top ==     9) strcat(msg,"P6DB    ");
      else if  (prop->dtv_rf_top.dtv_rf_top ==    10) strcat(msg,"P5P5DB  ");
      else if  (prop->dtv_rf_top.dtv_rf_top ==    11) strcat(msg,"P5DB    ");
      else if  (prop->dtv_rf_top.dtv_rf_top ==    12) strcat(msg,"P4P5DB  ");
      else if  (prop->dtv_rf_top.dtv_rf_top ==    13) strcat(msg,"P4DB    ");
      else if  (prop->dtv_rf_top.dtv_rf_top ==    14) strcat(msg,"P3P5DB  ");
      else if  (prop->dtv_rf_top.dtv_rf_top ==    15) strcat(msg,"P3DB    ");
      else if  (prop->dtv_rf_top.dtv_rf_top ==    16) strcat(msg,"P2P5DB  ");
      else if  (prop->dtv_rf_top.dtv_rf_top ==    17) strcat(msg,"P2DB    ");
      else if  (prop->dtv_rf_top.dtv_rf_top ==    18) strcat(msg,"P1P5DB  ");
      else if  (prop->dtv_rf_top.dtv_rf_top ==    19) strcat(msg,"P1DB    ");
      else if  (prop->dtv_rf_top.dtv_rf_top ==    20) strcat(msg,"P0P5DB  ");
      else if  (prop->dtv_rf_top.dtv_rf_top ==    21) strcat(msg,"0DB     ");
      else if  (prop->dtv_rf_top.dtv_rf_top ==    22) strcat(msg,"M0P5DB  ");
      else if  (prop->dtv_rf_top.dtv_rf_top ==    23) strcat(msg,"M1DB    ");
      else if  (prop->dtv_rf_top.dtv_rf_top ==    24) strcat(msg,"M1P5DB  ");
      else if  (prop->dtv_rf_top.dtv_rf_top ==    25) strcat(msg,"M2DB    ");
      else if  (prop->dtv_rf_top.dtv_rf_top ==    26) strcat(msg,"M2P5DB  ");
      else if  (prop->dtv_rf_top.dtv_rf_top ==    27) strcat(msg,"M3DB    ");
      else if  (prop->dtv_rf_top.dtv_rf_top ==    28) strcat(msg,"M3P5DB  ");
      else if  (prop->dtv_rf_top.dtv_rf_top ==    29) strcat(msg,"M4DB    ");
      else if  (prop->dtv_rf_top.dtv_rf_top ==    30) strcat(msg,"M4P5DB  ");
      else if  (prop->dtv_rf_top.dtv_rf_top ==    31) strcat(msg,"M5DB    ");
      else if  (prop->dtv_rf_top.dtv_rf_top ==    32) strcat(msg,"M5P5DB  ");
      else if  (prop->dtv_rf_top.dtv_rf_top ==    33) strcat(msg,"M6DB    ");
      else if  (prop->dtv_rf_top.dtv_rf_top ==    34) strcat(msg,"M6P5DB  ");
      else if  (prop->dtv_rf_top.dtv_rf_top ==    35) strcat(msg,"M7DB    ");
      else if  (prop->dtv_rf_top.dtv_rf_top ==    36) strcat(msg,"M7P5DB  ");
      else if  (prop->dtv_rf_top.dtv_rf_top ==    37) strcat(msg,"M8DB    ");
      else if  (prop->dtv_rf_top.dtv_rf_top ==    38) strcat(msg,"M8P5DB  ");
      else if  (prop->dtv_rf_top.dtv_rf_top ==    39) strcat(msg,"M9DB    ");
      else if  (prop->dtv_rf_top.dtv_rf_top ==    40) strcat(msg,"M9P5DB  ");
      else if  (prop->dtv_rf_top.dtv_rf_top ==    41) strcat(msg,"M10DB   ");
      else if  (prop->dtv_rf_top.dtv_rf_top ==    42) strcat(msg,"M10P5DB ");
      else if  (prop->dtv_rf_top.dtv_rf_top ==    43) strcat(msg,"M11DB   ");
      else if  (prop->dtv_rf_top.dtv_rf_top ==    44) strcat(msg,"M11P5DB ");
      else if  (prop->dtv_rf_top.dtv_rf_top ==    45) strcat(msg,"M12DB   ");
      else if  (prop->dtv_rf_top.dtv_rf_top ==    46) strcat(msg,"M12P5DB ");
      else if  (prop->dtv_rf_top.dtv_rf_top ==    47) strcat(msg,"M13DB   ");
      else if  (prop->dtv_rf_top.dtv_rf_top ==    48) strcat(msg,"M13P5DB ");
      else if  (prop->dtv_rf_top.dtv_rf_top ==    49) strcat(msg,"M14DB   ");
      else if  (prop->dtv_rf_top.dtv_rf_top ==    50) strcat(msg,"M14P5DB ");
      else if  (prop->dtv_rf_top.dtv_rf_top ==    51) strcat(msg,"M15DB   ");
      else if  (prop->dtv_rf_top.dtv_rf_top ==    52) strcat(msg,"M15P5DB ");
      else if  (prop->dtv_rf_top.dtv_rf_top ==    53) strcat(msg,"M16DB   ");
      else if  (prop->dtv_rf_top.dtv_rf_top ==    54) strcat(msg,"M16P5DB ");
      else if  (prop->dtv_rf_top.dtv_rf_top ==    55) strcat(msg,"M17DB   ");
      else if  (prop->dtv_rf_top.dtv_rf_top ==    56) strcat(msg,"M17P5DB ");
      else if  (prop->dtv_rf_top.dtv_rf_top ==    57) strcat(msg,"M18DB   ");
      else if  (prop->dtv_rf_top.dtv_rf_top ==    58) strcat(msg,"M18P5DB ");
      else                                           sprintf(msg,"%s%d", msg, prop->dtv_rf_top.dtv_rf_top);
     break;
    #endif /*     Si2141_DTV_RF_TOP_PROP */
    #ifdef        Si2141_DTV_RSQ_RSSI_THRESHOLD_PROP
     case         Si2141_DTV_RSQ_RSSI_THRESHOLD_PROP_CODE:
      sprintf(msg,"DTV_RSQ_RSSI_THRESHOLD");
       strcat(msg,separator); strcat(msg,"-LO "); sprintf(msg,"%s%d", msg, prop->dtv_rsq_rssi_threshold.lo);
     break;
    #endif /*     Si2141_DTV_RSQ_RSSI_THRESHOLD_PROP */
    #ifdef        Si2141_DTV_WB_AGC_SPEED_PROP
     case         Si2141_DTV_WB_AGC_SPEED_PROP_CODE:
      sprintf(msg,"DTV_WB_AGC_SPEED");
       strcat(msg,separator); strcat(msg,"-ATTACK ");
           if  (prop->dtv_wb_agc_speed.attack ==     0) strcat(msg,"AUTO ");
      else                                             sprintf(msg,"%s%d", prop->dtv_wb_agc_speed.attack);
       strcat(msg,separator); strcat(msg,"-DECAY ");
           if  (prop->dtv_wb_agc_speed.decay  ==     0) strcat(msg,"AUTO ");
      else                                             sprintf(msg,"%s%d", prop->dtv_wb_agc_speed.decay);
     break;
    #endif /*     Si2141_DTV_WB_AGC_SPEED_PROP */
    #ifdef        Si2141_TUNER_BLOCKED_VCO_PROP
     case         Si2141_TUNER_BLOCKED_VCO_PROP_CODE:
      sprintf(msg,"TUNER_BLOCKED_VCO");
       strcat(msg,separator); strcat(msg,"-VCO_CODE "); sprintf(msg,"%s%d", msg, prop->tuner_blocked_vco.vco_code);
     break;
    #endif /*     Si2141_TUNER_BLOCKED_VCO_PROP */
    #ifdef        Si2141_TUNER_BLOCKED_VCO2_PROP
     case         Si2141_TUNER_BLOCKED_VCO2_PROP_CODE:
      sprintf(msg,"TUNER_BLOCKED_VCO2");
       strcat(msg,separator); strcat(msg,"-VCO_CODE "); sprintf(msg,"%s%d", msg, prop->tuner_blocked_vco2.vco_code);
     break;
    #endif /*     Si2141_TUNER_BLOCKED_VCO2_PROP */
    #ifdef        Si2141_TUNER_BLOCKED_VCO3_PROP
     case         Si2141_TUNER_BLOCKED_VCO3_PROP_CODE:
      sprintf(msg,"TUNER_BLOCKED_VCO3");
       strcat(msg,separator); strcat(msg,"-VCO_CODE "); sprintf(msg,"%s%d", msg, prop->tuner_blocked_vco3.vco_code);
     break;
    #endif /*     Si2141_TUNER_BLOCKED_VCO3_PROP */
    #ifdef        Si2141_TUNER_LO_INJECTION_PROP
     case         Si2141_TUNER_LO_INJECTION_PROP_CODE:
      sprintf(msg,"TUNER_LO_INJECTION");
       strcat(msg,separator); strcat(msg,"-BAND_1 ");
           if  (prop->tuner_lo_injection.band_1 ==     0) strcat(msg,"LOW_SIDE  ");
      else if  (prop->tuner_lo_injection.band_1 ==     1) strcat(msg,"HIGH_SIDE ");
      else                                               sprintf(msg,"%s%d", msg, prop->tuner_lo_injection.band_1);
       strcat(msg,separator); strcat(msg,"-BAND_2 ");
           if  (prop->tuner_lo_injection.band_2 ==     0) strcat(msg,"LOW_SIDE  ");
      else if  (prop->tuner_lo_injection.band_2 ==     1) strcat(msg,"HIGH_SIDE ");
      else                                               sprintf(msg,"%s%d", msg, prop->tuner_lo_injection.band_2);
       strcat(msg,separator); strcat(msg,"-BAND_3 ");
           if  (prop->tuner_lo_injection.band_3 ==     0) strcat(msg,"LOW_SIDE  ");
      else if  (prop->tuner_lo_injection.band_3 ==     1) strcat(msg,"HIGH_SIDE ");
      else                                               sprintf(msg,"%s%d", msg, prop->tuner_lo_injection.band_3);
     break;
    #endif /*     Si2141_TUNER_LO_INJECTION_PROP */
    #ifdef        Si2141_TUNER_RETURN_LOSS_PROP
     case         Si2141_TUNER_RETURN_LOSS_PROP_CODE:
      sprintf(msg,"TUNER_RETURN_LOSS");
       strcat(msg,separator); strcat(msg,"-CONFIG ");
           if  (prop->tuner_return_loss.config ==     3) strcat(msg,"3   ");
      else if  (prop->tuner_return_loss.config ==     7) strcat(msg,"7   ");
      else if  (prop->tuner_return_loss.config ==    11) strcat(msg,"11  ");
      else if  (prop->tuner_return_loss.config ==    15) strcat(msg,"15  ");
      else if  (prop->tuner_return_loss.config ==    19) strcat(msg,"19  ");
      else if  (prop->tuner_return_loss.config ==    23) strcat(msg,"23  ");
      else if  (prop->tuner_return_loss.config ==    27) strcat(msg,"27  ");
      else if  (prop->tuner_return_loss.config ==    31) strcat(msg,"31  ");
      else if  (prop->tuner_return_loss.config ==    35) strcat(msg,"35  ");
      else if  (prop->tuner_return_loss.config ==    39) strcat(msg,"39  ");
      else if  (prop->tuner_return_loss.config ==    43) strcat(msg,"43  ");
      else if  (prop->tuner_return_loss.config ==    47) strcat(msg,"47  ");
      else if  (prop->tuner_return_loss.config ==    51) strcat(msg,"51  ");
      else if  (prop->tuner_return_loss.config ==    59) strcat(msg,"59  ");
      else if  (prop->tuner_return_loss.config ==    67) strcat(msg,"67  ");
      else if  (prop->tuner_return_loss.config ==    75) strcat(msg,"75  ");
      else if  (prop->tuner_return_loss.config ==    83) strcat(msg,"83  ");
      else if  (prop->tuner_return_loss.config ==    91) strcat(msg,"91  ");
      else if  (prop->tuner_return_loss.config ==   103) strcat(msg,"103 ");
      else if  (prop->tuner_return_loss.config ==   115) strcat(msg,"115 ");
      else if  (prop->tuner_return_loss.config ==   127) strcat(msg,"127 ");
      else                                              sprintf(msg,"%s%d", msg, prop->tuner_return_loss.config);
       strcat(msg,separator); strcat(msg,"-MODE ");
           if  (prop->tuner_return_loss.mode   ==     0) strcat(msg,"TERRESTRIAL ");
      else if  (prop->tuner_return_loss.mode   ==     1) strcat(msg,"CABLE       ");
      else                                              sprintf(msg,"%s%d", msg, prop->tuner_return_loss.mode);
     break;
    #endif /*     Si2141_TUNER_RETURN_LOSS_PROP */
    #ifdef        Si2141_XOUT_PROP
     case         Si2141_XOUT_PROP_CODE:
      sprintf(msg,"XOUT");
       strcat(msg,separator); strcat(msg,"-AMP ");
           if  (prop->xout.amp ==     0) strcat(msg,"HIGH ");
      else if  (prop->xout.amp ==     1) strcat(msg,"LOW  ");
      else                              sprintf(msg,"%s%d", msg, prop->xout.amp);
     break;
    #endif /*     Si2141_XOUT_PROP */
     default : sprintf(msg,"Unknown property code '0x%06x'\n", prop_code); return ERROR_Si2141_UNKNOWN_PROPERTY; break;
  }
  return NO_Si2141_ERROR;
}
/***********************************************************************************************************************
  Si2141_L1_FillPropertyStringText function
  Use:        property text retrieval function
              Used to retrieve the property text for a selected property.
  Parameter: *api      the Si2141 context
  Parameter: prop_code the property Id (used to know which property to use)
  Parameter: separator the string to use between fields (often either a blank or a newline character)
  Parameter: msg       the string used to store the resulting string (usually declared with a size of 1000 bytes)
  Returns:    NO_Si2141_ERROR if successful.
 ***********************************************************************************************************************/
void          Si2141_L1_FillPropertyStringText(L1_Si2141_Context *api, unsigned int prop_code, const char *separator, char *msg) {
  Si2141_L1_PropertyText (api->prop, prop_code, separator, msg);
}
/***********************************************************************************************************************
  Si2141_L1_GetPropertyString function
  Use:        current property text retrieval function
              Used to retrieve the property value from the hardware then retrieve the corresponding property text.
  Parameter: *api      the Si2141 context
  Parameter: prop_code the property Id (used to know which property to use)
  Parameter: separator the string to use between fields (often either a blank or a newline character)
  Parameter: msg       the string used to store the resulting string (usually declared with a size of 1000 bytes)
  Returns:    NO_Si2141_ERROR if successful.
 ***********************************************************************************************************************/
unsigned char Si2141_L1_GetPropertyString     (L1_Si2141_Context *api, unsigned int prop_code, const char *separator, char *msg) {
    int res;
    res = Si2141_L1_GetProperty2(api,prop_code);
    if (res!=NO_Si2141_ERROR) { sprintf(msg, "%s",Si2141_L1_API_ERROR_TEXT(res)); return res; }
    Si2141_L1_PropertyText(api->prop, prop_code, separator, msg);
    return NO_Si2141_ERROR;
}
#endif /* Si2141_GET_PROPERTY_STRING */








