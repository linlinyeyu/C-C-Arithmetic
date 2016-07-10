#include "stdio.h"
#include "stdlib.h"
#include "iostream"
#define Maxsize 50
using namespace std;

typedef struct Node {
	char data;
	struct Node *lchild,*rchild;
} BiTNode;

typedef struct {
	char data[Maxsize];
} SqTree;

typedef struct {
	BiTNode* data[Maxsize];
	int top;
} SqStack;

typedef struct {
	BiTNode* data[Maxsize];
	int front,rear;
} SqQueue;

typedef struct {
	BiTNode *data[Maxsize];
	int level[Maxsize];
	int front,rear;
} Qu;

typedef struct {
	BiTNode *t;
	int tag;
} stack;

typedef struct node {
	BiTNode* data;
	struct node *next;
} LinkList;

typedef struct ThreadNode {
	char data;
	struct ThreadNode *lchild,*rchild;
	int ltag,rtag;
} ThreadTree;

void InitStack(SqStack *&S) {
	S=new SqStack();
	S->top=-1;
}

bool IsEmpty(SqStack *S) {
	if(S->top==-1)
		return true;
	else
		return false;
}

bool IsEmptyQ(SqQueue *Q) {
	if(Q->front==Q->rear)
		return true;
	else
		return false;
}

void Push(SqStack *&S,BiTNode *x) {
	S->top++;
	S->data[S->top]=x;
}

void Pop(SqStack *&S,BiTNode *&x) {
	x=S->data[S->top];
	S->top--;
}

void GetTop(SqStack *S,BiTNode *&x) {
	x=S->data[S->top];
}

void InitQueue(SqQueue *&Q) {
	Q=new SqQueue();
	Q->front=Q->rear=0;
}

void EnQueue(SqQueue *&Q,BiTNode *x) {
	Q->data[Q->rear]=x;
	Q->rear++;
}

void DeQueue(SqQueue *&Q,BiTNode *&x) {
	x=Q->data[Q->front];
	Q->front++;
}

void Visit(BiTNode *p) {
	cout<<p->data<<" ";
}

//查找i,j最早共同祖先节点
int Comm_Ancestor(SqTree *T,int i,int j) {
	if(T->data[i]!='\0'&&T->data[j]!='\0') {
		while(i!=j) {
			if(i>j)
				i=i/2;
			else
				j=j/2;
		}
		return T->data[i];
	}
}

//非递归后序遍历二叉树
void PostOrder(BiTNode *T) {
	SqStack *S;
	InitStack(S);
	BiTNode *p=T;
	BiTNode *r;
	r=NULL;
	while(p||!IsEmpty(S)) {
		if(p) {
			Push(S,p);
			p=p->lchild;
		} else {
			GetTop(S,p);
			if(p->rchild&&p->rchild!=r) {
				p=p->rchild;
				Push(S,p);
				p=p->lchild;
			} else {
				Pop(S,p);
				Visit(p);
				r=p;
				p=NULL;
			}
		}
	}
}

//自下而上，从右而左层次遍历
void LevelOrder(BiTNode *T) {
	SqQueue *Q;
	SqStack *S;
	BiTNode *p;
	InitQueue(Q);
	InitStack(S);
	EnQueue(Q,T);
	while(!IsEmptyQ(Q)) {
		DeQueue(Q,p);
		Push(S,p);
		if(p->lchild)
			EnQueue(Q,p->lchild);
		if(p->rchild)
			EnQueue(Q,p->rchild);
	}
	while(!IsEmpty(S)) {
		Pop(S,p);
		Visit(p);
	}
}

//非递归求二叉树高度
int Btdepth(BiTNode *T) {
	SqQueue *Q;
	BiTNode *p;
	int last=1,level=0;
	InitQueue(Q);
	EnQueue(Q,T);
	while(!IsEmptyQ(Q)) {
		DeQueue(Q,p);
		if(p->lchild)
			EnQueue(Q,p->lchild);
		if(p->rchild)
			EnQueue(Q,p->rchild);
		if(Q->front==last) {
			level++;
			last=Q->rear;
		}
	}
	return level;
}

