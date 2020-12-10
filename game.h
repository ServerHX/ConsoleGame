#include "main.h"

#ifndef KEY_CODE
#define KEY_CODE

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4
#define ESC 5
//키보드 입력 숫자로 치환 

#endif

#ifndef GAME_COM
#define GAME_COM

int tmpo; //게임 완료 확인 변수 
int comp[10]; //레벨을 얼마나 깼는지 나타내는 임시배열 
int death; //죽음 확인 변수 

#endif

#ifndef _ACCOUNT_
#define _ACCOUNT_

typedef struct
{
	char name[50]; //이름 
	char id[50]; //아이디 
	char psw[50]; //암호 
	int lc; //게임 진척도 
}per; //구조체 별칭 per 
//계정 정보 구조체  

#endif

void titledraw(int*);
void titledrawh(int*);
int menudraw();
int menudrawh();
void infodraw();
int keycontrol();
int maplistdraw();
void drawmap(int*, int*);
void drawmaph(int*, int*);
void drawmapR(int*, int*);
void drawmapRh(int*, int*);
void gloop(int);
void glooph(int);
void move(int*, int*, int, int, int*, int*, int*, int);
void moveh(int*, int*, int, int, int*, int*, int*, int);
void drawui(int*, int*, int*, int*);
void account(per[], int*, int*, int*);
int deathb();
//game.c, account.c 관련 함수 선언 

