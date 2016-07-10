#include "stdio.h"
#include "stdlib.h"
#include "iostream"
#define Maxsize 15 
using namespace std;

typedef struct CSNode
{
	char data;
	struct CSNode *lchild,*rchild;
}CSTree;

typedef struct Node
{
	int data;
	struct Node *lchild,*rchild;
}BiTNode;

//孩子兄弟表示存储的森林的叶子结点数 
int Leaves(CSTree *T)
{
	if(T==NULL)
		return 0;
	if(T->lchild==NULL)
		return 1+Leaves(T->rchild);
	else
		return Leaves(T->lchild)+Leaves(T->rchild);
}

//孩子兄弟链表的递归深度
int Height(CSTree *T)
{
	int hs,hc;
	if(T==NULL)
		return 0;
	else
	{
		hc=Height(T->lchild);
		hs=Height(T->rchild);
		if(hc+1>hs)
			return hc+1;
		else
			return hs;
	}
 } 

//已知树的层次序列及每个节点的度，求该树孩子-兄弟链表
void CreateCSTree_Degree(CSTree *&T,char e[],int degree[],int n)
{
	CSTree *pointer=new CSTree[Maxsize];
	int i,j,d,k=0;
	for(i=0;i<n;i++)
	{
		pointer[i]=new CSTree;
		pointer[i]->data=e[i];
		pointer[i]->lchild=pointer[i]->rchild=NULL;
	}
	for(i=0;i<n;i++)
	{
		d=degree[i];
		if(d)
		{
			k++;
			pointer[i]->lchild=pointer[k];
			for(j=2;j<=d;j++)
				pointer[k-1]->rchild=pointer[k];
		}
	}
	T=pointer[0];
	delete []pointer;
}

//二叉排序树非递归查找
BiTNode *BST_Select(BiTNode *T,int x)
{
	while(T&&T->data!=x)
	{
		if(T->data>x)
			T=T->lchild;
		else
			T=T->rchild;
	}
	return T;
 }

//二叉排序树递归查找
BiTNode *BST_SelectD(BiTNode *T,int x)
{
	if(T->data==x)
		return T;
	if(T->data>x)
		return BST_SelectD(T->lchild,x);
	if(T->data<x)
		return BST_SelectD(T->rchild,x);
 }
 
 //二叉排序树插入操作
 void BST_Insert(BiTNode *&T,int x)
 {
 	if(T==NULL)
 	{
 		T=new BiTNode();
 		T->data=x;
 		T->lchild=T->rchild=NULL;
	 }
	if(T->data==x)
	 	return;
	if(T->data>x)
		BST_Insert(T->lchild,x);
	else
		BST_Insert(T->rchild,x);
  }
  
 //构造二叉排序树
 void Crea_BST(BiTNode *&T,int str[],int n)
 {
 	T=NULL;
 	int i=0;
 	while(i<n)
 	{
 		BST_Insert(T,str[i]);
 		i++;
	 }
  } 
