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
/***************************************************************************************
                  Skyworks Solutions Broadcast Si2151 Layer 3 console application


   L3 sample application header
   FILE: Si2151_L3_Test.h
   Supported IC : Si2151
   Compiled for ROM 61 firmware 1_1_build_11
   Revision: 0.7
   Date: June 09 2022
****************************************************************************************/

#ifndef   Si2151_L3_TEST_H
#define   Si2151_L3_TEST_H

#define   Si2151_COMMAND_PROTOTYPES

#include "Si2151_L2_API.h"
#include "Si2151_Commands_Prototypes.h"

#define   Si2151_BASE_ADDRESS 0xc0
#define   SYSTEM_PAUSE system("pause")

void Si2151_configure_i2c_communication    (L1_Si2151_Context *api);

#ifdef    Si2151_COMMAND_LINE_APPLICATION

int  Si2151_DisplayStatusByte              (L1_Si2151_Context *api);
int  Si2151_GetRevision                    (L1_Si2151_Context *api);
int  Si2151_TunerStatus                    (L1_Si2151_Context *Si2151);
int  Si2151_GetUserFrequency               (unsigned long *fIn);
int  Si2151_help                           (void);
void Si2151_menu                           (unsigned char full);
int  Si2151_demoLoop                       (L1_Si2151_Context *api, char* choice);

#endif /* Si2151_COMMAND_LINE_APPLICATION */

#endif /* Si2151_L3_TEST_H */







