#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
	int month[]={1,2,3,4,5,6,7,8};
	int day[]={31,29,31,30,31,30,31,8};
	int n,m,d,k=0;
	cin>>n;
	while(n!=0){
			cin>>m>>d;
	for(int i=0;i<8;i++){
		if(month[i]==m)
			break;
		k++;
	}
	int sum=day[k]-d;
	for(int i=k+1;i<8;i++){
		sum+=day[i];
	}
	cout<<sum;
	n--;
}
	return 0;
}
