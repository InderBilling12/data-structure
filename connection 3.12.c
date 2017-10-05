#include<stdio.h>
#include<stdlib.h>
int count=0;//to keep trace of index
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
void print(struct node*head)
{
    struct node*ptr=head;
    while(ptr!=NULL)
        {
            printf("%d ",ptr->info);
            ptr=ptr->link;
        }
    return ;

}
void specialPRINT(struct node*head1,struct node*head2)
{
   struct node*t1=head1,*t2=head2,*p,*q;//we will use these

   while(t1!=NULL)
   {
       for(p=t2;p!=NULL;p=p->link)
       {
           count++;
           if(count==t1->info)
          {
            printf("%d ",p->info);
            t2=p->link;//t2 ab current node ka next ho jaega
            t1=t1->link;//if print occurs only then these are updated further
            break;

          }

       }
   }
}

int main()
{

    struct node*head1=NULL,*head2=NULL;
    int n1,n2;
    printf("enter no. of elements of first and second list:\n");
    scanf("%d%d",&n1,&n2);
     printf("enter the elements to be inserted in first list in sorted way :\n");
    while(n1>0)
    {
        int item;

        scanf("%d",&item);
        head1 = createList(item,head1);
        n1--;
    }
       printf("enter the elements to be inserted in second list:\n");
    while(n2>0)
    {
        int item;

        scanf("%d",&item);
        head2= createList(item,head2);
        n2--;
    }

    printf("\nthe first list is:\n");
    print(head1);
    printf("\nthe 2nd list is:\n");
    print(head2);
    printf("\nthe 2nd list according to first is:\n");
    specialPRINT(head1,head2);
}
