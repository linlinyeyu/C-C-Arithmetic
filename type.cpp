#include "type.h"
using namespace std;

int sqlist::MidFind(int x,int low,int high) {
	int mid=(low+high)/2;
	if(data[mid]==x)
		return mid;
	if(data[mid]<x)
		return MidFind(x,mid+1,high);
	else
		return MidFind(x,low,mid-1);
	if(low>high)
		return -1;
}

int sqlist::FindSwith(int x)
{
	int i=-1;
	while(data[i]!=x&&i<length)
		i++;
	if(i<length&&i>=0)
	{
		int temp=data[i-1];
		data[i-1]=data[i];
		data[i]=temp;
		return --i;
	}
	else
		return -1;
}

int sqlist::MatchString(string x,string y)
{
	int i=0,j=0;
	while(i<x.length()&&j<y.length())
	{
		if(x[i]==y[j])
		{
			i++;
			j++;
		}
		
		else
		{
			i=i-j+1;
			j=0;
		}
	}
	if(j>=y.length())
		return i;
	return -1;	
}
