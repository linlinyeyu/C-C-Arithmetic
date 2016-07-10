#include "stdio.h"
#include "stdlib.h"

typedef struct lnode
{
      int data;
      struct lnode *next;
}linklist;

void createlistf(linklist *&L,int a[],int n)
{
     linklist *s;
     int i;
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

void createlistr(linklist *&L,int a[],int n)
{
     linklist *s,*r;
     int i;
     L=(linklist *)malloc(sizeof(linklist));
     r=L;
     for(i=0;i<n;i++)
     {
          s=(linklist *)malloc(sizeof(linklist));
          s->data=a[i];
          r->next=s;
          r=s;
          }
     r->next=NULL;
}

bool getelem(linklist *L,int i,int &e)
{
     int j=0;
     linklist *p=L;
     while(j<i&&p!=NULL)
     { 
         j++;
         p=p->next;
     }
     if(p==NULL)
        return false;
     else
     {
         e=p->data;
         return true;
     }
}

int listlength(linklist *L)
{
    int n=0;
    linklist *p=L;
    while(p->next!=NULL)
    {
        n++;
        p=p->next;
        }
        return n;
}

int locateelem(linklist *L,int e)
{
    int i=1;
    linklist *p=L->next;
    while(p!=NULL&&p->data!=e)
    {
       p=p->next;
       i++;
       }
    if(p==NULL)
    return(0);
    else 
    return(i);
}

bool listinsert(linklist *&L,int i,int e)
{
     int j=0;
     linklist *p=L,*s;
     while(j<i-1&&p!=NULL)
     {
        p=p->next;
        j++;
        }
     if(p==NULL)
     return false;
     else
     {
         s=(linklist *)malloc(sizeof(linklist));
         s->data=e;
         s->next=p->next;
         p->next=s;
         return true;
         }
}
bool listdelete(linklist *&L,int i,int &e)
{
     int j=0;
     linklist *p=L,*q;
     while(j<i-1&&p!=NULL)
     {
       p=p->next;
       j++;
       }
       if(p==NULL)
       return false;
       else
       {
           q=p->next;
           if(q==NULL)
           return false;
           e=q->data;
           p->next=q->next;
           free(q);
           return true;
           }
}
                 
void displist(linklist *L)
{
     linklist *p=L->next;
     while(p!=NULL)
     {
          printf("%6d",p->data);
          p=p->next;
          }
     printf("\n");
}

int main()
{
    int x[]={32,42,334,22,67,89};
    int a,c,d,f;
    bool b,e,g;
    linklist *A;
    createlistr(A,x,6);
    b=getelem(A,4,c);
    d=locateelem(A,67);
    listinsert(A,4,76);
    listdelete(A,2,f);
    displist(A);
    a=listlength(A);
    printf("%d\n",a);
    printf("%d\n",c);
    printf("%d\n",d);
    printf("%d\n",f);
    system("pause");
    return 0;
}

