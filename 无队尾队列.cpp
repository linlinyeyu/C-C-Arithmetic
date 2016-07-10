#include "stdio.h"
#include "stdlib.h"
#define maxsize 50

typedef struct
{
        int data[maxsize];
        int front;
        int count;
}qutype;

void initqueqe(qutype *&qu)
{
     qu=(qutype *)malloc(sizeof(qutype));
     qu->front=0;
     qu->count=0;
}

bool enqueqe(qutype *&qu,int e)
{
     int rear;
     if(qu->count==maxsize)
     return false;
     rear=(qu->front+qu->count)%maxsize;
     rear=(rear+1)%maxsize;
     qu->data[rear]=e;
     qu->count++;
     return true;
}

bool dequeqe(qutype *&qu,int &e)
{
     if(qu->count==0)
     return false;
     else
     { 
     qu->front=(qu->front+1)%maxsize;
     e=qu->data[qu->front];
     qu->count--;
     return true;
     }
}

int main()
{
    qutype *A;
    int a,b,c;
    enqueqe(A,4);
    enqueqe(A,5);
    enqueqe(A,9);
    dequeqe(A,a);
    dequeqe(A,b);
    enqueqe(A,43);
    dequeqe(A,c);
    enqueqe(A,90);
    printf("%4d\n",a);
    printf("%4d\n",b);
    printf("%4d\n",c);
    system("pause");
    return 0;
}              

     
                  
