
#include<stdio.h>
#define max 50
int stack[max]={0};
void push(int item)
{
    if(stack[0]==max)//overflow condition
        printf("stack overflow occured\n");
    else
    stack[++stack[0]]=item;//increment stack[0] and push item

}
int pop()
{
    int item;
    if(stack[0]==0)//empty stack
        printf("underflow condition\n");
    else
    {
       item=stack[stack[0]];
        stack[0]=stack[0]-1;//decrease stack[0] by 1
    }
    return item;
}
int top_()
{
     if(stack[0]==0)//empty stack
       return 1000;
        else
            return stack[stack[0]];
}
int isEMPTY()
{
    return stack[0];
}
void display()
{
    int i=0;
    if(stack[0]==0)
        printf("empty stack:\n");
    else
        for(i=stack[0];i>0;i--)
            printf("%d ",stack[i]);
}
int main()
{
    int c=1;
    while(c==1)
    {  int ch;
    printf("press 1 to push the element into stack:\n");
    printf("press2 to pop element from stack:\n");
    printf("press 3 to get stack[0] of stack:\n");
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
        {   if(stack[0]!=0)
            printf("the stack[0] of stack is:%d\n",top_());
            else
                printf("empty stack:\n");
        }
        break;
    case 4:
        {
            int c=isEMPTY();
            if(c==0)
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
