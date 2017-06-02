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
        printf(" %d",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void insertAtN(int x,int n)
{ int i;
struct node* temp=(struct node*)malloc(sizeof(struct node));
temp->data=x;
    struct node*current=head;
    for(i=0;i<n-2;i++)
        {
            current=current->next;
        }
        temp->next=current->next;
        temp->prev=current;
        current->next->prev=temp;
        current->next=temp;//before this change previous of temp 's next
}
void deleteAtN(int n)
{     int i;
      struct node*current=head;
      struct node*temp;
      if(n==1)//deletion at beginning
      {
          current->next->prev=NULL;
          head=current->next;
          free(current);
          return;
      }
      for(i=0;i<n-2;i++)
        {
            current=current->next;
        }
        temp=current->next;
        current->next=temp->next;
        temp->next->prev=temp->prev;
        free(temp);

}
main()
{      insert(5);
       insert(13);
       insert(4);
       printf("the list in forward order is:");
        print();
        insertAtN(8,2);
        insertAtN(1,3);
        print();
        deleteAtN(4);
        deleteAtN(1);
        print();






}

