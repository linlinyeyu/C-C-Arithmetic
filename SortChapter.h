#include "iostream"
using namespace std;

class Sort
{
	public:
		void InsertSort(int data[],int n); //ֱ�Ӳ������� 
		void DispArray(int data[],int n); //���˳��� 
		void DoubleDirectionBubbleSort(int *data,int n); //˫��ð������ 
		void OddPreEven(int *data,int n);  //�������Ƶ�ż��ǰ�� 
		void QuickSort(int *data,int low,int high); //���ȡֵ�������� 
		int Merge(int *data,int low,int high);	 //�������򻮷� 
		int SelectNumK(int *data,int low,int high,int k); //Ѱ�ҵ�kС��Ԫ�� 
}; 
