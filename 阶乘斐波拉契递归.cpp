#include "stdio.h"
#include "stdlib.h"
#define maxsize 50

typedef struct
{
        int data[maxsize];
        int length;
}sqlist;

void createlist(sqlist &L,int A[],int n)
{
     int i;
     for(i=0;i<n;i++)
     L.data[i]=A[i];
     L.length=n;
}     
             
int fun(int n)
{
    if(n==1)
    return 1;
    else
    return(fun(n-1)*n);
}

int fib(int n)
{
    if(n==1||n==2)
    return 1;
    else
    return(fib(n-1)+fib(n-2));
}

void hanoi(int n,char x,char y,char z)
{
     if(n==1)
     printf("将第%d个盘片从%c移动到%c\n",n,x,z);
     else
     {
         hanoi(n-1,x,z,y);
         printf("将第%d个盘片从%c移动到%c\n",n,x,z);
         hanoi(n-1,y,x,z);
         }
}

void move(char getone,char putone)
{
     printf("%c->%c\n",getone,putone);
}

double find(float A[],int i)
{
       double m;
       if(i==0)
       return(A[0]);
       else
       {
          m=find(A,i-1);
          if(m>A[i])
          return(A[i]);
          else
          return(m);
}
}          

int Max(sqlist L,int i,int j)
{
    int max1,max2,max,mid;
    if(i==j)
    max=L.data[i];
    else
    {
        mid=(i+j)/2;
        max1=Max(L,i,mid);
        max2=Max(L,mid+1,j);
        max=(max1>max2)?max1:max2;
        }
        return(max);
}
                          
int main()
{
    int x[]={1,23,34,21,34,215,343,64,23,12,1222,1223,23,1223},a;
    sqlist A;
    double g;
    float B[]={12,23.1,123,21,33,21,56.2,12,12.1};
    g=find(B,8);
    createlist(A,x,14);
    a=Max(A,0,13);
    printf("%f\n",g);
    printf("%d\n",a);
    system("pause");
    return 0;
}
        
