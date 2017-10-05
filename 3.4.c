#include<stdio.h>
#include"base file.c"
void reverse()
{
    struct node*current=head,*prev=NULL,*next;
    while(current!=NULL)
    {
        next=current->link;
        current->link=prev;
        prev=current;
        current=next;
    }
    head=prev;
}

int main()
{
    int n=0;
    printf("enter no. of elements to be inserted in a list:\n");
    scanf("%d",&n);
    int m=n;//to keep value of n
    while(n>0)
    {
        int item;
        printf("enter the element to be inserted:\n");
        scanf("%d",&item);
        createList(item);
        n--;
    }
    printf("the list created is:\n");
    print();


    return 0;
}