//判断二叉树是否为完全二叉树
bool IsCompleteBt(BiTNode *T) {
	BiTNode *p;
	SqQueue *Q;
	InitQueue(Q);
	EnQueue(Q,T);
	while(!IsEmptyQ(Q)) {
		DeQueue(Q,p);
		if(p) {
			EnQueue(Q,p->lchild);
			EnQueue(Q,p->rchild);
		} else {
			while(!IsEmptyQ(Q)) {
				DeQueue(Q,p);
				if(p!=NULL)
					return false;
			}
		}
	}
	return true;
}

//计算二叉树所有双分支节点个数
int CountDoubleNode(BiTNode *T) {
	/*int i=0;
	BiTNode *p;
	SqQueue *Q;
	InitQueue(Q);
	EnQueue(Q,T);
	while(!IsEmptyQ(Q))
	{
		DeQueue(Q,p);
		if(p)
		{
			if(p->lchild&&p->rchild)
				i++;
			if(p->lchild)
				EnQueue(Q,p->lchild);
			if(p->rchild)
				EnQueue(Q,p->rchild);
		}
	}
	return i;*/
	if(T==NULL)
		return 0;
	else if(T->lchild!=NULL&&T->rchild!=NULL)
		return CountDoubleNode(T->lchild)+CountDoubleNode(T->rchild)+1;
	else
		return CountDoubleNode(T->lchild)+CountDoubleNode(T->rchild);
}

//把树B所有结点的左、右子树进行交换
void SwapNode(BiTNode *&T) {
	BiTNode *p;
	if(T) {
		SwapNode(T->lchild);
		SwapNode(T->rchild);
		p=T->lchild;
		T->lchild=T->rchild;
		T->rchild=p;
	}
}


//求先序遍历序列中第k个结点的值
char DataNode(BiTNode *T,int k) {
	int i=0;
	SqStack *S;
	InitStack(S);
	BiTNode *p=T;
	Push(S,p);
	while(p&&!IsEmpty(S)) {
		Pop(S,p);
		i++;
		if(i==k) {
			return p->data;
			break;
		}
		if(p->rchild)
			Push(S,p->rchild);
		if(p->lchild)
			Push(S,p->lchild);
	}
	/*if(T==NULL)
		return '#';
	if(i==k)
	return T->data;
	i++;
	char ch;
	ch=DataNode(T->lchild,k);
	if(ch!='#')
		return ch;
	ch=DataNode(T->rchild,k);
		return ch;*/
}

//删除元素值为x的子树
void Delete(BiTNode *&T) {
	if(T) {
		Delete(T->lchild);
		Delete(T->rchild);
		free(T);
	}
}

void DeleteXNode(BiTNode *&T,char x) {
	SqStack *S;
	InitStack(S);
	BiTNode *p=T;
	Push(S,p);
	if(T->data==x) {
		Delete(T);
		return;
	}
	while(p&&!IsEmpty(S)) {
		Pop(S,p);
		if(p->rchild)
			if(p->rchild->data==x) {
				Delete(p->rchild);
				p->rchild=NULL;
			} else
				Push(S,p->rchild);
		if(p->lchild)
			if(p->lchild->data==x) {
				Delete(p->lchild);
				p->lchild=NULL;
			} else
				Push(S,p->lchild);
	}

	/*SqQueue *Q;
	BiTNode *p;
	InitQueue(Q);
	if(T)
	{
		if(T->data==x)
		{
			Delete(T);
			return;
		}
	EnQueue(Q,T);
	while(!IsEmptyQ(Q))
	{
		DeQueue(Q,p);
		if(p->lchild)
			if(p->lchild->data==x)
			{
				Delete(p->lchild);
				p->lchild=NULL;
			}
			else
				EnQueue(Q,p->lchild);
		if(p->rchild)
			if(p->rchild->data==x)
			{
				Delete(p->rchild);
				p->rchild=NULL;
			}
			else
				EnQueue(Q,p->rchild);
	}
	}*/
}

