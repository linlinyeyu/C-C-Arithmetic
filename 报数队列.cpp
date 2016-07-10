#include "stdio.h"
#include "stdlib.h"
#define maxsize 50

typedef struct
{
        int data[maxsize];
        int front;
        int rear;
}sqqueqe;

void number(int n)
{
     int i,e;
     sqqueqe *q;
     q->front=q->rear=0;
     for(i=0;i<=n;i++)
     {
       q->rear=(q->rear+1)%maxsize;
       q->data[q->rear]=i;
       }
       printf("报数出列顺序:");
       while(q->front!=q->rear)
       {
          q->front=(q->front+1)%maxsize;
          e=q->data[q->front];
          printf("%d",e);
          if(q->front!=q->rear)
          {
             q->front=(q->front+1)%maxsize;
             e=q->data[q->front];
             q->rear=(q->rear+1)%maxsize;
             q->data[q->rear]=e;
             }
             }
             printf("\n");
}

int main()
{
    int i,n=20;
    number(n);
    system("pause");
    return 0;
}                          
