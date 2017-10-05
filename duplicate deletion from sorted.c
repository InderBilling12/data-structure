#include<stdio.h>
#include"basefile.c"
void deleteDUP(struct node*p)
{
    struct node*temp=head;
 while(temp->link!=p)//here head node deletion case will not be possible bcz that is the first node which we encounter
{temp=temp->link;}
 temp->link=p->link;//we set  next link of node to be deleted to its previous node
 free(p);//if memory is also to be deallocated
// printf("hello3");
}

int main()
{
    struct node*temp,*p;
    int n=0;
    printf("enter no. of elements to be inserted in a list:\n");
    scanf("%d",&n);
    printf("enter the elements to be inserted in sorted way:\n");
    while(n>0)
    {
        int item;
        scanf("%d",&item);
        createList(item);
        n--;
    }
    printf("the list created is:\n");
    print();
    printf("\n the list after deletion of duplicates is:\n");
    temp=head;
    while(temp->link!=NULL)
    { //printf("hello1\n");
     if(temp->info==temp->link->info)//agar uski next info bhi vhi hain
     {// printf("hello2\n");
         p=temp->link;//p mein duplicate node ka address daalo
        temp=temp->link->link;// if we use temp!=NULL then this statement creates problem
         deleteDUP(p);

    }

     else temp=temp->link;
    }
     print();
    return 0;
}
