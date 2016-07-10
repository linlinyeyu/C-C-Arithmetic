#include "stdio.h"
#include "stdlib.h"
#define maxsize 50
#define maxop 7
typedef struct 
{
     char data[maxsize];
     int top;
}sqstack;

void initstack(sqstack *&s)
{
     s=(sqstack *)malloc(sizeof(sqstack));
     s->top=-1;
}

bool push(sqstack *&s,char e)
{
     if(s->top==maxsize-1)
     return false;
     s->top++;
     s->data[s->top]=e;
     return true;
}

bool pop(sqstack *&s,char &e)
{
     if(s->top==-1)
     return false;
     e=s->data[s->top];
     s->top--;
     return true;
}

bool gettop(sqstack *&s,char &e)
{
     if(s->top==-1)
     return false;
     e=s->data[s->top];
     return true;
}

void destroy(sqstack *&s)
{
     free(s);
}

bool stackempty(sqstack *s)
{
     return (s->top==-1);
}
          
bool symmetry(char str[])
{ 
     int i;char e;
     sqstack *st;
     initstack(st);
     for(i=0;str[i]!='\0';i++)
     push(st,str[i]);
     for(i=0;str[i]!='\0';i++)
     {
        pop(st,e);
        if(str[i]!=e)
        {
          destroy(st);
          return false;
          }
          }
     destroy(st);
     return true;
}     

bool match(char exp[],int n)
{
     int i=0;char e;
     bool match=true;
     sqstack *st;
     initstack(st);
     while(i<n&&match)
     {
        if(exp[i]=='(')
        push(st,exp[i]);
        else if(exp[i]==')')
        {
            if(gettop(st,e)==true)
            {
               if(e!='(')
               match=false;
               else
               pop(st,e);
               }
            else match=false;
            }
            i++;
            }
            if(!stackempty(st))
            match=false;
            destroy(st);
            return match;
}

struct
{
      char ch;
      int pri;
}lpri[]={{'=',0},{'(',1},{'*',5},{'/',5},{'+',3},{'-',3},{')',6}},
 rpri[]={{'=',0},{'(',6},{'*',4},{'/',4},{'+',2},{'-',2},{')',1}};
 
int leftpri(char op)
{
    int i;
    for(i=0;i<maxop;i++)
    if(lpri[i].ch==op)return lpri[i].pri;
}

int rightpri(char op)
{
    int i;
    for(i=0;i<maxop;i++)
    if(rpri[i].ch==op)
    return rpri[i].pri;
}

bool inop(char ch)
{
     if(ch=='('||ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch==')')
     return true;
     else 
     return false;
}

int precede(char op1,char op2)
{
    if(leftpri(op1)==rightpri(op2))
    return 0;
    else if(leftpri(op1)<rightpri(op2))
    return -1;
    else 
    return 1;
}

void trans(char *exp,char postexp[])
{
     struct
     {
        char data[maxsize];
        int top;
}op;
int i=0;
op.top=-1;
op.top++;
op.data[op.top]='=';
while(*exp!='\0')
{
   if(!inop(*exp))
   {
      while(*exp>='0'&&*exp<='9')
      {
         postexp[i++]=*exp;
         exp++;
         }
         postexp[i++]='#';
         }
         else
         switch(precede(op.data[op.top],*exp))
         {
           case -1:
                op.top++;op.data[op.top]=*exp;
                exp++;
                break;
           case 0:
                op.top--;
                exp++;
                break;
           case 1:
                postexp[i++]=op.data[op.top];
                op.top--;
                break;
                }
                }
                while(op.data[op.top]!='=')
                {
                  postexp[i++]=op.data[op.top];
                  op.top--;
                  }
                  postexp[i]='\0';
}

float compvalue(char *postexp)
{
      struct
      {
      float data[maxsize];
      int top;
      }st;
      float d,a,b,c;
      st.top=-1;
      while(*postexp!='\0')
      {
         switch(*postexp)
         {
            case '+':
                 a=st.data[st.top];
                 st.top--;
                 b=st.data[st.top];
                 st.top--;
                 c=a+b;
                 st.top++;
                 st.data[st.top]=c;
                 break;
            case '-':
                 a=st.data[st.top];
                 st.top--;
                 b=st.data[st.top];
                 st.top--;
                 c=b-a;
                 st.top++;
                 st.data[st.top]=c;
                 break;
            case '*':
                 a=st.data[st.top];
                 st.top--;
                 b=st.data[st.top];
                 st.top--;
                 c=a*b;
                 st.top++;
                 st.data[st.top]=c;
                 break;
            case '/':
                 a=st.data[st.top];
                 st.top--;
                 b=st.data[st.top];
                 st.top--;
                 if(a!=0)
                 {
                 c=b/a;
                 st.top++;
                 st.data[st.top]=c;
                 }
                 else
                 {
                     printf("\n\t除零错误！\n");
                     exit(0);
                     } 
                 break;
            default:
                 d=0;
                 while(*postexp>='0'&&*postexp<'9')
                 {
                   d=10*d+*postexp-'0';
                   postexp++;
                   }
                   st.top++;
                   st.data[st.top]=d;
                   break;
                   }
                   postexp++;
                   }
                   return(st.data[st.top]);
}                   
     
int main()
{
    char exp[]="(56-20)/(4-2)";
    char postexp[maxsize];
    trans(exp,postexp);
    printf("中缀表达式:%s\n",exp);
    printf("后缀表达式:%s\n",postexp);
    printf("表达式的值:%g\n",compvalue(postexp)); 
    system("pause");
    return 0;
}
                             
