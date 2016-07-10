#include "stdio.h"
#include "stdlib.h"

int power(int x,int n)
{
    int k,s=1;
    for(k=1;k<=n;k++)
    s*=x;
    return (s);
}

int main()
{
    int pow,exp;
    printf("please input pow and exp:");
    scanf("%d%d",&pow,&exp);
    printf("power(%d,%d)is:%d\n",pow,exp,power(pow,exp));
    
    system("pause");
    return 0;
}
