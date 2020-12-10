#include "util.h"

void init()
{
	system("mode con cols=100 lines=40 | title GAME"); //콘솔 크기 조정 
	
	HANDLE consolehandle=GetStdHandle(STD_OUTPUT_HANDLE); //콘솔 가져오기 
	CONSOLE_CURSOR_INFO consolecursor; //커서 정보 가져오기 
	consolecursor.bVisible=0; 
	consolecursor.dwSize=1;
	//주기적인 커서 점멸 없애기  
	SetConsoleCursorInfo(consolehandle, &consolecursor); //정보 갱신
}
//설정을 게임모드로 바꾸는 함수 

void uninit()
{
	system("mode con cols=42 lines=20 | title LOGIN"); //콘솔 크기 조정 
	HANDLE consolehandle=GetStdHandle(STD_OUTPUT_HANDLE); //콘솔 가져오기 
	CONSOLE_CURSOR_INFO consolecursor; //커서 정보 가져오기 
	consolecursor.bVisible=1; 
	consolecursor.dwSize=20;
	//주기적인 커서 점멸 부활  
	SetConsoleCursorInfo(consolehandle, &consolecursor); //정보 갱신
}
//설정을 로그인 모드로 복구하는 함수
 
void curdes()
{
	HANDLE consolehandle=GetStdHandle(STD_OUTPUT_HANDLE); //콘솔 가져오기 
	CONSOLE_CURSOR_INFO consolecursor; //커서 정보 가져오기 
	consolecursor.bVisible=0; 
	consolecursor.dwSize=1;
	//주기적인 점멸 없애기  
	SetConsoleCursorInfo(consolehandle, &consolecursor); //정보 갱신
}
//커서 깜빡임 제거 함수 
 	
void gotoxy(int x, int y)
{
	HANDLE consolehandle = GetStdHandle(STD_OUTPUT_HANDLE); //콘솔 가져오기 
	COORD pos; //좌표 가져오기 
	pos.X = x;
	pos.Y = y;
	//좌표값 매개변수로 전환 
	SetConsoleCursorPosition(consolehandle, pos);
	//매개변수 좌표로 이동 
}
//커서 위치 조정 함수 

void setcolor(int forg, int backg)
{
	HANDLE consolehandle=GetStdHandle(STD_OUTPUT_HANDLE);
	int code=forg+backg*16; //글자색, 배경색 코드 설정 
	SetConsoleTextAttribute(consolehandle, code); //색깔 설정 갱신 
}
//글자와 배경색 갱신 함수 

void flush(void)
{
	while(getchar()!='\n'); //입력 버퍼 클리어 
}

//게임 기능 구현 함수 
