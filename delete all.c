#include<stdio.h>
#include"basefile.c"
void delete()
{

    while(head!=NULL)
    {struct node*temp=head,*p,*q;//because every time we delete any of these and use it in next loop will run infinitely
        p=temp;
        q=temp->link;
        free(p);
        head=q;
        if(q!=NULL)
        temp=temp->link;

    }

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
    delete();
   print();//if program runs well it will not print anything
    return 0;
}
