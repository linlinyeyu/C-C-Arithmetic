/*
*�ļ����ƣ�memory.c
*ժҪ���״���Ӧ�㷨ʵ���������ͻ��ճ���
*
*���ߣ�����
*������ڣ�2011��10��15�� 
*/
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
const int CANUSE = 1;
const int CANTUSE = 0;
//#define  MSIZE  128;
const int MSIZE = 128;
 
 
//�ڴ���� 
struct MZone
{
       //��������ʼ��ַ 
    int begin_addr; 
       //һ�������������ĳ���
    int length;       
       //״̬ 
    int state;
       //�ڴ���������
    char task_name[32];    
       //ָ����һ�����з���
    struct MZone *next;    
};
 
//�ڴ�ͷָ�� 
struct MZone *Mhead = NULL;
int Minsert(struct MZone* Mnew);
int Mreturn(char taskname[]);
 
//showmemory��������ʾ��ǰ�ڴ������� 
void showmemory()
{
     struct MZone *Mpoint = Mhead;
      
     printf("�ڴ��ʹ�����\n");
     printf("beginaddr\tlength\tstate\ttask\n"); 
      
     while( NULL!=Mpoint)
     {
         printf("%dk\t\t",Mpoint->begin_addr);
         printf("%dk\t",Mpoint->length);
         Mpoint->state?printf("CANUSE\t"):printf("CANTUSE\t");
         printf("%s\n",Mpoint->task_name);
         Mpoint = Mpoint->next;
     } 
     
     system("pause");
      
}
 
//memoallocate���������ڷ����ڴ� 
void memoallocate(void)
{
     struct MZone *Mnew = (struct MZone*)malloc(sizeof(struct MZone));
     printf("����Ҫ�����ڴ��С(kb):\n");
     scanf("%d",&Mnew->length);
     printf("����������:\n");
     scanf("%s",&Mnew->task_name);
     Minsert(Mnew)?printf("�����ڴ�ɹ�\n"):printf("û�з��ϴ�С�Ŀ��з������ڴ����ʧ�ܡ�\n"); 
     system("pause");
     free(Mnew);
}
 
//Minsert���������ܲ������񵽿��з��� 
int Minsert(struct MZone* Mnew)
{
 
     struct MZone *Zinsert = Mhead;
     //flag����ָʾ��Zinsert����NULL����û���ڴ���Է��� 
     int flag = 1;   
      
     while( Zinsert->length<Mnew->length || !Zinsert->state)
     {
             if( NULL!=Zinsert->next )
             {
                Zinsert = Zinsert->next;
             }
             else
             {   
                 Zinsert = Zinsert->next;
                 break;
             }
             
     }
      
     if( NULL==Zinsert ) 
     {
         return 0;
     }
     
     if( MSIZE == Zinsert->begin_addr+Mnew->length )
     {
          Zinsert->state = CANTUSE;
          strcpy(Zinsert->task_name , Mnew->task_name);
          Zinsert->next = NULL;
          return 1;
     }
     else
     {
         struct MZone *Ztail = (struct MZone *)malloc(sizeof(struct MZone));
         Zinsert->state = CANTUSE;
         strcpy(Zinsert->task_name , Mnew->task_name);
         Zinsert->length = Mnew->length;
         Zinsert->next = Ztail;
          
         memset( Ztail, 0, sizeof(char)*32 );
         Ztail->begin_addr = Zinsert->begin_addr + Mnew->length;
         Ztail->state = CANUSE;
         Ztail->length = MSIZE - Ztail->begin_addr;
         Ztail->next = NULL;
          
         return 1;
     }
}
 
//memoreturn���������ڻ����ڴ�
void memoreturn(void)
{
     char tname[32];
     printf("����Ҫ�ջص�������\n");
     scanf("%s",tname);
     Mreturn(tname); 
     system("pause"); 
} 
 
//Mreturn���������ܻ����ڴ�
int Mreturn(char taskname[])
{
    struct MZone *front = NULL;
    struct MZone *position = Mhead;
    struct MZone *tail = Mhead->next;
     
    while( 0!=strcmp(position->task_name,taskname) ) 
    {
           front = position;
           if( NULL!=position->next )
           {
               position = position->next;
           }
           else
           {
               position = NULL;
               break;
           }
           tail = position->next;
    }
     
    if( NULL==position )
    {
        printf("�ڴ���û�д�����");   
    }
    else
    {
      //������CANTUSE 
      if( NULL!=tail&&NULL!=front )
       {
     
            if( front->state&&tail->state )
            {
                front->length = front->length + position->length + tail->length;
                front->next = tail->next;
                free(position);
                free(tail);
            }
            else if( front->state&&!tail->state )
            {
                front->length = front->length + position->length;
                front->next = position->next;
                free(position);
            }
            else if( !front->state&&tail->state )
            {
                position->length = position->length + tail->length;
                memset( position->task_name, 0, sizeof(char)*32 );
                position->next = tail->next;
                position->state = CANUSE;
                free(tail);
            }
            else if( !front->state&&!tail->state )
            {
                memset( position->task_name, 0, sizeof(char)*32 );
                position->state = CANUSE;   
            }
       }
       else if( NULL!=tail&&NULL==front )
       {
         if( !tail->state )
          {
             memset( position->task_name, 0, sizeof(char)*32 );
             position->state = CANUSE;
          }
          else
          {
             position->length = position->length + tail->length;
             position->next = NULL;
             free(tail);
          }
       } 
       else if( NULL==tail&&NULL!=front )
       {
         if(front->state)
          { 
              front->length = front->length + position->length;
              front->next = NULL;
              free(position);
          }
          else
          {
              memset( position->task_name, 0, sizeof(char)*32 );
              position->state = CANUSE;
          }
       }
       else if( NULL==tail&&NULL==front )
       {
            memset( position->task_name, 0, sizeof(char)*32 );
            position->state = CANUSE; 
       }
    printf("�ڴ���ճɹ���\n");
   }
}
  
int main(void)
{
     int func_ = 0;
      
     //��ʼ��Mhead 
     Mhead = (struct MZone*)malloc(sizeof(struct MZone));
     Mhead->begin_addr = 0;
     Mhead->length = MSIZE;
     Mhead->state = CANUSE;
     memset(Mhead->task_name, 0, sizeof(char)*32 );
     Mhead->next = NULL;
      
     while( 1 )
     {
           printf("******************�״���Ӧ�㷨ʵ���������ͻ���ϵͳ���ڴ�MSIZE��***************");
           printf("|1:�鿴�ڴ�������\n");
           printf("|2:��������ڴ�\n");
           printf("|3:��������ڴ�\n");
           printf("|4:�˳�����\n");
           printf("********************************************************************************");
           scanf("%d",&func_);
           switch( func_ )
           {
                   case 1 :showmemory();break;
                   case 2 :memoallocate();break;
                   case 3 :memoreturn();break; 
                   case 4 :return 1;
           }
           system("cls");
     }       
}
