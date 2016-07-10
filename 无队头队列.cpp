#include "stdio.h"
#include "stdlib.h"

typedef struct lnode 
{
        int data;
        struct lnode *next;
}linklist;

void initqueqe(linklist *&rear)
{
     rear=NULL;
}

void enqueqe(linklist *&rear,int e)
{
     linklist *p;
     p=(linklist *)malloc(sizeof(linklist));
     p->data=e;
     if(rear==NULL)
     {
         p->next=p;
         rear=p;
         }
     else
     {
         p->next=rear->next;
         rear->next=p;
         rear=p;
         }
}

bool dequeqe(linklist *&rear,int &e)
{
     linklist *p;
     if(rear==NULL)
     return false;
     if(rear->next==rear)
     {
         e=rear->data;
         free(rear);
         rear=NULL;
         }
     else
     {
         p=rear->next;
         e=p->data;
         rear->next=p->next;
         free(p);
         }
         return true;
}

int main()
{
    linklist *A;
    int a,b,c,d,e;
    initqueqe(A);
    enqueqe(A,4);
    enqueqe(A,5);
    enqueqe(A,90);
    enqueqe(A,34);
    dequeqe(A,a);
    dequeqe(A,b);
    dequeqe(A,c);
    enqueqe(A,8);
    dequeqe(A,d);
    printf("%4d\n%4d\n%4d\n%4d\n",a,b,c,d);
    system("pause");
    return 0;
}
                 
                      
