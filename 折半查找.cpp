#include "stdio.h"
#include "stdlib.h"
#include "iostream"
#include "type.h"
using namespace std;

int main()
{
	int x[]={1,2,3,4,5,6,7,8,9,10};
	int y=10;
	int low=1;
	string str1="abcaacaabaa";
	string str2="acaab";
	sqlist *obj=new sqlist();
	for(int i=0;i<y;i++)
	{
		obj->data[i]=x[i];
	}
	obj->length=y;
	cout<<obj->MidFind(5,low,obj->length)<<endl;
	cout<<obj->FindSwith(5)<<endl;
	cout<<obj->MatchString(str1,str2)<<endl;
	system("pause");
	return 0;
}
