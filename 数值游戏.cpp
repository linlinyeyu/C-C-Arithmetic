#include "stdio.h"
#include "stdlib.h"
#include "iostream"
#include "math.h"
using namespace std;

void junge(int m,int n) {
	int i;
	if(m%2==0){
		i=m/2;
	}else{
		i=m/2+1;
	}
	cout<<i<<endl;
} 

int main(){
	int m,n;
	while(1) {
		scanf("%d%d",&m,&n);
		junge(m,n);
	}
	return 0;
}
