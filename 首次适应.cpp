/*
*文件名称：memory.c
*摘要：首次适应算法实现主存分配和回收程序
*
*作者：刘金
*完成日期：2011年10月15日 
*/
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
const int CANUSE = 1;
const int CANTUSE = 0;
//#define  MSIZE  128;
const int MSIZE = 128;
 
 
//内存分区 
struct MZone
{
       //空闲区起始地址 
    int begin_addr; 
       //一个连续空闲区的长度
    int length;       
       //状态 
    int state;
       //内存中任务名
    char task_name[32];    
       //指向下一个空闲分区
    struct MZone *next;    
};
 
//内存头指针 
struct MZone *Mhead = NULL;
int Minsert(struct MZone* Mnew);
int Mreturn(char taskname[]);
 
//showmemory函数，显示当前内存分配情况 
void showmemory()
{
     struct MZone *Mpoint = Mhead;
      
     printf("内存的使用情况\n");
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
 
//memoallocate函数，用于分配内纯 
void memoallocate(void)
{
     struct MZone *Mnew = (struct MZone*)malloc(sizeof(struct MZone));
     printf("输入要分配内存大小(kb):\n");
     scanf("%d",&Mnew->length);
     printf("输入任务名:\n");
     scanf("%s",&Mnew->task_name);
     Minsert(Mnew)?printf("分配内存成功\n"):printf("没有符合大小的空闲分区，内存分配失败。\n"); 
     system("pause");
     free(Mnew);
}
 
//Minsert函数，功能插入任务到空闲分区 
int Minsert(struct MZone* Mnew)
{
 
     struct MZone *Zinsert = Mhead;
     //flag用于指示是Zinsert到了NULL，既没有内存可以分配 
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
 
//memoreturn函数，用于回收内存
void memoreturn(void)
{
     char tname[32];
     printf("输入要收回的任务名\n");
     scanf("%s",tname);
     Mreturn(tname); 
     system("pause"); 
} 
 
//Mreturn函数，功能回收内存
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
        printf("内存中没有此任务！");   
    }
    else
    {
      //不能用CANTUSE 
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
    printf("内存回收成功！\n");
   }
}
  
int main(void)
{
     int func_ = 0;
      
     //初始化Mhead 
     Mhead = (struct MZone*)malloc(sizeof(struct MZone));
     Mhead->begin_addr = 0;
     Mhead->length = MSIZE;
     Mhead->state = CANUSE;
     memset(Mhead->task_name, 0, sizeof(char)*32 );
     Mhead->next = NULL;
      
     while( 1 )
     {
           printf("******************首次适应算法实现主存分配和回收系统（内存MSIZE）***************");
           printf("|1:查看内存分配情况\n");
           printf("|2:申请分配内存\n");
           printf("|3:申请回收内存\n");
           printf("|4:退出程序\n");
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
