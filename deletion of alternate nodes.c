#include<stdio.h>
#include"basefile.c"
void delete(struct node*p)
{
    struct node*temp=head;
 while(temp->link!=p)//here head node deletion case will not be possible bcz that is the first node which we encounter
{temp=temp->link;}
 temp->link=p->link;//we set  next link of node to be deleted to its previous node
 free(p);//if memory is also to be deallocated
// printf("hello3");
}
void deleteALT()
{
    int count=0;
    struct node*temp=head,*p;
    while(temp!=NULL)// do ot use temp->link!=null bcz the in case of even no. of elements last node will not be deleted
    {
        count++;
        if(count%2==0)//if even numbered node send it for deletion
        {
            p=temp;//use another pointer for deletion
            temp=temp->link;
            delete(p);
        }
        else
            temp=temp->link;

    }
}
int main()
{
     struct node*temp;
    int n=0;
    printf("enter no. of elements to be inserted in a list:\n");
    scanf("%d",&n);
    printf("enter the elements to be inserted :\n");
    while(n>0)
    {
        int item;
        scanf("%d",&item);
        createList(item);
        n--;
    }
    printf("the list created is:\n");
    print();
    printf("\nthe list after deletion of alternate nodes is:\n");
    deleteALT();
    print();
}
