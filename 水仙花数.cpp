#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

void cubenum(int a,int b)
{
     int m,n,q,k=0;
     for(m=1;m<10;m++){
        for(n=0;n<10;n++){
          for(q=0;q<10;q++){
            if(m*m*m+n*n*n+q*q*q==m*100+n*10+q){
            k=m*100+n*10+q;
            if(k>=a&&k<=b)
            cout<<k<<" ";
            else
            k=0;
            }
          }
        }
     }
     if(k==0)
     cout<<"no"<<endl;
}

int main()
{
    int a,b;
    while(a!=' '&&b!=' '){
    cin>>a>>b;
}
    cubenum(a,b);
    system("pause");
    return 0;
}
