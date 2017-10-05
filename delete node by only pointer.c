#include<stdio.h>
#include"basefile.c"
int main()
{
    struct node*p=NULL;
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
    printf("enter the pointer to the node to be deleted:");
    scanf("%d",&p);
}
