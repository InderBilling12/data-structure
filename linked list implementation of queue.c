#include<stdio.h>//this we can implement by circular linked list also
#include<stdlib.h>
struct node
{
   int info;
   struct node*link;
}*front=NULL,*rear=NULL;
void enqueue(int data)
{
    struct node*curr=(struct node*)malloc(sizeof(struct node));
    if(curr==NULL)
       {
           printf("overflow condition\n");
            exit(1);
       }
       if(front==NULL)//empty queue
        front=curr;
        else//for non empty
            rear->link=curr;
            rear=curr;//update rear
            curr->info=data;
            curr->link=NULL;//setting last node 's link as null
}
int dequeue()
{
    if(front==NULL)
    {
        printf("underflow condition:\n");
        exit(1);
    }
    int data=front->info;
    struct node*temp=front;//to deallocate memory
    front=front->link;
    free(temp);
    return data;
}
int peek()
{
   if(front==NULL)
    {
        printf("underflow condition:\n");
        exit(1);
    }
    return front->info;
}
void display()
{
    struct node*temp=front;
    if(front==NULL)
    {
        printf("empty queue:\n");
        exit(1);
    }
    while(temp)
    {
        printf("%d ",temp->info);
        temp=temp->link;
    }
    printf("\n");
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
