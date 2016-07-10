#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	int n=1;
	while(n!=0)
	{
		cin>>n;
		if(n%2==0)
			cout<<n/2<<endl;
		if(n%2!=0)
			cout<<(n/2)+1<<endl;
		cout<<endl;	
	}
	return 0;
}
