#include<stdio.h>
#define max 10
int stack[max];
int top1=0,top2=max+1;//we we will needing two tops
void pushA(int item)
{     if(top1 != top2-1)
      stack[++top1]=item;
      else
        printf("stack overflow:\n");
}
void pushB(int item)
{     if(top1 != top2-1)
      stack[--top2]=item;
      else
        printf("stack overflow:\n");
}
int popA()
{  int item;
    if(top1==0)
        {
            printf("nothing to pop\n");
            exit(1);
        }
    else
    {
        item=stack[top1];
        top1--;
    }
    return item;
}
int popB()
{  int item;
    if(top2==max+1)
        {
            printf("nothing to pop\n");
            exit(1);
        }
    else
    {item=stack[top2];
    top2++;
    }
    return item;
}
void displayA()
{
    int i=0;
    if(top1 == 0)
    {
        printf("Nothing to display");
        return;
    }
    for(i = top1;i>0;i--)
        printf("%d ",stack[i]);
    printf("\n");
}
void displayB()
{
    int i=0;
    if(top2!=max+1)
    {
        for(i=top2;i<max+1;i++)
        printf("%d ",stack[i]);
        }
        else
            printf("empty stack B");
}
int main()
{
    int ch,c=1;
while(c==1)
{
    printf("1.push A:\n");
    printf("2.pop A :\n");
    printf("3.push B:\n");
    printf("4.pop B\n");
    printf("5.display A:\n");
    printf("6.display B:\n");
    printf("enter your choice:\n");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
        {
            int x;
            printf("enter the element to be pushed onto stack A:\n");
            scanf("%d",&x);
            pushA(x);
        }
        break;

    case 2:
        {
                printf("the item popped is:%d\n",popA());
        }
        break;
    case 3:
        {
            int x;
            printf("enter the element to be pushed onto stack B:\n");
            scanf("%d",&x);
            pushB(x);
        }
        break;
        case 4:
        {
                printf("the item popped is:%d\n",popB());
        }
        break;

    case 5:
        {
            displayA();
        }
        break;
         case 6:
        {
            displayB();
        }
        break;
    default:
        printf("\nenter a valid option:\n");
    }
    printf("\npress 1 to do 1 more operation ,0 to exit");
    scanf("%d",&c);
    }
}
