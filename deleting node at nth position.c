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
void print(){
struct node* temp=head;
printf("the list is:");
while(temp!=NULL)
{
 printf("%d ",temp->data);
 temp=temp->link;
}
printf("\n");

}
void delete(int n){
     struct node *temp1=head;
    if(n==1)
    { int i;
       head=temp1->link;
        return;
    }
    int i;
    for(i=0;i<n-2;i++)
{
    temp1=temp1->link;
}
struct node *temp2=head;
    for(i=0;i<n-1;i++)
{
    temp2=temp2->link;
}
temp1->link=temp2->link;



}
main()
{
insert(1,1);//list is 1
insert(2,1);//2 1
insert(3,2);// 2 3 1
insert(4,3);//2 3 4 1
print();
delete(2);//list is 2 4 1
print();
}

