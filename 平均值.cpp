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
    printf("\n计算平均值、方差和标准差!\n\n");
    printf("请输入实验数据的个数（取值在2到%d之间）\n",N);
    for(;;){
            scanf("%d",&num);
            if(num>1&&num<=N) break;
            printf("Error:%d超过数据合法范围，请重新输入\n",num);
            }
            
            get_data(x,num);
            mean=average(x,num);
            var=variance(x,num,mean);
            stdev=sqrt(var);
            
            printf("\n实验数据的平均值为:%.2f\n",mean);
            printf("实验数据的方差为:%.2f\n",var);
            printf("实验数据的标准差为:%.2f\n",stdev);
            
            system("pause");
            return 0;
            }
            
void get_data(double x[],int n)
{
     int k;
     puts("请输入实验数据:\n");
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
