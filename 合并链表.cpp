#include <stdio.h>
#include <stdlib.h>
#include <iostream>
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

class Solution {
public:
    Sqlist* Merge(Sqlist* pHead1, Sqlist* pHead2)
{
    Sqlist *pHead=NULL,*cur=NULL;
        if(pHead1==NULL)
            return pHead2;
        if(pHead2==NULL)
            return pHead1;
        while(pHead1!=NULL&&pHead2!=NULL){
            if(pHead1->data<=pHead2->data){
                if(pHead==NULL){
                    cur=pHead=pHead1;
                }else{
                cur->next=pHead1;
                cur=cur->next;
            }
                pHead1=pHead1->next;
            }
            else{
                if(pHead==NULL){
                    cur=pHead=pHead2;
                }else{
                cur->next=pHead2;
                cur=cur->next;
            }
                pHead2=pHead2->next;
            }
        }
        if(pHead1!=NULL){
            cur->next=pHead1;
            
        }
        if(pHead2!=NULL){
            cur->next=pHead2;
            
        }
        return pHead->next;
}
};

void Put(int *x){
	x=new int[200];
	int i=0;
	for(;i<200;i++){
		cin>>x[i];
		if(getchar()=='\n')
		break;
	}
}

int main(){
	Sqlist *List1,*List2,*List;
	int x[]={1,2,3,4,5,6},y[]={4,5,6,7,8,9};
	int a=sizeof(x)/sizeof(x[0]);
	int b=sizeof(y)/sizeof(y[0]);
	Initlist(List1);
	Initlist(List2);
	Initlist(List);
	Creatlist(List1,x,a);
	Creatlist(List2,y,b);
	Displaylist(List1);
	Displaylist(List2);
	Solution *obj=new Solution();
	List=obj->Merge(List1,List2);
	Displaylist(List);
	system("pause");
	return 0;
}
