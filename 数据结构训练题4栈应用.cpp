#include "stdio.h"
#include "stdlib.h"
#include "iostream"
#define Maxsize 50
using namespace std;

typedef struct
{
	char data[Maxsize];
	int top;
}SqStack;

typedef struct
{
	char data[Maxsize];
	int front,rear;
}SqQueue;

void InitStack(SqStack *&S)
{
	S=new SqStack();
	S->top=-1;
}

void Push(SqStack *&S,char x)
{
	S->top++;
	S->data[S->top]=x;
}

void Pop(SqStack *&S,char &x)
{
	x=S->data[S->top];
	S->top--;
}

void InitQueue(SqQueue *&Q)
{
	Q=new SqQueue();
	Q->front=0;
	Q->rear=0;
}

void EnQueue(SqQueue *&Q,char x)
{
	Q->data[Q->rear]=x;
	Q->rear++;
}

void DeQueue(SqQueue *&Q,char &x)
{
	x=Q->data[Q->front];
	Q->front++;
}

bool IsEmpty(SqQueue *Q)
{
	if(Q->front==Q->rear)
		return true;
	else
		return false;
}

//括号匹配 
bool Match(SqStack *&S,string str)
{
	char e;
	for(int i=0;i<str.length();i++)
	{
		switch(str[i]){
			case '(':
				Push(S,'(');
				break;
			case '[':
				Push(S,'[');
				break;
			case '{':
				Push(S,'{');
				break;
			case ')':
				Pop(S,e);
				if(e!='(')
					return false;
				break;
			case ']':
				Pop(S,e);
				if(e!='[')
					return false;
				break;
			case '}':
				Pop(S,e);
				if(e!='{')
					return false;
				break;
			default:
				break;
		}
	}
	if(S->top!=-1)
		return false;
	return true;
}
//火车硬卧软卧调度 
void Train_Arrange(SqStack *&S,char *train)
{
	char *p=train,*q=train,c;
	while(*p)
	{
		if(*p=='H')
			Push(S,*p);
		if(*p=='S')
			*(q++)=*p;
		*p++;
	}
	while(S->top!=-1)
	{
		Pop(S,c);
		*(q++)=c;
	}
}

//递归函数计算
int Count(int x,int n)
{
	if(n==0)
		return 1;
	else if(n==1)
		return 2*x;
	else
	{
		return 2*x*Count(x,n-1)-2*(n-1)*Count(x,n-2);
	}
 }

//渡口管理调度
void Arrange_Dock(SqQueue *&Q1,SqQueue *&Q2,SqQueue *&Q)
{
	int i=0,j=0;
	char x;
	while(j<10)
	{
		if(i<4&&!IsEmpty(Q1))
		{
			DeQueue(Q1,x);
			EnQueue(Q,x);
			i++;
			j++;	
		}
		if(i==4&&!IsEmpty(Q2))
		{
			DeQueue(Q2,x);
			EnQueue(Q,x);
			i=0;
			j++;
		}
		if(IsEmpty(Q1)&&!IsEmpty(Q2))
		{
			DeQueue(Q2,x);
			EnQueue(Q,x);
			j++;
		}
		if(!IsEmpty(Q1)&&IsEmpty(Q2))
		{
			DeQueue(Q1,x);
			EnQueue(Q,x);
			j++;
		}
		if(IsEmpty(Q1)&&IsEmpty(Q2))
			j=11;
	}
 } 
 
int main()
{
	/*SqStack *S;
	string x="(((({{[[]]}}))))";
	InitStack(S);
	bool a=Match(S,x);
	cout<<a<<endl;*/
	cout<<Count(3,5)<<endl;
	system("pause");
	return 0;
}

