/*
 * lab3_inc.h
 *
 *  Created on: Nov 13, 2024
 *      Author: Admin
 */

#ifndef INC_INC_LAB3_LAB3_INC_H_
#define INC_INC_LAB3_LAB3_INC_H_
#include "main.h"
#include "spi.h"
#include "tim.h"
#include "gpio.h"
#include "fsmc.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "software_timer.h"
#include "led_7seg.h"
#include "button.h"
#include "lcd.h"
#include "picture.h"
/* USER CODE END Includes */
enum eColor{emClear, emRed, emGreen, emYellow};
enum eNormalState{emRG, emRY, emGR, emYR};
enum eState{emInit, emNormal, emERed, emEGreen, emEYellow};
void fsm();
void normal_mode();
void edit_mode(enum eColor color);
void lcd_display(char* str_mode, uint8_t count_1, uint8_t count_2, enum eColor color_1, enum eColor color_2);
void init();


#endif /* INC_INC_LAB3_LAB3_INC_H_ */
