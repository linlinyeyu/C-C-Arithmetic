#include "iostream"
using namespace std;

class Sort
{
	public:
		void InsertSort(int data[],int n); //直接插入排序 
		void DispArray(int data[],int n); //输出顺序表 
		void DoubleDirectionBubbleSort(int *data,int n); //双向冒泡排序 
		void OddPreEven(int *data,int n);  //将奇数移到偶数前面 
		void QuickSort(int *data,int low,int high); //随机取值快速排序 
		int Merge(int *data,int low,int high);	 //快速排序划分 
		int SelectNumK(int *data,int low,int high,int k); //寻找第k小的元素 
}; 
