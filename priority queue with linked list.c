#include<stdio.h>//this we can implement by circular linked list also
#include<stdlib.h>
struct node
{
   int info;
   int priority;
   struct node*link;
}*front=NULL,*rear=NULL;
void enqueue(int data,int priority)//here deletion is rapid but insertion big o(n)
{
    struct node*curr=(struct node*)malloc(sizeof(struct node));
    if(curr==NULL)
    {
        printf("overflow condition:\n");
        exit(1);
    }
    if(front==NULL)//if queue is empty
    {
        front=curr;
        rear=curr;
        curr->link=NULL;
        curr->info=data;
        curr->priority=priority;
        return;
    }
    curr->info=data;//do these here link we can adjust downside code
    curr->priority=priority;
    if(priority>front->priority)//agar front ki priority se greater hain::equal ke liye fifo rule
    {
        curr->link=front;//front update krna
        front=curr;
        return;
    }
    //agar priority kahi aur lie kr rhi hain toh
    struct node*temp=front;//to traverse the queue
    while(temp->link && priority>temp->link->priority)
    temp=temp->link;
     //now we have reached the node after which we have to insert the new node
     curr->link=temp->link;
      temp->link=curr;
      return ;
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
            {
                int data,priority;
            printf("enter the element to be inserted into queue with its priority:\n");
            scanf("%d%d",&data,&priority);
            enqueue(data,priority);
            break;
            }

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
