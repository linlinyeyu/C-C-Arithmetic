#include "stdio.h"
#include "stdlib.h"
#include "iostream"
using namespace std;

typedef struct Node {
	int data;
	struct Node *next;
} LinkList;

//ͷ�巨����������
void CreateList(LinkList *&L,int x[],int n) {
	LinkList *s;
	L=new LinkList();
	L->next=NULL;
	for(int i=0; i<n; i++) {
		s=new LinkList();
		s->data=x[i];
		s->next=L->next;
		L->next=s;
	}
}

//β�巨����������
void CreateListR(LinkList *&L,int x[],int n) {
	LinkList *s,*r;
	L=new LinkList();
	L->next=NULL;
	r=L;
	for(int i=0; i<n; i++) {
		s=new LinkList();
		s->data=x[i];
		s->next=r->next;
		r->next=s;
		r=s;
	}
	r->next=NULL;
}

//���������
void DispList(LinkList* L) {
	LinkList *p=L->next;
	while(p!=NULL) {
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
}

//�ݹ�ɾ��ֵΪx�Ľڵ�
void Del_x(LinkList *&L,int x) {
	LinkList *p;
	if(L==NULL)
		return;
	if(L->data==x) {
		p=L;
		L=L->next;
		free(p);
		Del_x(L,x);
	} else
		Del_x(L->next,x);
}

//ɾ����ͷ�ڵ�ĵ���������xֵ
void DeleteX(LinkList *&L,int x) {
	LinkList *pre=L,*p,*q;
	p=pre->next;
	while(p!=NULL) {
		if(p->data==x) {
			q=p;
			pre->next=p->next;
			p=p->next;
			free(q);
		} else {
			pre=pre->next;
			p=p->next;
		}
	}
}

//���������ͷ�ڵ�ĵ�����
LinkList* RDispList(LinkList *L) {
	/*if(L->next!=NULL){
		RDispList(L->next);
	}
	cout<<L->data<<" ";
	*/
	LinkList *s,*q;
	s=new LinkList();
	s->next=NULL;
	while(L!=NULL) {
		q=L->next;
		L->next=s->next;
		s->next=L;
		L=q;
	}
	return s;
}

//ɾ����Сֵ�ڵ�
void DelMinNum(LinkList *&L) {
	LinkList *Minpre=L,*Min,*p,*pre;
	Min=Minpre->next;
	pre=Min;
	p=pre->next;
	while(p!=NULL) {
		if(p->data<Min->data) {
			Min=p;
			Minpre=pre;
		} else {
			pre=pre->next;
			p=pre->next;
		}
	}
	Minpre->next=Min->next;
	free(Min);
}

//����ͷ�ڵ�ĵ�����͵�����
LinkList* OnReverse(LinkList *&L) {
	LinkList *s,*q;
	s=new LinkList();
	s->next=NULL;
	while(L!=NULL) {
		q=L->next;
		L->next=s->next;
		s->next=L;
		L=q;
	}
	return s;
}

//��һ����ͷ�ڵ�ĵ������������
void SortList(LinkList *&L) {
	LinkList *pre,*r,*q;
	r=L->next;
	q=r->next;
	r->next=NULL;
	r=q;
	while(r!=NULL) {
		q=r->next;
		pre=L;
		while(pre->next!=NULL&&pre->next->data<r->data)
			pre=pre->next;
		r->next=pre->next;
		pre->next=r;
		r=q;
	}
}

//ɾ�����ڸ�������ֵ֮���Ԫ��
void DelDurNum(LinkList *&L,int x,int y) {
	LinkList *pre=L,*p=pre->next;
	while(p!=NULL) {
		if(p->data>x&&p->data<y) {
			LinkList *q=p;
			pre->next=p->next;
			p=p->next;
			free(q);
		} else {
			pre=pre->next;
			p=pre->next;
		}
	}
}

//�ҳ������������ڵ�
LinkList *SearchCommonPoint(LinkList *&L1,LinkList *&L2) {
	int GetLength(LinkList *L);
	int len,len1,len2;
	LinkList *p1,*p2;
	p1=L1->next;
	p2=L2->next;
	len1=GetLength(L1);
	len2=GetLength(L2);
	if(len1<len2) {
		p1=L2;
		p2=L1;
		len=len2;
		len2=len1;
		len1=len;
	}
	while(len1>len2) {
		p1=p1->next;
		len1--;
	}
	while(p1->data!=p2->data&&p1!=NULL) {
		p1=p1->next;
		p2=p2->next;
	}
	return p1;
}

int GetLength(LinkList *L) {
	int count=0;
	LinkList *p=L->next;
	while(p!=NULL) {
		p=p->next;
		count++;
	}
	return count;
}

//����������������������ͷŽڵ���ռ�洢�ռ�
void DispSort(LinkList *&L) {
	while(L->next!=NULL) {
		LinkList *pre=L;
		LinkList *p=pre->next;
		while(p->next!=NULL) {
			if(p->next->data<pre->next->data) {
				pre=p;
				p=p->next;
			}
		}
		cout<<pre->next->data<<" ";
		LinkList *u=pre->next;
		pre->next=u->next;
		free(u);
	}
	free(L);
}

//���������Ϊ������ͷ�ڵ�����һ��Ϊ������ţ���һ�����Ϊż�������˳�򲻱�
LinkList *DisCreate(LinkList *&L1) {
	int i=0;
	LinkList *p=L1->next,*L2;
	LinkList *r1,*r2;
	L1->next=NULL;
	L2=new LinkList();
	L2->next=NULL;
	r2=L2;
	r1=L1;
	while(p!=NULL) {
		i++;
		if(i%2==0) {
			r2->next=p;
			r2=p;
		} else {
			r1->next=p;
			r1=p;
		}
		p=p->next;
	}
	r1->next=NULL;
	r2->next=NULL;
	return L1;
}

//�͵ز��Ϊ�������Ա�
void SplitList(LinkList *&L1,LinkList *&L2) {
	int i=0;
	LinkList *p=L1->next,*r;
	L1->next=NULL;
	L2=new LinkList();
	L2->next=NULL;
	r=L1;
	while(p!=NULL) {
		i++;
		if(i%2==0) {
			LinkList *q=p->next;
			p=L2->next;
			L2->next=p;
			p=q;
		} else {
			r->next=p;
			r=p;
			p=p->next;
		}
	}
	r->next=NULL;
}

//ɾ����ֵ��ͬ��Ԫ�أ�ʹ���в������ظ���Ԫ��
void Del_Same(LinkList *&L) {
	LinkList *p=L->next;
	while(p->next!=NULL) {
		if(p->data==p->next->data) {
			p->next=p->next->next;
		} else
			p=p->next;
	}
}

//�ϲ�����������������Ϊ�ݼ���������
LinkList* UnionDesc(LinkList *&L1,LinkList *&L2) {
	LinkList *L;
	LinkList *p1=L1->next;
	LinkList *p2=L2->next;
	L=new LinkList();
	L->next=NULL;
	while(p1&&p2) {
		if(p1->data<p2->data) {
			LinkList *q=p1->next;
			p1->next=L->next;
			L->next=p1;
			p1=q;
		} else {
			LinkList *q=p2->next;
			p2->next=L->next;
			L->next=p2;
			p2=q;
		}
	}
	while(p1) {
		LinkList *q=p1->next;
		p1->next=L->next;
		L->next=p1;
		p1=q;
	}
	while(p2) {
		LinkList *q=p2->next;
		p2->next=L->next;
		L->next=p2;
		p2=q;
	}
	return L;
}

//��AB�������������в�������Ԫ������C�����ƻ�A,B�ڵ�
LinkList *CommonList(LinkList *&L1,LinkList *&L2) {
	LinkList *L,*s,*p1=L1->next,*p2=L2->next,*r;
	L=new LinkList();
	L->next=NULL;
	r=L;
	while(p1&&p2) {
		if(p1->data<p2->data)
			p1=p1->next;
		else if(p1->data>p2->data)
			p2=p2->next;
		else {
			s=new LinkList();
			s->data=p1->data;
			r->next=s;
			r=s;
			p1=p1->next;
			p2=p2->next;
		}
	}
	r->next=NULL;
	return L;
}
//����������Ľ���
LinkList *Union(LinkList *&L1,LinkList *&L2) {
	LinkList *p1,*p2,*r;
	p1=L1->next;
	p2=L2->next;
	L1->next=NULL;
	r=L1;
	while(p1&&p2) {
		if(p1->data<p2->data)
			p1=p1->next;
		else if(p2->data<p1->data)
			p2=p2->next;
		else {
			r->next=p1;
			r=p1;
			p1=p1->next;
			p2=p2->next;
		}
	}
	r->next=NULL;
	return L1;
}

//�ж�����B�Ƿ�������A������������
bool Pattern(LinkList *&L1,LinkList *&L2) {
	LinkList *p1=L1->next;
	LinkList *p2=L2->next;
	while(p1&&p2) {
		if(p1->data==p2->data) {
			p1=p1->next;
			p2=p2->next;
		} else {
			p1=p1->next;
			p2=L2->next;
		}
	}
	if(p1==NULL)
		return false;
	if(p2==NULL)
		return true;
}

//�жϴ�ͷ�ڵ��ѭ��˫�����Ƿ�Գ�
/*bool Symmetry(DLinkList *&L1)
{
	
 }*/

//��ֻ��ͷָ��listǰ���£����������е�����k��λ���ϵĽڵ�
int SearchLast(LinkList *&L,int k)
{
	LinkList *p=L->next;
	LinkList *q=L->next;
	int count=0;
	while(p!=NULL)
	{
		if(count<k)
			count++;
		else
			q=q->next;
		p=p->next;
	}
	if(count==k)
		{
			cout<<q->data<<endl;
			return 1;
		}
	else
		return 0;
 }

//�ҳ���������ͬ��׺����ʼλ��
LinkList *SearchFirst(LinkList *&L1,LinkList *&L2)
{
	LinkList *p1=L1->next;
	LinkList *p2=L2->next;
	int len1=GetLength(L1);
	int len2=GetLength(L2);
	int len;
	if(len1<len2)
	{
		p1=L2->next;
		p2=L1->next;
		len=len1;
		len1=len2;
		len2=len;
	}
	while(len1>len2)
	{
		p1=p1->next;
		len1--;
	}
	while(p1&&p2&&p1->data!=p2->data)
	{
		p1=p1->next;
		p2=p2->next;
	}
	return p1;
 } 
int main() {
	LinkList *L1,*L2,*L;
	int x[]= {3,4,1,1,2,3,4,5,6};
	int y[]= {1,1,2,3,4,5,6};
	CreateListR(L1,x,9);
	CreateListR(L2,y,7);
	L=SearchFirst(L1,L2);
	DispList(L);
	system("pause");
	return 0;
}
