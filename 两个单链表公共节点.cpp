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
		ListNode* FindFirstCommonNode( ListNode *pHead1, ListNode *pHead2) {
			ListNode *p1,*p2;
			p1=pHead1->next;
			p2=pHead2->next;
			int len1=GetLen(pHead1->next);
			int len2=GetLen(pHead2->next);
			if(len1<=len2){
				p1=pHead2;
				p2=pHead1;
				int len=len1;
				len1=len2;
				len2=len;
			}
			while(len1>len2){
				p1=p1->next;
				--len1;
			}
			while(p1!=NULL&&p1!=p2){
				p1=p1->next;
				p2=p2->next;
			}
			return p1;
		}
			/*int nLength1 = GetLen(pHead1);
			int nLength2 = GetLen(pHead2);

			int nLengthDif = nLength1 - nLength2;

			ListNode *pHeadLong = pHead1;
			ListNode *pHeadShort = pHead2;
			if(nLength2 > nLength1 ) {
				ListNode *pHeadLong = pHead2;
				ListNode *pHeadShort = pHead1;

				nLengthDif = nLength2 - nLength1;




			}
			//先在长链表上走几步，再同时在两个链表上遍历。
			for(int i = 0; i < nLengthDif; i++)
				pHeadLong = pHeadLong->next;

			while((pHeadLong != NULL)&&(pHeadShort != NULL)
			        &&(pHeadLong != pHeadShort )) {

				pHeadLong = pHeadLong->next;
				pHeadShort = pHeadShort->next;

			}
			//得到第一个公共节点

			ListNode *pFirstCommonNode =    pHeadLong ;


			return pFirstCommonNode;
		}*/

		int GetLen(ListNode *pHead) {
			int len=0;
			ListNode *p=pHead->next;
			while(p!=NULL) {
				++len;
				p=p->next;
			}
			return len;
		}
};

void Creatlist(ListNode *&L,int x[],int n) {
	ListNode *s,*r;
	int i;
	L=(ListNode *)malloc(sizeof(ListNode));
	r=L;
	for(i=0; i<n; i++) {
		s=(ListNode *)malloc(sizeof(ListNode));
		s->val=x[i];
		r->next=s;
		r=s;
	}
	r->next=NULL;
}

void Displaylist(ListNode *pHead) {
	ListNode *p=pHead;
	while(p!=NULL) {
		cout<<p->val;
		p=p->next;
	}
	cout<<endl;
}

void DispList(ListNode *L) {
	ListNode *p=L->next;
	while(p!=NULL) {
		cout<<p->val<<" ";
		p=p->next;
	}
	cout<<endl;
}

int main() {
	ListNode *pHead1,*pHead2,*pHead;
	int x[]= {1,2,3,4,5,6,7};
	int y[]= {7,8,9,4,5,6,7};
	Creatlist(pHead1,x,7);
	Creatlist(pHead2,y,7);
	DispList(pHead1);
	DispList(pHead2);
	Solution *obj=new Solution();
	pHead=obj->FindFirstCommonNode(pHead1,pHead2);
	//cout<<pHead->val<<endl;
	Displaylist(pHead);
	system("pause");
	return 0;
}
