struct node{
int info;
struct node*link;
}*head=NULL;
void createList(int item  )
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
void print()
{
    struct node*ptr=head;
    while(ptr!=NULL)
        {
            printf("%d ",ptr->info);
            ptr=ptr->link;
        }
    return ;

}

