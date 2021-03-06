/* Copyright Statement:
 *
 * @2015 MediaTek Inc. All rights reserved.
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek Inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 *
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
 * RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER ON
 * AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
 * NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
 * SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
 * SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES TO LOOK ONLY TO SUCH
 * THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES
 * THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES
 * CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK
 * SOFTWARE RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND
 * CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
 * AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
 * OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO
 * MEDIATEK FOR SUCH MEDIATEK SOFTWARE.
 */

/**
  * @page low_power_with_psram project guidelines
  * @{

@par Overview

 - Provide an example to measure power consumption on several features
    1.Power OFF & Deep Sleep
    2.GPS
    3.BT audio
    4.BT Voice

@par Hardware and software environment

  - Supported platform
    - LinkIt 2523 HDK

  - PC/environment configuration
   - A serial tool is required, such as hyper terminal, for UART logging.
   - COM port settings. baudrate: 115200, data bits: 8, stop bit: 1, parity: none and flow control: off.
  
  - BT host device (Andorid/Iphone)

@par Directory contents
  - Source and header files
   - project\mt2523_hdk\apps\low_power_with_psram\inc					Common header file.
   - project\mt2523_hdk\apps\low_power_with_psram\src\gnss_screen			GPS demo source code.
   - project\mt2523_hdk\apps\low_power_with_psram\src\bt_audio				BT audio source code.
   - project\mt2523_hdk\apps\low_power_with_psram\src\pxp_screen			BLE PXP source code.
   - project\mt2523_hdk\apps\low_power_with_psram\src\sensor_demo			Sensor algorithm demo source code.
   - project\mt2523_hdk\apps\low_power_with_psram\src\watch_face			Watch face demo source code.
   - project\mt2523_hdk\apps\low_power_with_psram\src\graphicLib			GDI interface source code.
       
  - Project configuration files using GCC
   - mt2523_hdk/apps/low_power_with_psram/GCC/feature.mk            Feature configuration file.
   - mt2523_hdk/apps/low_power_with_psram/GCC/Makefile              Makefile.
   - mt2523_hdk/apps/low_power_with_psram/GCC/flash.ld              Linker script.

@par Run the example
  - Build the example project with the command for GCC compiler, "./build.sh mt2523_hdk low_power_with_psram bl" under the SDK root folder
  - Download the bin file to LinkIt 2523 HDK.
  - Connect board to PC with serial port cables, UART 1 for logging, UART 2 for AT command.
  - Open serial tools for logging and AT command.
  - Input corresponding at command to enable feature and do low power measurement
    - Power OFF
      1. AT+ETSMO=0\0d\0a
      2. Reboot Device
      3. AT+SM=5\0d\0a
    - Deep Sleep
      1. AT+ETSMO=0\0d\0a
      2. Reboot Device
      3. AT+SM=6,1\0d\0a
    - BT Voice (eSCO/8k) With PSRAM
      0.AT+SYSLOG="*",1,1\0d\0a
      1.AT+ETSMO=3\0d\0a
      2.Reboot Device
      3.AT+BTHFINIT=1\0d\0a
      4.Reboot Device
      5.pair device (Device name: BT_Audio_Demo)
      6.Make call
    - BT A2DP
      0.AT+SYSLOG="*",1,1\0d\0a
      1.AT+ETSMO=3\0d\0a
      2.Reboot Device
      3.pair device (Device name: BT_Audio_Demo)
      4.Playback from host device (Ex: Phone)
    - GPS on
      1.AT+EGPSC=1\0d\0a
      2.AT+SM=6,1\0d\0a

* @}
*/