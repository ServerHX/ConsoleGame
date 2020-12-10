#include "game.h"
#include "util.h"
#include "game_map.h"
//<함수 명 뒤에 h가 붙은 함수(drawmaph, moveh, glooph 등)은 HELL모드 전용 함수>

char tempmap[30][80]; //레벨 변동에 따른 맵 임시저장 배열 
char tempR[30][80]; //resume(재개) 효과에 따른 맵 임시저장 배열 

//==========================================================================아래로 그래픽 함수 목록==========================================================================
void drawmap(int* x, int* y) //맵 그리기 함수 
{
	system("cls"); //화면 초기화 
	int a, b; //가로 세로 변수 
	for(a=0; a<30; a++) 
	{
		gotoxy(10, a+5); //(0,0)으로 부터 가로로 10, 세로로 5만큼 떨어진 지점에서 맵 구성 시작 
		for(b=0; b<80; b++)
		{
			char temp=tempmap[a][b];
			if(temp=='0')
			{
	            setcolor(black, black); //0은 검정 
                printf(" ");
            }
            else if(temp=='1')
            {
                setcolor(white, white); //1은 하얀색 
                printf("#");
            }
            else if(temp=='s')
            {
            	*x=b+10;
            	*y=a+5;
                setcolor(cyan, cyan); // 플레이어는 초록색 
                printf("@");
            }
            else if(temp=='q')
            {
            	setcolor(red, red); //장애물은 붉은색 
                printf("O");
            }
            else if(temp=='k')
            {
            	setcolor(yellow, yellow); //열쇠는 노란색 
            	printf("*");
 		    }
 		    else if(temp=='l')
 		    {
 		    	setcolor(brown, black); //문은 십자형 갈색 
 		    	printf("+");
 		    }
		}
		setcolor(white, black); //색 초기화 
		printf("\n");
	}
}

void drawmaph(int* x, int* y) //맵 그리기 함수 
{
	system("cls"); //화면 초기화 
	int a, b; //가로 세로 변수 
	for(a=0; a<30; a++) 
	{
		gotoxy(10, a+5);
		for(b=0; b<80; b++)
		{
			char temp=tempmap[a][b];
			if(temp=='0')
			{
	            setcolor(black, black); //0은 검정 
                printf(" ");
            }
            else if(temp=='1')
            {
                setcolor(red, red); //1은 하얀색 
                printf("O");
            }
            else if(temp=='s')
            {
            	*x=b+10;
            	*y=a+5;
                setcolor(cyan, cyan); // 플레이어는 초록색 
                printf("@");
            }
            else if(temp=='q')
            {
            	setcolor(red, red); //장애물은 붉은색 
                printf("O");
            }
            else if(temp=='k')
            {
            	setcolor(yellow, yellow); //열쇠는 노란색 
            	printf("*");
 		    }
 		    else if(temp=='l')
 		    {
 		    	setcolor(brown, black); //문은 십자형 갈색 
 		    	printf("+");
 		    }
		}
		setcolor(white, black); //색 초기화 
		printf("\n");
	}
}

void drawmapR(int *x, int *y) //resume에 따른 맵 그리기 함수 
{
	system("cls");
	int a, b;
	for(a=0; a<30; a++)
	{
		gotoxy(10, a+5);
		for(b=0; b<80; b++)
		{
			char temp=tempR[a][b];
			if(temp=='0')
			{
	            setcolor(black, black);
                printf(" ");
            }
            else if(temp=='1')
            {
                setcolor(white, white);
                printf("#");
            }
            else if(temp=='s')
            {
            	*x=b+10;
            	*y=a+5;
                setcolor(cyan, cyan);
                printf("@");
            }
            else if(temp=='q')
            {
            	setcolor(red, red);
                printf("O");
            }
            else if(temp=='k')
            {
            	setcolor(yellow, yellow);
            	printf("*");
 		    }
 		    else if(temp=='l')
 		    {
 		    	setcolor(brown, black);
 		    	printf("+");
 		    }
		}
		setcolor(white, black);
		printf("\n");
	}
}

void drawmapRh(int *x, int *y) //resume에 따른 맵 그리기 함수 
{
	system("cls");
	int a, b;
	for(a=0; a<30; a++)
	{
		gotoxy(10, a+5);
		for(b=0; b<80; b++)
		{
			char temp=tempR[a][b];
			if(temp=='0')
			{
	            setcolor(black, black);
                printf(" ");
            }
            else if(temp=='1')
            {
                setcolor(red, red);
                printf("O");
            }
            else if(temp=='s')
            {
            	*x=b+10;
            	*y=a+5;
                setcolor(cyan, cyan);
                printf("@");
            }
            else if(temp=='q')
            {
            	setcolor(red, red);
                printf("O");
            }
            else if(temp=='k')
            {
            	setcolor(yellow, yellow);
            	printf("*");
 		    }
 		    else if(temp=='l')
 		    {
 		    	setcolor(brown, black);
 		    	printf("+");
 		    }
		}
		setcolor(white, black);
		printf("\n");
	}
}
	
