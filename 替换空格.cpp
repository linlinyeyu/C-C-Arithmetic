#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#define MAXLEN 100
using namespace std;
void ReplaceBlack(char *p,int length)
{
  if (p != NULL)
  {
    int i, end, pos ,size_black = 0,lennew;
    
    for (i=0; i != length; i++)
    {
        if (p[i] == ' ')
            size_black++;
    }
    lennew = length + 2 * size_black;
    if(lennew > MAXLEN)
        return;
    pos = lennew-1;
    end = length-1;
    while(pos != end)
    {
        if (p[end] != ' ')
            p[pos--] = p[end--];
        else
        {
            p[pos--] = '0';
            p[pos--] = '2';
            p[pos--] = '%';
            end--;
        }
    }//while
  }
}

int main()
{
    char *a = new char();
    strcpy(a,"hello world ");
    int length=strlen(a);
    ReplaceBlack(a,length);
    cout<<a<<endl;
    system("pause");
    return 0;
}
