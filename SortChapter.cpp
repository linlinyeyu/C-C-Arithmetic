#include "SortChapter.h"
#include <stdlib.h>
using namespace std;

void Sort::InsertSort(int data[],int n)
{
	int i,j;
	int temp;
	/*for(i=1;i<n;i++)
	{
		temp=data[i];
		j=i-1;
		while(j>=0&&temp<data[j])
		{
			data[j+1]=data[j];
			j--;
		}
		data[j+1]=temp;
	}*/
	for(i=1;i<n;i++)
	{
			temp=data[i];
			for(j=i-1;j>=0;j--)
			{
				if(data[j]>temp)
					data[j+1]=data[j];
				else
					break;	
			}
			data[j+1]=temp;
	}
}

void Sort::DispArray(int data[],int n)
{
	for(int i=0;i<n;i++)
		cout<<data[i]<<" ";
	cout<<endl;
}

void Sort::DoubleDirectionBubbleSort(int *data,int n)
{
	int low=0,high=n-1;
	bool flag=false;
	while(low<high&&!flag)
	{
		flag=true;
		for(int i=low;i<high;i++)
		{
			if(data[i+1]<data[i])
			{
				int temp=data[i+1];
				data[i+1]=data[i];
				data[i]=temp;
				flag=false;
			}
		}
		high--;
		for(int i=high;i>low;i--)
		{
			if(data[i-1]>data[i])
			{
				int temp=data[i-1];
				data[i-1]=data[i];
				data[i]=temp;
				flag=false;
			}
		}
		low++;
	}
}

void Sort::OddPreEven(int *data,int n)
{
	int i=0,j=n-1;
	while(i<j){
		while(data[j]%2==0)
			j--;
		while(data[i]%2!=0)
			i++;
		int temp=data[i];
		data[i]=data[j];
		data[j]=temp;
		i++;
		j--;
	}
}

int Sort::Merge(int *data,int low,int high)
{
	int pos=low+rand()%(high-low+1);
	int temp=data[pos];
	data[pos]=data[low];
	data[low]=temp;
	while(low<high)
	{
		while(data[high]>temp)
			high--;
		int tem=data[low];
		data[low]=data[high];
		data[high]=tem;
		while(data[low]<temp)
			low++;
		tem=data[high];
		data[high]=data[low];
		data[low]=tem;
	}
	data[low]=temp;
	return low;
}

void Sort::QuickSort(int *data,int low,int high)
{
	if(low<high)
	{
		int pos=Merge(data,low,high);
		QuickSort(data,pos+1,high);
		QuickSort(data,low,pos-1);
	}
}

int Sort::SelectNumK(int *data,int low,int high,int k)
{
	int pos=Merge(data,low,high);
	if(pos==k)
		return data[pos-1];
	if(pos>k)
		return SelectNumK(data,low,pos-1,k);
	if(pos<k)
		return SelectNumK(data,pos+1,high,k);
}
