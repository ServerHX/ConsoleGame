#include "main.h"

#ifndef _COLOR_LIST_
#define _COLOR_LIST_

enum{
	black,
	blue,
	green,
	cyan,
	red,
	purple,
	brown,
	lightgray,
	darkgray,
	lightblue,
	lightgreen,
	lightcyan,
	lightred,
	lightpurple,
	yellow,
	white
};
//색 열거형 
#endif

void init();
void uninit();
void gotoxy(int, int);
void setcolor(int, int);
void flush();
void curdes();
//util.c 함수 선언 