//利用中序和先序建立二叉链表
void CreateTNodePI(BiTNode *&T,char x[],char y[],int l1,int r1,int l2,int r2) {
	int i;
	T=new BiTNode();
	T->data=x[l1];
	for(i=l2; i<r2; i++) {
		if(y[i]!=T->data)
			i++;
	}
	int llen=i-l2;
	int rlen=r2-i;
	if(llen)
		CreateTNodePI(T->lchild,x,y,l1+1,l1+llen,l2,l2+llen-1);
	else
		T->lchild=NULL;
	if(rlen)
		CreateTNodePI(T->rchild,x,y,r1-rlen+1,r1,r2-rlen+1,r2);
	else
		T->rchild=NULL;
}

//打印值为x的所有祖先
bool DispXParNode(BiTNode *&T,char x) {
	SqStack *S;
	InitStack(S);
	BiTNode *p,*r;
	p=T;
	r=NULL;
	while(p||!IsEmpty(S)) {
		if(p&&p->data!=x) {
			Push(S,p);
			p=p->lchild;
		}
		if(p->data==x) {
			p=NULL;
			break;
		}
		if(p==NULL) {
			GetTop(S,p);
			if(p->rchild&&p->rchild!=r) {
				if(p->rchild->data!=x) {
					p=p->rchild;
					Push(S,p);
					p=p->lchild;

				} else {
					Push(S,p);
					break;
				}
			} else {
				Pop(S,p);
				r=p;
				p=NULL;
			}
		}
	}
	if(IsEmpty(S))
		return false;
	while(S->top!=-1) {
		Pop(S,p);
		Visit(p);
	}
	return true;

	//递归
	/*if(DispXParNode(T->lchild,x)||DispXParNode(T->rchild,x))
	{
		Visit(T);
		return true;
	 }
	 return false;*/
}

//查找两个节点最近公共节点
BiTNode *Ancestor(BiTNode *T,BiTNode *p,BiTNode *q) {
	/*BiTNode *t=T,*r;
	SqStack *S1,*S2;
	InitStack(S1);
	InitStack(S2);
	r=NULL;
	while(t||!IsEmpty(S1))
	{
		while(t&&t!=p&&t!=q)
		{
			Push(S1,t);
			t=t->lchild;
		}
		if(t==NULL)
		{
			GetTop(S1,t);
			if(t->rchild&&t->rchild!=r)
			{
				t=t->rchild;
				Push(S1,t);
				t=t->lchild;
			}
			else
			{
				Pop(S1,t);
				r=t;
				t=NULL;
			}
		}
		while(!IsEmpty(S1)&&S1->data[S1->top]==r)
		{
			if(t==p)
			{
				for(int i=0;i<=S1->top;i++)
				S2->data[i]=S1->data[i];
				S2->top=S1->top;
			}
			if(t==q)
				for(int i=S1->top;i>-1;i--)
				{
					for(int j=S2->top;j>-1;j--)
						if(S1->data[i]==S2->data[j])
							return S1->data[i];
				}
			S1->top--;
		}
	}
	return NULL;*/

	stack s[Maxsize],s1[Maxsize];
	BiTNode *t;
	int top=0,top1;
	t=T;
	while(T||top>0) {
		while(t!=NULL&&t!=p&&t!=q)
			while(t) {
				s[++top].t=t;
				s[top].tag=0;
				t=t->lchild;
			}
		while(top!=0&&s[top].tag==1) {
			if(s[top].t==p) {
				for(int i=1; i<=top; i++)
					s1[i]=s[i];
				top1=top;
			}
			if(s[top].t==q)
				for(int i=top; i>0; i--) {
					for(int j=top1; j>0; j--)
						if(s1[j].t=s[i].t)
							return s[i].t;
				}
			top--;
		}
		if(top!=0) {
			s[top].tag=1;
			t=s[top].t->rchild;
		}
	}
	return NULL;
}

