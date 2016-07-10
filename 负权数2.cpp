#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
char *str = "0123456789ABCDEFGHGKLMNOPQRSTUVWXYZ";



char* tostr(int a, int b){
	int absb = abs(b);
	int absa = abs(a);
	char tmp[37] = {0};
	char res[37] = { 0 };
	int i = 0;
	while (a){
		if (abs(a)%absb) {
			tmp[i] = str[abs(a) % absb];
			i++;
		}
		else
		{
			tmp[i] = str[abs(a) % absb];
			i++;
		}
		a = (a - abs(a) % absb) / b;
	}
	int ik = i;
	for (int j =0; j <ik; j++){
		i--;
		res[j] = tmp[i];
	}
	return res;
}

int main(){
	int n, k;
	while (scanf("%d%d", &n, &k) != EOF&&!(n == 0 && k == 0)){
		char *res = tostr(n, k);
		printf("%s", res);
	}
}
