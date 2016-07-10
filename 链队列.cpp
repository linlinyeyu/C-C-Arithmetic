#include "stdio.h"
#include "stdlib.h"

typedef struct qnode 
{
        int data;
        struct qnode *next;
}qnode;

typedef struct 
{
        qnode *front;
        qnode *rear;
}liqueqe;                

void initqueqe(liqueqe *&q)
{
     q=(liqueqe *)malloc(sizeof(liqueqe));
     q->front=q->rear=NULL;
}

void enqueqe(liqueqe *&q,int e)
{
     qnode *p;
     p=(qnode *)malloc(sizeof(qnode));
     p->data=e;
     p->next=NULL;
     if(q->rear==NULL)
     q->front=q->rear=p;
     else
     {
         q->rear->next=p;
         q->rear=p;
         }
}

bool dequeqe(liqueqe *&q,int &e)
{
       qnode *t;
       if(q->rear==NULL)
       return false;
       t=q->front;
       if(q->front==q->rear)
       q->front=q->rear=NULL;
       else
       q->front=q->front->next;
       e=t->data;
       free(t);
       return true;
}

int main()
{
    liqueqe *A;
    int a,b,c;
    initqueqe(A);
    enqueqe(A,4);
    enqueqe(A,78);
    enqueqe(A,45);
    dequeqe(A,a);
    enqueqe(A,56);
    dequeqe(A,b);
    dequeqe(A,c);
    printf("%4d\n",a);
    printf("%4d\n",b);
    printf("%4d\n",c);
    system("pause");
    return 0;
}
                       
