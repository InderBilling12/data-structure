#include<stdio.h>
#define max 10
void push(int item,int arr[],int * top)//pass top by reference
{
    if(!(*top == max-1))
        arr[++(*top)] = item;
    else
     {
         printf("overflow:\n");
         exit(1);
     }
}
int pop(int arr[],int *ptr)
{

    if(!(*ptr==-1))
    {
      return arr[(*ptr)--];
    }
    else
    {
        printf("underflow\n");
        exit(1);
    }
}
void display(int arr[],int top)
{
    int i=0;
    if(top==-1)
    {
        printf("underflow\n");
        exit(1);
    }
    for(i=0;i<top+1;i++)
        printf("%d ",arr[i]);
    printf("\n");
}
int main()
{
    int stack1[max],stack2[max];
    int top1=-1,top2=-1;
    while(1)
    {
        int ch;
        printf("1.enqueue\n2.dequeue\n3.exit\n4.display\n");
        printf("enter choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            {
                int item;
                printf("enter data:\n");
                scanf("%d",&item);
                push(item,stack1,&top1);
                break;
            }
        case 2:
            {
                while(top1>0)//take from first stack and push to other and print top of other stack ,,,,here we are making dequeue costly
                {
                    push(pop(stack1,&top1),stack2,&top2);
                }
                printf("the item dequeued is:%d\n",pop(stack1,&top1));//print last element left in stack by popping it
                while(top2>-1)
                {
                     push(pop(stack2,&top2),stack1,&top1);//now push again from stack2 to stack1 back
                }
            }
            break;
        case 3:
            exit(1);
            break;
        case 4:
            display(stack1,top1);
            break;
        default:
            printf("invalid option:\n");
            break;
        }
    }

}
