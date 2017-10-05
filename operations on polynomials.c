#include<stdio.h>
#include<stdlib.h>
struct node{
       int expo;
       int coeff;
       struct node*link;
};
struct node*createListspecial(int expo1,int coeff1,struct node*head)
{
    if(head==NULL)//if list is empty
    {
        struct node*temp=(struct node*)malloc(sizeof(struct node));
        head=temp;
        temp->expo=expo1;
        temp->coeff=coeff1;
        temp->link=NULL;
        return head;
    }
    struct node *ptr;
             while(ptr!=NULL)
    {   if(ptr->expo==expo1)
           {
             ptr->coeff+=coeff1;
            return head;
           }
        ptr=ptr->link;
    }
    struct node*temp=(struct node*)malloc(sizeof(struct node));
          temp->expo=expo1;
        temp->coeff=coeff1;

       ptr = head;
       while(ptr->link)
        ptr = ptr->link;
      ptr->link=temp;
    temp->link=NULL;
    return head;
};

struct node* createList(int expo1,int coeff1,struct node*head  )
{
    if(head==NULL)//if list is empty
    {
        struct node*temp=(struct node*)malloc(sizeof(struct node));
        head=temp;
        temp->expo=expo1;
        temp->coeff=coeff1;
        temp->link=NULL;
        return head;
    }
    struct node*temp=(struct node*)malloc(sizeof(struct node));
        struct node*ptr=head;
    while(ptr->link!=NULL)
    {
        ptr=ptr->link;
    }
    ptr->link=temp;
    temp->link=NULL;
    temp->expo=expo1;
    temp->coeff=coeff1;
    return head;

}
void print(struct node*head)
{
    struct node*ptr=head;
    while(ptr!=NULL)
        {
            printf("%dx^%d ",ptr->coeff,ptr->expo);
            if(ptr->link!=NULL)//agar last term hain toh + ki need nhi hain
                printf(" + ");
            ptr=ptr->link;
        }

    return ;

}
int main()
{
    struct node*start1=NULL,*start2=NULL,*start3=NULL,*p,*q,*start4=NULL;
    int m,n;
    printf("enter the terms in first and second polynomial:\n");
    scanf("%d%d",&m,&n);
    printf("enter the terms of first polynomial:in order :exponent and coefficient\n");
    while(m--)
    {
        int expo,coeff;
        scanf("%d%d",&expo,&coeff);//take input of exponent and coefficient
        start1=createList(expo,coeff,start1);
    }
    printf("enter the terms of second polynomial:in order :exponent and coefficient\n");
        while(n--)
    {
        int expo,coeff;
        scanf("%d%d",&expo,&coeff);//take input of exponent and coefficient
        start2=createList(expo,coeff,start2);
    }
    p=start1;//store head of first list
    q=start2;//store head of second list
    while(p!=NULL && q!=NULL)//exit when either of list finishes
    {
        if(p->expo>q->expo)
            {
                start3=createList(p->expo,p->coeff,start3);//agar pehli list ki term badi hain toh new list mein daalo aur p ko updat kro
                p=p->link;
            }
        else if(p->expo>q->expo)
            {
                start3=createList(q->expo,q->coeff,start3);//agar doosri ki term badi hain to use new mein daalo aur q ko update kro
                q=q->link;
            }
            else//agar dono equal hain toh sum krke new mein daalo aur dono ko update kro
            {
             start3=createList(p->expo,p->coeff+q->coeff,start3);
             p=p->link;
             q=q->link;
            }
    }

    while(p!=NULL)//agar abhi bhi first list ki kuch terms rehti hain toh
    {
        start3=createList(p->expo,p->coeff,start3);
        p=p->link;
    }
    while(q!=NULL)//agar doori ki terms rehri hain toh
    {
         start3=createList(q->expo,q->coeff,start3);
        q=q->link;
    }
    p=start1;
    q=start2;//p and q ko re-initialise kro bcz abhi multiply krna hain
 //assuming first list has higher expo otherwise we can write the case
    while(p!=NULL)
    {   q=start2;
        while(q!=NULL)//all times traverse full list
    {
        start4=createListspecial(p->expo+q->expo,p->coeff*q->coeff,start4);//we have keep it in sorted way
        q=q->link;
    }
    p=p->link;//after 1 traversal of second list update p
    }
    printf("the polynomials are :\n");
    print(start1);
    printf("\nand\n");
    print(start2);
    printf("\nthe sum of polynomials is:\n");
    print(start3);
    printf("\nmultiplied polynomial is:\n");
    print(start4);
}