void titledraw(int* k) //제목 그리기 함수 
{
	int alpha= rand() % (90000) + 10000; //계정코드 출력에 따른 난수 설정 
 
	 char title[11][73]=
	{
		{"1111111111111111111111111111111111111111111111111111111111111111111111111"},
		{"1000000000000000000000000000000000000000000000000000000000000000000000001"},
		{"1000010000001001111111000000001100100000000000010011111110011000000100001"},
		{"1000010000001001000000000000010010010000000000100010000000010100000100001"},
		{"1000010000001001000000000000100001001000000001000010000000010010000100001"},
		{"1000011111111001111111000001111111100100000010000011111110010001000100001"},
		{"1000010000001001000000000010000000010010000100000010000000010000100100001"},
		{"1000010000001001000000000100000000001001001000000010000000010000010100001"},
		{"1000010000001001111111001000000000000100110000000011111110010000001100001"},
		{"1000000000000000000000000000000000000000000000000000000000000000000000001"},
		{"1111111111111111111111111111111111111111111111111111111111111111111111111"}
		
	}; //타이틀 배열 
	
	system("cls"); //화면초기화 

    gotoxy(2, 2);
	printf("계정번호 #%d%d로 접속하셨습니다.", *k, alpha); //계정 코드 출력 
	
	int a, b; //가로 세로 변수 
	for(a=0; a<11; a++)
	{
		gotoxy(13, a+5);
		for(b=0; b<73; b++)
		{
			char temp=title[a][b];
			if(temp=='0')
			{
	            setcolor(black, black);
                printf(" ");
            }
            else if(temp=='1')
            {
                setcolor(white, white);
                printf("#");
            } 
		}
	} //위 타이틀 출력 
	setcolor(white, black); //색 초기화 

} 

void titledrawh(int* k) //제목 그리기 함수 
{
	int alpha= rand() % (90000) + 10000; //계정코드 설정에 따른 난수 설정 
 
	 char title[11][47]=
	{
		{"11111111111111111111111111111111111111111111111"},
		{"10000000000000000000000000000000000000000000001"},
		{"10000100000010011111110010000000001000000000001"},
		{"10000100000010010000000010000000001000000000001"},
		{"10000100000010010000000010000000001000000000001"},
		{"10000111111110011111110010000000001000000000001"},
		{"10000100000010010000000010000000001000000000001"},
		{"10000100000010010000000010000000001000000000001"},
		{"10000100000010011111110011111111001111111100001"},
		{"10000000000000000000000000000000000000000000001"},
		{"11111111111111111111111111111111111111111111111"}
	
	}; //타이틀 배열 
	
	system("cls"); //화면초기화 

    gotoxy(2, 2);
	printf("계정번호 #%d%d로 접속하셨습니다.", *k, alpha); //계정 코드 출력 
	
	int a, b; //가로 세로 변수 
	for(a=0; a<11; a++)
	{
		gotoxy(24, a+5);
		for(b=0; b<47; b++)
		{
			char temp=title[a][b];
			if(temp=='0')
			{
	            setcolor(black, black);
                printf(" ");
            }
            else if(temp=='1')
            {
                setcolor(white, white);
                printf("#");
            } 
		}
	} //위 타이틀 출력 
	setcolor(white, black); //색 초기화 

}  

int menudraw() //게임 메뉴 출력 함수 
{
	int x=43; 
	int y=20;
	//그리기 초기 설정 좌표 
	gotoxy(x-2, y);
	printf("> GAME START");
	gotoxy(x, y+2);
	printf("GAME INFO");
	gotoxy(x, y+4);
	printf("  HELL  ");
	gotoxy(x, y+6);
	printf(" LOGOUT ");
	gotoxy(x, y+8);
	printf("  EXIT  ");
	while(1)
	{
		int n=keycontrol(); //사용자가 입력한 키 받아와서 n에 저장 
		switch(n)
		{
			case UP:
				{
					if(y>20)
					{
						gotoxy(x-2, y);
						printf(" ");
						gotoxy(x-2, y-2);
						printf(">");
						y=y-2;
					}
					break;
				}
			
			case DOWN:
			    {
				    if(y<28)
					{
						gotoxy(x-2, y);
						printf(" ");
						gotoxy(x-2, y+2);
						printf(">");
						y=y+2;
					}
    	            break;
    	        }
    	        
            case SUBMIT:
            	return (y-20)/2;
	    }
	    //W누르면(n=1(DOWN)) 위로 올라가고, S누르면 (n=2(UP)) 아래로 내려가고, 스페이스바 누르면 (n=4(SUBMIT)) 
		//선택한 항목의 번호를 반환 
	}	        
}    

