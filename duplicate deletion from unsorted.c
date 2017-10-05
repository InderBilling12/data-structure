#include<stdio.h>
#include"basefile.c"
void deleteDUP(struct node*p)
{
    struct node*temp=head;
 while(temp->link!=p)//here head node deletion case will not be possible bcz that is the first node which we encounter
{temp=temp->link;}
 temp->link=p->link;//we set  next link of node to be deleted to its previous node
 free(p);//if memory is also to be deallocated
 //printf("hello3");
}
int main()
{
    struct node*temp,*p,*q;
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
    printf("\nthe list after deletion of duplicates is:\n");
    temp=head;
    while(temp->link!=NULL)//termination condition
    {   //  printf("bye");
        for(p=temp->link;p!=NULL;)//we will have to check that element with all other elements
        {  //printf("hello2");
            if(temp->info==p->info)//if info matches go for deletion
                {  //printf("hello1");
                     q=p;//use separate pointer for deletion otherwise we won't be getting valid address next time
                    p=p->link;
                    deleteDUP(q);
                }
                else
                    p=p->link;
        }
        temp=temp->link;


    }
     print();

}
