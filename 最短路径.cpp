#include <iostream> 

using namespace std;  

#define MAX_NODE 1000  
#define INFINITY   9999999
#define NIL   -1

typedef struct ArcNode  
{  
    int adjvex;//��ָ��Ľڵ��ֵ����ı�ţ�  
    int distance;//����֮��ľ���
    int weight; //�ߵ�Ȩ��
    ArcNode* next;//ָ����һ����  
    ArcNode(int value)  
    {  
        adjvex = value;  
        next = NULL;  
    }  
};//�ڽӱ�ڵ�  

typedef struct  
{  
    int vexdata; //ͷ�ڵ�ı��  
    struct ArcNode* firstarc;//��һ���ڽӱ�ڵ�ĵ�ַ  
}VexNode, AdjList[MAX_NODE];//ͷ���  

typedef struct  
{  
    AdjList vexNodes;  
    int vexNum;  
    int arcNum;//��ǰ�ڵ���Ŀ�ͻ���  
}GraphWithAL;//�ڽӱ��ʾ��ͼ  

//���Ҫ����ı��Ƿ��Ѿ����ڣ��������ͼ  
bool CheckArcIsExist(GraphWithAL* G, int v1, int v2)  
{  
    ArcNode* temp = G->vexNodes[v1].firstarc;  
    while(temp!=NULL)  
    {  
        if(temp->adjvex == v2)  
            return true;  
        temp = temp->next;  
    }  
    return false;  
}  

//����ͼ��vexNum������ĸ�����arcNum����ߵĸ�����isUnDirected������� �Ƿ�������ͼ  
void CreateGraph(GraphWithAL* G, int vexNum, int arcNum)  
{  
    memset(G, 0 ,sizeof(GraphWithAL));  
    //��ʼ��ͷ���  
    int i = 0;  
    for(i=0; i<vexNum; ++i)  
    {  
        G->vexNum = vexNum;  
        G->vexNodes[i].firstarc = NULL;  
        G->vexNodes[i].vexdata = i;//��0��ʼ���㶥��  
    }  
    //��ʼ����  
    for(i=0; i<arcNum; ++i)  
    {  
        //����ߵĶ����β��  
        int v1, v2, weight;
        printf("������ߵĶ����β���Լ�Ȩֵ��\n");  
        cin>>v1>>v2>>weight;  
        if(CheckArcIsExist(G, v1, v2))  
            continue;  
        ArcNode* arcNode = new ArcNode(v2);  
        //����Ҫ������Ƿ��Ѿ����ڣ�����û�м���  
        arcNode->next = G->vexNodes[v1].firstarc;
        arcNode->weight= weight;
        G->vexNodes[v1].firstarc = arcNode;  
        G->arcNum++;   
    }  
}  

//��ʼ��d[]�������Դ�㵽������������·�����룬num����ڵ���Ŀ
void InitialSingleSource(int s, int d[], int pi[], int num)
{
    int i=0;
    for(; i<num; ++i)
    {
        d[i] =INFINITY ;
        pi[i] = NIL;
    }
    d[s] = 0;
}

//�ɳڼ���
void Relax(int u, int v, int weight, int d[], int pi[])
{
    if(d[v] > d[u]+weight)
    {
        d[v] = d[u] +weight;
        pi[v] = u;
    }
}

//������С�� ,ʹ����С�ѽṹ�洢d[]���±�ֵ��Ŀ�������ķ�ʽȡ��d[]�е���Сֵ�±�
void fix_min_heap(int a[], int pos, int len, int d[]) {  
    int left = 2 * pos + 1;  
    int right = 2 * pos + 2;  
    int min = pos;  
    if (left < len && d[a[left]] < d[a[pos]])  
        min = left;  
    if (right < len && d[a[right]] < d[a[min]])  
        min = right;  
    if (pos != min) {  
        int tep = a[pos];  
        a[pos] = a[min];  
        a[min] = tep;  
        fix_min_heap(a, min, len, d);  
    }  
}  
//������С��  
void build_min_heap(int a[], int len, int d[]) {  
    int parent = (len - 1) / 2;  
    int i = 0, j = 0;  
    for (i = parent; i >= 0; --i) {  
        int left = 2 * i + 1;  
        int right = 2 * i + 2;  
        int min = i;  
        if (left < len && d[a[left]] < d[a[i]])  
            min = left;  
        if (right < len && d[a[right]] < d[a[min]])  
            min = right;  
        if (i != min) {  
            int tep = a[i];  
            a[i] = a[min];  
            a[min] = tep;  
            fix_min_heap(a, min, len, d);  
        }  
    }  
}  

//ȥ����С�ѵ���Сֵ
int ExtractMin(int a[], int n, int d[])
{
     int temp = a[0];
     a[0] = a[n-1];
     fix_min_heap(a, 0, n-1, d);
     return temp;
}

void Dijkstra(GraphWithAL* G, int s)
{

    int* d = new int[G->vexNum];//��¼ÿ�������Դ�����С����
    int* pi = new int[G->vexNum];
    int* a = new int[G->vexNum];//��¼��С����d���±�ֵ
    int i=0;
    for(i=0; i<G->vexNum; ++i)//��ʼ��a
        a[i] = i;
    InitialSingleSource(s, d, pi, G->vexNum);
    int num = G->vexNum;//�����С���е�ֵΪ�����������
    
    while(num != 0)
    {
        int min = ExtractMin(a, num--, d);
        ArcNode* temp = G->vexNodes[min].firstarc;
        while(temp != NULL)
        {
            Relax(min, temp->adjvex, temp->weight, d, pi);
            temp = temp->next;
        }

    }
    printf("Դ�㵽������̾���Ϊ:\n"); 
    for(i=1; i<=G->vexNum; ++i) 
        cout<<d[i]<<" ";
    cout<<endl;
}

int main()  
{  
    GraphWithAL G;  
    int n, m;
    printf("�����붥�����ͱ���:\n");  
    while(cin>>n>>m)  
    {  
        if(n==0)  
            break;
        CreateGraph(&G, n, m);  
        Dijkstra(&G,  1);
    }
    system("pause");
    return 0;  
} 
