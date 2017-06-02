#include<stdio.h>
#include<stdlib.h>
struct node{
     int data;
     struct node * link;
};
void print(struct node* head);
void insert(int x,struct node** head);
main()
{
    struct node* A=NULL;
    int i,j;
    printf("enter total count of numbers");
    scanf("%d",&i);
    for(j=0;j<i;j++)
    { int x;
        printf("enter number");
        scanf("%d",&x);
        insert(x,&A);
        print(A);
    }
}
void insert(int x,struct node** head)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->link=*head;
    *head=temp;
}
void print(struct node* head)
{
    printf("the list is:");
    while(head!=NULL)
    {
        printf("%d ",head->data);
        head=head->link;
    }
    printf("\n");
}