int menudrawh() //게임 메뉴 출력 함수 
{
	int x=43; 
	int y=20;
	gotoxy(x-2, y);
	printf("> GAME START");
	gotoxy(x, y+2);
	printf("GAME INFO");
	gotoxy(x, y+4);
	printf(" HEAVEN ");
	gotoxy(x, y+6);
	printf(" LOGOUT ");
	gotoxy(x, y+8);
	printf("  EXIT  ");
	while(1)
	{
		int n=keycontrol();
		switch(n)
		{
			case UP:
				{
					if(y>20)
					{
						gotoxy(x-2, y);
						printf(" ");
						gotoxy(x-2, y-2);
						printf(">");
						y=y-2;
					}
					break;
				}
			
			case DOWN:
			    {
				    if(y<28)
					{
						gotoxy(x-2, y);
						printf(" ");
						gotoxy(x-2, y+2);
						printf(">");
						y=y+2;
					}
    	            break;
    	        }
    	        
            case SUBMIT:
            	return (y-20)/2;
	    }
	}	        
}    

void infodraw() //게임 규칙 설명 함수 
{
	system("cls");
	printf("\n\n\n\n");
	printf("                                            [CONTROLS]\n\n");
	printf("                                       MOVEMENT: W, A, S, D\n");
	printf("                                           SELECT: SPACE\n\n\n\n");
	printf("                                          [INSTRUCTIONS]\n\n");
	printf("                          1) Avoid red blocks and make your way to the gate!\n\n");
	printf("                          2) Collect keys to break through hidden doors!\n\n");
	printf("                          3) Find items that will make your adventure easier!\n\n");
	printf("                          4) Now, press space and begin your adventure!\n\n\n\n\n\n\n");
	printf("                              <PRESS SPACEBAR TO RETURN TO MAIN MENU>");
	
	
	while(1)
	{
		if(keycontrol()==SUBMIT)
		{
			break;
		}
	} //스페이스바 누를 시에는 반복문 종료, 함수 탈출 
}

int maplistdraw() //맵 리스트 그리기 
{
	int x=44;
	int y=15;
	system("cls");
	printf("\n\n");
	gotoxy(x-1, y-3);
	printf("[SELECT MAP]");
	gotoxy(x-2, y);
	printf("> (LEVEL 1)");
	gotoxy(x, y+2);
	printf("(LEVEL 2)");
	gotoxy(x, y+4);
	printf("(LEVEL 3)");
	gotoxy(x, y+6);
	printf("(LEVEL 4)");
	gotoxy(x, y+8);
	printf("(LEVEL 5)");
	gotoxy(x, y+10);
	printf("(BACK)");
	//항목 
	
	while(1)
	{
		int n=keycontrol();
		switch(n)
		{
			case UP:
				if(y>15)
				{
					gotoxy(x-2, y);
					printf(" ");
					gotoxy(x-2, y-2);
					y -= 2;
					printf(">");
				}
				break;
				
			case DOWN:
				if(y<25)
				{
					gotoxy(x-2, y);
					printf(" ");
					gotoxy(x-2, y+2);
					y += 2;
					printf(">");
				}
				break;
				
			case SUBMIT:
				return (y-15)/2;
		}
	} //항목 선택 이동 반복문 
}

void drawui(int *x, int *y, int *key, int *health)
{
	setcolor(white, black); //글자색 흰색 
	gotoxy(10, 2);
	printf("Position: %02d, %02d", *x, *y);
	
	setcolor(red, black); //글자색 붉은색 
	gotoxy(80, 2);
	printf("HEALTH: %d", *health);
	
	setcolor(yellow, black); //글자색 노란색 
	gotoxy(45, 2);
	printf("Key: %d", *key);
} //게임 맨 위 UI  
	

//==========================================================================아래로 기능 함수 목록==========================================================================
int keycontrol() //키 인식 함수 
{
	char temp=getch(); //키 값 가져오기 
	if(temp=='w'|| temp=='W')
        return UP;
    else if(temp=='s'|| temp=='S')
        return DOWN;
    else if(temp=='a'|| temp=='A')
        return LEFT;
    else if(temp=='d'|| temp=='D')
        return RIGHT;   
	else if(temp==' ')
	    return SUBMIT; 
	else if(temp==27)
	    return ESC;  
	    //소문자 대문자 구별 안함 
		//game.h헤더에서 매크로로 정의함  
}

