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
      int i;
      int j;
}box;

typedef struct
{
       box data[maxsize];
       int length;
}pathtype;

void mgpath(int xi,int yi,int xe,int ye,pathtype path)
{
     int i,j,di,count=0,k;
     if(xi==xe&&yi==ye)
     {
       path.data[path.length].i=xi;
       path.data[path.length].j=yi;
       path.length++;
       printf("ÃÔ¹¬Â·¾¶%dÈçÏÂ:\n",++count); 
       for(k=0;k<path.length;k++)
       {
           printf("\t(%d,%d)",path.data[k].i,path.data[k].j);
           if((k+1)%5==0)
           printf("\n");
           }
           printf("\n");
           }
       else
       {
           if(mg[xi][yi]==0)
           {
             di=0;
             while(di<4)
             {
               path.data[path.length].i=xi;
               path.data[path.length].j=yi;
               path.length++;
               switch(di)
               {
                 case 0:i=xi-1;j=yi;break;
                 case 1:i=xi;j=yi+1;break;
                 case 2:i=xi+1;j=yi;break;
                 case 3:i=xi;j=yi-1;break;
                 }
                 mg[xi][yi]=-1;
                 mgpath(i,j,xe,ye,path);
                 mg[xi][yi]=0;
                 path.length--;
                 di++;
                 }
                 }
                 }
}

int main()
{
        pathtype a;
        mgpath(1,1,8,8,a); 
        system("pause");
        return 0;
}
                     
       
                       
