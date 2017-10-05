#include<stdio.h>
struct node{
int info;
struct node*link;
}*top=NULL;
void push(int item)
{
    struct node*temp=(struct node*)malloc(sizeof(struct node));
    if(temp==NULL)//overflow condition
        printf("stack overflow");
    else//add at beginning
    {
      temp->info=item;
      if(top==NULL)
      {
          temp->link=NULL;
          temp->info=item;
          top=temp;
          return;
      }
      temp->link=top;
      top=temp;
      temp->info=item;
}
}
int pop()
{   int item;
    if(top==NULL)
       return 999;
    else//deletion from beginning
    {
        item=top->info;
        top=top->link;
        return item;
    }
}
int top_()
{
    return top->info;
}
struct node* isEMPTY()
{
    return top;
}
void display()
{
    struct node*curr=top;
    if(top==NULL)
        printf("empty stack:\n");
    while(curr!=NULL)
    {
        printf("%d ",curr->info);
        curr=curr->link;
    }
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
        {   if(top!=0)
            printf("the top of stack is:%d\n",top_());
            else
                printf("empty stack:\n");
        }
        break;
    case 4:
        {
            struct node*c=isEMPTY();
            if(c==NULL)
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