int deathb() //죽었을때 출력 내용 
{
	int x=43;
	int y=17;
	
	system("cls");
	gotoxy(x+2, y-7);
	printf("< GAME OVER >");	
	gotoxy(x-5, y);
	printf(">       (RESTART)");
	gotoxy(x-3, y+4);
	printf("(RETURN TO LEVEL MENU)");
	gotoxy(x-3, y+8);
	printf("     (EXIT GAME)");	
	while(1)
	{
		int n=keycontrol();
		switch(n)
		{
			case UP:
				{
					if(y>17)
					{
						gotoxy(x-5, y);
						printf(" ");
						gotoxy(x-5, y-4);
						printf(">");
						y=y-4;
					}
					break;
				}
			
			case DOWN:
			    {
				    if(y<25)
					{
						gotoxy(x-5, y);
						printf(" ");
						gotoxy(x-5, y+4);
						printf(">");
						y=y+4;
					}
    	            break;
    	        }
    	        
            case SUBMIT:
            	return (y-17)/4;
	    }
	}	    
 
}
		 
void gloop(int mc) //게임 레벨 선택 루프 
{	
    int maxkey; //각 레벨 당 최대 열쇠개수 
    
    death=0; //처음에는 죽지 않았으므로 죽음 확인 전역 변수에 0저장 
    int tempnum; //죽음 확인 2차 변수 
    int c1=0; //레벨 클리어 확인 변수 
	tmpo=0; //레벨 완료 확인 변수 
	int key=0; //열쇠 개수 
	int health=3; //체력 
	int x, y; //위치 변수 
	int playing=1; //게임 중인지 확인하는 변수 
	
	if(mc==0) //레벨 리스트에서 첫번째 항목을 선택한 경우 
	{
		maxkey=5; //최대열쇠 개수=5 
		memcpy(tempmap, map1, sizeof(tempmap)); //맵 배열 전체를 tempmap(게임 실행 전용 임시맵 배열)에 복사 
	    memcpy(tempR, map1, sizeof(tempR)); //맵 배열 전체를 tempR(게임 일지정지 후 재개할 시 이용됨)에 복사 
	}
	
	else if(mc==1) //레벨 리스트에서 두번째 항목을 선택한 경우 
	{
		if(comp[0]==1) //전 레벨 클리어 시에 작동 
		{
			maxkey=6;
			memcpy(tempmap, map2, sizeof(tempmap));
			memcpy(tempR, map2, sizeof(tempR));
		}
		
		else if(comp[0]==0) //전 레벨 클리어 안될시에 작동 
		{
			system("cls");
			gotoxy(36, 19);
			printf("<PREVIOUS LEVEL NOT COMPLETED>");
			Sleep(2000);
			int m1= maplistdraw(); //레벨 리스트 다시 그림 
		    gloop(m1); //리스트에서 선택한 항목으로 게임 루프 재실행 
		    return;
        }
	}
	
	else if(mc==2)
	{
		if(comp[1]==1) //전 레벨 클리어 시에 작동 
		{
			maxkey=5;
			memcpy(tempmap, map3, sizeof(tempmap));
			memcpy(tempR, map3, sizeof(tempR));
		}
		
		else if(comp[1]==0) //전 레벨 클리어 안될시에 작동 
		{
			system("cls");
			gotoxy(36, 19);
			printf("<PREVIOUS LEVEL NOT COMPLETED>");
			Sleep(2000);
			int m2= maplistdraw();
		    gloop(m2);
		    return;
        }
	}
	
	else if(mc==3)
	{
		if(comp[2]==1) //전 레벨 클리어 시에 작동 
		{
			maxkey=6;
			memcpy(tempmap, map4, sizeof(tempmap));
			memcpy(tempR, map4, sizeof(tempR));
		}
		
		else if(comp[2]==0) //전 레벨 클리어 안될시에 작동 
		{
			system("cls");
			gotoxy(36, 19);
			printf("<PREVIOUS LEVEL NOT COMPLETED>");
			Sleep(2000);
			int m3= maplistdraw();
		    gloop(m3);
		    return;
        }
	}
	
	else if(mc==4)
	{
		if(comp[3]==1) //전 레벨 클리어 시에 작동 
		{
			maxkey=6;
			memcpy(tempmap, map5, sizeof(tempmap));
			memcpy(tempR, map5, sizeof(tempR));
		}
		
		else if(comp[3]==0) //전 레벨 클리어 안될시에 작동 
		{
			system("cls");
			gotoxy(36, 19);
			printf("<PREVIOUS LEVEL NOT COMPLETED>");
			Sleep(2000);
			int m4= maplistdraw();
		    gloop(m4);
		    return;
        }
	}
	//전 레벨 미완료시 경고, 맵 정보 복사 
	
	else if(mc==5)
	{
		return; //함수 탈출 
	}
	// 위 코드: 맵 정보 받아와서 tempmap에 저장하는 과정 
	 
	drawmap(&x, &y); //tempmap 정보를 바탕으로 맵 그리기 
	
	B:
		
	while(playing) //playing=1이면 게임 중 
	{
		if(death) //죽음 확인 전역변수=1이 되면 작동 
		{
			playing=0; //게임 실행 중을 나타내는 변수 playing에 0을 저장->게임 중지된 상태 
			setcolor(white, black);
			system("cls");
			tempnum=deathb(); //함수 실행후 결과 받아옴 
			if(tempnum==0)
			{
				playing=1;
			    gloop(mc);
			    return;
			    //게임 재시작 선택 시 
			}
			
			else if(tempnum==1)
			{
				playing=0;
				int abc1=maplistdraw();
				gloop(abc1);
				return;
				//레벨 메뉴로 돌아가기 선택 시 
			}
			
			else if(tempnum==2)
			{
				playing=0;
				return;
				//게임 종료 선택 시->메인화면으로 복귀  
			}
				  
		}
		//위 코드: 죽음이 확인된 후 단계 
	
	    //아래 코드: 게임 실행 중 움직임 관련 
		int key1=keycontrol(); //키보드 입력 받아옴 
		switch(key1) 
		{
			before:
			case UP:
				while(1)
				{
					drawui(&x, &y, &key, &health); //상단 UI 그림 
					move(&x, &y, 0, -1, &key, &health, &playing, maxkey); //move함수 실행 
		        	Sleep(70); //플레이어 스피드 조절용 타임 딜레이 
		        	if(kbhit() || tmpo || death)
		        	{
		        		break; //다른 키보드 입력이 감지되었거나, 레벨을 완료했거나, 죽었을때 반복문 탈출 
		        	}
				}
				break;
			case DOWN:
				while(1)
				{
					drawui(&x, &y, &key, &health);
					move(&x, &y, 0, 1, &key, &health, &playing, maxkey);
		        	Sleep(70);
		        	if(kbhit() || tmpo || death)
		        	{
		        		break;
		        	}
				}
				break;
			case RIGHT:
				while(1)
				{
					drawui(&x, &y, &key, &health);
					move(&x, &y, 1, 0, &key, &health, &playing, maxkey);
		        	Sleep(52);
		        	if(kbhit() || tmpo || death)
		        	{
		        		break;
		        	}
				}
				break;
            case LEFT:
            	while(1)
				{
					drawui(&x, &y, &key, &health);
					move(&x, &y, -1, 0, &key, &health, &playing, maxkey);
		        	Sleep(52);
		        	if(kbhit() || tmpo || death)
		        	{
		        		break;
		        	}
				}
            	break;
           	case ESC: 
           		playing=0;
           		break;
           		
  		    default: 
  		        goto before;
        }
	}
	//캐릭터 움직이기
		
			 
	system("cls");
	setcolor(white, black);
	//화면 초기화
	 
	if(tmpo==1) //레벨 통과시 어떤 레벨 통과했는지 출력 
	{
		comp[mc]=1;
		gotoxy(42, 19);
		printf("COMPLETED LEVEL %d!", mc+1); 
		Sleep(2000);
		int k1= maplistdraw();
		gloop(k1);
		return;
	}
	
	else if(tmpo==0) //레벨 통과못하고 esc 누를 시 일시정지 메뉴 출력 
	{
		int cho=-1;
		int x=43;
		int y=17;
		system("cls");
		printf("\n\n");
		gotoxy(x+2, y-7);
		printf("< PAUSED >");
		gotoxy(x-5, y);
		printf(">       (RESUME)");
		gotoxy(x-7, y+3);
		printf("           (DIE)");
		gotoxy(x-3, y+6);
		printf("(RETURN TO LEVEL MENU)");
		gotoxy(x-3, y+9);
		printf("     (EXIT GAME)");
			
		while(1)
		{
			A:
			if(cho>=0)
			{
				break;
			}
			
			int n=keycontrol();
			switch(n)
			{
				case UP:
					if(y>17)
					{
						gotoxy(x-5, y);
						printf(" ");
						gotoxy(x-5, y-3);
						y -= 3;
						printf(">");
					}
					break;
					
				case DOWN:
					if(y<26)
					{
						gotoxy(x-5, y);
						printf(" ");
						gotoxy(x-5, y+3);
						y += 3;
						printf(">");
					}
					break;
					
				case SUBMIT:
					cho= (y-17)/3;
					goto A;
			}
		}
		setcolor(white, black);
			
		if(cho==0)
		{
			playing=1;
			drawmapR(&x, &y);
			goto B;
		}
		//게임 재개(RESUME) 선택 시 임시 맵 출력 함수 drawmapR에서 저장된 맵 다시 출력 후 게임 재시작 
		
		else if(cho==1)
		{
			playing=0;
			gloop(mc);
		}
		//게임 재시작(DIE) 선택 시 처음부터 다시 시작->맵도 처음으로 초기화 
		
	    else if(cho==2)
		{
			int ab= maplistdraw();
			gloop(ab);
		}
		//레벨 메뉴로 돌아가기 
		
		else if(cho==3)
		{
			return;
		}
		//게임 종료->메인 화면으로 복귀 
    }
}

