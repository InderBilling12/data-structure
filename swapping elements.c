#include<stdio.h>
#include"base file.c"
void infoExchange()
{
    struct node*temp=head;
    while(temp->link!=NULL  )//this condition works fine for odd no. of nodes..
    {
        int x=temp->info;
        temp->info=temp->link->info;
        temp->link->info=x;
        temp=temp->link->link;
        if(temp==NULL)//if we have even no. of nodes
            break;
     }
}
void linkExchange()
{
    struct node *r=head,*p=head,*q;
    while(p->link!=NULL)
          {
              q = p->link;//swap p and q::p mein curren node ka address or q mein uski next ka
              p->link = q->link;
              q->link = p;
              if(r == head)//agar r first node hain toh q ab first node ho jaegi
                head = q;
              else
                r->link = q;//nahi to
              r = p//next time we will we needing address of node previous to the node we r operating on ::upar wale
              // else mei n use hain::3rd node pe operate hr rhe hain to 2nd node mein 4th ka address bhi daalna padega
              p = p->link;
              if(p==NULL)//if even no. of node then this is the exit
                break;
          }

}
int main()
{
     int n=0;
    printf("enter no. of elements to be inserted in a list:\n");
    scanf("%d",&n);
    int m=n;//to keep value of n
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
    printf("\n");
    //infoExchange();
    //print();
    linkExchange();print();


}
