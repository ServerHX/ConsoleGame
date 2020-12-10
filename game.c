#include "game.h"
#include "util.h"
#include "game_map.h"
//<�Լ� �� �ڿ� h�� ���� �Լ�(drawmaph, moveh, glooph ��)�� HELL��� ���� �Լ�>

char tempmap[30][80]; //���� ������ ���� �� �ӽ����� �迭 
char tempR[30][80]; //resume(�簳) ȿ���� ���� �� �ӽ����� �迭 

//==========================================================================�Ʒ��� �׷��� �Լ� ���==========================================================================
void drawmap(int* x, int* y) //�� �׸��� �Լ� 
{
	system("cls"); //ȭ�� �ʱ�ȭ 
	int a, b; //���� ���� ���� 
	for(a=0; a<30; a++) 
	{
		gotoxy(10, a+5); //(0,0)���� ���� ���η� 10, ���η� 5��ŭ ������ �������� �� ���� ���� 
		for(b=0; b<80; b++)
		{
			char temp=tempmap[a][b];
			if(temp=='0')
			{
	            setcolor(black, black); //0�� ���� 
                printf(" ");
            }
            else if(temp=='1')
            {
                setcolor(white, white); //1�� �Ͼ�� 
                printf("#");
            }
            else if(temp=='s')
            {
            	*x=b+10;
            	*y=a+5;
                setcolor(cyan, cyan); // �÷��̾�� �ʷϻ� 
                printf("@");
            }
            else if(temp=='q')
            {
            	setcolor(red, red); //��ֹ��� ������ 
                printf("O");
            }
            else if(temp=='k')
            {
            	setcolor(yellow, yellow); //����� ����� 
            	printf("*");
 		    }
 		    else if(temp=='l')
 		    {
 		    	setcolor(brown, black); //���� ������ ���� 
 		    	printf("+");
 		    }
		}
		setcolor(white, black); //�� �ʱ�ȭ 
		printf("\n");
	}
}

void drawmaph(int* x, int* y) //�� �׸��� �Լ� 
{
	system("cls"); //ȭ�� �ʱ�ȭ 
	int a, b; //���� ���� ���� 
	for(a=0; a<30; a++) 
	{
		gotoxy(10, a+5);
		for(b=0; b<80; b++)
		{
			char temp=tempmap[a][b];
			if(temp=='0')
			{
	            setcolor(black, black); //0�� ���� 
                printf(" ");
            }
            else if(temp=='1')
            {
                setcolor(red, red); //1�� �Ͼ�� 
                printf("O");
            }
            else if(temp=='s')
            {
            	*x=b+10;
            	*y=a+5;
                setcolor(cyan, cyan); // �÷��̾�� �ʷϻ� 
                printf("@");
            }
            else if(temp=='q')
            {
            	setcolor(red, red); //��ֹ��� ������ 
                printf("O");
            }
            else if(temp=='k')
            {
            	setcolor(yellow, yellow); //����� ����� 
            	printf("*");
 		    }
 		    else if(temp=='l')
 		    {
 		    	setcolor(brown, black); //���� ������ ���� 
 		    	printf("+");
 		    }
		}
		setcolor(white, black); //�� �ʱ�ȭ 
		printf("\n");
	}
}

void drawmapR(int *x, int *y) //resume�� ���� �� �׸��� �Լ� 
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

void drawmapRh(int *x, int *y) //resume�� ���� �� �׸��� �Լ� 
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
	
void titledraw(int* k) //���� �׸��� �Լ� 
{
	int alpha= rand() % (90000) + 10000; //�����ڵ� ��¿� ���� ���� ���� 
 
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
		
	}; //Ÿ��Ʋ �迭 
	
	system("cls"); //ȭ���ʱ�ȭ 

    gotoxy(2, 2);
	printf("������ȣ #%d%d�� �����ϼ̽��ϴ�.", *k, alpha); //���� �ڵ� ��� 
	
	int a, b; //���� ���� ���� 
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
	} //�� Ÿ��Ʋ ��� 
	setcolor(white, black); //�� �ʱ�ȭ 

} 

