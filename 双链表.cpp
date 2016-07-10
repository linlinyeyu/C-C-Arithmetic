#include "stdio.h"
#include "stdlib.h"

typedef struct dnode
{
        int data;
        struct dnode *prior;
        struct dnode *next;
}dlinklist;        

void createlistf(dlinklist *&L,int a[],int n)
{
     dlinklist *s;
     int i;
     L=(dlinklist *)malloc(sizeof(dlinklist));
     L->next=L->prior=NULL;
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

void createlistr(dlinklist *&L,int a[],int n)
{
     dlinklist *s,*r;
     int i;
     L=(dlinklist *)malloc(sizeof(dlinklist));
     L->next=L->prior=NULL;
     r=L;
     for(i=0;i<n;i++)
     {
        s=(dlinklist *)malloc(sizeof(dlinklist));
        s->data=a[i];
        r->next=s;
        s->prior=r;
        r=s;
        }
     r->next=NULL;
}

bool listinsert(dlinklist *&L,int i,int e)
{
     dlinklist *p=L,*s;
     int j=0;
     while(j<i-1&&p!=NULL)
     {
        j++;
        p=p->next;
        }
     if(p==NULL)
     return false;
     else
     {
         s=(dlinklist *)malloc(sizeof(dlinklist));
         s->data=e;
         s->next=p->next;
         if(p->next!=NULL)
         p->next->prior=s;
         s->prior=p;
         p->next=s;
         return true;
         }
}

bool listdelete(dlinklist *&L,int i,int &e)
{
     int j=0;
     dlinklist *p=L,*q;
     while(j<i-1&&p!=NULL)
     {
       j++;
       p=p->next;
       }
       if(p==NULL)
       return false;
       else
       {
           q=p->next;
           if(q==NULL)
           return false;
           e=L->data;
           p->next=q->next;
           if(p!=NULL)
           p->next->prior=p;
           free(q);
           return true;
           }
}           

void reverse(dlinklist *&L)
{
     dlinklist *p=L->next,*q;
     L->next=NULL;
     while(p!=NULL)
     {
       q=p->next;
       p->next=L->next;
       if(L->next!=NULL)
       L->next->prior=p;
       L->next=p;
       p->prior=L;
       p=q;
       }
}
void sort(dlinklist *&L)
{
     dlinklist *p,*q,*pre;
     p=L->next->next;
     L->next->next=NULL;
     while(p!=NULL)
     {
       q=p->next;
       pre=L;
       while(pre->next!=NULL&&pre->next->data<p->data)
       pre=pre->next;
       p->next=pre->next;
       if(pre->next!=NULL)
       pre->next->prior=p;
       pre->next=p;
       p->prior=pre;
       p=q;
       }
}       
                            
void displist(dlinklist *L)
{
     dlinklist *p=L->next;
     while(p!=NULL)
     {
        printf("%4d",p->data);
        p=p->next;
        }
     printf("\n");
}
   
int main()
{
    dlinklist *A;
    int x[]={23,44,54,62,87,45,332,56},a;
    createlistf(A,x,8);
    listinsert(A,4,90);
    listdelete(A,5,a);
    reverse(A);
    sort(A);
    displist(A);
    system("pause");
    return 0;
}
            
