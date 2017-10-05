#include<stdio.h>
int front=-1;//to keep track of top of queue
int rear=-1;//to keep rack of last added element
#define max 100
int queue[max];
void enqueue(int data)
{
    if(rear==max-1)//full
    {
        printf("overflow condition\n");
        exit(1);
    }
    if(front==-1)//empty
        front=0;
    queue[++rear]=data;
}
int dequeue()
{
    if(front==-1||front==rear+1)//empty queue
    {
        printf("underflow condition\n");
        exit(1);
    }
    return queue[front++];
}
int peek()
{
    if(front==-1||front==rear+1)//empty queue
    {
        printf("underflow condition\n");
        exit(1);
    }
    return queue[front];
}
void display()
{
    printf("the queue is:\n");
    int i=0;
    for(i=front;i<rear+1;i++)
        printf("%d ",queue[i]);

}
int main()
{
    while(1)
    {
        int ch;
        printf("1.enqueue\n2.dequeue\n3.peek\n4.display\n5.exit\n");
        printf("enter choice:\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            {int x;
            printf("enter the element to be inserted into queue:\n");
            scanf("%d",&x);
            enqueue(x);
            break;}

        case 2:
            printf("the dequeued element is:%d\n",dequeue());
            break;

        case 3:
            printf("the peek of queue is:%d\n",peek());
            break;
        case 4:
            display();
            printf("\n");
            break;
        case 5:
            exit(1);
            break;
        default:
            printf("wrong choice\n");
        }
    }
}
