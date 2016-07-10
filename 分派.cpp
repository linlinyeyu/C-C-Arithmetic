#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#define COUNT 64
 
 
//���������ַ�ṹ�� 
typedef struct PhysicalADD
{
       //����� 
      int cylinum ;
      //�ŵ��� 
      int tracknum ;
      //������ 
      int sectornum ;
}PhADD;
 
//λʾͼ�������鹲8�����棬ÿ��������2���ŵ������棩��ÿ���ŵ��ֳ�4�������¼����Ҫ64λ����ʾλʾͼ��filename��¼���б�����ļ��� 
struct bitmapinfo
{ 
    int bitmap[COUNT]  ;
    char filename[COUNT][32];
};
 
struct bitmapinfo *bitinfo = NULL; 
 
//showbitmap���������ܴ�ӡλʾͼ��Ϣ 
void showbitmap(void)
{
     int i = 0; 
     //������λʾͼbitmap����õ�ĳλ��״̬ 
     printf("��ǰϵͳ����λʾͼ��0��ʾ����ã���\n");
      
     for( ;i<COUNT;i++)
     {    
          if( 0==i%8)
          {
              printf("\n");   
          } 
          printf("%d��:%d\t",i+1,bitinfo->bitmap[i]);
     }
      
     system("pause");
}
 
//diskallocate���������������� 
void diskallocate(void)
{
     //���û�������Ҫ����������� 
     int neednum;
     int i ;
     int busy = 0;
     char filestor[32]; 
      
     printf("������Ҫ����Ŀ���:\n");
     scanf("%d",&neednum);
     printf("�����ļ���:\n");
     scanf("%s",filestor);
      
     for( i=0;i<COUNT;i++)
     {
          busy =busy + bitinfo->bitmap[i]; 
     }
     if( 64-busy<neednum )
     {
                     printf("û���㹻�Ŀ��д��̣�����ʧ�ܣ�");
     }
     else
     {
          printf("��ʼ����...\n"); 
          for(i=0 ; i<COUNT; i++)
          {
              if( 0==bitinfo->bitmap[i])
              {
                  printf("����������ַΪ:��%d�����棬\t��%d���ŵ�,\t��%d������\n",i/8+1,i%8/4,(i%8)%4);
                  bitinfo->bitmap[i] = 1;
                  strcpy(bitinfo->filename[i] , filestor);
                  neednum--;
              }
              if( 0==neednum)
              {
                  break;
              }
               
          }
          printf("����ɹ���\n");   
     }
      
     system("pause");
}
 
void diskreturn(void)
{
     char filereturn[32]; 
     int i;
      
     printf("����Ҫ���յ��ļ���");
     scanf("%s",filereturn);
     for( i=0;i<COUNT;i++)
     {
         if( 0!=strcmp(filereturn,bitinfo->filename[i]) )
         {
             continue;     
         }
         else
         {
             bitinfo->bitmap[i] = 0; 
             printf("����λʾͼ�е�%d�ֽڵĵ�%dλ�������\n",i/8+1,i%8+1);
         }
     }
     system("pause");
}
 
 
int main (void)
{
     int j;
     //binfo��ʼ��
     bitinfo = (struct bitmapinfo *)malloc(sizeof(struct bitmapinfo));
     for( j=0; j<COUNT;j++)
     {
         bitinfo->bitmap[j]=0;
         memset( bitinfo->filename[j], 0, sizeof(char)*32 ); 
     }
 
    //����ѡ�� 
    int func = 0;
      
     while( 1 )
     {
           printf("******************�״���Ӧ�㷨ʵ���������ͻ���ϵͳ****************************");
           printf("|1:�鿴����λʾͼ\n");
           printf("|2:���������̿ռ�\n");
           printf("|3:������մ��̿ռ�\n");
           printf("|4:�˳�����\n");
           printf("********************************************************************************");
           scanf("%d",&func);
           switch( func )
           {
                   case 1 :showbitmap();break;
                   case 2 :diskallocate();break;
                   case 3 :diskreturn();break; 
                   case 4 :return 1;
           }
     }   
     
}
