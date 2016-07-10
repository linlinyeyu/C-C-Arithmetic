#include "stdio.h"
#include "stdlib.h"
#define maxsize 50

typedef struct 
{
     int data[maxsize];
     int front,rear;
}sqqueqe;

void initqueqe(sqqueqe *&q)
{
     q=(sqqueqe *)malloc(sizeof(sqqueqe));
     q->front=q->rear=-1;
}

bool enqueqe(sqqueqe *&q,int e)
{
     if(q->rear==maxsize-1)
     return false;
     q->rear++;
     q->data[q->rear]=e;
     return true;
}

bool dequeqe(sqqueqe *&q,int &e)
{
     if(q->front==q->rear)
     return false;
     q->front++;
     e=q->data[q->front];
     return true;
}

int main()
{
    sqqueqe *A;
    int a,b,i;
    initqueqe(A);
    enqueqe(A,3);
    enqueqe(A,5);
    enqueqe(A,7);
    dequeqe(A,a);
    enqueqe(A,90);
    dequeqe(A,b);
    enqueqe(A,6);
    for(i=2;i<5;i++)
    printf("%4d",A->data[i]);
    printf("\n");
    printf("%4d\n",a);
    printf("%4d\n",b);
    system("pause");
    return 0;
}
         
     
                    
