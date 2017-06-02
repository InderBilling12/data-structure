#include<stdio.h>
#include<stdlib.h>
void print();
void insert(int x);
struct node{
     int data;
     struct node * link;
};
struct node* A=NULL;
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
}
void insert(int x)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->link=A;
    A=temp;
}
void print()
{ printf("the list is:");
    struct node* temp = A;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->link;
    }
    printf("\n");
}
