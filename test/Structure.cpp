#include <stdio.h>
#include <stdlib.h>

struct Point              //����ü ����
{
   double p;              //�ð� ������
   char B[50];            //�г���
   int rank;              //����
};

struct Point d[12];    //����ü �迭 ����


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