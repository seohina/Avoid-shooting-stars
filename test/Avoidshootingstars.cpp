#include <stdio.h>          
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>
#include <MMSystem.h>
#pragma comment(lib, "winmm.lib" )
#include"Structure.cpp"
#define MAX_STAR      100

#pragma comment(lib, "winmm.lib")
#include "Mmsystem.h"
#include "Digitalv.h"
MCI_OPEN_PARMS m_mciOpenParms;                             //���� ���� ����� ���� MCI�Լ�
MCI_PLAY_PARMS m_mciPlayParms;
DWORD m_dwDeviceID;
MCI_OPEN_PARMS mciOpen;
MCI_PLAY_PARMS mciPlay;
int dwID;

typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE;

struct r
{
   int x1, y1;                                             //���ּ� ��ǥ ������ ���� ����ü ����
}R;

void setcursortype(CURSOR_TYPE c)                           //Ŀ���� ��������� �Լ� ����
{
         CONSOLE_CURSOR_INFO CurInfo;
         switch (c)
         {
         case NOCURSOR:
                 CurInfo.dwSize = 1;
                 CurInfo.bVisible = FALSE;
                 break;
         case SOLIDCURSOR:
                 CurInfo.dwSize = 100;
                 CurInfo.bVisible = TRUE;
                 break;
         case NORMALCURSOR:
                 CurInfo.dwSize = 20;
                 CurInfo.bVisible = TRUE;
                 break;
         }
         SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo);
}

void gotoxy(int x, int y)                        //��ǥ ����� ���� gotoxy�Լ� ����
{
         COORD CursorPosition = { x, y };
         SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CursorPosition);
}

int MAP()
{                                              //���� ���� ����ϴ� �Լ� ����
   int u=0, t=0;
   
   for(u=0;u<81;u++)
   {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
      gotoxy(u,0);
      printf("*");
      gotoxy(u,25);
      printf("*");
   }
   for(t=0;t<25;t++)
   {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
      gotoxy(0,t);
      printf("*");
      gotoxy(80,t);
      printf("*");
   
   
}
   return 0;
}

struct d                       //4���� ���˺��� ��ǥ ������ ���� ����ü ����
{
   int x2, y2, a2, b2, c2, g2, e2, f2;
   
}stars[MAX_STAR];

struct I                     //������ ��ǥ ������ ���� ����ü ����
{
   int j, u;
}item;
 


void MenuPrint (){              //�޴��� ����ϴ� �Լ� ����
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    printf("                                                                                  \n\n\n\n");

   printf("                                                 ���˺� ���ϱ� ���� ! \n\n\n\n");
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    printf("                                    �ڡڡڡڡڡڡڡڡڡ� �޴� �ڡڡڡڡڡڡڡڡڡ�\n\n\n\n");
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    printf("                                                  1. �� �� �� ��\n\n\n\n");
    printf("                                                  2. �� �� �� ��\n\n\n\n");
    printf("                                                  3. �� �� �� ŷ\n\n\n\n"); 
    printf("                                                  4. �� �� �� ��\n\n\n\n");
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    printf("                                    �ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�\n\n\n\n"); 
      
}


