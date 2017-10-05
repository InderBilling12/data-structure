#include<stdio.h>
#include"basefile.c"
void print_(struct node*h1)
{
    struct node*ptr=h1;
    while(ptr!=NULL)
        {
            printf("%d ",ptr->info);
            ptr=ptr->link;
        }
    return ;

}
int findMID()
{
    struct node*temp=head,*p=head;//2 pointers start ko pint krenge ,,1st ko 1
                                      //step at a time change kro 2nd ko 2 steps..whem 2nd reaches end 1st one will be in mid
      while(p->link!=NULL)// this will work fine for odd numbered elements....bcz p hamesa odd node ko point krega toh easily null check ho jaega
      {
          temp=temp->link;
          p=p->link->link;
          if(p->link->link==NULL)// for even number nodes
            break;
      }
      return temp->info;
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
    printf("the list created is :\n");
    print();
    printf("the middle element is:\n");

    printf("\n the middle element of list is:%d \n",findMID());
}
