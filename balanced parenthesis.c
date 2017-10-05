
#include<stdio.h>
#define max 50
char stack[max];
int top=0;
void push(int item)
{
    if(top==max)//overflow condition
        printf("stack overflow occured\n");
    else
    stack[++top]=item;//increment top and push item

}
int pop()
{
    int item;
    if(top==0)//empty stack
        printf("underflow condition\n");
    else
    {
       item=stack[top];
        top=top-1;//decrease top by 1
    }
    return item;
}
int top_()
{
     if(top==0)//empty stack
       return 1000;
        else
            return stack[top];
}
int isEMPTY()
{
    return top;
}
int  check(char a,char b)
{
    if(a==')' && b=='(')
    return 1;
    else if(a==']' && b=='[')
    return 1;
    else if(a=='}' && b=='{')
    return 1;
    else
    return 0;

}
int main()
{   int i=0,a=1,c=1;
    char s[100];
    printf("enter the arithmetic expression:\n");
    gets(s);
    int x=strlen(s);
    for(i=0;i<x;i++)
    {
        if(s[i]=='('||s[i]=='{'||s[i]=='[')
            push(s[i]);
        else if(s[i]==')'||s[i]=='}'||s[i]==']')
        {    if(top>0)//only then we can pop
             a=check(s[i],pop());
             else
                {    c=1;
                    printf("excess closing parenthesis\n");
                }
            if(a==1)
                continue;
            else
            {   a=0;
                printf("parenthesis mismatch\n");
                break;
            }
        }
    }
    if(a==1 && top==0 && c!=1)
        printf("balanced parenthesis\n");
    else if(a==1 &&top!=0)//sabhi match huye par sabhi pop nhi huye
    printf("excess opening parenthesis\n");
}