int main()           //�����Լ� ����
{
    int select, t;
   setcursortype(NOCURSOR);
z:
   mciSendCommandW(dwID, MCI_CLOSE, 0, NULL); 
   mciOpen.lpstrElementName = "bgm.wav";                     //�޴������� ������� ���
 mciOpen.lpstrDeviceType = "mpegvideo";
 
 mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_ELEMENT|MCI_OPEN_TYPE,
  (DWORD)(LPVOID)&mciOpen);
 
 dwID = mciOpen.wDeviceID;
 
  mciSendCommand(dwID, MCI_PLAY, MCI_DGV_PLAY_REPEAT, 
     (DWORD)(LPVOID)&m_mciPlayParms);
    x:
    MenuPrint();
   y:
    select=getch();
  
   if (select=='1')     //1 �Է� ���� ����
   {

  sndPlaySoundA("jump.wav",SND_ASYNC | SND_NODEFAULT | NULL);            //�÷��� ���� �Լ��� ȿ���� ���

      double level=0;
	  mciSendCommandW(dwID, MCI_CLOSE, 0, NULL);       
      mciOpen.lpstrElementName = "bgm2.wav";                 //���� ���� �� ����� ���
 mciOpen.lpstrDeviceType = "mpegvideo";
 
 mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_ELEMENT|MCI_OPEN_TYPE,
  (DWORD)(LPVOID)&mciOpen);
 
 dwID = mciOpen.wDeviceID;
 
  mciSendCommand(dwID, MCI_PLAY, MCI_DGV_PLAY_REPEAT,
     (DWORD)(LPVOID)&m_mciPlayParms);
        system("cls");
        MAP();                                           //���� ��� ���
        {
   setcursortype(NOCURSOR);
     R.x1 = 40, R.y1 = 12;                               //���ּ��� ��� ��ġ�ϰ� �ʱ�ȭ
       char ch;
       int abc=1;
       item.j = NULL;                                    //������ �ּ� �ʱ�ȭ
      item.u = NULL;
     clock_t start, end, zxc;
     double pst;                                         //���� �÷��� �ð��� ��� �����ϱ� ���� ���� ����

         gotoxy(R.x1, R.y1);
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);


   srand(time(NULL));
   int i, j;
   int count= 1 + level;                                 //������ �ø��� ����� ���� ����
   
   for(i=0;i<50;i++)                                     //4������ ���˺��� �ʱ�ȭ
   {
      stars[i].x2=rand()%77+2;
      stars[i].y2=rand()%2+2;
   }
   for(i=0;i<50;i++)
   {
      stars[i].c2=rand()%2+2;
      stars[i].g2=rand()%22+2;
   }
   for(i=0;i<50;i++)
   {
      stars[i].a2=rand()%77+2;
      stars[i].b2=rand()%2+22;
   }
   for(i=0;i<50;i++)
   {
      stars[i].e2=rand() % 2 + 77;
      stars[i].f2=rand()%22 + 2;
   }
   printf("������");                                       //���ּ� ���
      gotoxy(R.x1, R.y1+3);
      
       gotoxy(R.x1-10,R.y1+1);
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	   printf("Ű���带 ����� ��ȯ���ּ���.");
	   gotoxy(R.x1, R.y1+4);
      
       gotoxy(R.x1-10,R.y1+2);
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	  printf("�ƹ�Ű �Է½� ���� ����\n");
    while(1){
          if(kbhit()==0)                                  //kbhit()�� ����ؼ� �ƹ�Ű �Է½� ���� �����ϰ� ����
             continue;
        else{
             gotoxy(R.x1-10,R.y1+1);
             printf("                             ");      //���� ��� ȭ�鿡�� ��µ� ���� ����
          gotoxy(R.x1-2, R.y1);
                 printf("            ");
             gotoxy(R.x1, R.y1+3);
             printf("                             ");
			 gotoxy(R.x1-10, R.y1+2);
             printf("                             ");
             break;
          }

          }
   start = clock();                                       //���� �ð��� ����
   int p=1;                               //���˺� ������ ���� ���� ����
   while(abc)
   {
      if(p%50==0)                         //P�� �����Ͽ� 50�� ����� �Ǹ� �������� �÷��ش�.
   {
      level=level+1;
      count = level+1 ;
   }

      for(i=0;i<count;i++)
      {
       //������ �Ʒ��� ���� ���˺� ��� �� �ʱ�ȭ
         stars[i].y2++;
         if(stars[i].y2 >= 25 )
                {
               gotoxy(stars[i].x2, stars[i].y2-1);            
                printf("   ");
                    stars[i].x2 = rand() % 74 + 2;
                    stars[i].y2 = rand()%1 + 2;
            }
       gotoxy(stars[i].x2, stars[i].y2-1);
                printf("   ");
             gotoxy(stars[i].x2, stars[i].y2);
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                printf("��");
            //�Ʒ����� ���� ���� ���˺� ��� �� �ʱ�ȭ
            stars[i].b2--;
         if(stars[i].b2 <= 0 )
                {
               gotoxy(stars[i].a2, stars[i].b2+1);
                printf("   ");
                    stars[i].a2 = rand() % 74 + 2;
                    stars[i].b2 = rand()%1+23;
            }
       gotoxy(stars[i].a2, stars[i].b2+1);
                printf("   ");
             gotoxy(stars[i].a2, stars[i].b2);
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                printf("��");

         //���ʿ��� ���������� ���� ���˺� ��� �� �ʱ�ȭ
         stars[i].c2++;
         if(stars[i].c2 >= 78 )
                {
               gotoxy(stars[i].c2-1, stars[i].g2);            
                printf("  ");
                    stars[i].c2 = rand() % 2 + 2;
                    stars[i].g2 = rand()%22 + 2;
            }
       gotoxy(stars[i].c2-1, stars[i].g2);
                printf(" ");
             gotoxy(stars[i].c2, stars[i].g2);
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                printf("��");
            //�����ʿ��� �������� ���� ���˺� ��� �� �ʱ�ȭ
             stars[i].e2--;
         if(stars[i].e2 <= 1 )
                {
               gotoxy(stars[i].e2+1, stars[i].f2);            
                printf("  ");
                    stars[i].e2 = rand() % 2 + 76;
                    stars[i].f2 = rand()%22 + 2;
            }
       gotoxy(stars[i].e2+1, stars[i].f2);
                printf("  ");
             gotoxy(stars[i].e2, stars[i].f2);
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                printf("��");
            
            gotoxy(item.j, item.u);                                           //������ ��ǥ�� ��Ʈ ���
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
          printf("��");
          
          
          gotoxy(0, 0);
           SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
          printf("*");

             

             gotoxy(R.x1, R.y1);
                 printf("   ");
             if(kbhit()==1){                         //Ű�� �Է����� �������� ���˺��� �����̰� �ϱ� ���ؼ� kbhit()���
             ch=getch();
                 switch (ch)                         //����ġ���� ����ؼ� w, a, s, d�� ���ּ��� �����̰� ����
                 {
                 case 119:
                          if (R.y1 > 1) R.y1--;
                          break;
                 case 115:
                          if (R.y1 < 24) R.y1++;
                          break;
                 case 97:
                          if (R.x1 > 1) R.x1--;
                          break;
                 case 100:
                          if (R.x1 < 73) R.x1++;
                    break;
                 } 
             }
          
          
         
           
             SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            gotoxy(R.x1, R.y1);
              printf("��");                
            printf(" ");

            if((stars[i].a2==R.x1 && stars[i].b2==R.y1)||(stars[i].a2==R.x1-1 && stars[i].b2==R.y1)||(stars[i].a2==R.x1+1 && stars[i].b2==R.y1))
         {   //���˺��� ���ּ��� �浹�ϸ� 
			 sndPlaySoundA("stop.wav",SND_ASYNC | SND_NODEFAULT | NULL); //ȿ���� ���
            end=clock();                                                   //���� �ð� ����
            pst = (double)(end-start)/CLK_TCK;                             //������ �÷����� �ð� pst�� ����
            printf("����ð� : %.2f\n", pst);
           

         FILE *fp;                               //���Ͽ� ��ŷ�� �����ϱ� ���ؼ� ���ϼ���
       ranking();
         fp=fopen("sample.txt", "w");
         printf("�г����� �Է��ϼ��� : ");
         scanf("%s", d[10].B);                     //�г����� ����ü�� �Է�
       d[10].p=pst;
        
            abc=0;
         while(1)
    {    
        for(i=0;i<10;i++)                         //for������ ��ŷ�� �����Ѵ�.
        {
            if(d[i].p<=d[i+1].p)                  //��������
            {
                d[11]=d[i+1];
                d[i+1]=d[i];
                d[i]=d[11];
            }
        }
        if(d[0].p>=d[1].p&&d[1].p>=d[2].p&&d[2].p>=d[3].p&&d[3].p>=d[4].p&&d[4].p>=d[5].p&&d[5].p>=d[6].p&&d[6].p>=d[7].p&&d[7].p>=d[8].p&&d[8].p>=d[9].p&&d[9].p>=d[10].p)
         break;
 
    }
         for(i=0;i<12;i++)                    //���Ͽ� �ٽ� ����
         {
         fprintf(fp,"%s   ",d[i].B);
         fprintf(fp, "%.2f\n", d[i].p);
         }
         fclose(fp);
       system("cls");
	   sndPlaySoundA("jump.wav",SND_ASYNC | SND_NODEFAULT | NULL); //ȿ���� ���
       goto z;
         }
            if((stars[i].c2==R.x1 && stars[i].g2==R.y1)||(stars[i].c2==R.x1-1 && stars[i].g2==R.y1)||(stars[i].c2==R.x1+1 && stars[i].g2==R.y1))
             {//���˺��� ���ּ��� �浹�ϸ� 
			 sndPlaySoundA("stop.wav",SND_ASYNC | SND_NODEFAULT | NULL); //ȿ���� ���
            end=clock();                                                   //���� �ð� ����
            pst = (double)(end-start)/CLK_TCK;                             //������ �÷����� �ð� pst�� ����
            printf("����ð� : %.2f\n", pst);
           

         FILE *fp;                               //���Ͽ� ��ŷ�� �����ϱ� ���ؼ� ���ϼ���
       ranking();
         fp=fopen("sample.txt", "w");
         printf("�г����� �Է��ϼ��� : ");
         scanf("%s", d[10].B);                     //�г����� ����ü�� �Է�
       d[10].p=pst;
        
            abc=0;
         while(1)
    {    
        for(i=0;i<10;i++)                         //for������ ��ŷ�� �����Ѵ�.
        {
            if(d[i].p<=d[i+1].p)                  //��������
            {
                d[11]=d[i+1];
                d[i+1]=d[i];
                d[i]=d[11];
            }
        }
        if(d[0].p>=d[1].p&&d[1].p>=d[2].p&&d[2].p>=d[3].p&&d[3].p>=d[4].p&&d[4].p>=d[5].p&&d[5].p>=d[6].p&&d[6].p>=d[7].p&&d[7].p>=d[8].p&&d[8].p>=d[9].p&&d[9].p>=d[10].p)
         break;
 
    }
         for(i=0;i<12;i++)                    //���Ͽ� �ٽ� ����
         {
         fprintf(fp,"%s   ",d[i].B);
         fprintf(fp, "%.2f\n", d[i].p);
         }
         fclose(fp);
       system("cls");
	   sndPlaySoundA("jump.wav",SND_ASYNC | SND_NODEFAULT | NULL); //ȿ���� ���
       goto z;
         }
            if((stars[i].e2==R.x1 && stars[i].f2==R.y1)||(stars[i].e2==R.x1-1 && stars[i].f2==R.y1)||(stars[i].e2==R.x1+1 && stars[i].f2==R.y1))
             {//���˺��� ���ּ��� �浹�ϸ� 
			 sndPlaySoundA("stop.wav",SND_ASYNC | SND_NODEFAULT | NULL); //ȿ���� ���
            end=clock();                                                   //���� �ð� ����
            pst = (double)(end-start)/CLK_TCK;                             //������ �÷����� �ð� pst�� ����
            printf("����ð� : %.2f\n", pst);
           

         FILE *fp;                               //���Ͽ� ��ŷ�� �����ϱ� ���ؼ� ���ϼ���
       ranking();
         fp=fopen("sample.txt", "w");
         printf("�г����� �Է��ϼ��� : ");
         scanf("%s", d[10].B);                     //�г����� ����ü�� �Է�
       d[10].p=pst;
        
            abc=0;
         while(1)
    {    
        for(i=0;i<10;i++)                         //for������ ��ŷ�� �����Ѵ�.
        {
            if(d[i].p<=d[i+1].p)                  //��������
            {
                d[11]=d[i+1];
                d[i+1]=d[i];
                d[i]=d[11];
            }
        }
        if(d[0].p>=d[1].p&&d[1].p>=d[2].p&&d[2].p>=d[3].p&&d[3].p>=d[4].p&&d[4].p>=d[5].p&&d[5].p>=d[6].p&&d[6].p>=d[7].p&&d[7].p>=d[8].p&&d[8].p>=d[9].p&&d[9].p>=d[10].p)
         break;
 
    }
         for(i=0;i<12;i++)                    //���Ͽ� �ٽ� ����
         {
         fprintf(fp,"%s   ",d[i].B);
         fprintf(fp, "%.2f\n", d[i].p);
         }
         fclose(fp);
       system("cls");
	   sndPlaySoundA("jump.wav",SND_ASYNC | SND_NODEFAULT | NULL); //ȿ���� ���
       goto z;
         }
            if((stars[i].x2==R.x1 && stars[i].y2==R.y1)||(stars[i].x2==R.x1-1 && stars[i].y2==R.y1)||(stars[i].x2==R.x1+1 && stars[i].y2==R.y1))
          {  //���˺��� ���ּ��� �浹�ϸ� 
			 sndPlaySoundA("stop.wav",SND_ASYNC | SND_NODEFAULT | NULL); //ȿ���� ���
            end=clock();                                                   //���� �ð� ����
            pst = (double)(end-start)/CLK_TCK;                             //������ �÷����� �ð� pst�� ����
            printf("����ð� : %.2f\n", pst);
           

         FILE *fp;                               //���Ͽ� ��ŷ�� �����ϱ� ���ؼ� ���ϼ���
       ranking();
         fp=fopen("sample.txt", "w");
         printf("�г����� �Է��ϼ��� : ");
         scanf("%s", d[10].B);                     //�г����� ����ü�� �Է�
       d[10].p=pst;
        
            abc=0;
         while(1)
    {    
        for(i=0;i<10;i++)                         //for������ ��ŷ�� �����Ѵ�.
        {
            if(d[i].p<=d[i+1].p)                  //��������
            {
                d[11]=d[i+1];
                d[i+1]=d[i];
                d[i]=d[11];
            }
        }
        if(d[0].p>=d[1].p&&d[1].p>=d[2].p&&d[2].p>=d[3].p&&d[3].p>=d[4].p&&d[4].p>=d[5].p&&d[5].p>=d[6].p&&d[6].p>=d[7].p&&d[7].p>=d[8].p&&d[8].p>=d[9].p&&d[9].p>=d[10].p)
         break;
 
    }
         for(i=0;i<12;i++)                    //���Ͽ� �ٽ� ����
         {
         fprintf(fp,"%s   ",d[i].B);
         fprintf(fp, "%.2f\n", d[i].p);
         }
         fclose(fp);
       system("cls");
	   sndPlaySoundA("jump.wav",SND_ASYNC | SND_NODEFAULT | NULL); //ȿ���� ���
       goto z;
         }
			//���˺��� �������� �������� ������ ��°��� ������� �ʰ� ����
         if((stars[i].a2==item.j && stars[i].b2==item.u)||(stars[i].a2+1==item.j && stars[i].b2==item.u)||(stars[i].a2==item.j+1 && stars[i].b2==item.u))
         {
            gotoxy(item.j, item.u);
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
          
         }
            if((stars[i].c2==item.j && stars[i].g2==item.u)||(stars[i].c2+1==item.j && stars[i].g2==item.u)||(stars[i].c2==item.j+1 && stars[i].g2==item.u))
               {
            gotoxy(item.j, item.u);
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
         
         }
            if((stars[i].e2==item.j && stars[i].f2==item.u)||(stars[i].e2+1==item.j && stars[i].f2==item.u)||(stars[i].e2==item.j+1 && stars[i].f2==item.u))
              {
            gotoxy(item.j, item.u);
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
          
         }
            if((stars[i].x2==item.j && stars[i].y2==item.u)||(stars[i].x2+1==item.j && stars[i].y2==item.u)||(stars[i].x2==item.j+1 && stars[i].y2==item.u))
               {
            gotoxy(item.j, item.u);
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
          
         }

      }
     zxc=clock();
     if(((zxc-start)/CLK_TCK)%10==0)            //������ 10�ʸ��� ����, �ʱ�ȭ
          {
           gotoxy(item.j, item.u);
           printf("   ");
           item.j = rand() % 77 + 2;
             item.u = rand() % 22 + 2;
         
          }
             if((R.x1==item.j && R.y1==item.u)||(R.x1==item.j-1 && R.y1==item.u))
          {    //���ּ��� �������� ������
			  sndPlaySoundA("item.wav",SND_ASYNC | SND_NODEFAULT | NULL);   //ȿ���� ���
              for(i=0;i<count;i++)            //4���� ���˺� ���
              {
                 gotoxy(stars[i].x2, stars[i].y2);
                 printf("   ");
                 stars[i].x2=rand()%77+2;
                 stars[i].y2=rand()%2+2;
              }
              for(i=0;i<count;i++)
              {
                 gotoxy(stars[i].c2, stars[i].g2);
                 printf("   ");
                 stars[i].c2=rand()%2+2;
                 stars[i].g2=rand()%22+2;
              }
              for(i=0;i<count;i++)
              {
                 gotoxy(stars[i].a2, stars[i].b2);
                 printf("   ");
                 stars[i].a2=rand()%77+2;
                 stars[i].b2=rand()%2+22;
              }
              for(i=0;i<count;i++)
              {
                 gotoxy(stars[i].e2, stars[i].f2);
                 printf("   ");
                 stars[i].e2=rand() % 2 + 77;
                 stars[i].f2=rand()%22 + 2;
              }
              item.j = 0;
              item.u = 0;
              Sleep(1000);
           
             }
    Sleep(80);
    p++;
      }
   
     
   }
       
        
   }
   else if(select=='2')        //2�Է� ��
   {
   sndPlaySoundA("jump.wav",SND_ASYNC | SND_NODEFAULT | NULL);   //ȿ���� ���
      setcursortype(NOCURSOR);
      system("cls");
         printf("\n\n\n\n\n\n\n\n\n\n       �ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ� �����̽��� �Է½� �޴��� ���ư� �ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ� \n\n");//���� ���� ���
		 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		 printf("                   ���˺� ������ ���ּ��� Ű���� w(��), a(����), s(�Ʒ�), d(������)�� �������� \n");
         printf("                  ��濡�� ���ƿ��� ���˺��� ���ϸ�, �ִ��� ���� ���� ����� �����ϴ� �����̴�.\n");
         printf("       ���� �ȿ����� �������� �����Ǵµ� �������� ������ ���˺����� �ʱ�ȭ�� ������ �� ��Ȱ�ϰ� �ϰ� �����ش�.\n\n");
		 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
         printf("       �ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�\n");
         while(1)
         {
      if(kbhit()==0||(getch()!=32))     //�����̽��� �Է½� �ٽ� �޴��� ���ư��� kbhit()���
      {
         continue;
      }
	  system("cls");
	  sndPlaySoundA("jump.wav",SND_ASYNC | SND_NODEFAULT | NULL); //ȿ���� ���
     goto x;
         }
   }
   else if(select=='3')       //3�Է� ��
   {
   sndPlaySoundA("jump.wav",SND_ASYNC | SND_NODEFAULT | NULL); //ȿ���� ���
      system("cls");
     ranking();
    printf("\n\n\n\n\n\       �ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ� �����̽��� �Է½� �޴��� ���ư� �ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�\n\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
     for(t=0;t<10;t++)        //��ŷ ���
     {
        printf("                %d                               %s                     %.2f ��\n\n", t+1, d[t].B, d[t].p);
     }
              while(1)
         {
      if(kbhit()==0||(getch()!=32))     //�����̽��� �Է½� �ٽ� �޴��� ���ư��� kbhit()���
      {
         continue;
      }
	  sndPlaySoundA("jump.wav",SND_ASYNC | SND_NODEFAULT | NULL); //ȿ���� ���
	  system("cls");
     goto x;
         }
   }
  
   else if(select=='4') //4�Է� ��
   {
   sndPlaySoundA("jump.wav",SND_ASYNC | SND_NODEFAULT | NULL); //ȿ���� ���

      printf("������ �����մϴ�...\n"); //���� ����
            return 0;
			sndPlaySoundA("jump.wav",SND_ASYNC | SND_NODEFAULT | NULL); //ȿ���� ���
   }
   else
      goto y;
   
        
    return 0;
}