#include<stdio.h>
#define max 50
int stack1[max];
int stack2[max];
int top1=0;
int top2=0;
void pushA(int item)
{
    if(top1==max)//overflow condition
        printf("stack overflow occured\n");
    else
    stack1[++top1]=item;//increment top and push item

}
int popA()
{
    int item;
    if(top1==0)//empty stack
        printf("underflow condition\n");
    else
    {
       item=stack1[top1];
        top1=top1-1;//decrease top by 1
    }
    return item;
}
void pushB(int item)
{
    if(top2==max)//overflow condition
        printf("stack overflow occured\n");
    else
    stack2[++top2]=item;//increment top and push item

}
void displayA()
{
    int i=0;
    if(top1==0)
        printf("empty stack:\n");
    else
        for(i=top1;i>0;i--)
            printf("%d ",stack1[i]);
}
void displayB()
{
    int i=0;
    if(top2==0)
        printf("empty stack:\n");
    else
        for(i=top2;i>0;i--)
            printf("%d ",stack2[i]);
}
int main()
{
    int a,i=0;
    printf("enter no. of elements of stack:\n");
    scanf("%d",&a);
    printf("enter elements:\n");
    for(i=0;i<a;i++)
    { int x;
        scanf("%d",&x);
        pushA(x);
    }
    printf("the stack before reversing is:\n");
     displayA();
    for(i=top1;i>0;i--)
    {
        pushB(popA(stack1[i]));
    }
     printf("\nthe stack after reversing is:\n");
    displayB();
}
