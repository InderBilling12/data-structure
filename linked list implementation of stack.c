#include<stdio.h>
#include<stdlib.h>
struct node{
     int data;
     struct node * link;
};
struct node* top=NULL; //to identify top of stack :we use head as top;
void push(int x)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->link=top;
    top=temp;
}
void print()
{ printf("\nthe list is:");
    struct node* temp = top;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->link;
    }
    printf("\n");
}
void pop()
{   struct node* temp = top;
    if(top==NULL)
    {
        printf("nothing to pop");
        return;
    }
    top=temp->link;
    free(temp);
}

void ISempty()
{
    if(top==NULL)
        printf("\nempty stack\n");
    else
        printf("\nstack is not empty\n");
}int top_()
{
    return top->data;
}
main()
{    ISempty();
    push(2);print();
    push(4);print();
    push(8);print();
    pop();print();
    printf("\nthe top of stack is:%d", top_())  ;print();
    ISempty();


}
