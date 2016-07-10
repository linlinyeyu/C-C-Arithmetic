#include "stdio.h"
#include "stdlib.h"
#define maxcol 10

typedef struct nodel
{
        int data[maxcol];
        struct nodel *next;
}dlist;

typedef struct node2
{
        int row,col;
        dlist *next;
}hlist;

void createtable(hlist *&h)
{
     int i,j;
     dlist *r,*s;
     h=(hlist *)malloc(sizeof(hlist));
     h->next=NULL;
     printf("表的行数，列数:");
     scanf("%d%d",&h->row,&h->col);
     for(i=0;i<h->row;i++)
     {
       printf("第%d行:",i+1);
       s=(dlist *)malloc(sizeof(dlist));
       for(j=0;j<h->col;j++)
       scanf("%d",&s->data[j]);
       if(h->next==NULL)
       h->next=s;
       else
       r->next=s;
       }
       r->next=NULL;
}
void destroytable(hlist *&h)
{
     dlist *pre=h->next,*p=pre->next;
     while(p!=NULL)
     {
        free(pre);
        pre=p;
        p=p->next;
        }
     free(pre);
     free(h);
}
     
void disptable(hlist *h)
{
     int j;
     dlist *p=h->next;
     while(p!=NULL)
     {
         for(j=0;j<h->col;j++)
         printf("%4d",p->data[j]);
         printf("\n");
         p=p->next;
         }
}
void linktable(hlist *h1,hlist *h2,hlist *&h)
{
     int i,j,k;
     dlist *p=h1->next,*q,*s,*r;
     printf("连接字段是：第一个表序号，第二个表序号：");
     scanf("%d%d",&i,&j);
     h=(hlist *)malloc(sizeof(hlist));
     h->row=0;
     h->col=h1->col+h2->col;
     h->next=NULL;
     while(p!=NULL)
     {
        q=h2->next;
        while(q!=NULL)
        {
            if(p->data[i-1]==q->data[j-1])
            {
               s=(dlist *)malloc(sizeof(dlist));
               for(k=0;k<h1->col;k++)
               s->data[k]=p->data[k];
               for(k=0;k<h2->col;k++)
               s->data[h1->col+k]=q->data[k];
               if(h->next==NULL)
               h->next=s;
               else
               r->next=s;
               r=s;
               h->row++;
               }
               q=q->next;
               }
               p=p->next;
               }
               r->next=NULL;
}
                
int main()
{
    hlist *A;
    createtable(A);
    disptable(A);
    destroytable(A);
    return 0;
}
    
         

       
        
