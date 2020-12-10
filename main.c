#include "main.h"
#include "game.h"
#include "util.h"
//기본 헤더파일 포함 
 
int main()
{
	int trytwice=0; //처음 실행인지를 확인하는 변수 
	int hh=0; //HEAVEN 난이도랑 HELL 난이도를 변경할 때 사용되는 변수 
	int k; //현재 접속한 계정 리턴값 
	int exitnum=0; //로그인 과정에서 종료 
	char trash[100]; //txt 파일에서 계정을 구분하는데 쓰이는 '/' 표시를 받아오는데 사용(쓰레기값 제거) 
	int num=0; //최대 계정수 
	int a1, a2; //계정 정보 초기화 반복문 변수 
	int b=0, c=0; //파일 저장 반복문 변수 
	srand(time(NULL)); //랜덤 회원코드 출력 시드 설정 
	per iden[100]; //회원정보 최대 100개 받는 구조체 배열 iden
	   
	for(a1=0; a1<100; a1++)
	{
	    strcpy(iden[a1].name, "0");
		strcpy(iden[a1].id, "0");
		strcpy(iden[a1].psw, "0");   
		iden[a1].lc=0;
	}
	//계정 정보 전부 초기화 
	
	
	FILE *re=fopen("gamedb.txt", "rt"); //정보 복구 텍스트 열기  
	K:
    if(re != NULL)
    {
		while(1)
		{
		    if(feof(re) != 0)
		    break;
		    fscanf(re, "%s %s %s %d %s", iden[b].name, iden[b].id, iden[b].psw, &iden[b].lc, trash);
		    b++;
		}
	}
	//읽을 txt 파일이 존재할 경우 gamedb.txt파일에서 계정 정보를 읽어옴 
	
	for(a2=0; a2<10; a2++)
	    comp[a2]=0;
    //레벨을 얼마나 깼는지 알려주는 배열 모두 0으로 초기화 
    
    if(!trytwice)
    {
		num=b-1;
		if(num<0)
		num=0;
	} //처음 실행하는 경우에 num에 계정 개수 최댓값 저장 
	
	int b4=0; //목록 수 -> 반복문에 이용 
	
	account(iden, &num, &exitnum, &k); //회원가입 및 로그인 메뉴 함수 
	
	for(c=0; c<iden[k].lc; c++)
    {
   	    comp[c]=1;
    }
	
    //레벨 클리어 구조체 정보를 comp임시배열에 다시 저장 
    
    HH:
	if(!exitnum) //게임 종료가 아닐때 
	{	
	    if(!hh)
		{	
			init(); //커서 숨기기 및 콘솔 기본 설정 
				
			while(1)
			{
				titledraw(&k); //타이틀 그리기 
				int mc=menudraw(); //메뉴 그리고 선택정보 받기 
				if(mc==0)
				{
					int n=maplistdraw(); //맵 리스트 그리기 
					gloop(n); //HEAVEN 게임 실행 주요 함수 
					
				}
				//게임실행 
				
				else if(mc==1)
					 infodraw();
			    //게임 설명 
			    
			    else if(mc==2)
			    {
			    	hh=1;
			    	goto HH;
			    }
			    //HEAVEN에서 HELL로 이동
				 
				else if(mc==3)
				{
					trytwice=1; //처음인지 확인하는 변수를 1로 바꿈(처음 아님을 의미) 
					system("cls");
					while(b4<10)
					{
						if(comp[b4] == 0)
						break;
				        b4++;
				    }
				    iden[k].lc=b4;
					//comp 임시배열의 내용을 구조체에 저장 (게임 진척도 저장) 
				 	
				 		
				 	
				  	  FILE *fp=fopen("gamedb.txt", "wt"); //정보 저장 텍스트 열기 
				  	  for(b=0; b<num; b++)
					    {
						    fprintf(fp, "%s ", iden[b].name);
						    fprintf(fp, "%s ", iden[b].id);
						    fprintf(fp, "%s ", iden[b].psw);
						    fprintf(fp, "%d ", iden[b].lc);
						    fprintf(fp, "/ ");
						}
						//구조체에 저장된 게임정보를 txt파일에 적음 
					fclose(fp); //파일 닫기 
	                goto K; //로그인 화면으로 돌아감 
			    }
				//로그아웃 
				
				else if(mc==4)
					 break;
			    //게임 종료 
			    
				system("cls");
			    //화면초기화 
			}
		}
		
		if(hh) //HEAVEN 모드에서 HELL모드로 전환한 경우 
		{
			init(); //커서 숨기기 및 콘솔 기본 설정 
				
			while(1)
			{
				titledrawh(&k); //타이틀 그리기 
				int mc=menudrawh(); //메뉴 그리고 선택정보 받기 
				if(mc==0)
				{
					int n=maplistdraw(); //맵 그리기 
					glooph(n); //HELL 게임 실행 주요 함수 
					
				}
				//게임실행 
				
				else if(mc==1)
					 infodraw();
			    //게임 설명 
			    
			    else if(mc==2)
			    {
			    	hh=0;
			    	goto HH;
			    }
			    //HEAVEN 모드로 돌아감 
			    
				else if(mc==3)
				{
					trytwice=1; //처음인지 확인하는 변수를 1로 바꿈(처음 아님을 의미) 
					system("cls");
					while(b4<10)
					{
						if(comp[b4] == 0)
						break;
				        b4++;
				    }
				    iden[k].lc=b4;
					//comp 임시배열의 내용을 구조체에 저장 (게임 진척도 저장) 
				 	
				 		
				 	
				  	  FILE *fp=fopen("gamedb.txt", "wt"); //정보 저장 텍스트 열기 
				  	  for(b=0; b<num; b++)
					    {
						    fprintf(fp, "%s ", iden[b].name);
						    fprintf(fp, "%s ", iden[b].id);
						    fprintf(fp, "%s ", iden[b].psw);
						    fprintf(fp, "%d ", iden[b].lc);
						    fprintf(fp, "/ ");
						} 
						//구조체에 저장된 게임정보를 txt파일에 적음
						
					fclose(fp); //파일 닫기 
	                goto K; //로그인 화면으로 돌아감 
			    }
				//로그아웃 
				
				else if(mc==4)
					 break;
			    //게임 종료 
			    
				system("cls");
			    //화면초기화 
			}
		}
		//게임 콘솔 활성화 및 종료 단계 
	}
		

    //이 아래로는 exitnum=0, 즉 게임 종료가 확인되었을때 실행되는 코 

        while(b4<10)
		{
			if(comp[b4] == 0)
			break;
	        b4++;
	    }
	    iden[k].lc=b4;
		//comp 임시배열의 내용을 구조체에 저장 
	 	
	 		
	 	
	  	  FILE *fp=fopen("gamedb.txt", "wt"); //정보 저장 텍스트 열기 
	  	  for(b=0; b<num; b++)
		    {
			    fprintf(fp, "%s ", iden[b].name);
			    fprintf(fp, "%s ", iden[b].id);
			    fprintf(fp, "%s ", iden[b].psw);
			    fprintf(fp, "%d ", iden[b].lc);
			    fprintf(fp, "/ ");
			}
			
		fclose(fp); //쓰기 파일 닫기 
		fclose(re); //읽기 파일 닫기 
		return 0; //main 함수 종료 
}

