#include "stdio.h"
#include "stdlib.h"
#include "iostream"
#define Maxsize 50
using namespace std;

typedef struct
{
	int data[Maxsize];
	int front,rear;
	int tag;
}SqQueue;

typedef struct
{
	int data[Maxsize];
	int top;
}SqStack;

void InitQueue(SqQueue *&Q)
{
	Q=new SqQueue();
	Q->front=0;
	Q->rear=0;
	Q->tag=0;
}

//入队操作 
bool EnQueue(SqQueue *&Q,int x)
{
	if(Q->front==Q->rear&&Q->tag==1)
		return false;
	Q->data[Q->rear]=x;
	Q->rear=(Q->rear+1)%Maxsize;
	Q->tag=1;
	return true;
}

//出队操作
bool DeQueue(SqQueue *&Q,int &x)
{
	if(Q->front==Q->rear&&Q->tag==0)
		return false;
	x=Q->data[Q->front];
	Q->front=(Q->front+1)%Maxsize;
	Q->tag=0;
	return true;
 }
 
 //创建队列
 void CreateQueue(SqQueue *&Q,int x[],int n)
 {
 	for(int i=0;i<n;i++)
 	{
 		Q->data[Q->rear]=x[i];
		Q->rear=(Q->rear+1)%Maxsize;
		Q->tag=1; 
	 }
  }
 
 //输出队列
 void DispQueue(SqQueue *Q)
 {
 	for(int i=Q->front;i<Q->rear;i++)
 	{
 		cout<<Q->data[i]<<" ";
	 }
	 cout<<endl;
  } 

//将队列中元素逆置
void ReverseQueue(SqQueue *&Q,SqStack *&S)
{
	S=new SqStack();
	S->top=-1;
	while(Q->front!=Q->rear)
	{
		S->data[++S->top]=Q->data[Q->front];
		Q->front=(Q->front+1)%Maxsize;
	}
	while(S->top!=-1)
	{
		Q->data[Q->rear]=S->data[S->top--];
		Q->rear=(Q->rear+1)%Maxsize;
	}
 } 
int main()
{
	SqQueue *Q;
	SqStack *S;
	int a;
	int x[]={2,3,4,5,6,1,2,3,4};
	InitQueue(Q);
	CreateQueue(Q,x,9);
	ReverseQueue(Q,S);
	DispQueue(Q);
	system("pause");
	return 0;
}
