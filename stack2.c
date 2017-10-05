#include<stdio.h>
#define max 50
int stack[max];
int top=max+1;//here top=max is the first entered ,top=1 is the last
void push(int item)
{
    if(top==1)//overflow condition
        printf("stack overflow occured\n");
    else
    stack[--top]=item;//increment top and push item

}
int pop()
{
    int item;
    if(top==max+1)//empty stack
        printf("underflow condition\n");
    else
    {
       item=stack[top];
        top=top+1;//increase top by 1
    }
    return item;
}
int top_()
{
     if(top==max+1)//empty stack
       return 1000;
        else
            return stack[top];
}
int isEMPTY()
{
    return top;
}
void display()
{
    int i=0;
    if(top==max+1)
        printf("empty stack:\n");
    else
        for(i=top;i<max+1;i++)
            printf("%d ",stack[i]);
}
int main()
{
    int c=1;
    while(c==1)
    {  int ch;
    printf("press 1 to push the element into stack:\n");
    printf("press2 to pop element from stack:\n");
    printf("press 3 to get top of stack:\n");
    printf("press 4 to check status of stack\n");
    printf("press 5 to display members of stack:\n");
    printf("enter your choice:\n");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
        {
            int x;
            printf("enter the element to be pushed onto stack:\n");
            scanf("%d",&x);
            push(x);
        }
        break;

    case 2:
        {
            int c=pop();
            if(c==1000)
                printf("underflow condition:\n");
            else
                printf("the item popped is:%d\n",c);
        }
        break;
    case 3:
        {   if(top!=max+1)
            printf("the top of stack is:%d\n",top_());
            else
                printf("empty stack:\n");
        }
        break;
    case 4:
        {
            int c=isEMPTY();
            if(c==max+1)
                printf("empty stack:\n");
            else
                printf("stack is not empty:\n");
        }
        break;
    case 5:
        {
            display();
        }
        break;
    default:
        printf("\nenter a valid option:\n");
    }
    printf("\npress 1 to do 1 more operation ,0 to exit");
    scanf("%d",&c);
    }
}
