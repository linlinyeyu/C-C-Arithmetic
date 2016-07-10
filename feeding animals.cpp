#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#define INF 10001

using namespace std;

int main()
{
    int cas;
    while((scanf("%d" , &cas)) != EOF)
    {
          int a[8][cas];
          int i , j; 
          for(i = 0;i < 8;i++)
              {
                  for(j = 0; j < cas; j++)
                  { 
                    cin>>a[i][j]; 
                  }
              } 
          int min[10001];
          memset(min,10001,sizeof(min)); 
          int total = 0;
          for(j = 0; j < cas; j++)
              {
                    for(i = 0;i < 8;i++)
                    {    
                          min[j] = min[j] < a[i][j] ? min[j] : a[i][j];
                    }  
              total += min[j];
              }
          cout<<total<<endl;
    }
    return 0; 
}  
