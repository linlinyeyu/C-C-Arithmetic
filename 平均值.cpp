#include "stdio.h"
#include "stdlib.h"
#include "math.h"

#define N 50

void get_data(double x[],int n);
double average(double x[],int n);
double variance(double x[],int n,double mean);

int main()
{
    double x[N]; 
    int num;
    double mean,var,stdev;
    printf("\n����ƽ��ֵ������ͱ�׼��!\n\n");
    printf("������ʵ�����ݵĸ�����ȡֵ��2��%d֮�䣩\n",N);
    for(;;){
            scanf("%d",&num);
            if(num>1&&num<=N) break;
            printf("Error:%d�������ݺϷ���Χ������������\n",num);
            }
            
            get_data(x,num);
            mean=average(x,num);
            var=variance(x,num,mean);
            stdev=sqrt(var);
            
            printf("\nʵ�����ݵ�ƽ��ֵΪ:%.2f\n",mean);
            printf("ʵ�����ݵķ���Ϊ:%.2f\n",var);
            printf("ʵ�����ݵı�׼��Ϊ:%.2f\n",stdev);
            
            system("pause");
            return 0;
            }
            
void get_data(double x[],int n)
{
     int k;
     puts("������ʵ������:\n");
     for(k=0;k<n;k++){
         printf("x[%d]=",k);
         scanf("%lg",&x[k]);
         }
         }
         
double average(double x[],int n)
{
       double sum; 
       int k;
       for(sum=0,k=0;k<n;k++){
                              printf("\nx[%d]=%.2f",k,x[k]);
                              sum+=x[k];
                              }
                              return sum/n;
                              }

double variance(double x[],int n,double mean)
{
       double divisor,sum;
       int k;
       for(sum=k=0;k<n;k++)
       sum+=pow(x[k]-mean,2);
       if(n<20)
       divisor=n-1;
       else
       divisor=n;
       
       return sum/divisor;
} 
