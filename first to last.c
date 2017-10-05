#include<stdio.h>
#include"basefile.c"
void moveTOend()
{
    struct node* temp=head,*t=head;
    while(temp->link!=NULL)//last  node takk pahunchna hain
    {
        temp=temp->link;
    }
    head=t->link;//current head node ka link ab head ho jaega
    temp->link=t;//last node ka link original first node se krna hain
    t->link= NULL;//ab jo last node hain uska link null krna hain

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
    printf("\nthe list after moving first node to last is:\n");
    moveTOend();
    print();


    return 0;
}

