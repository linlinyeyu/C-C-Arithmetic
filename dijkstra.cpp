#include <iostream>
using namespace std;
#define MAXVEX 20
#define MAXARC 100
#define MAX 100

//��������
int s[MAX];
int path[MAX];
int d[MAX];

//�ڽӾ�����
struct ALGraph
{
  char vexs[MAXVEX];//��������
  int arcs[MAXVEX][MAXVEX];//�ڽӾ���
  int vexnum;//������
  int arcnum;//����
};

ALGraph G;//����һ������ͼ���ڽӾ�������

class Dijkstra
{
  public:
    int Locatevex(ALGraph G,char v);//ͼ�Ļ���������Ѱ�Ҷ���λ�õ��±�
    void CreateALGraph(ALGraph &G);//����һ������ͼ���ڽӾ����ʾ
    int Choose(ALGraph G,int d[],int s[]);//ѡ����С��d[i]
    void dijkstra(ALGraph G,int v,int s[],int d[]);//Dijkstra�㷨
};


//ͼ�Ļ���������Ѱ�Ҷ���λ�õ��±�
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

//����һ������ͼ���ڽӾ����ʾ
void Dijkstra::CreateALGraph(ALGraph &G)
{
     char v1,v2;
     int w;
     cout<<"������ͼ�Ķ������ͱ���:";
     cin>>G.vexnum>>G.arcnum;
     cout<<"�����붥��ֵ:"<<endl;
     for(int i=0;i<G.vexnum;i++)//���춥������
     cin>>G.vexs[i];
     for(int p=0;p<G.vexnum;p++)//��ʼ���ڽӾ��󣨿�ʼʱ���ж�ΪMAX����ʾ���ж��㶼��������
     for(int q=0;q<G.vexnum;q++)
     G.arcs[p][q]=MAX;
     for(int k=0;k<G.arcnum;k++)//�����ڽӾ���
     {
       cout<<"����ߵĶ����Ȩֵ:"<<endl;
       cin>>v1>>v2>>w;
       int a=Locatevex(G,v1);
       int b=Locatevex(G,v2);
       G.arcs[a][b]=w;
       }
       cout<<"����ͼ���ڽӾ��󴴽���ϣ�"<<endl;
       }
       
       //ѡ����С��d[i]
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
     
 //Dijkstra�㷨
 void Dijkstra::dijkstra(ALGraph G,int v,int s[],int d[])
 {
      int n=G.vexnum;
      for(int i=0;i<n;i++)//��ʼ�������飨������vΪԴ�㣩
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
       for(int i=0;i<n-1;i++)//��Դ����ֻ��n-1���㣬ֻҪѭ��n-1��
       {
        k=Choose(G,d,s);
        for(int l=0;l<G.vexnum;l++)
        if(s[l]==0&&d[k]+G.arcs[k][l]<d[l])
        {
         d[l]=d[k]+G.arcs[k][l];
         path[l]=k;
         }
}
cout<<"Դ�㵽�����������·��Ϊ:\t"<<endl;
for(int i=0;i<G.vexnum;i++)
if(i!=v)
cout<<d[i]<<"";
cout<<endl;
}

//������
int main()
{
    Dijkstra di;
    di.CreateALGraph(G);
    cout<<endl;
    
    int i;
    cout<<"����Դ��:";
    cin>>i;
    di.dijkstra(G,i,s,d);
    cout<<endl;
    system("pause");
} 
