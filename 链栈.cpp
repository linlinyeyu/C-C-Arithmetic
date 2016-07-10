#include "stdio.h" 
#include "stdlib.h"

typedef struct linknode
{
        int data;
        struct linknode *next;
}listack;

void initstack(listack *&s)
{
     s=(listack *)malloc(sizeof(listack));
     s->next=NULL;
}

void push(listack *&s,int e)
{
     listack *p;
     p=(listack *)malloc(sizeof(listack));
     p->data=e;
     p->next=s->next;
     s->next=p;
}

bool pop(listack *&s,int &e)
{
     listack *p;
     if(s->next==NULL)
     return false;
     p=s->next;
     e=p->data;
     s->next=p->next;
     free(p);
     return true;
} 

bool gettop(listack *s,int &e)
{
     if(s->next==NULL)
     return false;
     e=s->next->data;
     return true;
}

int main()
{
    listack *A;
    int a,b,c,d,e,f;
    initstack(A);
    push(A,3);
    push(A,4);
    push(A,7);
    push(A,0);
    pop(A,a);
    pop(A,b);
    push(A,45);
    push(A,12);
    pop(A,c);
    gettop(A,d);
    printf("%4d%4d%4d%4d",a,b,c,d);
    printf("\n");
    system("pause");
    return 0;
}                               