void glooph(int mc) //게임 레벨 선택 루프 
{	
    int maxkey; //최대 열쇠 개수 
    
    death=0; //죽음 확인 전역 변수  
    int tempnum; //죽음 확인 2차 변수 
    int c1=0; //레벨 클리어 확인 변수 
	tmpo=0; //레벨 완료 확인 변수 
	int key=0; //열쇠 개수 
	int health=3; //체력 
	int x, y; //위치 변수 
	int playing=1; //게임중 확인 변수 
	
	if(mc==0)
	{
		if(comp[4]==1) //전 레벨 클리어 시에 작동 
		{
			maxkey=5;
			memcpy(tempmap, map1, sizeof(tempmap));
			memcpy(tempR, map1, sizeof(tempR));
		}
		
		else if(comp[4]==0) //전 레벨 클리어 안될시에 작동 
		{
			system("cls");
			gotoxy(36, 19);
			printf("<PREVIOUS LEVEL NOT COMPLETED>");
			Sleep(2000);
			int m1= maplistdraw();
		    glooph(m1);
		    return;
        }
	}
	
	
	else if(mc==1)
	{
		if(comp[5]==1) //전 레벨 클리어 시에 작동 
		{
			maxkey=6;
			memcpy(tempmap, map2, sizeof(tempmap));
			memcpy(tempR, map2, sizeof(tempR));
		}
		
		else if(comp[5]==0) //전 레벨 클리어 안될시에 작동 
		{
			system("cls");
			gotoxy(36, 19);
			printf("<PREVIOUS LEVEL NOT COMPLETED>");
			Sleep(2000);
			int m1= maplistdraw();
		    glooph(m1);
		    return;
        }
	}
	
	else if(mc==2)
	{
		if(comp[6]==1) //전 레벨 클리어 시에 작동 
		{
			maxkey=5;
			memcpy(tempmap, map3, sizeof(tempmap));
			memcpy(tempR, map3, sizeof(tempR));
		}
		
		else if(comp[6]==0) //전 레벨 클리어 안될시에 작동 
		{
			system("cls");
			gotoxy(36, 19);
			printf("<PREVIOUS LEVEL NOT COMPLETED>");
			Sleep(2000);
			int m2= maplistdraw();
		    glooph(m2);
		    return;
        }
	}
	
	else if(mc==3)
	{
		if(comp[7]==1) //전 레벨 클리어 시에 작동 
		{
			maxkey=6;
			memcpy(tempmap, map4, sizeof(tempmap));
			memcpy(tempR, map4, sizeof(tempR));
		}
		
		else if(comp[7]==0) //전 레벨 클리어 안될시에 작동 
		{
			system("cls");
			gotoxy(36, 19);
			printf("<PREVIOUS LEVEL NOT COMPLETED>");
			Sleep(2000);
			int m3= maplistdraw();
		    glooph(m3);
		    return;
        }
	}
	
	else if(mc==4)
	{
		if(comp[8]==1) //전 레벨 클리어 시에 작동 
		{
			maxkey=6;
			memcpy(tempmap, map5, sizeof(tempmap));
			memcpy(tempR, map5, sizeof(tempR));
		}
		
		else if(comp[8]==0) //전 레벨 클리어 안될시에 작동 
		{
			system("cls");
			gotoxy(36, 19);
			printf("<PREVIOUS LEVEL NOT COMPLETED>");
			Sleep(2000);
			int m4= maplistdraw();
		    glooph(m4);
		    return;
        }
	}
	//전 레벨 미완료시 경고, 맵 정보 복사 
	
	else if(mc==5)
	{
		return;
	}
	//맵 정보 받아오기
	 
	drawmaph(&x, &y); //맵 그리기 
	
	B:
		
	while(playing)
	{
		if(death)
		{
			playing=0;
			setcolor(white, black);
			system("cls");
			tempnum=deathb(); 
			if(tempnum==0)
			{
				playing=1;
			    glooph(mc);
			    return;
			}
			
			else if(tempnum==1)
			{
				playing=0;
				int abc1=maplistdraw();
				glooph(abc1);
				return;
			}
			
			else if(tempnum==2)
			{
				playing=0;
				return;
			}
				  
		}
		//죽음이 확인된 후 단계 
	
		int key1=keycontrol();
		switch(key1)
		{
			before:
			case UP:
				while(1)
				{
					drawui(&x, &y, &key, &health);
					moveh(&x, &y, 0, -1, &key, &health, &playing, maxkey);
		        	Sleep(70);
		        	if(kbhit() || tmpo || death)
		        	{
		        		break;
		        	}
				}
				break;
			case DOWN:
				while(1)
				{
					drawui(&x, &y, &key, &health);
					moveh(&x, &y, 0, 1, &key, &health, &playing, maxkey);
		        	Sleep(70);
		        	if(kbhit() || tmpo || death)
		        	{
		        		break;
		        	}
				}
				break;
			case RIGHT:
				while(1)
				{
					drawui(&x, &y, &key, &health);
					moveh(&x, &y, 1, 0, &key, &health, &playing, maxkey);
		        	Sleep(52);
		        	if(kbhit() || tmpo || death)
		        	{
		        		break;
		        	}
				}
				break;
            case LEFT:
            	while(1)
				{
					drawui(&x, &y, &key, &health);
					moveh(&x, &y, -1, 0, &key, &health, &playing, maxkey);
		        	Sleep(52);
		        	if(kbhit() || tmpo || death)
		        	{
		        		break;
		        	}
				}
            	break;
           	case ESC: 
           		playing=0;
           		break;
           		
  		    default: 
  		        goto before;
        }
	}
	//캐릭터 움직이기
		
			 
	system("cls");
	setcolor(white, black);
	//화면 초기화
	 
	if(tmpo==1) //레벨 통과 시(tmpo=1) 어떤 레벨 통과했는지 출력 및 return 
	{
		comp[mc+5]=1;
		gotoxy(42, 19);
		printf("COMPLETED LEVEL %d!", mc+1); 
		Sleep(2000);
		int k1= maplistdraw();
		glooph(k1);
		return;
	}
	
	else if(tmpo==0) //레벨 통과못하고 esc 누를 시에 return 
	{
		int cho=-1;
		int x=43;
		int y=17;
		//setcolor(white, black);
		system("cls");
		printf("\n\n");
		gotoxy(x+2, y-7);
		printf("< PAUSED >");
		gotoxy(x-5, y);
		printf(">       (RESUME)");
		gotoxy(x-7, y+3);
		printf("           (DIE)");
		gotoxy(x-3, y+6);
		printf("(RETURN TO LEVEL MENU)");
		gotoxy(x-3, y+9);
		printf("     (EXIT GAME)");
			
		while(1)
		{
			A:
			if(cho>=0)
			{
				break;
			}
			
			int n=keycontrol();
			switch(n)
			{
				case UP:
					if(y>17)
					{
						gotoxy(x-5, y);
						printf(" ");
						gotoxy(x-5, y-3);
						y -= 3;
						printf(">");
					}
					break;
					
				case DOWN:
					if(y<26)
					{
						gotoxy(x-5, y);
						printf(" ");
						gotoxy(x-5, y+3);
						y += 3;
						printf(">");
					}
					break;
					
				case SUBMIT:
					cho= (y-17)/3;
					goto A;
			}
		}
		setcolor(white, black);
			
		if(cho==0)
		{
			playing=1;
			drawmapRh(&x, &y);
			goto B;
		}
		
		else if(cho==1)
		{
			playing=0;
			glooph(mc);
		}
		
	    else if(cho==2)
		{
			int ab= maplistdraw();
			glooph(ab);
		}
		
		else if(cho==3)
		{
			return;
		}
    }
}

