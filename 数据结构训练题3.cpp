#include "stdio.h"
#include "stdlib.h"
#include "iostream"
#include "string"
#define Maxsize 50
using namespace std;

typedef struct
{
	char data[Maxsize];
	int top;
}SqStack;

typedef struct Node
{
	char data;
	struct Node *next;
}LinkList;

//判断操作序列是否合法 
bool IsLegal(string x)
{
	int j=0;
	int k=0;
	for(int i=0;i<x.length();i++)
	{
		if(x[i]=='I')
			j++;
		if(x[i]=='O')
			k++;
		if(k>j)
			return false;
	}
	if(j!=k)
		return false;
	else
		return true;
}

//判断单链表前n个元素是否中心对称
bool JudgeSymmetry(LinkList *&L)
{
	int GetLength(LinkList *L);
	int i=GetLength(L);
	SqStack *S;
	S->top=-1;
	LinkList *p=L->next;
	for(int k=0;k<i/2;k++)
	{
		S->data[k]=p->data;
		S->top++;
		p=p->next;
	}
	if(i%2==1)
		p=p->next;
	while(p!=NULL)
	{
		if(S->data[S->top]==p->data)
		{
			S->top--;
			p=p->next;
		}
		if(S->data[S->top]!=p->data)
			break;
	}
	if(S->top==-1)
		return true;
	else
		return false;
 } 
 
 int GetLength(LinkList *L)
 {
 	int i=0;
 	LinkList *p=L->next;
 	while(p!=NULL)
 	{
 		i++;
 		p=p->next;
	 }
	 return i;
 }
 
 void CreateList(LinkList *&L,char x[],int n)
 {
 	L=new LinkList();
 	L->next=NULL;
 	LinkList *s,*r;
 	r=L;
 	for(int i=0;i<n;i++)
 	{
 		s=new LinkList();
 		s->data=x[i];
 		r->next=s;
 		r=s;
	 }
	 r->next=NULL;
 }
 
 void DispList(LinkList *L)
 {
 	LinkList *p=L->next;
 	while(p!=NULL)
 	{
 		cout<<p->data<<" ";
 		p=p->next;
	 }
	 cout<<endl;
 }
 
 
int main()
{
	LinkList *L;
	char x[]={'a','b','c','d','e','d','c','b'};
	CreateList(L,x,8);
	DispList(L);
	bool a=JudgeSymmetry(L);
	cout<<a<<endl;
	system("pause");
	return 0;
}
