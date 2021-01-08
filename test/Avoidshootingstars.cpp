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
MCI_OPEN_PARMS m_mciOpenParms;                             //동시 음악 출력을 위한 MCI함수
MCI_PLAY_PARMS m_mciPlayParms;
DWORD m_dwDeviceID;
MCI_OPEN_PARMS mciOpen;
MCI_PLAY_PARMS mciPlay;
int dwID;

typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE;

struct r
{
   int x1, y1;                                             //우주선 좌표 저장을 위한 구조체 선언
}R;

void setcursortype(CURSOR_TYPE c)                           //커서를 지우기위한 함수 선언
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

void gotoxy(int x, int y)                        //좌표 사용을 위한 gotoxy함수 선언
{
         COORD CursorPosition = { x, y };
         SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CursorPosition);
}

int MAP()
{                                              //게임 맵을 출력하는 함수 선언
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

struct d                       //4방향 별똥별의 좌표 저장을 위한 구조체 선언
{
   int x2, y2, a2, b2, c2, g2, e2, f2;
   
}stars[MAX_STAR];

struct I                     //아이템 좌표 저장을 위한 구조체 선언
{
   int j, u;
}item;
 


void MenuPrint (){              //메뉴를 출력하는 함수 선언
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    printf("                                                                                  \n\n\n\n");

   printf("                                                 별똥별 피하기 게임 ! \n\n\n\n");
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    printf("                                    ★★★★★★★★★★ 메뉴 ★★★★★★★★★★\n\n\n\n");
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    printf("                                                  1. 게 임 시 작\n\n\n\n");
    printf("                                                  2. 게 임 설 명\n\n\n\n");
    printf("                                                  3. 게 임 랭 킹\n\n\n\n"); 
    printf("                                                  4. 게 임 종 료\n\n\n\n");
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    printf("                                    ★★★★★★★★★★★★★★★★★★★★★★★\n\n\n\n"); 
      
}


int main()           //메인함수 선언
{
    int select, t;
   setcursortype(NOCURSOR);
z:
   mciSendCommandW(dwID, MCI_CLOSE, 0, NULL); 
   mciOpen.lpstrElementName = "bgm.wav";                     //메뉴에서의 배경음악 출력
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
  
   if (select=='1')     //1 입력 게임 시작
   {

  sndPlaySoundA("jump.wav",SND_ASYNC | SND_NODEFAULT | NULL);            //플레이 사운드 함수로 효과음 출력

      double level=0;
	  mciSendCommandW(dwID, MCI_CLOSE, 0, NULL);       
      mciOpen.lpstrElementName = "bgm2.wav";                 //게임 시작 후 배경음 출력
 mciOpen.lpstrDeviceType = "mpegvideo";
 
 mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_ELEMENT|MCI_OPEN_TYPE,
  (DWORD)(LPVOID)&mciOpen);
 
 dwID = mciOpen.wDeviceID;
 
  mciSendCommand(dwID, MCI_PLAY, MCI_DGV_PLAY_REPEAT,
     (DWORD)(LPVOID)&m_mciPlayParms);
        system("cls");
        MAP();                                           //게임 배경 출력
        {
   setcursortype(NOCURSOR);
     R.x1 = 40, R.y1 = 12;                               //우주선을 가운데 위치하게 초기화
       char ch;
       int abc=1;
       item.j = NULL;                                    //아이템 주소 초기화
      item.u = NULL;
     clock_t start, end, zxc;
     double pst;                                         //게임 플레이 시간을 잠시 저장하기 위한 변수 선언

         gotoxy(R.x1, R.y1);
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);


   srand(time(NULL));
   int i, j;
   int count= 1 + level;                                 //레벨을 올릴때 사용할 변수 선언
   
   for(i=0;i<50;i++)                                     //4방향의 별똥별들 초기화
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
   printf("⊆⊙⊇");                                       //우주선 출력
      gotoxy(R.x1, R.y1+3);
      
       gotoxy(R.x1-10,R.y1+1);
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	   printf("키보드를 영어로 변환해주세요.");
	   gotoxy(R.x1, R.y1+4);
      
       gotoxy(R.x1-10,R.y1+2);
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	  printf("아무키 입력시 게임 시작\n");
    while(1){
          if(kbhit()==0)                                  //kbhit()을 사용해서 아무키 입력시 게임 시작하게 설정
             continue;
        else{
             gotoxy(R.x1-10,R.y1+1);
             printf("                             ");      //게임 대기 화면에서 출력된 값들 지움
          gotoxy(R.x1-2, R.y1);
                 printf("            ");
             gotoxy(R.x1, R.y1+3);
             printf("                             ");
			 gotoxy(R.x1-10, R.y1+2);
             printf("                             ");
             break;
          }

          }
   start = clock();                                       //시작 시간을 저장
   int p=1;                               //별똥별 증가를 위한 변수 선언
   while(abc)
   {
      if(p%50==0)                         //P가 증가하여 50의 배수가 되면 레벨값을 올려준다.
   {
      level=level+1;
      count = level+1 ;
   }

      for(i=0;i<count;i++)
      {
       //위에서 아래로 가는 별똥별 출력 및 초기화
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
                printf("★");
            //아래에서 위로 가는 별똥별 출력 및 초기화
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
                printf("★");

         //왼쪽에서 오른쪽으로 가는 별똥별 출력 및 초기화
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
                printf("★");
            //오른쪽에서 왼쪽으로 가는 별똥별 출력 및 초기화
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
                printf("★");
            
            gotoxy(item.j, item.u);                                           //아이템 좌표에 하트 출력
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
          printf("♥");
          
          
          gotoxy(0, 0);
           SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
          printf("*");

             

             gotoxy(R.x1, R.y1);
                 printf("   ");
             if(kbhit()==1){                         //키를 입력하지 않을때도 별똥별이 움직이게 하기 위해서 kbhit()사용
             ch=getch();
                 switch (ch)                         //스위치문을 사용해서 w, a, s, d로 우주선이 움직이게 설정
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
              printf("◎");                
            printf(" ");

            if((stars[i].a2==R.x1 && stars[i].b2==R.y1)||(stars[i].a2==R.x1-1 && stars[i].b2==R.y1)||(stars[i].a2==R.x1+1 && stars[i].b2==R.y1))
         {   //별똥별과 우주선이 충돌하면 
			 sndPlaySoundA("stop.wav",SND_ASYNC | SND_NODEFAULT | NULL); //효과음 출력
            end=clock();                                                   //종료 시간 측정
            pst = (double)(end-start)/CLK_TCK;                             //게임을 플레이한 시간 pst에 저장
            printf("경과시간 : %.2f\n", pst);
           

         FILE *fp;                               //파일에 랭킹을 저장하기 위해서 파일선언
       ranking();
         fp=fopen("sample.txt", "w");
         printf("닉네임을 입력하세요 : ");
         scanf("%s", d[10].B);                     //닉네임을 구조체에 입력
       d[10].p=pst;
        
            abc=0;
         while(1)
    {    
        for(i=0;i<10;i++)                         //for문으로 랭킹을 정렬한다.
        {
            if(d[i].p<=d[i+1].p)                  //버블정렬
            {
                d[11]=d[i+1];
                d[i+1]=d[i];
                d[i]=d[11];
            }
        }
        if(d[0].p>=d[1].p&&d[1].p>=d[2].p&&d[2].p>=d[3].p&&d[3].p>=d[4].p&&d[4].p>=d[5].p&&d[5].p>=d[6].p&&d[6].p>=d[7].p&&d[7].p>=d[8].p&&d[8].p>=d[9].p&&d[9].p>=d[10].p)
         break;
 
    }
         for(i=0;i<12;i++)                    //파일에 다시 저장
         {
         fprintf(fp,"%s   ",d[i].B);
         fprintf(fp, "%.2f\n", d[i].p);
         }
         fclose(fp);
       system("cls");
	   sndPlaySoundA("jump.wav",SND_ASYNC | SND_NODEFAULT | NULL); //효과음 출력
       goto z;
         }
            if((stars[i].c2==R.x1 && stars[i].g2==R.y1)||(stars[i].c2==R.x1-1 && stars[i].g2==R.y1)||(stars[i].c2==R.x1+1 && stars[i].g2==R.y1))
             {//별똥별과 우주선이 충돌하면 
			 sndPlaySoundA("stop.wav",SND_ASYNC | SND_NODEFAULT | NULL); //효과음 출력
            end=clock();                                                   //종료 시간 측정
            pst = (double)(end-start)/CLK_TCK;                             //게임을 플레이한 시간 pst에 저장
            printf("경과시간 : %.2f\n", pst);
           

         FILE *fp;                               //파일에 랭킹을 저장하기 위해서 파일선언
       ranking();
         fp=fopen("sample.txt", "w");
         printf("닉네임을 입력하세요 : ");
         scanf("%s", d[10].B);                     //닉네임을 구조체에 입력
       d[10].p=pst;
        
            abc=0;
         while(1)
    {    
        for(i=0;i<10;i++)                         //for문으로 랭킹을 정렬한다.
        {
            if(d[i].p<=d[i+1].p)                  //버블정렬
            {
                d[11]=d[i+1];
                d[i+1]=d[i];
                d[i]=d[11];
            }
        }
        if(d[0].p>=d[1].p&&d[1].p>=d[2].p&&d[2].p>=d[3].p&&d[3].p>=d[4].p&&d[4].p>=d[5].p&&d[5].p>=d[6].p&&d[6].p>=d[7].p&&d[7].p>=d[8].p&&d[8].p>=d[9].p&&d[9].p>=d[10].p)
         break;
 
    }
         for(i=0;i<12;i++)                    //파일에 다시 저장
         {
         fprintf(fp,"%s   ",d[i].B);
         fprintf(fp, "%.2f\n", d[i].p);
         }
         fclose(fp);
       system("cls");
	   sndPlaySoundA("jump.wav",SND_ASYNC | SND_NODEFAULT | NULL); //효과음 출력
       goto z;
         }
            if((stars[i].e2==R.x1 && stars[i].f2==R.y1)||(stars[i].e2==R.x1-1 && stars[i].f2==R.y1)||(stars[i].e2==R.x1+1 && stars[i].f2==R.y1))
             {//별똥별과 우주선이 충돌하면 
			 sndPlaySoundA("stop.wav",SND_ASYNC | SND_NODEFAULT | NULL); //효과음 출력
            end=clock();                                                   //종료 시간 측정
            pst = (double)(end-start)/CLK_TCK;                             //게임을 플레이한 시간 pst에 저장
            printf("경과시간 : %.2f\n", pst);
           

         FILE *fp;                               //파일에 랭킹을 저장하기 위해서 파일선언
       ranking();
         fp=fopen("sample.txt", "w");
         printf("닉네임을 입력하세요 : ");
         scanf("%s", d[10].B);                     //닉네임을 구조체에 입력
       d[10].p=pst;
        
            abc=0;
         while(1)
    {    
        for(i=0;i<10;i++)                         //for문으로 랭킹을 정렬한다.
        {
            if(d[i].p<=d[i+1].p)                  //버블정렬
            {
                d[11]=d[i+1];
                d[i+1]=d[i];
                d[i]=d[11];
            }
        }
        if(d[0].p>=d[1].p&&d[1].p>=d[2].p&&d[2].p>=d[3].p&&d[3].p>=d[4].p&&d[4].p>=d[5].p&&d[5].p>=d[6].p&&d[6].p>=d[7].p&&d[7].p>=d[8].p&&d[8].p>=d[9].p&&d[9].p>=d[10].p)
         break;
 
    }
         for(i=0;i<12;i++)                    //파일에 다시 저장
         {
         fprintf(fp,"%s   ",d[i].B);
         fprintf(fp, "%.2f\n", d[i].p);
         }
         fclose(fp);
       system("cls");
	   sndPlaySoundA("jump.wav",SND_ASYNC | SND_NODEFAULT | NULL); //효과음 출력
       goto z;
         }
            if((stars[i].x2==R.x1 && stars[i].y2==R.y1)||(stars[i].x2==R.x1-1 && stars[i].y2==R.y1)||(stars[i].x2==R.x1+1 && stars[i].y2==R.y1))
          {  //별똥별과 우주선이 충돌하면 
			 sndPlaySoundA("stop.wav",SND_ASYNC | SND_NODEFAULT | NULL); //효과음 출력
            end=clock();                                                   //종료 시간 측정
            pst = (double)(end-start)/CLK_TCK;                             //게임을 플레이한 시간 pst에 저장
            printf("경과시간 : %.2f\n", pst);
           

         FILE *fp;                               //파일에 랭킹을 저장하기 위해서 파일선언
       ranking();
         fp=fopen("sample.txt", "w");
         printf("닉네임을 입력하세요 : ");
         scanf("%s", d[10].B);                     //닉네임을 구조체에 입력
       d[10].p=pst;
        
            abc=0;
         while(1)
    {    
        for(i=0;i<10;i++)                         //for문으로 랭킹을 정렬한다.
        {
            if(d[i].p<=d[i+1].p)                  //버블정렬
            {
                d[11]=d[i+1];
                d[i+1]=d[i];
                d[i]=d[11];
            }
        }
        if(d[0].p>=d[1].p&&d[1].p>=d[2].p&&d[2].p>=d[3].p&&d[3].p>=d[4].p&&d[4].p>=d[5].p&&d[5].p>=d[6].p&&d[6].p>=d[7].p&&d[7].p>=d[8].p&&d[8].p>=d[9].p&&d[9].p>=d[10].p)
         break;
 
    }
         for(i=0;i<12;i++)                    //파일에 다시 저장
         {
         fprintf(fp,"%s   ",d[i].B);
         fprintf(fp, "%.2f\n", d[i].p);
         }
         fclose(fp);
       system("cls");
	   sndPlaySoundA("jump.wav",SND_ASYNC | SND_NODEFAULT | NULL); //효과음 출력
       goto z;
         }
			//별똥별이 아이템을 지나갈때 아이템 출력값이 사라지지 않게 설정
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
     if(((zxc-start)/CLK_TCK)%10==0)            //아이템 10초마다 생성, 초기화
          {
           gotoxy(item.j, item.u);
           printf("   ");
           item.j = rand() % 77 + 2;
             item.u = rand() % 22 + 2;
         
          }
             if((R.x1==item.j && R.y1==item.u)||(R.x1==item.j-1 && R.y1==item.u))
          {    //우주선이 아이템을 먹으면
			  sndPlaySoundA("item.wav",SND_ASYNC | SND_NODEFAULT | NULL);   //효과음 출력
              for(i=0;i<count;i++)            //4방향 별똥별 출력
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
   else if(select=='2')        //2입력 시
   {
   sndPlaySoundA("jump.wav",SND_ASYNC | SND_NODEFAULT | NULL);   //효과음 출력
      setcursortype(NOCURSOR);
      system("cls");
         printf("\n\n\n\n\n\n\n\n\n\n       ★★★★★★★★★★★★★★★★★ 스페이스바 입력시 메뉴로 돌아감 ★★★★★★★★★★★★★★★★★★ \n\n");//게임 설명 출력
		 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		 printf("                   별똥별 게임은 우주선을 키보드 w(위), a(왼쪽), s(아래), d(오른쪽)로 움직여서 \n");
         printf("                  사방에서 날아오는 별똥별을 피하며, 최대한 오래 버텨 기록을 갱신하는 게임이다.\n");
         printf("       게임 안에서는 아이템이 생성되는데 아이템을 먹으면 별똥별들이 초기화되 게임을 더 원활하게 하게 도와준다.\n\n");
		 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
         printf("       ★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★\n");
         while(1)
         {
      if(kbhit()==0||(getch()!=32))     //스페이스바 입력시 다시 메뉴로 돌아가게 kbhit()사용
      {
         continue;
      }
	  system("cls");
	  sndPlaySoundA("jump.wav",SND_ASYNC | SND_NODEFAULT | NULL); //효과음 출력
     goto x;
         }
   }
   else if(select=='3')       //3입력 시
   {
   sndPlaySoundA("jump.wav",SND_ASYNC | SND_NODEFAULT | NULL); //효과음 출력
      system("cls");
     ranking();
    printf("\n\n\n\n\n\       ★★★★★★★★★★★★★★★★★ 스페이스바 입력시 메뉴로 돌아감 ★★★★★★★★★★★★★★★★★★\n\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
     for(t=0;t<10;t++)        //랭킹 출력
     {
        printf("                %d                               %s                     %.2f 초\n\n", t+1, d[t].B, d[t].p);
     }
              while(1)
         {
      if(kbhit()==0||(getch()!=32))     //스페이스바 입력시 다시 메뉴로 돌아가게 kbhit()사용
      {
         continue;
      }
	  sndPlaySoundA("jump.wav",SND_ASYNC | SND_NODEFAULT | NULL); //효과음 출력
	  system("cls");
     goto x;
         }
   }
  
   else if(select=='4') //4입력 시
   {
   sndPlaySoundA("jump.wav",SND_ASYNC | SND_NODEFAULT | NULL); //효과음 출력

      printf("게임을 종료합니다...\n"); //게임 종료
            return 0;
			sndPlaySoundA("jump.wav",SND_ASYNC | SND_NODEFAULT | NULL); //효과음 출력
   }
   else
      goto y;
   
        
    return 0;
}