#include "stdio.h"
#include "stdlib.h"
#define maxsize 50

typedef struct 
{
      int data[maxsize];
      int front,rear;
}sqqueqe;  

bool dequeqe(sqqueqe *&p,int &e)
{
     if(p->front==p->rear)
     return false;
     e=p->data[p->rear];
     p->rear=(p->rear-1+maxsize)%maxsize;
     return true;
}

bool enqueqe(sqqueqe *&p,int e)
{
     if((p->rear+1)%maxsize==p->front)
     return false;
     p->data[p->front]=e;
     p->front=(p->front-1+maxsize)%maxsize;
     return true;
}

int main()
{
    sqqueqe *A;
    int a,b,c;
    enqueqe(A,4);
    enqueqe(A,5);
    enqueqe(A,6);
    dequeqe(A,a);
    enqueqe(A,7);
    dequeqe(A,b);
    dequeqe(A,c);
    printf("%4d\n%4d\n%4d\n",a,b,c);
    system("pause");
    return 0;
}                  
