// union-find.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdio.h"
#include "stdlib.h"
#define N 8
typedef struct node
{
        int data;            //�ڵ��Ӧ�ı�� 
        int rank;            //�ڵ��Ӧ��
        int parent;          //�ڵ��Ӧ˫���±�
} UFSTree;

/*���鼯���ĳ�ʼ��*/
void MAKE_SET(UFSTree t[])
{
     int i;
     for(i=1;i<=N;i++)
     {
                      t[i].data=i;
                      
                      t[i].rank=0;
                      t[i].parent=i;
     }
}

//����һ��Ԫ����������,������ڵ���ֵ��ʾ�伯�� 
int find(UFSTree t[],int x)
{
    if(x!=t[x].parent)
        return(find(t,t[x].parent));
    else
        return(x);
}

/*����Ԫ�ظ��������ļ��ϵĺϲ�*/
void UNION(UFSTree t[],int x,int y)
{
     x=find(t,x);
     y=find(t,y);
     if(t[x].rank>t[y].rank)
          t[y].parent=x;
     else
     {
         t[x].parent=y;
         if(t[x].rank=t[y].rank)
              t[y].rank++;
     }
}

int main(UFSTree t[])
{
    t=(UFSTree *)malloc(sizeof(UFSTree)); 
    MAKE_SET(t);
    int k,j;
    UNION(t,1,2);
    UNION(t,3,4);
    UNION(t,7,8);
    UNION(t,2,4);
    k=find(t,1);
    printf("find(1)=%d",k);
    printf("\n");
    UNION(t,1,7);
    j=find(t,3);
    printf("find(3)=%d",j);
    UNION(t,2,3);
    printf("\n");
    getchar();
	getchar();
    return 0;
}