void move(int *x, int *y, int _x, int _y, int* key, int *health, int *playing, int maxk) //캐릭터 움직임 매커니즘 
{
	int ini=0;
	if(*health==0)
	{
		death=1;
	} //체력이 0이 될 경우, 전역변수 death에 1을 저장->gloop함수 내에서 죽음 관련 코드 실행  
	char mapobj=tempmap[*y+_y-5][*x+_x-10]; //원래 위치로 부터 해당 방향으로 _x, _y만큼 이동한 위치에 존재하는 유닛 감지 
    setcolor(white, black);

    if(mapobj=='0') //유닛이 빈 공간인 경우 
    {
        gotoxy(*x, *y);
	    printf(" ");
	    
		setcolor(cyan, cyan);
		gotoxy(*x+_x, *y+_y);
		printf("@");
		
		tempR[*y-5][*x-10]='0';
		tempmap[*y-5][*x-10]='0'; //맵 갱신 
		
		//플레이어 원래 위치를 공백으로 만들고, 다음 위치에 플레이어 출력 
		
		*x+=_x;
	    *y+=_y;
	    //플레이어 좌표값 증가 
	    
	    tempR[*y-5][*x-10]='s';
	    tempmap[*y-5][*x-10]='s'; //맵 갱신 
	}
	
	else if(mapobj=='q') //유닛이 붉은 벽인 경우 
	{
	    *health -= 1; //체력 감소 
	    Sleep(500); //0.5초 딜레이 (체력이 너무 빠른 속도로 감소되는 걸 방지하기 위한 목적)
		//체력 감소 후 딜레이를 주어 다음 액션을 취할 수 있도록 해 붉은 벽으로 부터 멀어지도록 함 
		//해당 코드가 없으면 붉은 벽에 부딪히자마자 플레이어 체력이 0이 되버림 
	    tempR[*y-5][*x-10]='q';
	    tempmap[*y-5][*x-10]='q'; //맵 갱신 
	}
	
	else if(mapobj=='k') //유닛이 열쇠인 경우 
	{
		gotoxy(*x, *y);
	    printf(" ");
	    
		setcolor(cyan, cyan);
		gotoxy(*x+_x, *y+_y);
		printf("@");
		
		tempR[*y-5][*x-10]='0';
		tempmap[*y-5][*x-10]='0';
		
		*x+=_x;
	    *y+=_y;
	    
		*key+=1;
		tempR[*y-5][*x-10]='k';
		tempmap[*y-5][*x-10]='k';
		
		//열쇠에 +1, 플레이어 이동 
	}
	
	else if(mapobj=='l') //유닛이 십자형 문인 경우 
	{
		if(*key>=maxk) //획득한 열쇠의 수가 맵에서 요구되는 최대 열쇠의 수를 넘어설 때 
		{
			gotoxy(*x, *y);
	        printf(" ");
	    
	    	setcolor(cyan, cyan);
	    	gotoxy(*x+_x, *y+_y);
	    	printf("@");
		
			tempR[*y-5][*x-10]='0';
			tempmap[*y-5][*x-10]='0';
		
	    	*x+=_x;
	        *y+=_y;
	        *key=0; //열쇠의 수를 0으로 초기화 
			ini=1;  
			
			tempR[*y-5][*x-10]='l';
			tempmap[*y-5][*x-10]='l';
			setcolor(white, black);
			
			if(ini==1) //문 통과 확인 
			{
				printf("\a"); //경고음 출력 
				setcolor(white, black);
				*playing=0;
				tmpo=1; //통과 점수=1로 바꿈 
			}
			
		}
	}
			
}

