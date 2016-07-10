#include "stdio.h"
#include "stdlib.h"

typedef struct lnode
{
    int data;
    struct lnode *next;
}linklist;

typedef struct dlnode
{
        int data;
        struct dlnode *prior;
        struct dlnode *next;
}dlinklist;

void createlist(linklist *&L,int a[],int n)
{
     int i;
     linklist *s;
     L=(linklist *)malloc(sizeof(linklist));
     L->next=NULL;
     for(i=0;i<n;i++)
     {
        s=(linklist *)malloc(sizeof(linklist));
        s->data=a[i];
        s->next=L->next;
        L->next=s;
        }
}

void dcreatelist(dlinklist *&L,int a[],int n)
{
     dlinklist *s;
     int i;
     L=(dlinklist *)malloc(sizeof(dlinklist));
     L->prior=L->next=NULL;
     for(i=0;i<n;i++)
     {
          s=(dlinklist *)malloc(sizeof(dlinklist));
          s->data=a[i];
          s->next=L->next;
          if(L->next!=NULL)
          L->next->prior=s;
          s->prior=L;
          L->next=s;
          }
} 

void displist(linklist *L)
{
     linklist *p=L->next;
     while(p!=NULL)
     {
        printf("%4d",p->data);
        p=p->next;
        }
        printf("\n");
}

void ddisplist(dlinklist *L)
{
     dlinklist *p=L->next;
     while(p!=NULL)
     {
        printf("%4d",p->data);
        p=p->next;
        }
        printf("\n");
}

int count(linklist *L,int x)
{
    int n=0;
    linklist *p=L->next;
    while(p!=NULL)
    {
       if(p->data==x)
       n++;
       p=p->next;
       }
       return(n);
}

bool delelem(dlinklist *&L,int x)
{
     dlinklist *p=L->next;
     while(p!=NULL&&p->data!=x)
     p=p->next;
     if(p!=NULL)
     {
       p->next->prior=p->prior;
       p->prior->next=p->next;
       free(p);
       return true;
       }
       else
       return false;
}
     
int main()
{
    linklist *A;
    dlinklist *B;
    int x[]={23,12,435,22,12,33,23,456,23,12},a;
    dcreatelist(B,x,10);
    delelem(B,12);
    ddisplist(B);
    system("pause");
    return 0;
}

           
        
