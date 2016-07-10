#include "stdio.h"
#include "stdlib.h"
#include "iostream"
using namespace std;

typedef struct LNode{
	int data;
	struct LNode *next;
}Sqlist;

void Initlist(Sqlist *&L){
	L=new Sqlist();
	L->next=NULL;
}

void Creatlist(Sqlist *&L,int x[],int n){
	Sqlist *s,*r;
	int i;
	L=new Sqlist();
	r=L;
	for(i=0;i<n;i++){
		s=new Sqlist();
		s->data=x[i];
		r->next=s;
		r=s;
	}
	r->next=NULL;
} 

void Displaylist(Sqlist *L){
	Sqlist *p=L->next;
	while(p!=NULL){
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
}

int main(){
	Sqlist *L;
	int x[]={1,2,3,4,5,6,7,6,7,0};
	Initlist(L);
	Creatlist(L,x,10);
	Displaylist(L);
	system("pause");
	return 0;
}
