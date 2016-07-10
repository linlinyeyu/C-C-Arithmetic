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
     q->front=q->rear=0;
}

bool enqueqe(sqqueqe *&q,int e)
{
     if((q->rear+1)%maxsize==q->front)
     return false;
     q->rear=(q->rear+1)%maxsize;
     q->data[q->rear]=e;
     return true;
}

bool dequeqe(sqqueqe *&q,int &e)
{
     if(q->front==q->rear)
     return false;
     q->front=(q->front+1)%maxsize;
     e=q->data[q->front];
     return true;
}

int main()
{
    sqqueqe *A;
    int a,b,c,i;
    enqueqe(A,4);
    enqueqe(A,56);
    enqueqe(A,89);
    dequeqe(A,a);
    dequeqe(A,b);
    enqueqe(A,90);
    enqueqe(A,34);
    dequeqe(A,c);
    printf("\n");
    printf("%4d\n",a);
    printf("%4d\n",b);
    printf("%4d\n",c);
    system("pause");
    return 0;
}
             
