#include "stdio.h"
#include "stdlib.h"
#define maxsize 50

int mg[10][10]=
{
    {1,1,1,1,1,1,1,1,1,1},
    {1,0,0,1,0,0,0,1,0,1},
    {1,0,0,1,0,0,0,1,0,1},
    {1,0,0,0,0,1,1,0,0,1},
    {1,0,1,1,1,0,0,0,0,1},
    {1,0,0,0,1,0,0,0,0,1},
    {1,0,1,0,0,0,1,0,0,1},
    {1,0,1,1,1,0,1,1,0,1},
    {1,1,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1}};
    
typedef struct 
{
        int i,j;
        int pre;
}box;

typedef struct
{
        box data[maxsize];
        int front,rear;
}qutype;

bool mgpath1(int xi,int yi,int xe,int ye)
{
     void print(qutype q,int front);
     qutype p;
     int i,j,find=0,di;
     p.front=p.rear=-1;
     p.rear++;
     p.data[p.rear].i=xi;
     p.data[p.rear].j=yi;
     p.data[p.rear].pre=-1;
     mg[xi][yi]=-1;
     while(p.front!=p.rear&&!find)
     {
         p.front++;
         i=p.data[p.front].i;
         j=p.data[p.front].j;
         if(i==xe&&j==ye)
         {
            find=1;
            print(p,p.front);
            return true;
            }
         for(di=0;di<4;di++)
         {
            switch(di)
            {
              case 0:i=p.data[p.front].i-1;j=p.data[p.front].j;break;
              case 1:i=p.data[p.front].i;j=p.data[p.front].j+1;break;
              case 2:i=p.data[p.front].i+1;j=p.data[p.front].j;break;
              case 3:i=p.data[p.front].i;j=p.data[p.front].j-1;break;
              }
              if(mg[i][j]==0)
              {
                p.rear++;
                p.data[p.rear].i=i;
                p.data[p.rear].j=j;
                p.data[p.rear].pre=p.front;
                mg[i][j]=-1;
                }
                }
                }
                return false;
}

void print(qutype p,int front)
{
     int k=front,j,ns=0;
     do
     {
       j=k;
       k=p.data[k].pre;
       p.data[j].pre=-1;
       }while(k!=0);
       k=0;
     while(k<maxsize)
     {
        if(p.data[k].pre==-1)
        {
           ns++;
           printf("(%d,%d)",p.data[k].i,p.data[k].j);
           if(ns%5==0)
           printf("\n");
           }
           k++;
           }
        printf("\n");
}

int main()
{
    if(!mgpath1(1,1,8,8))
    printf("该迷宫问题没有解");
    system("pause");
    return 0;
}
            
                     
                
            
            
                 
                
