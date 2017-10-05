#include<stdio.h>
#include<stdlib.h>
struct node{
       int info;
       struct node*link;
};

struct node* createList(int item,struct node*head  )
{
    if(head==NULL)//if list is empty
    {
        struct node*temp=(struct node*)malloc(sizeof(struct node));
        head=temp;
        temp->info=item;
        temp->link=NULL;
        return head;
    }
    struct node*temp=(struct node*)malloc(sizeof(struct node));
        struct node*ptr=head;
    while(ptr->link!=NULL)
    {
        ptr=ptr->link;
    }
    ptr->link=temp;
    temp->link=NULL;
    temp->info=item;
    return head;

}
void identical(struct node*head1,struct node*head2)
{
    int count=0;
    struct node*ptr1=head1,*ptr2=head2;
    while(ptr1!=NULL && ptr2!=NULL)
    {
        if(ptr1->info!=ptr2->info)
        {
            count=1;;
            break;
        }

        ptr1=ptr1->link;
        ptr2=ptr2->link;

    }

    if(count==0 && ptr1==NULL && ptr2==NULL)
        printf("IDENTICAL");
    else
        printf("not identical");
    return;
}
int main()
{

    struct node*head1=NULL,*head2=NULL;
    int n1,n2;
    printf("enter no. of elements of first and second list:\n");
    scanf("%d%d",&n1,&n2);
    while(n1>0)
    {
        int item;
         printf("enter the element to be inserted in first list:\n");
        scanf("%d",&item);
        head1 = createList(item,head1);
        n1--;
    }
    while(n2>0)
    {
        int item;
         printf("enter the element to be inserted in second list:\n");
        scanf("%d",&item);
        head2= createList(item,head2);
        n2--;
    }
    identical(head1,head2);





}
