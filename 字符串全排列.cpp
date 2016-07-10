#include "stdio.h"
#include "stdlib.h"
#include "iostream"
#include <string>
using namespace std;

void Permutation_Solution1(string pstr,int begin,int end)
{
	if(begin==end-1){
		for(int i=0;i<end;i++)
			cout<<pstr[i]<<" ";
		cout<<endl;
	} 
	else{
		for(int k=begin;k<end;k++){
			swap(pstr[k],pstr[begin]);
			Permutation_Solution1(pstr,begin+1,end);
			swap(pstr[k],pstr[begin]);
		}
	}
}

void swap(char &str,char &st)
{
	char temp=str;
	str=st;
	st=temp;
}

int main(){
	string str;
	cin>>str;
	int end=str.length();
	Permutation_Solution1(str,0,end);
	system("pause");
	return 0;
}
