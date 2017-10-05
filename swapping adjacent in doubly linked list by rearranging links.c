#include<stdio.h>
#include"createDouble.c"

void swapping()
{
    struct node*temp=head,*p=head,*q,*r,*t=head;
    while(p->next!=NULL)//this will work for odd  no. of nodes
    {
        q=p->next;//swapping ke liye 2 nodes li hain,,,,q me doosri ka address
        p->next=q->next;//pehle ka next aur prev doosre ke sath swap
        q->next=p;
        r=q->prev;
        q->prev=p->prev;
        p->prev=r;
        if(p==head)
            head=q;
        else
            t->next=q;//jaise 3rd node kr rhe hain toh doosri ki next toh set krni padegi jo ki q i.e. 4th hogi after swapping
        p=p->next;
        if(p==NULL)//for even no. of nodes
            break;
    }

}
 int main()
{
     int n=0;
    printf("enter no. of elements to be inserted in a list:\n");
    scanf("%d",&n);
    printf("enter the elements to be inserted:\n");
    while(n>0)
    {
        int item;
        scanf("%d",&item);
        createList(item);
        n--;
    }
    printf("the list created is:\n");
    print();
    swapping();
    printf("\nthe list after swapping adjacent elements is:\n");
    print();
}
