#include "main.h"

#ifndef KEY_CODE
#define KEY_CODE

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4
#define ESC 5
//Ű���� �Է� ���ڷ� ġȯ 

#endif

#ifndef GAME_COM
#define GAME_COM

int tmpo; //���� �Ϸ� Ȯ�� ���� 
int comp[10]; //������ �󸶳� ������ ��Ÿ���� �ӽù迭 
int death; //���� Ȯ�� ���� 

#endif

#ifndef _ACCOUNT_
#define _ACCOUNT_

typedef struct
{
	char name[50]; //�̸� 
	char id[50]; //���̵� 
	char psw[50]; //��ȣ 
	int lc; //���� ��ô�� 
}per; //����ü ��Ī per 
//���� ���� ����ü  

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
//game.c, account.c ���� �Լ� ���� 

