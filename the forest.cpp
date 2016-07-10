#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

void Match(string s) {
	string ss[]= {"littleken","knuthocean","dongfangxu","zap","kittig","robertcui","forest","flirly"};
	string str[]= {"li","kn","do","za","ki","ro","fo","fl"};
	int strlen[]= {9,10,10,3,6,9,6,6};
	int a[8]={0,0,0,0,0,0,0,0};
	for(int i=0; i<s.length()-1;) {
		for(int j=0; j<8; j++) {
			if(s.at(i)==str[j].at(0)&&s.at(i+1)==str[j].at(1)) {
				a[j]++;
				i=i+strlen[j];
				break;
			}
		}
	}
	int max=0;
	int bg=0;
	for(int i=0; i<8; i++)
		if(max<a[i]) {
			max=a[i];
			bg=i;
		}
	cout<<ss[bg]<<endl;
}

int main() {
	int n;
	while(scanf("%d",&n)!=EOF){
	for(int i=0; i<n; i++) {
		string s;
			cin>>s;
		Match(s);
}
}
	return 0;
}

