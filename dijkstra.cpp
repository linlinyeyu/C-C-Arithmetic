#include <iostream>
using namespace std;
#define MAXVEX 20
#define MAXARC 100
#define MAX 100

//辅助数组
int s[MAX];
int path[MAX];
int d[MAX];

//邻接矩阵定义
struct ALGraph
{
  char vexs[MAXVEX];//顶点向量
  int arcs[MAXVEX][MAXVEX];//邻接矩阵
  int vexnum;//顶点数
  int arcnum;//边数
};

ALGraph G;//申明一个无向图的邻接矩阵类型

class Dijkstra
{
  public:
    int Locatevex(ALGraph G,char v);//图的基本操作，寻找顶点位置的下标
    void CreateALGraph(ALGraph &G);//创建一个有向图的邻接矩阵表示
    int Choose(ALGraph G,int d[],int s[]);//选出最小的d[i]
    void dijkstra(ALGraph G,int v,int s[],int d[]);//Dijkstra算法
};


//图的基本操作，寻找顶点位置的下标
int Dijkstra::Locatevex(ALGraph G,char v)
{
    int i=0;
    while(i<G.vexnum&&v!=G.vexs[i])
    i++;
    if(i<G.vexnum)
    return i;
    else
    return -1;
}

//创建一个有向图的邻接矩阵表示
void Dijkstra::CreateALGraph(ALGraph &G)
{
     char v1,v2;
     int w;
     cout<<"请输入图的顶点数和边数:";
     cin>>G.vexnum>>G.arcnum;
     cout<<"请输入顶点值:"<<endl;
     for(int i=0;i<G.vexnum;i++)//构造顶点向量
     cin>>G.vexs[i];
     for(int p=0;p<G.vexnum;p++)//初始化邻接矩阵（开始时所有都为MAX，表示所有顶点都不相连）
     for(int q=0;q<G.vexnum;q++)
     G.arcs[p][q]=MAX;
     for(int k=0;k<G.arcnum;k++)//构造邻接矩阵
     {
       cout<<"输入边的顶点和权值:"<<endl;
       cin>>v1>>v2>>w;
       int a=Locatevex(G,v1);
       int b=Locatevex(G,v2);
       G.arcs[a][b]=w;
       }
       cout<<"有向图的邻接矩阵创建完毕！"<<endl;
       }
       
       //选出最小的d[i]
 int Dijkstra::Choose(ALGraph G,int d[],int s[])
 {
     int i,minpos,min;
     min=MAX;
     minpos=-1;
     for(i=1;i<G.vexnum;i++)
     if(d[i]<min&&s[i]==0)
     {
       min=d[i];
       minpos=i;
       }
     return minpos;
     }
     
 //Dijkstra算法
 void Dijkstra::dijkstra(ALGraph G,int v,int s[],int d[])
 {
      int n=G.vexnum;
      for(int i=0;i<n;i++)//初始化各数组（这里以v为源点）
     {
        s[i]=0;
        d[i]=G.arcs[v][i];
        if(i!=v&&d[i]<MAX)
        path[i]=v;
        else
        path[i]=-1;
        }
       s[v]=1;
       d[v]=0;
       int k;
       for(int i=0;i<n-1;i++)//除源点外只有n-1个点，只要循环n-1次
       {
        k=Choose(G,d,s);
        for(int l=0;l<G.vexnum;l++)
        if(s[l]==0&&d[k]+G.arcs[k][l]<d[l])
        {
         d[l]=d[k]+G.arcs[k][l];
         path[l]=k;
         }
}
cout<<"源点到其余各点的最短路径为:\t"<<endl;
for(int i=0;i<G.vexnum;i++)
if(i!=v)
cout<<d[i]<<"";
cout<<endl;
}

//主函数
int main()
{
    Dijkstra di;
    di.CreateALGraph(G);
    cout<<endl;
    
    int i;
    cout<<"输入源点:";
    cin>>i;
    di.dijkstra(G,i,s,d);
    cout<<endl;
    system("pause");
} 
