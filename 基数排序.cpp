#include <stdlib.h> 
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include<malloc.h>
# define MAX_NUM_OF_KEY 8//�ؼ������������ֵ
# define RD 10//�ؼ��ֻ�������ʱ��ʮ���������Ļ���
# define MAX_SPACE 10000
# define ERROR -1
typedef int KeyType;//�ؼ�������
typedef int InfoType;//����������

typedef struct SLCell//���
{
 KeyType keys[MAX_NUM_OF_KEY];//�ؼ���
    InfoType otheritmes;//����������
 struct SLCell * next;
}SLCell,* LNode;
typedef LNode ArrType[RD];//ָ���������ͣ����10������
typedef struct SLList //��ż�¼�����Ա�
{
 SLCell *H;// L Ϊ�������ͷָ��
    int keynum;//��¼�ĵ�ǰ�ؼ��ָ���
    int recnum;//��̬����ĵ�ǰ����
}SLList;
//keys(L.r[i].keys[],L.r[i].otheritmes) ;
void  keys(int keys[] ,int n)//Ϊ�ؼ��ָ�ֵ,�ؼ����ǴӸ�λ����λһ�η�������Key[]��
{
 int i;
 for(i=0;n>0;i++)
 {
        keys[i]=n;
  n=n/10;
 }
 
}
void OutExample(SLList L,int i)
{
 SLCell * p;
 cout<<endl;
 cout<<"��"<<i+1<<"���Ѽ�����ǣ�";
 for(p=L.H->next;p->next;p=p->next)
 {
  cout<<p->otheritmes<<"->";
 }
 cout<<p->otheritmes<<endl;
}
void creatExample(SLList &L)//β�巨��������
{
 int i,j,n;
 SLCell *p,*q;//qָ���β
 cout<<"������������¼�ĸ�����"<<endl;
 cin>>L.recnum;
 cout<<"������ؼ��ָ�����"<<endl;
 cin>>L.keynum;
 L.H=(SLCell *)malloc(sizeof(SLCell));//ͷ��㣬β�巨��������
 L.H->next=NULL;
 q=L.H;
 cout<<"������������¼��"<<endl;
 for(i=1;i<=L.recnum;i++)//����������
 {  
  cin>>n;
  p=(SLCell *)malloc(sizeof(SLCell));
  p->otheritmes=n;
  for(j=0;j<L.recnum;j++)//���ؼ��ֳ�ʼ��Ϊ0
   p->keys[j]=0;
  p->next=NULL;
  q->next=p;
  q=p;
 }
 p=L.H->next;
 while(p!=NULL)
 {
  keys(p->keys,p->otheritmes) ;//Ϊ�ؼ��ָ�ֵ,�ؼ����ǴӸ�λ����λһ�η�������Key[]��
  p=p->next;
 }
 cout<<endl<<"��LΪ:"<<endl;
 for(i=1,p=L.H->next;i<L.recnum;i++)//�������
 {
  cout<<p->otheritmes<<"->";
  p=p->next;
 }
 cout<<p->otheritmes;
}

void Distribute(SLList & L,int i,ArrType &f,ArrType &e)//��i�˷���,����i���ؼ����Ѽ�
{
 int j;
 SLCell *p;
    for(j=0;j<RD;j++)//��ͷָ���ʼ��
    f[j]=NULL;//���ӱ��ʼ��Ϊ�ձ�
 for(p=L.H->next;p;p=p->next)//pָʾ��ǰ�ڵ�λ��
 { 
  j=p->keys[i];
        if(f[j]==NULL)//�����ӱ�Ϊ��
   f[j]=p;
  else//�����ӱ���
   e[j]->next=p;//��pָ��Ľڵ����ڸ�i�ӱ���
  e[j]=p;//��βָ��ָ��ýڵ�
 }
}
void Collect(SLList &L,int i,ArrType f,ArrType e)//��i���ռ�
{
 int j;
 SLCell *t;
 for(j=0;!f[j];j++);//�ҵ���һ���ǿ��ӱ�
 L.H->next=f[j];//r[0].nextָ���һ���ǿ��ӱ�ĵ�һ���ڵ�
 t=e[j];//��t��¼��ǰ�ӱ�����һ���ڵ�
 while(j<RD-1)
 {
  for(j=j+1;j<RD-1&&!f[j] ;j++);//����һ���ǿ��ӱ�
  if(f[j])
  {
   t->next=f[j];
   t=e[j];//��t��¼��ǰ�ӱ�����һ���ڵ�
  }
 }
 t->next=NULL;//tָ�����һ���ǿ��ӱ�����һ���ڵ�
 OutExample(L,i);
}
void RadixSort(SLList &L)//��������
{
 int i;
    ArrType f,e;//��ͷָ�룬��β                                                                                                                                                                                                                                                       
 for(i=0;i<L.keynum;i++)//����keynum�˷��䣬�ռ�
 {
  Distribute(L,i,f,e);//��i�˷���
  Collect(L,i,f,e);//��i�˷��ռ�
 }
}
void main()
{
 SLList L;
    cout<<"��������(��ʽ�洢).cpp"<<endl<<"============="<<endl<<endl;
 creatExample(L);
 RadixSort(L);
}
