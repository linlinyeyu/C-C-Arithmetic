#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <iostream> ¡¡¡¡
#include <cstring> 

int max(int n, int m)
{
    int t;
    t = n > m ? n : m;
    return(t);
} 

int main()
{
    int dp[100005];
    int m, t, w[105], va[105];
    while((scanf("%d",&m)) != EOF)
    {
          int i,j, p, q;
          memset(dp, 0, sizeof(dp)); 
          for(j = 0; j < m; j++)
          {
                scanf("%d%d",&w[j],&va[j]);
          }
          scanf("%d", &t); 
          for(i = 0; i < m; i++)
          {
                for(j = t; j > -1; j--)
                {
                      if(j >= w[i])
                      { 
                            dp[j] = max(dp[j], dp[j-w[i]] + va[i]);
                      }
                }
            }
            printf("%d\n",dp[t]); 
    } 
    return 0;
} 
         
