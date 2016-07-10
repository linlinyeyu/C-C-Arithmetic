#include <stdlib.h> 
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include<malloc.h>
# define MAX_NUM_OF_KEY 8//关键字项数的最大值
# define RD 10//关键字基数，此时是十进制整数的基数
# define MAX_SPACE 10000
# define ERROR -1
typedef int KeyType;//关键字类型
typedef int InfoType;//数据域类型

typedef struct SLCell//结点
{
 KeyType keys[MAX_NUM_OF_KEY];//关键字
    InfoType otheritmes;//其他数据项
 struct SLCell * next;
}SLCell,* LNode;
typedef LNode ArrType[RD];//指针数组类型，存放10个队列
typedef struct SLList //存放记录的线性表
{
 SLCell *H;// L 为单链表的头指针
    int keynum;//记录的当前关键字个数
    int recnum;//静态链表的当前长度
}SLList;
//keys(L.r[i].keys[],L.r[i].otheritmes) ;
void  keys(int keys[] ,int n)//为关键字赋值,关键字是从个位到高位一次放入数组Key[]的
{
 int i;
 for(i=0;n>0;i++)
 {
        keys[i]=n;
  n=n/10;
 }
 
}
void OutExample(SLList L,int i)
{
 SLCell * p;
 cout<<endl;
 cout<<"第"<<i+1<<"趟搜集结果是：";
 for(p=L.H->next;p->next;p=p->next)
 {
  cout<<p->otheritmes<<"->";
 }
 cout<<p->otheritmes<<endl;
}
void creatExample(SLList &L)//尾插法建立链表
{
 int i,j,n;
 SLCell *p,*q;//q指向表尾
 cout<<"请输入待排序记录的个数："<<endl;
 cin>>L.recnum;
 cout<<"请输入关键字个数："<<endl;
 cin>>L.keynum;
 L.H=(SLCell *)malloc(sizeof(SLCell));//头结点，尾插法建立链表
 L.H->next=NULL;
 q=L.H;
 cout<<"请输入待排序记录："<<endl;
 for(i=1;i<=L.recnum;i++)//输入数据项
 {  
  cin>>n;
  p=(SLCell *)malloc(sizeof(SLCell));
  p->otheritmes=n;
  for(j=0;j<L.recnum;j++)//给关键字初始化为0
   p->keys[j]=0;
  p->next=NULL;
  q->next=p;
  q=p;
 }
 p=L.H->next;
 while(p!=NULL)
 {
  keys(p->keys,p->otheritmes) ;//为关键字赋值,关键字是从个位到高位一次放入数组Key[]的
  p=p->next;
 }
 cout<<endl<<"表L为:"<<endl;
 for(i=1,p=L.H->next;i<L.recnum;i++)//输出据项
 {
  cout<<p->otheritmes<<"->";
  p=p->next;
 }
 cout<<p->otheritmes;
}

void Distribute(SLList & L,int i,ArrType &f,ArrType &e)//第i趟分配,按第i个关键字搜集
{
 int j;
 SLCell *p;
    for(j=0;j<RD;j++)//队头指针初始化
    f[j]=NULL;//各子表初始化为空表
 for(p=L.H->next;p;p=p->next)//p指示当前节点位置
 { 
  j=p->keys[i];
        if(f[j]==NULL)//若该子表为空
   f[j]=p;
  else//若该子表不空
   e[j]->next=p;//将p指向的节点插入第个i子表中
  e[j]=p;//表尾指针指向该节点
 }
}
void Collect(SLList &L,int i,ArrType f,ArrType e)//第i趟收集
{
 int j;
 SLCell *t;
 for(j=0;!f[j];j++);//找到第一个非空子表
 L.H->next=f[j];//r[0].next指向第一个非空子表的第一个节点
 t=e[j];//用t记录当前子表的最后一个节点
 while(j<RD-1)
 {
  for(j=j+1;j<RD-1&&!f[j] ;j++);//找下一个非空子表
  if(f[j])
  {
   t->next=f[j];
   t=e[j];//用t记录当前子表的最后一个节点
  }
 }
 t->next=NULL;//t指向最后一个非空子表的最后一个节点
 OutExample(L,i);
}
void RadixSort(SLList &L)//基数排序
{
 int i;
    ArrType f,e;//队头指针，队尾                                                                                                                                                                                                                                                       
 for(i=0;i<L.keynum;i++)//进行keynum趟分配，收集
 {
  Distribute(L,i,f,e);//第i趟分配
  Collect(L,i,f,e);//第i趟分收集
 }
}
void main()
{
 SLList L;
    cout<<"基数排序(链式存储).cpp"<<endl<<"============="<<endl<<endl;
 creatExample(L);
 RadixSort(L);
}