void titledrawh(int* k) //���� �׸��� �Լ� 
{
	int alpha= rand() % (90000) + 10000; //�����ڵ� ������ ���� ���� ���� 
 
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
	
	}; //Ÿ��Ʋ �迭 
	
	system("cls"); //ȭ���ʱ�ȭ 

    gotoxy(2, 2);
	printf("������ȣ #%d%d�� �����ϼ̽��ϴ�.", *k, alpha); //���� �ڵ� ��� 
	
	int a, b; //���� ���� ���� 
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
	} //�� Ÿ��Ʋ ��� 
	setcolor(white, black); //�� �ʱ�ȭ 

}  

int menudraw() //���� �޴� ��� �Լ� 
{
	int x=43; 
	int y=20;
	//�׸��� �ʱ� ���� ��ǥ 
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
		int n=keycontrol(); //����ڰ� �Է��� Ű �޾ƿͼ� n�� ���� 
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
	    //W������(n=1(DOWN)) ���� �ö󰡰�, S������ (n=2(UP)) �Ʒ��� ��������, �����̽��� ������ (n=4(SUBMIT)) 
		//������ �׸��� ��ȣ�� ��ȯ 
	}	        
}    

int menudrawh() //���� �޴� ��� �Լ� 
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

void infodraw() //���� ��Ģ ���� �Լ� 
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
	} //�����̽��� ���� �ÿ��� �ݺ��� ����, �Լ� Ż�� 
}

int maplistdraw() //�� ����Ʈ �׸��� 
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
	//�׸� 
	
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
	} //�׸� ���� �̵� �ݺ��� 
}

void drawui(int *x, int *y, int *key, int *health)
{
	setcolor(white, black); //���ڻ� ��� 
	gotoxy(10, 2);
	printf("Position: %02d, %02d", *x, *y);
	
	setcolor(red, black); //���ڻ� ������ 
	gotoxy(80, 2);
	printf("HEALTH: %d", *health);
	
	setcolor(yellow, black); //���ڻ� ����� 
	gotoxy(45, 2);
	printf("Key: %d", *key);
} //���� �� �� UI  
	

//==========================================================================�Ʒ��� ��� �Լ� ���==========================================================================
int keycontrol() //Ű �ν� �Լ� 
{
	char temp=getch(); //Ű �� �������� 
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
	    //�ҹ��� �빮�� ���� ���� 
		//game.h������� ��ũ�η� ������  
}

int deathb() //�׾����� ��� ���� 
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
		 
