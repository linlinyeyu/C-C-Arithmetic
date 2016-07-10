#include "stdio.h"
#include "stdlib.h"
#define M 10000

int dist[M]={0},fa[M]={0},visit[M]={0};
int g[M][M]={0};
int n,start,end;
int findmin(){
    int i,flag;
    int min=987654321;
    for(i=1;i<=n;i++)
    if(visit[i]==0&&dist[i]<min&&dist[i]!=0){
      min=dist[i];
      flag=i;
      }
      return flag;
      }
      
 int Dijkstra(){
     int i,j,pos;
     for(i=1;i<=n;i++){
     dist[i]=g[start][i];
     if(dist[i]==123456789)
     fa[i]=1;
     else
     fa[i]=start;
     }
     
 visit[start]=1;
 for(i=1;i<=n;i++){
 pos=0;
 pos=findmin();
 if(pos==0)
 break;
 visit[pos]=1;
 for(j=1;j<=n;j++)
 if(visit[j]==0&&dist[j]>dist[pos]+g[pos][j])
 {
   dist[j]=dist[pos]+g[pos][j];
   fa[j]=pos;
}
}
}

int main()
{
    int i,j;
    int p;
    scanf("%d%d%d",&n,&start,&end);
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    scanf("%d",&g[i][j]);
    if(i!=j&&g[i][j]==0)
    g[i][j]=123456789;
}
int Dijkstra();
if(dist[end]==123456789)
printf("NO WAY.\n");
else{
     printf("%d\n",dist[end]);
     p=end;
     while(fa[p]!=p){
     printf("%d-->",p);
     p=fa[p];
     }
     printf("%d\n",start);
     }
     system("PAUSE");
     return 0;
     }
