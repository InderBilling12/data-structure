#include<stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node* prev;
  struct node* next;
};
struct node*head=NULL;
void insert(int x)
{
    struct node*current=(struct node*)malloc(sizeof(struct node));
    current->data=x;
    current->next=head;
   if(head!=NULL) head->prev=current;
     head=current;
    current->prev=NULL;
}
void print()
{
    struct node*temp=head;
    while(temp!=NULL)
    {
        printf(" %d %d %d \n",temp->prev,temp->data,temp->next);//tto verify whether it is doubly linked or no
        temp=temp->next;
    }
}
void reverse(struct node*head)
{ struct node*temp=head;
while(temp->next!=NULL)
temp=temp->next;
//we reach at end of list;
while(temp!=NULL)
{
    printf(" %d",temp->data);
    temp=temp->prev;
}

}

main()
{      insert(5);//list is 5
       insert(13);//list is 13 5
       insert(4);//list is 4 13 5
       //we made insertions at beggining
       printf("the list in forward order is:");
        print();
        printf("the reverse list is:");
        reverse(head);//this will verify properly




}
