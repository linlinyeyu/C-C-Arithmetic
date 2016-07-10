#include <stdio.h>
#include <stdlib.h>
#define maxsize 50


typedef struct node
{
        char data;
        struct node *lchild;
        struct node *rchild;
}BTNode;

void CreateBTNode(BTNode *&b,char *str)
{
     BTNode *St[maxsize],*p;
     int top=-1,k,j=0;
     char ch;
     b=NULL;
     ch=str[j];
     while(ch!='\0')
     {
         switch(ch)
         {
            case '(':top++;St[top]=p;k=1;break;
            case ')':top--;break;
            case ',':k=2;break;
            default:p=(BTNode *)malloc(sizeof(BTNode));
            p->data=ch;p->lchild=p->rchild=NULL;
            if(b==NULL)
            b=p;
            else
            {
                switch(k)
                {
                         case 1:St[top]->lchild=p;break;
                         case 2:St[top]->rchild=p;break;
                         }
                         }
                         }
                         j++;
                         ch=str[j];
                         }
}

void DispBTNode(BTNode *b)
{
     if(b!=NULL)
     {
                printf("%c",b->data);
                if(b->lchild!=NULL||b->rchild!=NULL)
                {
                  printf("(");
                  DispBTNode(b->lchild);
                  if(b->rchild!=NULL)printf(",");
                  DispBTNode(b->rchild);
                  printf(")");
                  }
                  }
}

int main()
{
    BTNode *A;
    char *a="A(B(D(,G)),C(E,F))";
    CreateBTNode(A,a);
    DispBTNode(A);
    printf("\n");
    system("pause");
    return 0;
} 
