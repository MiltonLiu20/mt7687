/* Copyright Statement:
 *
 * (C) 2005-2016  MediaTek Inc. All rights reserved.
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. ("MediaTek") and/or its licensors.
 * Without the prior written permission of MediaTek and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 * You may only use, reproduce, modify, or distribute (as applicable) MediaTek Software
 * if you have agreed to and been bound by the applicable license agreement with
 * MediaTek ("License Agreement") and been granted explicit permission to do so within
 * the License Agreement ("Permitted User").  If you are not a Permitted User,
 * please cease any access or use of MediaTek Software immediately.
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT MEDIATEK SOFTWARE RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES
 * ARE PROVIDED TO RECEIVER ON AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL
 * WARRANTIES, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
 * NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
 * SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
 * SUPPLIED WITH MEDIATEK SOFTWARE, AND RECEIVER AGREES TO LOOK ONLY TO SUCH
 * THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES
 * THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES
 * CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK
 * SOFTWARE RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND
 * CUMULATIVE LIABILITY WITH RESPECT TO MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
 * AT MEDIATEK'S OPTION, TO REVISE OR REPLACE MEDIATEK SOFTWARE AT ISSUE,
 * OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO
 * MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hal_lcd_if_hw.h"
#include "hal_lcd_if_hw_internal.h"
#include "bsp_lcd.h"
#include "mt25x3_hdk_lcd.h"

extern unsigned char frame_buffer[240*240*2];
void graphic_lib_blt(void)
{
	uint32_t i, j;
	HAL_LCD_ROI_PARA_STRUCT_T lcd_para;
	HAL_LCD_LAYER_PARA_STRUCT_T lcm_para;
	static int32_t is_init;

	if (!is_init)
	{
		is_init = 1;
		BSP_LCD_Init(0xF800);
	}
	lcd_para.tgt_start_x = 0;
	lcd_para.tgt_start_y = 0;	
	lcd_para.tgt_end_x = 239;
	lcd_para.tgt_end_y = 239;
	lcd_para.roi_offset_x = 0;
	lcd_para.roi_offset_y = 0;
	lcd_para.update_layer = 0;
	lcd_para.main_lcd_output = MAIN_LCD_OUTPUT_FORMAT;

	hal_lcd_config_roi(&lcd_para);
	
	lcm_para.src_key_en = 0;
	lcm_para.alpha_en = 0;
	lcm_para.clr_fmt = LCD_LAYER_COLOR_RGB565;
	lcm_para.alpha = 0;
	lcm_para.rotate = LAYER_ROTATE_0_DEGREE;
	lcm_para.row_size = 240;
	lcm_para.column_size = 240;
	lcm_para.window_x_offset = 0;
	lcm_para.window_y_offset = 0;
	lcm_para.layer_en = 0;
	lcm_para.buffer_address = &frame_buffer;
	lcm_para.pitch = 240*2;
	lcm_para.layer_en = HAL_LCD_LAYER0;

	hal_lcd_config_layer(&lcm_para);
	
	//hal_lcd_blt(lcd_para.tgt_start_x , lcd_para.tgt_start_y ,lcd_para.tgt_end_x, lcd_para.tgt_end_y);
	BSP_LCD_UpdateScreen(lcd_para.tgt_start_x , lcd_para.tgt_start_y ,lcd_para.tgt_end_x, lcd_para.tgt_end_y);
}

