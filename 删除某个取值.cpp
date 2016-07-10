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
     L=(sqlist *)malloc(sizeof(sqlist));
     for(i=0;i<n;i++)
     L->data[i]=a[i];
     L->length=n;
}

void diplist(sqlist *L)
{
     int i;
     for(i=0;i<L->length;i++)
     printf("%4d",L->data[i]);
     printf("\n");
}

void delnode1(sqlist *&L,int x)
{
     int k=0,i;
     for(i=0;i<L->length;i++)
     if(L->data[i]!=x)
     {
        L->data[k]=L->data[i];
        k++;
        }
     L->length=k;
}

void delnode2(sqlist *L,int x)
{
     int k=0,i=0;
     while(i<L->length)
     {
        if(L->data[i]==x)
        k++;
        else
        L->data[i-k]=L->data[i];
        i++;
}
      L->length-=k;
}

void move1(sqlist *&L)
{
     int i=0,j=L->length-1;
     int pivot=L->data[0],tmp;
     while(i<j)
     {
               while(i<j&&L->data[j]>pivot)
               j--;
               while(i<j&&L->data[i]<=pivot)
               i++;
               if(i<j)
         {
               tmp=L->data[i];
               L->data[i]=L->data[j];
               L->data[j]=tmp;
}
               }
      tmp=L->data[0];
      L->data[0]=L->data[i];
      L->data[i]=tmp;
      printf("%d\n",i);
}                    

void move2(sqlist *L)
{
     int i=0,j=L->length-1;
     int pivot=L->data[0];
     while(i<j)
     {
          while(i<j&&L->data[j]>pivot)
          j--;
          L->data[i]=L->data[j];
          i++;
          while(i<j&&L->data[i]<=pivot)
          i++;
          L->data[j]=L->data[i];
          j--;
}
     L->data[i]=pivot;
     printf("i=%d\n",i);
}
                                               
int main()
{
    int x[]={1,2,3,4,5,5,4,3,2,1};
    sqlist *A;
    createlist(A,x,10);
    diplist(A);
    system("pause");
    return 0;
}
