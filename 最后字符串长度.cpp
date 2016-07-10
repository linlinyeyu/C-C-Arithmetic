#include "stdio.h"
#include "stdlib.h"
#include "iostream"
#include <string>
#define max 1000
using namespace std;

int main()
{
    char str[max];
    cout<<"ÇëÊäÈë×Ö·û´®:"<<endl;
    gets(str);
int n=strlen(str);
int N=0;
for(int i=n-1;i>=0;i--)
{
    if(str[i]!=' ')
    N++;
    else
    break;
}
cout<<N<<endl; 
system("pause");
return 0;
}
