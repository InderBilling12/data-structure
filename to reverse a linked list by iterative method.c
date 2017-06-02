#include<stdio.h>
#include<stdlib.h>
void print();
void insert(int x);
void reverse();
struct node{
     int data;
     struct node * link;
};
struct node* head=NULL;
main()
{
    int i,j;
    printf("enter total count of numbers");
    scanf("%d",&i);
    for(j=0;j<i;j++)
    { int x;
        printf("enter number");
        scanf("%d",&x);
        insert(x);
        print();
    }
    printf("the reversed :\n");
    reverse();
    print();
}
void insert(int x)
{
    struct node* temp=(struct node*)malloc(sizeof( struct node));
    temp->data=x;
    temp->link=head;
    head=temp;
}
void print()
{ printf("the list is:");
    struct node* temp = head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->link;
    }
    printf("\n");
}
void reverse()
{ struct node *current ,*prev,*next;
   current=head;
   prev=NULL;
   while(current!=NULL)
   {
       next=current->link;
       current->link=prev;
       prev=current;
       current=next;
   }
head=prev;

}

