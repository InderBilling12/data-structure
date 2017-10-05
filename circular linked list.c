#include<stdio.h>
#include<stdlib.h>
struct node{
int info;
struct node*link;
}*last=NULL;
void createLIST(int item)
{
    struct node*temp=(struct node*)malloc(sizeof(struct node));
    if(last==NULL)//when the list is empty
    {
        last=temp;
        last->link=temp;//last ka link first ko point krna chahiye par ab sirf 1 elemnt hain
        temp->info=item;
        return;
    }
    struct node*p=last->link;//that is we start from first node as this the circular linked list
    //now we will just insertions at end
    //there we will be changing last
    while(p!=last)//jab tak dubara last nhi aa jata
        p=p->link;
    //now change original last's link to new node and then make new node last
    temp->link=last->link;//ab temp pehli node ko piont krega
    last->link=temp;
    last=temp;
    temp->info=item;

}
void insertATbeg(int item)
{
    struct node*temp=(struct node*)malloc(sizeof(struct node));
    //now we have to change last->link
    //purna last ka link ab new temp ka link ho jaega
    struct node*curr=last;
    temp->link=last->link;
    last->link=temp;
    temp->info=item;
}
void insertATend(int item)
{
    struct node*temp=(struct node*)malloc(sizeof(struct node));
      struct node*p=last->link;//that is we start from first node as this the circular linked list
    //now we will just insertions at end
    //there we will be changing last
    while(p!=last)//jab tak dubara last nhi aa jata
        p=p->link;
    //now change original last's link to new node and then make new node last
    temp->link=last->link;//ab temp pehli node ko piont krega
    last->link=temp;
    last=temp;
    temp->info=item;
}
void insertAFTER(int item1,int item2)//item2 is to be inserted
{
    struct node*temp=(struct node*)malloc(sizeof(struct node));
    struct node*curr=last->link;
    int c=0;//to check whether insertion possible or not
    //here we use do while loop for our termination
    do{
        if(curr->info==item1)
        {
            c=1;//means insertion possible
            break;
        }
        else//update kro agar nhi mila toh
            curr=curr->link;

    }while(curr!=last->link);
    //now we have got the required node after which we have to insert the node
    if(c==1)//if we node found
    {
        temp->link=curr->link;//temp mein pehle wale curr mein jo link tha woh daalo aur curr ke link mein temp daalo
        curr->link=temp;
        temp->info=item2;
    }
    else
        printf("\ninsertion not possible\n");
}
void delete(int item)
{
    struct node*curr=last->link,*prev=NULL;//we will be needing a node previous to the node which we will be deleting
    int c=0;//to check whether deletion is possible or not
    //we will use do -while loop to traverse
    do{
            if(curr->info==item)
            {
                c=1;
                break;
            }
            else//nhi toh prev aur curr ko update kro
            {
                prev=curr;
                curr=curr->link;
            }
    }while(curr!=last->link);//jab tak wo fir se 1st node pe nhi aa jata
    if(c==1)//if deletion possible
    {
        if(curr==last->link)//agar first delete krni hain toh
        last->link=curr->link;//abhi jo 2nd node hain usko first krdo
        else if(curr==last)//agar last delete krni hain toh;;;to last se 1 chod ke last ban jaega
        {
            prev->link=last->link;//ab jo ;ast hain uska link 1st node hain..ab last delete hoga toh woh last ke prhle wali mein daalo
            //abhi last ko update kro
            last=prev;
        }
        else  //agar beech mein koi delete krni hain toh simply prev ke link mein curr ks link daal do
            prev->link=curr->link;
    }
    else
        printf("deletion not possible:\n");
}
void display()
{
    struct node*curr=last->link;
    do{
        printf("%d ",curr->info);
        curr=curr->link;
    }while(curr!=last->link);
}
void reverse()
{
    struct node*temp=last->link,*prev=NULL,*next,*p=last->link;//we use p bcz last->link will be modified in between and thing will mess up
     do{
        next=temp->link;
     temp->link=prev;
     prev=temp;
    // last=temp;//this is the most important step,if we want to eliminate 2 steps after while and p
     temp=next;
     }while(temp!=p);//when all links are reversed it automatically exit,,,abhi hmm purani first node pe aa gye hain ,,uska link purana last krdo
     //aur usko naya last bna do
       temp->link=last;
    last=temp;
}
int main()
{  int c=1;
    while(c==1)
   {
    int ch;
   printf("press 1 to create a circular linked list :\n");
   printf("press 2 to insert element in the beginning of list:\n");
   printf("press 3 to insert at end of list:\n");
   printf("press 4 to insert after a given node:\n");
   printf("press 5 to delete a specific node:\n");
   printf("press 6 to display list :\n");
   printf("press 7 to reverse the circular linked list:\n");
   printf("enter your choice:\n");
      scanf("%d",&ch);
      switch(ch)
      {
      case 1:
         {
            int n;
        printf("enter how many elements u want to insert:\n");
        scanf("%d",&n);
        while(n--)
        {
            int x;
            printf("enter the element u want to insert:\n");
            scanf("%d",&x);
            createLIST(x);
        }
         }
        break;
      case 2:
        {
            int x;
        printf("enter the element to be inserted at beginning of list:\n");
        scanf("%d",&x);
        insertATbeg(x);
        }
        break;
      case 3:
                {
            int x;
        printf("enter the element to be inserted at end of list:\n");
        scanf("%d",&x);
        insertATend(x);
        }
        break;

      case 4:
        {
            int x,y;
            printf("entert the item after which you want to insert the item and enter the item also:\n");
            scanf("%d%d",&x,&y);
            insertAFTER(x,y);
        }
        break;
     case 5:
        {
            int x;
            printf("enter the data part of the node which you want to delete:\n");
            scanf("%d",&x);
            delete(x);
        }
        break;
      case 6:
        {
            display();
        }
        break;

      case 7:
        {
            reverse();
        }
        break;
      default:
        printf("enter valid operation:\n");
      }
      printf("\npress 1 to continue ,else 0: ");
      scanf("%d",&c);
}
}

