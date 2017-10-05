#include<stdio.h>
#include"basefile.c"
void swap(int i,int j)
{
    struct node *curr=head,*p=head,*q=NULL,*r=NULL,*s=NULL,*prev;//p q point to 2 nodes and r, s resp. point to their previous node,,prev is for swapping and storing address of previous node
    int count=0;//to keep track of index
    while(curr!=NULL)
    {
        count++;
        if(count==i)
        {
            r=prev;//r__ p ka previous hain
            p=curr;//present node mil gyi hain isko p mein store kro
            prev=p;//ab p prev ho jaaega next time ke liye
            curr=p->link;//abhi curr ko update krna hain
        }
        else if(count==j)
        {
            s=prev;//s__ q ka previous hain
            q=curr;//present node mil gyi hain isko q mein store kro
            prev=q;//ab p prev ho jaaega next time ke liye
            curr=q->link;//abhi curr ko update krna hain
        }
        else
            {   prev=curr;
                curr=curr->link;//agar upar mein se koi bhi index nhi mila toh curr ko update kro bas
            }

    }
    if(p!=NULL &&q!=NULL)//agar dono mein se koi null hua to required node nhi mili hain..islie swapping possible nhi hogi
    {
        //swapping the link part
        // this is the case when node are not adjacent
       if(q!=p->link)//swapping both link parts using temporary variable prev
        {prev=p->link;
        p->link=q->link;
        q->link=prev;
        if(p!=head)//aement gar p head hua toh yeh statement valid nahi hogi
          r->link=q;
        s->link=p;
        if(p==head)
            head=q;
        }
        if(q==p->link)
        {
            if(p!=head)
                r->link=q;
                p->link=q->link;
                q->link=s;//bcz here p=s
                if(p==head)
                    head=q;

        }


    }
    else
        printf("swapping not possible:\n");

}
int main()
  {
      int n=0,i,j;
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
    printf("enter the logical address of elements which u want to swap:\n");
    scanf("%d%d",&i,&j);
    swap(i,j);
    printf("after swapping of node the list becomes:\n");
    print();
  }
