#include <stdio.h>
#include <stdlib.h>

struct Point              //구조체 선언
{
   double p;              //시간 데이터
   char B[50];            //닉네임
   int rank;              //순위
};

struct Point d[12];    //구조체 배열 선언


int ranking(void)
{
   FILE *fp1;
   int m=0;

   fp1=fopen("sample.txt", "rt");

   for(m=0;m<11;m++)
   {
      fscanf(fp1,"%s   ",&d[m].B);
      fscanf(fp1,"%lf", &d[m].p);
   }

  

   fclose(fp1);
   
   return 0;
}