#include "main.h"
#include "game.h"
#include "util.h"
//�⺻ ������� ���� 
 
int main()
{
	int trytwice=0; //ó�� ���������� Ȯ���ϴ� ���� 
	int hh=0; //HEAVEN ���̵��� HELL ���̵��� ������ �� ���Ǵ� ���� 
	int k; //���� ������ ���� ���ϰ� 
	int exitnum=0; //�α��� �������� ���� 
	char trash[100]; //txt ���Ͽ��� ������ �����ϴµ� ���̴� '/' ǥ�ø� �޾ƿ��µ� ���(�����Ⱚ ����) 
	int num=0; //�ִ� ������ 
	int a1, a2; //���� ���� �ʱ�ȭ �ݺ��� ���� 
	int b=0, c=0; //���� ���� �ݺ��� ���� 
	srand(time(NULL)); //���� ȸ���ڵ� ��� �õ� ���� 
	per iden[100]; //ȸ������ �ִ� 100�� �޴� ����ü �迭 iden
	   
	for(a1=0; a1<100; a1++)
	{
	    strcpy(iden[a1].name, "0");
		strcpy(iden[a1].id, "0");
		strcpy(iden[a1].psw, "0");   
		iden[a1].lc=0;
	}
	//���� ���� ���� �ʱ�ȭ 
	
	
	FILE *re=fopen("gamedb.txt", "rt"); //���� ���� �ؽ�Ʈ ����  
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
	//���� txt ������ ������ ��� gamedb.txt���Ͽ��� ���� ������ �о�� 
	
	for(a2=0; a2<10; a2++)
	    comp[a2]=0;
    //������ �󸶳� ������ �˷��ִ� �迭 ��� 0���� �ʱ�ȭ 
    
    if(!trytwice)
    {
		num=b-1;
		if(num<0)
		num=0;
	} //ó�� �����ϴ� ��쿡 num�� ���� ���� �ִ� ���� 
	
	int b4=0; //��� �� -> �ݺ����� �̿� 
	
	account(iden, &num, &exitnum, &k); //ȸ������ �� �α��� �޴� �Լ� 
	
	for(c=0; c<iden[k].lc; c++)
    {
   	    comp[c]=1;
    }
	
    //���� Ŭ���� ����ü ������ comp�ӽù迭�� �ٽ� ���� 
    
    HH:
	if(!exitnum) //���� ���ᰡ �ƴҶ� 
	{	
	    if(!hh)
		{	
			init(); //Ŀ�� ����� �� �ܼ� �⺻ ���� 
				
			while(1)
			{
				titledraw(&k); //Ÿ��Ʋ �׸��� 
				int mc=menudraw(); //�޴� �׸��� �������� �ޱ� 
				if(mc==0)
				{
					int n=maplistdraw(); //�� ����Ʈ �׸��� 
					gloop(n); //HEAVEN ���� ���� �ֿ� �Լ� 
					
				}
				//���ӽ��� 
				
				else if(mc==1)
					 infodraw();
			    //���� ���� 
			    
			    else if(mc==2)
			    {
			    	hh=1;
			    	goto HH;
			    }
			    //HEAVEN���� HELL�� �̵�
				 
				else if(mc==3)
				{
					trytwice=1; //ó������ Ȯ���ϴ� ������ 1�� �ٲ�(ó�� �ƴ��� �ǹ�) 
					system("cls");
					while(b4<10)
					{
						if(comp[b4] == 0)
						break;
				        b4++;
				    }
				    iden[k].lc=b4;
					//comp �ӽù迭�� ������ ����ü�� ���� (���� ��ô�� ����) 
				 	
				 		
				 	
				  	  FILE *fp=fopen("gamedb.txt", "wt"); //���� ���� �ؽ�Ʈ ���� 
				  	  for(b=0; b<num; b++)
					    {
						    fprintf(fp, "%s ", iden[b].name);
						    fprintf(fp, "%s ", iden[b].id);
						    fprintf(fp, "%s ", iden[b].psw);
						    fprintf(fp, "%d ", iden[b].lc);
						    fprintf(fp, "/ ");
						}
						//����ü�� ����� ���������� txt���Ͽ� ���� 
					fclose(fp); //���� �ݱ� 
	                goto K; //�α��� ȭ������ ���ư� 
			    }
				//�α׾ƿ� 
				
				else if(mc==4)
					 break;
			    //���� ���� 
			    
				system("cls");
			    //ȭ���ʱ�ȭ 
			}
		}
		
		if(hh) //HEAVEN ��忡�� HELL���� ��ȯ�� ��� 
		{
			init(); //Ŀ�� ����� �� �ܼ� �⺻ ���� 
				
			while(1)
			{
				titledrawh(&k); //Ÿ��Ʋ �׸��� 
				int mc=menudrawh(); //�޴� �׸��� �������� �ޱ� 
				if(mc==0)
				{
					int n=maplistdraw(); //�� �׸��� 
					glooph(n); //HELL ���� ���� �ֿ� �Լ� 
					
				}
				//���ӽ��� 
				
				else if(mc==1)
					 infodraw();
			    //���� ���� 
			    
			    else if(mc==2)
			    {
			    	hh=0;
			    	goto HH;
			    }
			    //HEAVEN ���� ���ư� 
			    
				else if(mc==3)
				{
					trytwice=1; //ó������ Ȯ���ϴ� ������ 1�� �ٲ�(ó�� �ƴ��� �ǹ�) 
					system("cls");
					while(b4<10)
					{
						if(comp[b4] == 0)
						break;
				        b4++;
				    }
				    iden[k].lc=b4;
					//comp �ӽù迭�� ������ ����ü�� ���� (���� ��ô�� ����) 
				 	
				 		
				 	
				  	  FILE *fp=fopen("gamedb.txt", "wt"); //���� ���� �ؽ�Ʈ ���� 
				  	  for(b=0; b<num; b++)
					    {
						    fprintf(fp, "%s ", iden[b].name);
						    fprintf(fp, "%s ", iden[b].id);
						    fprintf(fp, "%s ", iden[b].psw);
						    fprintf(fp, "%d ", iden[b].lc);
						    fprintf(fp, "/ ");
						} 
						//����ü�� ����� ���������� txt���Ͽ� ����
						
					fclose(fp); //���� �ݱ� 
	                goto K; //�α��� ȭ������ ���ư� 
			    }
				//�α׾ƿ� 
				
				else if(mc==4)
					 break;
			    //���� ���� 
			    
				system("cls");
			    //ȭ���ʱ�ȭ 
			}
		}
		//���� �ܼ� Ȱ��ȭ �� ���� �ܰ� 
	}
		

    //�� �Ʒ��δ� exitnum=0, �� ���� ���ᰡ Ȯ�εǾ����� ����Ǵ� �� 

        while(b4<10)
		{
			if(comp[b4] == 0)
			break;
	        b4++;
	    }
	    iden[k].lc=b4;
		//comp �ӽù迭�� ������ ����ü�� ���� 
	 	
	 		
	 	
	  	  FILE *fp=fopen("gamedb.txt", "wt"); //���� ���� �ؽ�Ʈ ���� 
	  	  for(b=0; b<num; b++)
		    {
			    fprintf(fp, "%s ", iden[b].name);
			    fprintf(fp, "%s ", iden[b].id);
			    fprintf(fp, "%s ", iden[b].psw);
			    fprintf(fp, "%d ", iden[b].lc);
			    fprintf(fp, "/ ");
			}
			
		fclose(fp); //���� ���� �ݱ� 
		fclose(re); //�б� ���� �ݱ� 
		return 0; //main �Լ� ���� 
}

