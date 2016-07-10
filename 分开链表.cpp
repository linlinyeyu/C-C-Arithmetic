#include "stdio.h"
#include "stdlib.h"

typedef struct lnode
{
        int data;
        struct lnode *next;
}linklist;

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

void split(linklist *&L,linklist *&L1,linklist *&L2)
{
     linklist *p=L->next,*q,*r1;
     L1=L;
     r1=L1;
     L2=(linklist *)malloc(sizeof(linklist));
     L2->next=NULL;
     while(p!=NULL)
     {
         r1->next=p;
         r1=p;
         p=p->next;
         q=p->next;
         p->next=L2->next;
         L2->next=p;
         p=q;
         }
         r1->next=NULL;
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

void delmaxnode(linklist *&L)
{
     linklist *p=L->next,*pre=L,*max=p,*maxpre=pre;
     while(p!=NULL)
     {
         if(max->data<p->data)
         {
            max=p;
            maxpre=pre;
            }
         pre=p;
         p=p->next;
         }
     maxpre->next=max->next;
     free(max);
}

void sort(linklist *&L)
{
     linklist *p,*pre,*q;
     p=L->next->next;
     L->next->next=NULL;
     while(p!=NULL)
     {
        q=p->next;
        pre=L;
        while(pre->next!=NULL&&pre->next->data<p->data)
        pre=pre->next;
        p->next=pre->next;
        pre->next=p;
        p=q;
        }
}
                        
int main()
{
    int x[]={12,225,32,54,58,98,61,27,33,66,89,20,10};
    linklist *A,*B,*C;
    createlist(A,x,13);
    delmaxnode(A);
    sort(A);
    displist(A);
    system("pause");
    return 0;
}
    
    
     
