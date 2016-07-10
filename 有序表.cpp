#include "stdio.h"
#include "stdlib.h"
#define maxsize 50

typedef struct 
{
      int data[maxsize];
      int length;
}sqlist;

typedef struct lnode
{
        int data;
        struct lnode *next;
}linklist;
        
void createlist(sqlist *&L,int a[],int n)
{
     int i;
     L=(sqlist *)malloc(sizeof(sqlist));
     for(i=0;i<n;i++)
       L->data[i]=a[i];   
       L->length=n;
}

void displist(sqlist *L)
{
     int i;
     for(i=0;i<L->length;i++)
     printf("%4d",L->data[i]);
     printf("\n");
}
void createlistd(linklist *&L,int a[],int n)
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

void displistd(linklist *L)
{
     linklist *p=L->next;
     while(p!=NULL)
     {
        printf("%4d",p->data);
        p=p->next;
        }
        printf("\n");
}

void sortd(linklist *&L)
{
     linklist *p,*q,*pre;
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

void sort(sqlist *&L,int n)
{
    int i,j,tmp;
    for(i=0;i<n-1;i++)
    {
       for(j=n-1;j>i;j--)
       if(L->data[j]<L->data[j-1])
       {
          tmp=L->data[j];
          L->data[j]=L->data[j-1];
          L->data[j-1]=tmp;
       }
}       
}
               
void unionlist(sqlist *A,sqlist *B,sqlist *&C)
{
    int i=0,j=0,k=0;
    C=(sqlist *)malloc(sizeof(sqlist));
    while(i<A->length&&j<B->length)
    {
       if(A->data[i]<B->data[j])
       {
         C->data[k]=A->data[i];
         i++;
         k++;
         }
      else
      {
          C->data[k]=B->data[j];
          j++;
          k++;
          }
          }
     while(i<A->length)
     {
        C->data[k]=A->data[i];
        i++;
        k++;
        }
     while(j<B->length)
     {
        C->data[k]=B->data[j];
        j++;
        k++;
        }
     C->length=k;
}

void unionlist1(linklist *&A,linklist *&B,linklist *&C)
{
     linklist *pa=A->next,*pb=B->next,*s,*r;
     C=(linklist *)malloc(sizeof(linklist));
     r=C;
     while(pa!=NULL&&pb!=NULL)
     {
        if(pa->data<pb->data)
        {
        s=(linklist *)malloc(sizeof(linklist));
        s->data=pa->data;
        r->next=s;
        r=s;
        pa=pa->next;
        }
        else
        {
            s=(linklist *)malloc(sizeof(linklist));
            s->data=pb->data;
            r->next=s;
            r=s;
            pb=pb->next;
            }
            }
     while(pa!=NULL)
     {
         s=(linklist *)malloc(sizeof(linklist));
         s->data=pa->data;
         r->next=s;
         r=s;
         pa=pa->next;
         }
      while(pb!=NULL)
      {
         s=(linklist *)malloc(sizeof(linklist));
         s->data=pb->data;
         r->next=s;
         r=s;
         pb=pb->next;
         }
         r->next=NULL; 
}

void commnode(linklist *&A,linklist *B,linklist *C)
{
     linklist *pa=A->next,*pb=B->next,*pc=C->next,*q,*r;
     A->next=NULL;
     r=A;
     while(pa!=NULL)
     {
         while(pb!=NULL&&pa->data>pb->data)
         pb=pb->next;
         while(pc!=NULL&&pa->data>pc->data)
         pc=pc->next;
         if(pb!=NULL&&pc!=NULL&&pa->data==pb->data&&pa->data==pc->data)
         {
              r->next=pa;
              r=pa;
              pa=pa->next;
              }
              else
         {
              q=pa;
              pa=pa->next;
              free(q);
              }
         r->next=NULL;
} 
}       

void dels(linklist *&L)
{
     linklist *p=L->next,*q;
     while(p->next!=NULL)
     {
       if(p->data==p->next->data)
       {
         q=p->next;
         p->next=q->next;
         free(q);
         }
         else
         p=p->next;
      }
}
            
int main()
{
    linklist *A,*B,*C,*G;
    sqlist *D,*E,*F;
    int x[]={56,23,89,47,44,767,89,44},
    y[]={32,23,43,45,75,56,31,77,555},
    z[]={33,23,34,45,65,22,86,54,56};
    createlistd(A,x,8);
    createlistd(B,y,9);
    createlistd(G,z,9);
    createlist(D,x,8);
    createlist(E,x,9);
    sortd(A);
    sortd(B);
    sortd(G);
    sort(D,8);
    sort(E,9);
    commnode(G,B,A);
    dels(A);
    displist(D);
    displistd(G);
    displistd(A);
    system("pause");
    return 0;
}
             
           
       
                                
         
               
