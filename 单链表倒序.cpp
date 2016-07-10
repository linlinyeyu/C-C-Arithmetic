#include "stdio.h"
#include "stdlib.h"
#include "iostream"
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
};

class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
		/*ListNode *p=pHead->next,*q;
		while(p->next!=NULL){
			q=p->next;
			p->next=q->next;
			q->next=pHead->next;
			pHead->next=q;
		}
		p->next=pHead;
		pHead=p->next->next;
		p->next->next=NULL;
		return pHead;
	}*/
	/*ListNode *p1,*p2,*p3;
	p1=pHead;
	p2=p1->next;
	while(p2){
		p3=p2->next;
		p2->next=p1;
		p1=p2;
		p2=p3;
	}
	pHead->next=NULL;
	pHead=p1;
	return pHead;
}*/
ListNode *s;
        s=(ListNode *)malloc(sizeof(ListNode));
        s->next=NULL;
        while(pHead!=NULL){
            ListNode *q=pHead->next;
            pHead->next=s->next;
            s->next=pHead;
            pHead=q;
        }
        return s;
    }
};

void Creatlist(struct ListNode *&L,int x[],int n){
	struct ListNode *s,*r;
	int i;
	L=(ListNode *)malloc(sizeof(ListNode));
	r=L;
	for(i=0;i<n;i++){
		s=(ListNode *)malloc(sizeof(ListNode));
		s->val=x[i];
		r->next=s;
		r=s;
	}
	r->next=NULL;
}

void DisplayList(ListNode *L)
{
	ListNode *p=L->next;
	while(p->next!=NULL){
		cout<<p->val<<" ";
		p=p->next;
	}
	cout<<endl;
 } 
 
int main()
{
	ListNode *L,*s;
	int x[]={1,2,3,4,5,6,7,8,9};
	Creatlist(L,x,9);
	Solution *obj=new Solution();
	s=obj->ReverseList(L);
	DisplayList(s);
	system("pause");
	return 0;
}
