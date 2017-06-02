#include<stdio.h>
#include<stdlib.h>
struct node{
            int data;
            struct node* link;
};
struct node* head=NULL;
void insert(int x,int n){
struct node* temp =(struct node*)malloc(sizeof(struct node));
temp->data=x;
temp->link=NULL;
if(n==1)
{
    temp->link=head;
    head=temp;
    return;

}
struct node *temp1=head;
int i;
for(i=0;i<n-2;i++)
{
    temp1=temp1->link;
}
temp->link=temp1->link;
temp1->link=temp;

}
void reverse_print(struct node * current)
{
    if(current==NULL)
       return;
    reverse_print(current->link);
    printf(" %d",current->data);
}
void print(struct node* current)
{
     if(current==NULL)
       return;
     printf(" %d",current->data);
     print(current->link);
}
main()
{
insert(1,1);//list is 1
insert(2,1);//2 1
insert(3,2);// 2 3 1
insert(4,3);//2 3 4 1
printf("the linked list in reverse order is:");
reverse_print(head);
printf("\nthe linked in list in forward manner is:");
print(head);


}

