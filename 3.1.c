#include<stdio.h>
struct node{
       int info;
       struct node*link;
}*head=NULL;
void createList(int item)
{
    if(head==NULL)//if list is empty
    {
        struct node*temp=(struct node*)malloc(sizeof(struct node));
        head=temp;
        temp->info=item;
        temp->link=NULL;
        return;
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
    return;

}
void search(int item)
{
    int count=0;
    struct node*ptr=head;
    while(ptr!=NULL)
    {
        if(item==ptr->info)
            count++;
            ptr=ptr->link;
    }
    if(count>0)
        printf("the element %d occurs %d times in the given list",item,count);
    else
        printf("element not found");

}
void size()
{
    struct node*ptr=head;
    int min=head->info,max=head->info;
    while(ptr!=NULL)
    {
        if(ptr->info>=max)
            max=ptr->info;
        if(ptr->info<min)
            min=ptr->info;
        ptr=ptr->link;

    }
    printf("the smallest element in list is %d and largest element is %d",min,max);
    return ;
}
int main()
{
    int n=0,item;
    printf("enter no. of elements to be inserted in list:\n");
    scanf("%d",&n);
    while(n>0)
    {
        int item;
         printf("enter the element to be inserted:\n");
        scanf("%d",&item);
        createList(item);
        n--;
    }

    printf("enter item whose occurences are to be found:\n");
    scanf("%d",&item);
    search(item);
    size();//smallest and largest element of list

}
