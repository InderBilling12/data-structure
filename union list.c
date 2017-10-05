#include<stdio.h>
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
void deleteDUP(struct node*p,struct node*head)
{
    struct node*temp=head;
 while(temp->link!=p)//here head node deletion case will not be possible bcz that is the first node which we encounter
{temp=temp->link;}
 temp->link=p->link;//we set  next link of node to be deleted to its previous node
 free(p);//if memory is also to be deallocated
 //printf("hello3");
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
int main()
{
    struct node*head1=NULL,*head2=NULL,*head3=NULL,*temp=NULL,*p,*q;//pointer to first list ,2nd and new list:the 3 temporary pointer
    int n1,n2;
    printf("enter no. of elements of first and second list:\n");
    scanf("%d%d",&n1,&n2);
    printf("enter the element to be inserted in first list:\n");
    while(n1>0)
    {
        int item;
        scanf("%d",&item);
        head1 = createList(item,head1);
        n1--;
    }
    printf("enter the element to be inserted in second list:\n");
    while(n2>0)
    {
        int item;
        scanf("%d",&item);
        head2= createList(item,head2);
        n2--;
    }
    temp=head1;//to traverse first list
    while(temp->link!=NULL)
    {    temp=temp->link;}
    // we rech at end of first list ,,megre them
      temp->link=head2;
      //now delete duplicates
      temp=head1;//re initialise to point to first node as that is the union now
       while(temp->link!=NULL)//termination condition
    {   //  printf("bye");
        for(p=temp->link;p!=NULL;)//we will have to check that element with all other elements
        {  //printf("hello2");
            if(temp->info==p->info)//if info matches go for deletion
                {  //printf("hello1");
                     q=p;//use separate pointer for deletion otherwise we won't be getting valid address next time
                    p=p->link;
                    deleteDUP(q,head1);
                }
                else
                    p=p->link;
        }
        temp=temp->link;


    }
    printf("the union list is:\n");// combine two lists and delete duplicates
    print(head1);



}

