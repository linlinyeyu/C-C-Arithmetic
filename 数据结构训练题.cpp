#include "stdio.h"
#include "stdlib.h"
#include "iostream"
#define Maxsize 50
using namespace std;

//顺序表结构体
typedef struct {
	int data[Maxsize];
	int length;
} Sqlist;

//创建顺序表
void CreateList(Sqlist &L,int n,int x[]) {
	for(int i=0; i<n; i++) {
		L.data[i]=x[i];
	}
	L.length=n;
}

//输出顺序表
void DisplayList(Sqlist L) {
	for(int i=0; i<L.length; i++)
		cout<<L.data[i]<<" ";
	cout<<endl;
}

//删除最小值元素，并用最后一个元素替换
int DeleteMinNum(Sqlist &L,int &e) {
	int k=0;
	if(L.length<1)
		return 0;
	int value=L.data[0];
	for(int i=1; i<L.length; i++) {
		if(value>L.data[i]) {
			value=L.data[i];
			k=i;
		}
	}
	e=value;
	L.data[k]=L.data[L.length-1];
	L.length--;
	return e;
}

//逆序顺序表所有元素,时间复杂度为1
bool ReverseList(Sqlist &L) {
	if(L.length<1)
		return false;
	for(int i=0; i<L.length/2; i++) {
		int temp=L.data[i];
		L.data[i]=L.data[L.length-1-i];
		L.data[L.length-1-i]=temp;
	}
	return true;
}

//删除所有值为x的元素,时间复杂度为O(n)
bool DeleteNum(Sqlist &L,int x) {
	if(L.length<1)
		return false;
	int k=0;
	for(int i=0; i<L.length; i++) {
		if(L.data[i]==x)
			k++;
		else
			L.data[i-k]=L.data[i];
	}
	L.length=L.length-k;
	return true;
}

//删除在s与t之间值得元素
bool DeletePeriod(Sqlist &L,int s,int t) {
	if(L.length<1||s>t)
		return false;
	int k=0;
	for(int i=0; i<L.length; i++) {
		if(L.data[i]<s||L.data[i]>t) {
			L.data[k]=L.data[i];
			k++;
		}
	}
	if(k==0)
		return false;
	L.length=k;
	return true;
}

//删除重复元素
void DeleteRepeat(Sqlist &L) {
	int i=0,j=1,len=1;
	while(j<L.length) {
		for(i=0; i<len; i++) {
			if(L.data[i]==L.data[j])
				break;
		}
		if(i==len) {
			L.data[len++]=L.data[j];
		} else
			j++;
	}
	L.length=len;
}

//合并有序顺序表为新的有序顺序表
Sqlist UnionList(Sqlist &L1,Sqlist &L2,Sqlist &L) {
	int i=0,j=0,k=0;
	if(L1.data[0]<L2.data[0]) {
		L.data[i]=L1.data[0];
	} else {
		L.data[i]=L2.data[0];
		k++;
	}
	while(j<L1.length&&k<L2.length) {
		if(L1.data[j]<L2.data[k]) {
			L.data[i++]=L1.data[j];
			j++;
		} else {
			L.data[i++]=L2.data[k];
			k++;
		}
	}
	while(j<L1.length) {
		L.data[i++]=L1.data[j];
		j++;
	}
	while(k<L2.length) {
		L.data[i++]=L2.data[k];
		k++;
	}
	L.length=i;
	return L;
}

//将数组中两个顺序表互换
/*void Reverse(Sqlist &L,int n,int m) {
	int mid=(n+m)/2;
	for(int i=0;i<mid-n+1;i++)
	{
		int temp=L.data[i+n-1];
		L.data[i+n-1]=L.data[m-i-1];
		L.data[m-i-1]=temp;
	}
}*/

/*void Exchange(Sqlist &L,int m,int n)
{
	Reverse(L,1,L.length);
	Reverse(L,1,m);
	Reverse(L,m+1,n);
}*/

//查找数值为x的元素，并与后继元素交换
void SeleExchange(Sqlist &L,int x)
{
	int low=0,high=L.length-1,mid;
	while(low<=high){
		mid=(low+high)/2;
		if(L.data[mid]==x)
		break;
		else if(L.data[mid]<x)
		low=mid+1;
		else
		high=mid-1;
	}
	if(L.data[mid]==x&&mid!=L.length-1){
		int temp=L.data[mid];
		L.data[mid]=L.data[mid+1];
		L.data[mid+1]=temp;
	}
	if(low>high){
		for(int i=L.length-1;i>high;i--)
		L.data[i+1]=L.data[i];
		L.data[high+1]=x;
		L.length++;
	}
 } 

//2010年试题循环左移数组
void MoveLeft(Sqlist &L,int p)
{
	void Reverse(Sqlist &L,int n,int m);
	Reverse(L,1,L.length);
	Reverse(L,1,L.length-p);
	Reverse(L,L.length-p+1,L.length);
 } 

void Reverse(Sqlist &L,int n,int m)
{
	int mid=(n+m)/2;
	for(int i=0;i<mid-n+1;i++)
	{
		int temp=L.data[i+n-1];
		L.data[i+n-1]=L.data[m-i-1];
		L.data[m-i-1]=temp;
	}
}

//2011年试题求两个有序序列中位数
int FindMidNum(Sqlist &L1,Sqlist &L2,int n)
{
	int f1=0,r1=n-1,mid1,f2=0,r2=n-1,mid2;
	while(f1!=r1||f2!=r2)
	{
		mid1=(f1+r1)/2;
		mid2=(f2+r2)/2;
		if(L1.data[mid1]==L2.data[mid2])
			return L1.data[mid1];
		if(L1.data[mid1]<L2.data[mid2])
		{
			if((f1+r1)%2==0)
			{
				f1=mid1;
				r2=mid2;
			}
			else
			{
				f1=mid1+1;
				r2=mid2;
			}
				
		}
		else
		{
			if((f2+r2)%2==0)
			{
				r1=mid1;
				f2=mid2;
			}
			else
			{
				r1=mid1;
				f2=mid2+1;
			}
		}
	}
	return L1.data[f1]<L2.data[f2]?L1.data[f1]:L2.data[f2];
 }

//2013年试题求数组中主元素
int MainNum(Sqlist &L)
{
	int a,k=1,count=0;
	a=L.data[0];
	for(int i=1;i<L.length;i++){
		if(a==L.data[i])
		k++;
		else
		k--;
		if(k==0){
			a=L.data[i];
			k=1;
		}
	}
	for(int i=0;i<L.length;i++){
		if(L.data[i]==a)
		count++;
	}
	if(count>L.length/2)
	return a;
	return -1;
  }
    
int main() {
	Sqlist L1,L2,L;
	int e;
	int x[]= {2,3,4,5,6,7,8,9};
	int y[]= {6,7,8,10,11,12,13,14};
	int z[]={2,2,2,3,3,3,2,4,2,2,3};
	CreateList(L1,8,x);
	CreateList(L2,8,y);
	CreateList(L,11,z);
	cout<<MainNum(L)<<endl;
	system("pause");
	return 0;
}


