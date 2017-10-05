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
int main()
{
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

    struct node*temp=head,*temp2=NULL,*temp3=NULL,*prev=NULL,*p;//we will be needing  a pointer to the previous node
    while(temp->link!=NULL)//reach at end of list and them insert
        temp=temp->link;//we now have pointer to end
    //now lets find out the element
    temp2=head;//to traverse the list
    //temp1 to adjust link at last
    int count=0;
    while(1)
    {
         //printf("vvvvvv\n");
        p=temp2->link;//to use as next time because temp2 would be shifted at last and its link is NULL so we will get an infinite loop
        if(temp2->info<0)//if node's info part is negative move it to end
        {  // printf("hello3\n");
            count++;
        if(count==1)
            temp3=temp2;//this will help us to terminate the loop ab jab pehli movement hogi toh uska pointer store kr liya jab us pra dobara paunchege to terminate krna hain
             if(temp2!=head)//if head then  prev =null and its link has no meaning
               {   //printf("hello4\n");
                   prev->link=temp2->link;}//changing link from where node is removed
            if(temp2==head)
               {  // printf("hello2\n");
                   head=temp2->link;//update head pointer if first node is to be moved,,do this after above statement
                                    // as otherwise head would be updated and it will be true even for prev=null
               }

                 //printf("bye");
                temp->link=temp2;
                   temp2->link=NULL;//merging element at last
                   temp=temp2;//update temp also beacause it help us keep track of last node

              }

        else
            prev=temp2;//agar positive info part hain to prev ko update kro
        if(temp2==temp3 && count!=1)
            break;
        else
            temp2=p;//this can create problem as we have moved temp2 to another position and we are changing its link
}
// now we separated them and now its time to break the list
//temp3 is the start pointer of list of negatives
struct node*head2=prev->link;//we break the end of positive numbers thus link points to negative
prev->link=NULL;//now make it null so that lists are separated
printf("the new lists are:\n");
print_(head);
printf("\n");
print_(head2);
}
