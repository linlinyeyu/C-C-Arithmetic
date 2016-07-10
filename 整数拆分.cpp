#include <stdio.h>
#include <iostream>
#include <algorithm>
#define Maxsize 100

using namespace std;
typedef struct{
	int data[Maxsize];
	int top;
}Stack;

void InitStack(Stack *S){
	S=new Stack();
	S->top=-1;
}

void PushStack(Stack *S,int x){
	S->top++;
	S->data[S->top]=x;
}

void PopStack(Stack *S,int &x){
	x=S->data[S->top];
	S->top--;
}

void count(int n,Stack *S)
{
	int x,y;
	x=n/2;
	y=n-x;
	if(n>x*y)
	{
		PushStack(S,n);
	}
	else{
		count(x,S);
		count(y,S);
	}
}

int main( ) {
	int n;
	while(scanf("%d",&n)!=EOF){
		if(n==0)
			break;
		Stack *S;
		int x,arr[Maxsize],i=0;
		InitStack(S);
		count(n,S);
		while(S->top!=-1){
			PopStack(S,x);
			arr[i]=x;
			i++;
		}
		sort(arr,arr+i);
		while(i>=0){
			cout<<arr[i]<<" ";
			i--;
		}
		cout<<endl;
	}
	return 0;
}