void gloop(int mc) //���� ���� ���� ���� 
{	
    int maxkey; //�� ���� �� �ִ� ���谳�� 
    
    death=0; //ó������ ���� �ʾ����Ƿ� ���� Ȯ�� ���� ������ 0���� 
    int tempnum; //���� Ȯ�� 2�� ���� 
    int c1=0; //���� Ŭ���� Ȯ�� ���� 
	tmpo=0; //���� �Ϸ� Ȯ�� ���� 
	int key=0; //���� ���� 
	int health=3; //ü�� 
	int x, y; //��ġ ���� 
	int playing=1; //���� ������ Ȯ���ϴ� ���� 
	
	if(mc==0) //���� ����Ʈ���� ù��° �׸��� ������ ��� 
	{
		maxkey=5; //�ִ뿭�� ����=5 
		memcpy(tempmap, map1, sizeof(tempmap)); //�� �迭 ��ü�� tempmap(���� ���� ���� �ӽø� �迭)�� ���� 
	    memcpy(tempR, map1, sizeof(tempR)); //�� �迭 ��ü�� tempR(���� �������� �� �簳�� �� �̿��)�� ���� 
	}
	
	else if(mc==1) //���� ����Ʈ���� �ι�° �׸��� ������ ��� 
	{
		if(comp[0]==1) //�� ���� Ŭ���� �ÿ� �۵� 
		{
			maxkey=6;
			memcpy(tempmap, map2, sizeof(tempmap));
			memcpy(tempR, map2, sizeof(tempR));
		}
		
		else if(comp[0]==0) //�� ���� Ŭ���� �ȵɽÿ� �۵� 
		{
			system("cls");
			gotoxy(36, 19);
			printf("<PREVIOUS LEVEL NOT COMPLETED>");
			Sleep(2000);
			int m1= maplistdraw(); //���� ����Ʈ �ٽ� �׸� 
		    gloop(m1); //����Ʈ���� ������ �׸����� ���� ���� ����� 
		    return;
        }
	}
	
	else if(mc==2)
	{
		if(comp[1]==1) //�� ���� Ŭ���� �ÿ� �۵� 
		{
			maxkey=5;
			memcpy(tempmap, map3, sizeof(tempmap));
			memcpy(tempR, map3, sizeof(tempR));
		}
		
		else if(comp[1]==0) //�� ���� Ŭ���� �ȵɽÿ� �۵� 
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
		if(comp[2]==1) //�� ���� Ŭ���� �ÿ� �۵� 
		{
			maxkey=6;
			memcpy(tempmap, map4, sizeof(tempmap));
			memcpy(tempR, map4, sizeof(tempR));
		}
		
		else if(comp[2]==0) //�� ���� Ŭ���� �ȵɽÿ� �۵� 
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
		if(comp[3]==1) //�� ���� Ŭ���� �ÿ� �۵� 
		{
			maxkey=6;
			memcpy(tempmap, map5, sizeof(tempmap));
			memcpy(tempR, map5, sizeof(tempR));
		}
		
		else if(comp[3]==0) //�� ���� Ŭ���� �ȵɽÿ� �۵� 
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
	//�� ���� �̿Ϸ�� ���, �� ���� ���� 
	
	else if(mc==5)
	{
		return; //�Լ� Ż�� 
	}
	// �� �ڵ�: �� ���� �޾ƿͼ� tempmap�� �����ϴ� ���� 
	 
	drawmap(&x, &y); //tempmap ������ �������� �� �׸��� 
	
	B:
		
	while(playing) //playing=1�̸� ���� �� 
	{
		if(death) //���� Ȯ�� ��������=1�� �Ǹ� �۵� 
		{
			playing=0; //���� ���� ���� ��Ÿ���� ���� playing�� 0�� ����->���� ������ ���� 
			setcolor(white, black);
			system("cls");
			tempnum=deathb(); //�Լ� ������ ��� �޾ƿ� 
			if(tempnum==0)
			{
				playing=1;
			    gloop(mc);
			    return;
			    //���� ����� ���� �� 
			}
			
			else if(tempnum==1)
			{
				playing=0;
				int abc1=maplistdraw();
				gloop(abc1);
				return;
				//���� �޴��� ���ư��� ���� �� 
			}
			
			else if(tempnum==2)
			{
				playing=0;
				return;
				//���� ���� ���� ��->����ȭ������ ����  
			}
				  
		}
		//�� �ڵ�: ������ Ȯ�ε� �� �ܰ� 
	
	    //�Ʒ� �ڵ�: ���� ���� �� ������ ���� 
		int key1=keycontrol(); //Ű���� �Է� �޾ƿ� 
		switch(key1) 
		{
			before:
			case UP:
				while(1)
				{
					drawui(&x, &y, &key, &health); //��� UI �׸� 
					move(&x, &y, 0, -1, &key, &health, &playing, maxkey); //move�Լ� ���� 
		        	Sleep(70); //�÷��̾� ���ǵ� ������ Ÿ�� ������ 
		        	if(kbhit() || tmpo || death)
		        	{
		        		break; //�ٸ� Ű���� �Է��� �����Ǿ��ų�, ������ �Ϸ��߰ų�, �׾����� �ݺ��� Ż�� 
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
	//ĳ���� �����̱�
		
			 
	system("cls");
	setcolor(white, black);
	//ȭ�� �ʱ�ȭ
	 
	if(tmpo==1) //���� ����� � ���� ����ߴ��� ��� 
	{
		comp[mc]=1;
		gotoxy(42, 19);
		printf("COMPLETED LEVEL %d!", mc+1); 
		Sleep(2000);
		int k1= maplistdraw();
		gloop(k1);
		return;
	}
	
	else if(tmpo==0) //���� ������ϰ� esc ���� �� �Ͻ����� �޴� ��� 
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
		//���� �簳(RESUME) ���� �� �ӽ� �� ��� �Լ� drawmapR���� ����� �� �ٽ� ��� �� ���� ����� 
		
		else if(cho==1)
		{
			playing=0;
			gloop(mc);
		}
		//���� �����(DIE) ���� �� ó������ �ٽ� ����->�ʵ� ó������ �ʱ�ȭ 
		
	    else if(cho==2)
		{
			int ab= maplistdraw();
			gloop(ab);
		}
		//���� �޴��� ���ư��� 
		
		else if(cho==3)
		{
			return;
		}
		//���� ����->���� ȭ������ ���� 
    }
}

void glooph(int mc) //���� ���� ���� ���� 
{	
    int maxkey; //�ִ� ���� ���� 
    
    death=0; //���� Ȯ�� ���� ����  
    int tempnum; //���� Ȯ�� 2�� ���� 
    int c1=0; //���� Ŭ���� Ȯ�� ���� 
	tmpo=0; //���� �Ϸ� Ȯ�� ���� 
	int key=0; //���� ���� 
	int health=3; //ü�� 
	int x, y; //��ġ ���� 
	int playing=1; //������ Ȯ�� ���� 
	
	if(mc==0)
	{
		if(comp[4]==1) //�� ���� Ŭ���� �ÿ� �۵� 
		{
			maxkey=5;
			memcpy(tempmap, map1, sizeof(tempmap));
			memcpy(tempR, map1, sizeof(tempR));
		}
		
		else if(comp[4]==0) //�� ���� Ŭ���� �ȵɽÿ� �۵� 
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
		if(comp[5]==1) //�� ���� Ŭ���� �ÿ� �۵� 
		{
			maxkey=6;
			memcpy(tempmap, map2, sizeof(tempmap));
			memcpy(tempR, map2, sizeof(tempR));
		}
		
		else if(comp[5]==0) //�� ���� Ŭ���� �ȵɽÿ� �۵� 
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
		if(comp[6]==1) //�� ���� Ŭ���� �ÿ� �۵� 
		{
			maxkey=5;
			memcpy(tempmap, map3, sizeof(tempmap));
			memcpy(tempR, map3, sizeof(tempR));
		}
		
		else if(comp[6]==0) //�� ���� Ŭ���� �ȵɽÿ� �۵� 
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
		if(comp[7]==1) //�� ���� Ŭ���� �ÿ� �۵� 
		{
			maxkey=6;
			memcpy(tempmap, map4, sizeof(tempmap));
			memcpy(tempR, map4, sizeof(tempR));
		}
		
		else if(comp[7]==0) //�� ���� Ŭ���� �ȵɽÿ� �۵� 
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
		if(comp[8]==1) //�� ���� Ŭ���� �ÿ� �۵� 
		{
			maxkey=6;
			memcpy(tempmap, map5, sizeof(tempmap));
			memcpy(tempR, map5, sizeof(tempR));
		}
		
		else if(comp[8]==0) //�� ���� Ŭ���� �ȵɽÿ� �۵� 
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
	//�� ���� �̿Ϸ�� ���, �� ���� ���� 
	
	else if(mc==5)
	{
		return;
	}
	//�� ���� �޾ƿ���
	 
	drawmaph(&x, &y); //�� �׸��� 
	
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
		//������ Ȯ�ε� �� �ܰ� 
	
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
	//ĳ���� �����̱�
		
			 
	system("cls");
	setcolor(white, black);
	//ȭ�� �ʱ�ȭ
	 
	if(tmpo==1) //���� ��� ��(tmpo=1) � ���� ����ߴ��� ��� �� return 
	{
		comp[mc+5]=1;
		gotoxy(42, 19);
		printf("COMPLETED LEVEL %d!", mc+1); 
		Sleep(2000);
		int k1= maplistdraw();
		glooph(k1);
		return;
	}
	
	else if(tmpo==0) //���� ������ϰ� esc ���� �ÿ� return 
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

void move(int *x, int *y, int _x, int _y, int* key, int *health, int *playing, int maxk) //ĳ���� ������ ��Ŀ���� 
{
	int ini=0;
	if(*health==0)
	{
		death=1;
	} //ü���� 0�� �� ���, �������� death�� 1�� ����->gloop�Լ� ������ ���� ���� �ڵ� ����  
	char mapobj=tempmap[*y+_y-5][*x+_x-10]; //���� ��ġ�� ���� �ش� �������� _x, _y��ŭ �̵��� ��ġ�� �����ϴ� ���� ���� 
    setcolor(white, black);

    if(mapobj=='0') //������ �� ������ ��� 
    {
        gotoxy(*x, *y);
	    printf(" ");
	    
		setcolor(cyan, cyan);
		gotoxy(*x+_x, *y+_y);
		printf("@");
		
		tempR[*y-5][*x-10]='0';
		tempmap[*y-5][*x-10]='0'; //�� ���� 
		
		//�÷��̾� ���� ��ġ�� �������� �����, ���� ��ġ�� �÷��̾� ��� 
		
		*x+=_x;
	    *y+=_y;
	    //�÷��̾� ��ǥ�� ���� 
	    
	    tempR[*y-5][*x-10]='s';
	    tempmap[*y-5][*x-10]='s'; //�� ���� 
	}
	
	else if(mapobj=='q') //������ ���� ���� ��� 
	{
	    *health -= 1; //ü�� ���� 
	    Sleep(500); //0.5�� ������ (ü���� �ʹ� ���� �ӵ��� ���ҵǴ� �� �����ϱ� ���� ����)
		//ü�� ���� �� �����̸� �־� ���� �׼��� ���� �� �ֵ��� �� ���� ������ ���� �־������� �� 
		//�ش� �ڵ尡 ������ ���� ���� �ε����ڸ��� �÷��̾� ü���� 0�� �ǹ��� 
	    tempR[*y-5][*x-10]='q';
	    tempmap[*y-5][*x-10]='q'; //�� ���� 
	}
	
	else if(mapobj=='k') //������ ������ ��� 
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
		
		//���迡 +1, �÷��̾� �̵� 
	}
	
	else if(mapobj=='l') //������ ������ ���� ��� 
	{
		if(*key>=maxk) //ȹ���� ������ ���� �ʿ��� �䱸�Ǵ� �ִ� ������ ���� �Ѿ �� 
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
	        *key=0; //������ ���� 0���� �ʱ�ȭ 
			ini=1;  
			
			tempR[*y-5][*x-10]='l';
			tempmap[*y-5][*x-10]='l';
			setcolor(white, black);
			
			if(ini==1) //�� ��� Ȯ�� 
			{
				printf("\a"); //����� ��� 
				setcolor(white, black);
				*playing=0;
				tmpo=1; //��� ����=1�� �ٲ� 
			}
			
		}
	}
			
}

void moveh(int *x, int *y, int _x, int _y, int* key, int *health, int *playing, int maxk) //ĳ���� ������ ��Ŀ���� 
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
			
			if(ini==1) //�� ��� Ȯ�� 
			{
				printf("\a");
				setcolor(white, black);
				*playing=0;
				tmpo=1; //��� ����=1�� �ٲ� 
			}
			
		}
	}
			
}
