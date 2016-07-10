// union-find.cpp : 定义控制台应用程序的入口点。
//

#include "stdio.h"
#include "stdlib.h"
#define N 8
typedef struct node
{
        int data;            //节点对应的编号 
        int rank;            //节点对应秩
        int parent;          //节点对应双亲下标
} UFSTree;

/*并查集树的初始化*/
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

//查找一个元素所属集合,以其根节点数值表示其集合 
int find(UFSTree t[],int x)
{
    if(x!=t[x].parent)
        return(find(t,t[x].parent));
    else
        return(x);
}

/*两个元素各自所属的集合的合并*/
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


