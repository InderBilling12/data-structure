#include<stdio.h>
#include"basefile.c"
#include<stdlib.h>
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
struct node* findMID()//find mid and return pointer to it and then break the list
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
      return temp;
}
int main()
{
    struct node*temp=head,*temp2=NULL,*head2;
   int n=0;
    printf("enter no. of elements to be inserted in a list:\n");
    scanf("%d",&n);
    printf("\n enter the elements to be inserted in the list:\n ");
    while(n>0)
    {
        int item;
        scanf("%d",&item);
        createList(item);
        n--;
    }
    printf("the list created is:\n");
    print();
    temp2=findMID();//temp2 gets address of mid,iska link null kro aur iska link nyi list ke head pointer me daalo
    head2=temp2->link;
    temp2->link=NULL;
    printf("the lists after spliiting are:\n");
    print_(head);
    printf("\n");
    print_(head2);
}
