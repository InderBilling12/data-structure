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
void reverse(struct node * current)
{
    if(current->link==NULL)
    {
            head=current ;
            return;
    }
    reverse(current->link);
    current->link->link=current;
    current->link=NULL;
}
void print(){
struct node* temp=head;
printf("the list is:");
while(temp!=NULL)
{
 printf("%d ",temp->data);
 temp=temp->link;
}

}
main()
{
insert(1,1);//list is 1
insert(2,1);//2 1
insert(3,2);// 2 3 1
insert(4,3);//2 3 4 1
print();
printf("\nafter reversing:\n");
reverse(head);
print();

}

