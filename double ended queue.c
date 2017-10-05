#include<stdio.h>//we will implement by circular queue only because that is efficient
int front=-1;//to keep track of top of queue
int rear=-1;//to keep rack of last added element
#define max 100
int queue[max];
void insert_front(int data)
{
    if((front==0 && rear==max-1)||(front==rear+1))//if full
    {
        printf("overflow condition\n");
        exit(1);
    }
    if(front==-1)//if empty
        {
            front=0;
            rear=0;
        }
       else if(front==0)//means first place is already filled ,then insert at last
            front=max-1;
            else//if first place is filled and we have already inserted at last then we need to insert at 2nd last now
                front=front-1;
        queue[front]=data;
}
void insert_rear(int data)
{
    if((front==0 && rear==max-1)||(front==rear+1))//if full
    {
        printf("overflow condition\n");
        exit(1);
    }
    if(front==-1)//if empty
        {
            front=0;
            rear=0;

        }

   else
   {
       if(rear==max-1)//if last place is full
        rear=0;
        else//normal case
            rear=rear+1;
   }
        queue[rear]=data;
}
void display()
{
    printf("the queue is:\n");
    int i=front;
    if(front==-1)
    {
      printf("empty:\n");
      exit(1);
    }
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
   printf("\n");
}
int delete_front()//its condition will be related to insert_front
{
    if(front==-1)
    {
        printf("underflow condition\n");
        exit(1);
    }
    int data=queue[front];
    if(front==rear)//if only 1 element
       {
        front=-1;
        rear=-1;
       }
    else
    {
        if(front==max-1)//if it was at last.....relate it with insertion_front
            front=0;
            else//the other case
            front=front+1;
    }
      return data;
}
int delete_rear()//relate it with insert_rear
{
    if(front==-1)
    {
        printf("underflow condition\n");
        exit(1);
    }
    int data=queue[front];
    if(front==rear)//if only 1 element
       {
         front=-1;
         rear=-1;
       }
        else//now two cases possible
        {
            if(rear==0)//if it was at 0
                rear=max-1;
            else//the other case
                rear=rear-1;
        }
        return data;
}
int main()
{
    while(1)
    {
        int ch;
        printf("1.front insertion\n2.rear insertion\n3.front deletion\n4.rear deletion\n5.display\n6.exit\n");
        printf("enter choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            {
                int data;
            printf("enter data\n");
            scanf("%d",&data);
            insert_front(data);
            break;
            }
        case 2:
           {
            int data;
            printf("enter data\n");
            scanf("%d",&data);
            insert_rear(data);
            break;
           }
        case 3:
            printf("the element deleted is:%d\n",delete_front());
            break;
        case 4:
            printf("the element deleted is:%d\n",delete_rear());
            break;
        case 5:
            display();
            break;
        case 6:
            exit(1);
            break;
        default:
            printf("invalid option:\n");
        }
    }
}
