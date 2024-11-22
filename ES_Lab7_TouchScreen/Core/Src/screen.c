/*
 * screen.c
 *
 *  Created on: Nov 28, 2023
 *      Author: Admin
 */

#include "screen.h"

void screen_init(){
	lcd_ShowStr(60,10,"SNAKE GAME",GREEN,WHITE,24,1);
	lcd_ShowStr(40,60,"Player ID:",WHITE,BLACK,16,0);
	lcd_ShowIntNum(120, 60, ID, 4, WHITE, BLACK, 16);
//	lcd_Fill(50, 200, 190, 300, GREEN);
	lcd_ShowStr(40, 90, "Mode (B):", WHITE, BLACK, 16, 0);
	if(mode == NORMAL)
		lcd_ShowStr(120, 90, "NORMAL", WHITE, BLACK, 16, 0);
	if(mode == WALL)
		lcd_ShowStr(120, 90, "WALL", WHITE, BLACK, 16, 0);
	if(mode == WALLS)
		lcd_ShowStr(120, 90, "WALLS", WHITE, BLACK, 16, 0);
	if(mode == TIMER)
		lcd_ShowStr(120, 90, "TIMER", WHITE, BLACK, 16, 0);
	lcd_ShowStr(40, 120, "Speed (E):", WHITE, BLACK, 16, 0);
	if(speed == 1000)
		lcd_ShowStr(120, 120, "EASY", WHITE, BLACK, 16, 0);
	if(speed == 500)
		lcd_ShowStr(120, 120, "MEDIUM", WHITE, BLACK, 16, 0);
	if(speed == 100)
		lcd_ShowStr(120, 120, "HARD", WHITE, BLACK, 16, 0);

	lcd_ShowStr(40,155,"Hi, I\'m Slyther! <3",BLUE,BLACK,16,0);
	lcd_ShowStr(40,180,"Help me grow strong",BLUE,BLACK,16,0);
	lcd_ShowStr(40,205,"to protect our jungle! ",BLUE,BLACK,16,0);
//	lcd_ShowStr(90,235,"START",BLACK,BLACK,24,1);
}

void screen_play(){
	lcd_Fill(0, 0, 240, 200, WHITE);
	lcd_Fill(90, 210, 150, 250, BLUE);//UP
	lcd_ShowStr(110, 215, "UP", WHITE, BLUE, 24, 1);
	lcd_Fill(90, 260, 150, 300, BLUE);//DOWN
	lcd_ShowStr(95, 265, "DOWN", WHITE, BLUE, 24, 1);
	lcd_Fill(20, 260, 80, 300, BLUE);//LEFT
	lcd_ShowStr(28, 265, "LEFT", WHITE, BLUE, 24, 1);
	lcd_Fill(160, 260, 220, 300, BLUE);//RIGHT
	lcd_ShowStr(165, 265, "RGHT", WHITE, BLUE, 24, 1);
}

void screen_score(){
	lcd_ShowStr(0, 205, "Score: ", WHITE, WHITE, 24, 1);
	lcd_ShowIntNum(0, 230, score, 4, WHITE, BLACK, 24);
}

void screen_exit(){
	lcd_ShowStr(170, 205, "Exit", WHITE, WHITE, 24, 1);
	lcd_ShowStr(170, 230, " >> ", WHITE, WHITE, 24, 1);
}

void screen_game_over(){
	lcd_ShowStr(70,10,"GAME OVER",RED,WHITE,24,1);
	lcd_ShowStr(40, 180, "Score: ", WHITE, BLACK, 16, 0);
	lcd_ShowStr(40,60,"Player ID:",WHITE,BLACK,16,0);
	lcd_ShowIntNum(120, 60, ID, 4, WHITE, BLACK, 16);
	lcd_ShowStr(40, 90, "Mode (B):", WHITE, BLACK, 16, 0);
	if(mode == NORMAL)
		lcd_ShowStr(120, 90, "NORMAL", WHITE, BLACK, 16, 0);
	if(mode == WALL)
		lcd_ShowStr(120, 90, "WALL", WHITE, BLACK, 16, 0);
	if(mode == WALLS)
		lcd_ShowStr(120, 90, "WALLS", WHITE, BLACK, 16, 0);
	if(mode == TIMER)
		lcd_ShowStr(120, 90, "TIMER", WHITE, BLACK, 16, 0);
	lcd_ShowStr(40, 120, "Speed (E):", WHITE, BLACK, 16, 0);
	if(speed == 1000)
		lcd_ShowStr(120, 120, "EASY", WHITE, BLACK, 16, 0);
	if(speed == 500)
		lcd_ShowStr(120, 120, "MEDIUM", WHITE, BLACK, 16, 0);
	if(speed == 100)
		lcd_ShowStr(120, 120, "HARD", WHITE, BLACK, 16, 0);
//	lcd_ShowStr(40, 150, "Leaderboard (<)", WHITE, BLACK, 16, 0);
//	lcd_ShowStr(40, 180, "Time:", WHITE, BLACK, 16, 0);
	lcd_ShowStr(40, 150, "Time:", WHITE, BLACK, 16, 0);
	lcd_ShowIntNum(90, 150, count/60, 2, WHITE, BLACK, 16);
	lcd_ShowStr(110, 150, ":", WHITE, BLACK, 16, 0);
	lcd_ShowIntNum(120, 150, count%60, 2, WHITE, BLACK, 16);
	lcd_ShowIntNum(100, 180, score, 2, WHITE, BLACK, 16);
//	lcd_Fill(50, 250, 190, 300, GREEN);
//	lcd_ShowStr(80,260,"RESTART",BLACK,BLACK,24,1);
	lcd_ShowStr(40,211,"You did well!!! Again?",BLUE,BLACK,16,0);
}

