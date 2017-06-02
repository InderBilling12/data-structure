#include<stdio.h>
#define max_size 101
int a[max_size];
int top=-1;
void push(int x)
{   if(top==max_size-1)
   {
    printf("stack overflow");
    return;
   }
    top++;
    a[top]=x;
}
void pop()
{   if(top==-1)
    {
    printf("empty stack nothing to pop out");
    return;
    }
    top--;
}
void ISempty()
{
    if(top==-1)
        printf("\nempty stack");
    else
        printf("\nstack is not empty");
}
void print()
{
    int i;
    printf("\nthe stack is: ");
    for(i=0;i<top+1;i++)
        printf(" %d",a[i]);
}
int top_()
{
    return a[top];
}

main()
{
    push(2);print();
    push(4);print();
    push(8);print();
    pop();print();
    printf("\nthe top of stack is:%d", top_())  ;print();
    ISempty();


}
