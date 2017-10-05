#include<stdio.h>
int front=-1;//to keep track of top of queue
int rear=-1;//to keep rack of last added element
#define max 100
int queue[max];
void enqueue(int data)
{
    if(rear==max-1 && front==0||front==rear+1 )//if queue is full,,,here we need to check front for that
    {
        printf("overflow condition \n");
        exit(1);
    }
    else  if(front==-1)//if list is empty
    {
         front=0;
         rear=0;
    }
    else if(rear==max-1)//if rear is at last but front is not 0
    {
        rear=0;
    }
    else rear++;//normal case
    queue[rear]=data;

}
int dequeue()
{
    int data;
    if(front==-1||front==rear+1)
    {
        printf("underflow condition\n");
        exit(1);
    }
    data=queue[front];
    if(front==max-1)//if front is at last,then make it 0
        front=0;
    else if(front==rear)//if only one element
        front=rear=-1;
    else
        front++;
    return data;
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
     if(front==-1)
    {
      printf("empty queue:\n");
      exit(1);
    }
    int i=front;
   if(front<=rear)//first case if front is less than rear,,this is the normal case
   {
       while(i<=rear)
       {
           printf("%d ",queue[i++]);
       }
   }
   else//now we need to first print till max -1 and then till rear
   {
       while(i<=max-1)
         printf("%d ",queue[i++]);
       i=0;//we need to reinitialise it
       while(i<=rear)
       {
           printf("%d ",queue[i++]);
       }

   }
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
