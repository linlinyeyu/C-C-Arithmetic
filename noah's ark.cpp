#include <stdio.h>
#include <math.h>
#include <string.h>
#define yz 1

double hs(double a,char *c)
{      
       double k=1.0;
       if(strcmp(c,"meters")==0)k=100.0;
       if(strcmp(c,"cubits")==0)k=45.72;
       if(strcmp(c,"feet")==0)  k=30.48;
       if(strcmp(c,"inches")==0)k=2.54;
       a=a*k;
       return (a);
           
}

int main()
{         
          double length,width,height;
          double b[2]={0.0,0.0};
          char dlength[20],dwidth[20],dheight[20];
    while(scanf("%f,&length")!=EOF)
         {
         scanf("%s",dlength);
         scanf("%f",&width);
         scanf("%s",dwidth);
         scanf("%f",&height);
         scanf("%s",dheight);
		 if(fabs((b[0]-b[1]))<yz)printf("Spin");
         else 
             {
              if(fabs((b[0]-6*b[1]))<yz)printf("Excellent");
              else printf("Neither");}
               printf("\n\n");
         }

      return 0;
}
