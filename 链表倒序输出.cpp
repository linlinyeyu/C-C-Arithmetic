#include "stdio.h"
#include "stdlib.h"
#include "iostream"
#include <vector>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
};

class Solution {
	public:
		vector<int> printListFromTailToHead(struct ListNode* head) {
			vector<int> list;
/*			while(head!=NULL){
				list.insert(list.begin(),head->val);
				head=head->next;
			}*/
			if(head!=NULL){
				if(head->next!=NULL){
					list=printListFromTailToHead(head->next);
				}
				list.push_back(head->val);
			} 
			return list;
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

int main()
{
	struct ListNode *L;
	vector<int> v;
	int x[]={1,2,3,4,5,6,7,8,9};
	Creatlist(L,x,9);
	Solution *obj=new Solution();
	v=obj->printListFromTailToHead(L);
	for(vector<int>::size_type i = 0; i < v.size()-1; i++)
        cout<<v[i]<<" ";
        cout<<endl;
	system("pause");
	return 0;
}

