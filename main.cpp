#include <iostream>
#include "SortChapter.h"
using namespace std;

typedef enum{
	RED,WHITE,BLUE
}color;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void swap(int x,int y)
{
	int temp=x;
	x=y;
	y=temp;
}

void Flag_Arrange(color *a,int n)
{
	int i=0,j=0,k=n-1;
	while(j<=k)
		switch(a[j])
		{
			case RED:
				swap(a[i],a[j]);
				i++;
				j++;
				break;
			case WHITE:
				j++;
				break;
			case BLUE:
				swap(a[j],a[k]);
				k--;
				break;
		}
}

void DispColor(color *a,int n)
{
	for(int i=0;i<n;i++)
		switch(a[i])
		{
			case 0:
				cout<<"RED"<<" ";
				break;
			case 1:
				cout<<"WHITE"<<" ";
				break;
			case 2:
				cout<<"BLUE"<<" ";
				break;
		}
	cout<<endl;
}

int main(int argc, char** argv) {
	int data[]={34,12,32,56,33,67,89,45,78};
	int y=9;
	color a[]={WHITE,RED,BLUE,RED,RED,WHITE,WHITE,BLUE,RED,BLUE,WHITE,RED,BLUE};
	int n=13;
	Sort *obj=new Sort();
	obj->InsertSort(data,y);
	obj->DispArray(data,y);
	obj->DoubleDirectionBubbleSort(data,y);
	obj->DispArray(data,y);
	obj->OddPreEven(data,y);
	obj->DispArray(data,y);
	obj->QuickSort(data,0,8);
	obj->DispArray(data,y);
	cout<<obj->SelectNumK(data,0,8,5)<<endl;
	Flag_Arrange(a,13);
	DispColor(a,13);
	system("pause");
	return 0;
}