//求二叉树宽度
int  BTWidth(BiTNode *T) {
	BiTNode *p;
	int k,max,i,n;
	Qu *Q;
	Q=new Qu();
	Q->front=Q->rear=-1;
	Q->rear++;
	Q->data[Q->rear]=T;
	Q->level[Q->rear]=1;
	while(Q->front<Q->rear) {
		Q->front++;
		p=Q->data[Q->front];
		k=Q->level[Q->front];
		if(p->lchild) {
			Q->rear++;
			Q->data[Q->rear]=p->lchild;
			Q->level[Q->rear]=k+1;
		}
		if(p->rchild) {
			Q->rear++;
			Q->data[Q->rear]=p->rchild;
			Q->level[Q->rear]=k+1;
		}
	}
	cout<<"各节点层次编号为:"<<endl;
	for(i=0; i<=Q->rear; i++)
		cout<<Q->data[i]->data<<","<<Q->level[i]<<endl;
	max=0;
	i=0;
	k=1;
	while(i<=Q->rear) {
		n=0;
		while(i<=Q->rear&&Q->level[i]==k) {
			n++;
			i++;
		}
		k=Q->level[i];
		if(n>max)
			max=n;
	}
	return max;
}

//已知满二叉树先序序列求后序序列
void PreToPost(char *pre,int l1,int r1,char *post,int l2,int r2) {
	int half;
	if(r1>=l1) {
		post[r2]=pre[l1];
		half=(r1-l1)/2;
		PreToPost(pre,l1+1,l1+half,post,l2,l2+half-1);
		PreToPost(pre,l1+half+1,r1,post,l2+half,r2-1);
	}
}

//将叶节点从左至右连成一个单链表
/*LinkList *head;
LinkList *pre=NULL;
LinkList InOrderList(BiTNode *T) {
	if(T) {
		InOrderList(T->lchild);
		if(T->lchild==NULL&&T->rchild==NULL) {
			if(pre==NULL) {
				head=T;
				pre=T;
			} else {
				pre->lchild=T;
				pre=T;
			}
			InOrderList(T->rchild);
			pre->rchild=NULL;
		}
	}
	return head;
}*/

//判断两棵二叉树是否相似
bool Similar(BiTNode *T1,BiTNode *T2) {
	if(T1==NULL&&T2==NULL)
		return true;
	else if(T1==NULL||T2==NULL)
		return false;
	else {
		bool left=Similar(T1->lchild,T2->lchild);
		bool right=Similar(T1->rchild,T2->rchild);
		return left&&right;
	}
}

//找到中序线索二叉树中某指定节点在后序中的前驱节点
ThreadTree *InPost(ThreadTree *T,ThreadTree *p) {
	if(p->rtag==0)
		return p->rchild;
	else if(p->ltag==0)
		return p->lchild;
	else if(p->lchild==NULL)
		return NULL;
	else {
		if(p->ltag==1&&p->lchild!=NULL)
			p=p->lchild;
		if(p->ltag==0)
			return p->lchild;
		else
			return NULL;
		}
}

//计算二叉树带权路径长度
int WPL_PreOrder(BiTNode *T,int deep)
{
	static int wpl=0;
	if(T->lchild==NULL&&T->rchild==NULL)
		wpl+=deep*T->data;
	if(T->lchild!=NULL)
		WPL_PreOrder(T->lchild,deep+1);
	if(T->rchild!=NULL)
		WPL_PreOrder(T->rchild,deep+1);
	return wpl;
}
int WPLTree(BiTNode *T)
{
	return WPL_PreOrder(T,0);
} 

//创建二叉树
void CreateTNode(BiTNode *&T) {
	/*int i=0;
	while(i<S.length())
	{
		if(S[i]=='#')
		{
			T=NULL;
		 }
		else
		{
			T=new BiTNode();
			T->data=S[i];
			CreateTNode(T->lchild,S);
			CreateTNode(T->rchild,S);
		 }
	 }*/
	char ch;
	ch=getchar();
	if(ch=='#')
		T=NULL;
	else {
		T=new BiTNode();
		T->data=ch;
		CreateTNode(T->lchild);
		CreateTNode(T->rchild);
	}
}

void PreOrder(BiTNode *T) {
	if(T) {
		Visit(T);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}

void PostOrder2(BiTNode *T) {
	if(T) {
		PostOrder2(T->lchild);
		PostOrder2(T->rchild);
		Visit(T);
	}
}

void InOrder(BiTNode *T) {
	if(T) {
		InOrder(T->lchild);
		Visit(T);
		InOrder(T->rchild);
	}
}

int main() {
	char *x= "abdecfg";
	char *y=new char();
	BiTNode *T;
	CreateTNode(T);
	cout<<WPLTree(T);
	//SwapNode(T);
	system("pause");
	return 0;
}
