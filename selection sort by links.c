#include<stdio.h>
#include"basefile.c"
void selectionSORT()
{
    struct node*p= NULL,*q,*r,*s,*temp;//p , q points to two node;;r , s point to their previous nodes respe.,tempmis to swap p and q after links are adjusted
                                     // so that we can use them next time in the same way;
        for(r=p=head;p->link!=NULL;r=p,p=p->link)//last elemnt ko check krne ki jarrorat nahi hain
        {    //printf("hello1\n");
            for(s=q=p->link;q!=NULL;s=q,q=q->link)//q ___ p ki next ko point krega
            {// printf("hello2\n");
                if(p->info>q->info)//p ko sabhi ke saath check krna hain
                {
                    temp=p->link;//swapping their links
                    p->link=q->link;
                    q->link=temp;

                if(p!=head)//agar p head node nahi hain toh yeh statement valid hain
                    r->link=q;
                s->link=p;
                if(p==head)
                head=q;
                //ab p and q ko unki original position par lana hain
                temp=p;
                p=q;
                q=temp;
                }


            }
        }
}

void bubble_sort()
{
    struct node*p,*q,*r,*end,*temp=NULL;
    for(end=NULL;end!=head->link;end=q)
    {

        for(r=p=head;p->link!=end;r=p,p=p->link)
        { q=p->link;
            if(p->info>q->info)
            {
                p->link=q->link;
                q->link=p;
                if(p==head)
                    head=q;
                else
                    r->link=q;
                temp=p;
                p=q;
                q=temp;
            }
        }
    }
}
int main()
  {int n=0;
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
    printf("the sorted list after bubble sort is:\n");
    bubble_sort();
    print();
    printf("the sorted list after selection sort is:\n");
    selectionSORT();
    print();
    }