void moveh(int *x, int *y, int _x, int _y, int* key, int *health, int *playing, int maxk) //캐릭터 움직임 매커니즘 
{
	int ini=0;
	if(*health==0)
	{
		death=1;
	}
	char mapobj=tempmap[*y+_y-5][*x+_x-10];
    setcolor(white, black);

    if(mapobj=='0')
    {
        gotoxy(*x, *y);
	    printf(" ");
	    
		setcolor(cyan, cyan);
		gotoxy(*x+_x, *y+_y);
		printf("@");
		
		tempR[*y-5][*x-10]='0';
		tempmap[*y-5][*x-10]='0';
		
		*x+=_x;
	    *y+=_y;
	    
	    tempR[*y-5][*x-10]='s';
	    tempmap[*y-5][*x-10]='s';
	}
	
	else if(mapobj=='q' || mapobj=='1')
	{
	    *health -= 1;
	    Sleep(500);
	    tempR[*y-5][*x-10]='q';
	    tempmap[*y-5][*x-10]='q';
	}
	
	else if(mapobj=='k')
	{
		gotoxy(*x, *y);
	    printf(" ");
	    
		setcolor(cyan, cyan);
		gotoxy(*x+_x, *y+_y);
		printf("@");
		
		tempR[*y-5][*x-10]='0';
		tempmap[*y-5][*x-10]='0';
		
		*x+=_x;
	    *y+=_y;
	    
		*key+=1;
		tempR[*y-5][*x-10]='k';
		tempmap[*y-5][*x-10]='k';
	}
	
	else if(mapobj=='l')
	{
		if(*key>=maxk)
		{
			gotoxy(*x, *y);
	        printf(" ");
	    
	    	setcolor(cyan, cyan);
	    	gotoxy(*x+_x, *y+_y);
	    	printf("@");
		
			tempR[*y-5][*x-10]='0';
			tempmap[*y-5][*x-10]='0';
		
	    	*x+=_x;
	        *y+=_y;
	        *key=0;
			ini=1;
			
			tempR[*y-5][*x-10]='l';
			tempmap[*y-5][*x-10]='l';
			setcolor(white, black);
			
			if(ini==1) //문 통과 확인 
			{
				printf("\a");
				setcolor(white, black);
				*playing=0;
				tmpo=1; //통과 점수=1로 바꿈 
			}
			
		}
	}
			
}
