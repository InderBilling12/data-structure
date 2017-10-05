#include<stdio.h>
#include"basefile.c"
void moveLArge()//we use bubble sort concept we need just 1 pass
{
    struct node*temp=head,*p=head,*q;
    for(p=head;p->link!=NULL;p=p->link)
    {
        q=p->link;
        if(p->info>q->info)
        {
            int temp=p->info;
            p->info=q->info;
            q->info=temp;
        }
    }

}
void moveSMall()//we use selection sort concept
{
     struct node*temp=head,*p=head,*q;
     for(q=p->link;q!=NULL;q=q->link)
    {
        if(p->info>q->info)
        {
            int temp=p->info;
            p->info=q->info;
            q->info=temp;
        }
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
    printf("\nthe list after movement of largest to last is:\n");
    moveLArge();
    print();
    printf("\nthe list after movement of smallest to first is:\n ");
    moveSMall();
    print();
    return 0;
}
