#include<stdio.h>
#include"basefile.c"
void swapINfo()
{
    struct node*temp=head;
    while(temp->link!=NULL)
    {
        temp=temp->link;
    }
    int x;
    x=head->info;
    head->info=temp->info;
    temp->info=x;
}
void swapLInk()
{
    struct node*temp=head,*p=head;
    while(temp->link->link!=NULL)//last se i chhod ke exit  so that that can be linked to current first one i.e. original first node
    {
        temp=temp->link;
    }

    temp->link->link=p->link;
    head=temp->link;//we can also do it later on but then we need to store it in another pointer
      temp->link=p;
      p->link=NULL;

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
    printf("\n the list after swapping first and last by info is:\n");
    swapINfo();
    print();
    printf("\n the list after swapping first and last by link is:\n");
    swapLInk();
    print();


    return 0;
}
