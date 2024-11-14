/*
 * lab_src.cpp
 *
 *  Created on: Nov 13, 2024
 *      Author: Admin
 */
#include "lab3_inc.h"
#include <stdio.h>

static enum eState state = emInit;
static enum eColor LEDState = emClear;
static enum eNormalState colorState = emRG;
static uint8_t red_period = 5;
static uint8_t yellow_period = 1;
static uint8_t green_period = 4;
static uint8_t temp_period = 0;
static uint8_t isModify[2];
static uint8_t count_1;
static uint8_t count_2;

void fsm()
{
	switch(state){
	case emNormal:
		normal_mode();
		if(button_flag[0] == 1){
			button_flag[0] = 0;
			state = emERed;
			temp_period = red_period;
			isModify[0] = 0;
			isModify[1] = 0;
			setTimer2(5);
			LEDState = emClear;
		}
		break;
	case emERed:
		if(LEDState == emClear){
			LEDState = emRed;
		}else{
			LEDState = emClear;
		};

		edit_mode(LEDState);

		if(button_flag[0] == 1){
			button_flag[0] = 0;
			state = emEGreen;
			temp_period = green_period;
		}
		if(button_flag[1] == 1){
			button_flag[1] = 0;
			isModify[0] = 1;
			red_period = temp_period;
		}
		break;
	case emEGreen:
		if(LEDState == emClear){
			LEDState = emGreen;
		}else{
			LEDState = emClear;
		};

		edit_mode(LEDState);

		if(button_flag[0] == 1){
			button_flag[0] = 0;
			if(isModify[0] == 1 && isModify[1] == 1){
				state = emInit;
				yellow_period = red_period - green_period;
			}
			else{
				state = emEYellow;
				temp_period = yellow_period;
			}
		}
		if(button_flag[1] == 1){
			button_flag[1] = 0;
			isModify[1] = 1;
			green_period = temp_period;
		}
		break;
	case emEYellow:
		if(LEDState == emClear){
			LEDState = emYellow;
		}else{
			LEDState = emClear;
		};

		edit_mode(LEDState);

		if(button_flag[0] == 1){
			button_flag[0] = 0;
			state = emInit;
			if(isModify[0] == 1){
				green_period = red_period - yellow_period;
			}else{
				red_period = green_period + yellow_period;
			}
			temp_period = green_period;
		}
		if(button_flag[1] >= 1){
			button_flag[1] = 0;
			yellow_period = temp_period;
			red_period = yellow_period + green_period;
		}
		break;
	default:
		setTimer2(10);
		colorState = emRG;
		temp_period = 0;
		state = emNormal;
		button_flag[0] = 0;
		break;
	}
};
void normal_mode()
{
	switch(colorState){
	case emRG:
		count_1 = red_period - temp_period;
		count_2 = green_period - temp_period;
		lcd_display("Normal", count_1, count_2, emRed, emGreen);
		if(temp_period >= green_period){
			temp_period = 0;
			colorState = emRY;
		}
		break;
	case emRY:
		if(yellow_period == 0){
			colorState = emGR;
			break;
		}
		count_1 = yellow_period - temp_period;
		count_2 = yellow_period - temp_period;
		lcd_display("Normal", count_1, count_2, emRed, emYellow);
		if(temp_period >= yellow_period){
			temp_period = 0;
			colorState = emGR;
		}
		break;
	case emGR:
		count_2 = red_period - temp_period;
		count_1 = green_period - temp_period;
		lcd_display("Normal", count_1, count_2, emGreen, emRed);
		if(temp_period >= green_period){
			temp_period = 0;
			colorState = emYR;
		}
		break;
	default:
		count_1 = yellow_period - temp_period;
		count_2 = yellow_period - temp_period;
		lcd_display("Normal", count_1, count_2, emYellow, emRed);
		if(temp_period >= yellow_period){
			temp_period = 0;
			colorState = emRG;
		}
		break;
	}
	temp_period++;
};

void edit_mode(enum eColor color)
{
	if((state == emERed) || (state != emERed && temp_period < red_period)){
		if(button_flag[3] == 1){
			button_flag[3] = 0;
			temp_period++;
		}
		if(button_flag[7] == 1){
			button_flag[7] = 0;
			temp_period--;
		}
	}
	lcd_display("edit mode", temp_period, temp_period, color, color);
}

void lcd_display(char* str_mode, uint8_t count_1, uint8_t count_2, enum eColor color_1, enum eColor color_2){
	char mode_str[100];
	char count_str[100];
	sprintf(mode_str, "Mode = %s", str_mode);
	sprintf(count_str, "Count: %d\t%d", count_1, count_2);
	lcd_Clear(WHITE);
	lcd_StrCenter(0, 2, mode_str, RED, BLUE, 16, 1);
	lcd_ShowStr(20, 30, count_str, WHITE, RED, 24, 0);

	lcd_DrawCircle(60, 90, RED, 20, color_1 == emRed);
	lcd_DrawCircle(110, 90, YELLOW, 20, color_1 == emYellow);
	lcd_DrawCircle(160, 90, GREEN, 20, color_1 == emGreen);

	lcd_DrawCircle(60, 140, RED, 20, color_2 == emRed);
	lcd_DrawCircle(110, 140, YELLOW, 20, color_2 == emYellow);
	lcd_DrawCircle(160, 140, GREEN, 20, color_2 == emGreen);

	lcd_ShowPicture(80, 200, 90, 90, gImage_logo);
}

void init(){
	state = emInit;
};
