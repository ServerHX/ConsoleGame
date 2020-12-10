#include "util.h"

void init()
{
	system("mode con cols=100 lines=40 | title GAME"); //�ܼ� ũ�� ���� 
	
	HANDLE consolehandle=GetStdHandle(STD_OUTPUT_HANDLE); //�ܼ� �������� 
	CONSOLE_CURSOR_INFO consolecursor; //Ŀ�� ���� �������� 
	consolecursor.bVisible=0; 
	consolecursor.dwSize=1;
	//�ֱ����� Ŀ�� ���� ���ֱ�  
	SetConsoleCursorInfo(consolehandle, &consolecursor); //���� ����
}
//������ ���Ӹ��� �ٲٴ� �Լ� 

void uninit()
{
	system("mode con cols=42 lines=20 | title LOGIN"); //�ܼ� ũ�� ���� 
	HANDLE consolehandle=GetStdHandle(STD_OUTPUT_HANDLE); //�ܼ� �������� 
	CONSOLE_CURSOR_INFO consolecursor; //Ŀ�� ���� �������� 
	consolecursor.bVisible=1; 
	consolecursor.dwSize=20;
	//�ֱ����� Ŀ�� ���� ��Ȱ  
	SetConsoleCursorInfo(consolehandle, &consolecursor); //���� ����
}
//������ �α��� ���� �����ϴ� �Լ�
 
void curdes()
{
	HANDLE consolehandle=GetStdHandle(STD_OUTPUT_HANDLE); //�ܼ� �������� 
	CONSOLE_CURSOR_INFO consolecursor; //Ŀ�� ���� �������� 
	consolecursor.bVisible=0; 
	consolecursor.dwSize=1;
	//�ֱ����� ���� ���ֱ�  
	SetConsoleCursorInfo(consolehandle, &consolecursor); //���� ����
}
//Ŀ�� ������ ���� �Լ� 
 	
void gotoxy(int x, int y)
{
	HANDLE consolehandle = GetStdHandle(STD_OUTPUT_HANDLE); //�ܼ� �������� 
	COORD pos; //��ǥ �������� 
	pos.X = x;
	pos.Y = y;
	//��ǥ�� �Ű������� ��ȯ 
	SetConsoleCursorPosition(consolehandle, pos);
	//�Ű����� ��ǥ�� �̵� 
}
//Ŀ�� ��ġ ���� �Լ� 

void setcolor(int forg, int backg)
{
	HANDLE consolehandle=GetStdHandle(STD_OUTPUT_HANDLE);
	int code=forg+backg*16; //���ڻ�, ���� �ڵ� ���� 
	SetConsoleTextAttribute(consolehandle, code); //���� ���� ���� 
}
//���ڿ� ���� ���� �Լ� 

void flush(void)
{
	while(getchar()!='\n'); //�Է� ���� Ŭ���� 
}

//���� ��� ���� �Լ� 
