struct node{
int info;
struct node*prev;
struct node*next;
}*head=NULL;


void createList(int item)
{
    struct node*current=(struct node*)malloc(sizeof(struct node));
    struct node*temp=head;
    if(temp==NULL)
    {   head=current;
        current->prev=NULL;
        current->next=NULL;
        current->info=item;
        return;
    }
    while(temp->next!=NULL)
    temp=temp->next;
      temp->next=current;
      current->prev=temp;
      current->next=NULL;
      current->info=item;
      return;
}
void print()
{
    struct node*temp=head;
    while(temp!=NULL)
        {
            printf("%d ",temp->info);
            temp=temp->next;
        }

}

