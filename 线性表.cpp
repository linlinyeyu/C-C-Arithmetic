#include "stdio.h"
#include "stdlib.h"
#define maxsize 50

typedef struct
{
     int data[maxsize];
     int length;
}sqlist;

void createlist(sqlist *&L,int a[],int n)
{
     int i;
     L=(sqlist*)malloc(sizeof(sqlist));
     for(i=0;i<n;i++)
     L->data[i]=a[i];
     L->length=n;
}

void destroylist(sqlist *L)
{
     free(L);
}

int listlength(sqlist *L)
{
    return L->length;
}

bool getelem(sqlist *L,int i,int &e)
{
     if(i<1||i>L->length)
     return false;
     else
     e=L->data[i-1];
     return true;
}

void displist(sqlist *L)
{
     int i;
     for(i=0;i<L->length;i++)
     printf("%4d",L->data[i]);
     printf("\n");
}

int locateelem(sqlist *L,int e)
{
    int i=0;
    while(i<L->length&&L->data[i]!=e)
    i++;
    if(i>L->length)
    return 0;
    else
    return i+1;
}

bool listinsert(sqlist *&L,int i,int e)
{
     int j;
     if(i<1||i>L->length+1)
     return false;
     i--;
     for(j=L->length;j>i;j--)
     L->data[j]=L->data[j-1];
     L->data[i]=e;
     L->length++;
     return true;
}

bool listdelete(sqlist *L,int i,int &e)
{
     int j;
     if(i<1||i>L->length)
     return false;
     i--;
     e=L->data[i];
     for(j=i;j<L->length;j++)
     L->data[j]=L->data[j+1];
     L->length--;
     return true;
}

int main()
{
    int x[6]={3,6,5,2,8,9},a,c,d,e=8,g;
    bool b,f;
    sqlist *A;
    createlist(A,x,6);
    listinsert(A,4,1);
    listdelete(A,2,g);
    displist(A);
    a=listlength(A);
    b=getelem(A,3,c);
    d=locateelem(A,e);
    printf("%d\n",a);
    printf("%d\n",b);
    printf("%d\n",d);
    printf("%d\n",f);
    system("pause");
    return 0;
}
    
    
