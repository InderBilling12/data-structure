#include<stdio.h>
#include<stdlib.h>
struct node{
int roll_no;
char name[20];
float percent;
struct node*link;
}*last=NULL;
void createLIST(int item,struct node*head)
{
    struct node*temp=(struct node*)malloc(sizeof(struct node));
    printf("enter %%ge and name of student:\n");
    scanf("%f%s",&temp->percent,temp->name);
    if(last==NULL)//when the list is empty(means only header node we have)
    {
        last=temp;//ab last ko temp krdo
        head->link=temp;//ab header ka next ye new node ho jaegi
        temp->roll_no=item;
        head->roll_no++;//this is count ++
        head->percent=temp->percent;//bcz only 1 node we have
        last->link=head;//this is very important only then it will be circular
        return;
    }
    struct node*p=head->link;//that is we start from first node(after header node) as this the circular linked list
    //now we will just insertions at end
    //there we will be changing last
    while(p!=last)//jab tak dubara last nhi aa jata
        p=p->link;
    //now change original last's link to new node and then make new node last
    temp->link=last->link;//ab temp pehli header node ko piont krega
    last->link=temp;
    last=temp;
    temp->roll_no=item;
    head->roll_no++;//yeh count++ hain
      last->link=head;//this is very important only then it will be circular
    if(temp->percent>head->percent)
        head->percent=temp->percent;//toh max. change ho jaega
}
void insertATbeg(int item,struct node*head)//means after header node we have to insert,
{
       struct node*temp=(struct node*)malloc(sizeof(struct node));
    printf("enter %%ge and name of student:\n");
    scanf("%f%s",&temp->percent,temp->name);
    //just change link using header
    temp->link=head->link;//ab jo head ka link hain wo temp ka link ho jaega
    head->link=temp;
    temp->roll_no=item;
    head->roll_no++;//yeh count++ hain
      last->link=head;//this is very important only then it will be circular,but here it is not needed
     if(temp->percent>head->percent)
        head->percent=temp->percent;//toh max. change ho jaega
}
void insertATend(int item,struct node*head)
{
    struct node*temp=(struct node*)malloc(sizeof(struct node));
    printf("enter %%ge and name of student:\n");
    scanf("%f%s",&temp->percent,temp->name);
     struct node*p=head->link;//that is we start from first node(after header node) as this the circular linked list
    //now we will just insertions at end
    //there we will be changing last
    while(p!=last)//jab tak dubara last nhi aa jata
        p=p->link;
    //now change original last's link to new node and then make new node last
    temp->link=last->link;//ab temp pehli header node ko piont krega
    last->link=temp;
    last=temp;
    temp->roll_no=item;
    head->roll_no++;//yeh count++ hain
      last->link=head;//this is very important only then it will be circular
    if(temp->percent>head->percent)
        head->percent=temp->percent;//toh max. change ho jaega
}
void insertAFTER(int item1,int item2,struct node*head)
{
    struct node*temp=(struct node*)malloc(sizeof(struct node));
    printf("enter %%ge and name of student:\n");
    scanf("%f%s",&temp->percent,temp->name);
    struct node*curr=head->link;
    int c=0;//to check whether we can insert or not
    while(curr!=head)//jab takk header par nhi paunch jata
    {
        if(curr->roll_no==item1)
        {
            c=1;//means possible insertion
            break;
        }
        else
            curr=curr->link;//nhi toh update kro
    }
    if(c==1)//if found
    {
        temp->link=curr->link;//ab curr ka link new node ka link ho jaega aur temp curr ka link hoga
        curr->link=temp;
        temp->roll_no=item2;
          last->link=head;//this is very important only then it will be circular
          head->roll_no++;
    }
    else
        printf("such insertion is not possible");
}
void delete(int item,struct node*head)
{
     struct node*curr=head->link,*prev=head;//bcz head to delete nhi hogi
    int c=0;//to check whether we can insert or not
    while(curr!=head)//jab takk header par nhi paunch jata
    {
        if(curr->roll_no==item)
        {
            c=1;//means possible deletion
              head->roll_no--;//to count decrease kro
            break;
        }
        else
           {    prev=curr;
                 curr=curr->link;//nhi toh update kro
    }
    }
    if(c==1)//if found
    {
        prev->link=curr->link;
        if(curr==last)
            last=prev;//agar last ko delete kiya toh last ko update kro

    }
    else
        printf("deletion not possible\n");
}

void display(struct node*head)
{
    struct node*curr=head->link;
    while(curr!=head)
    {
        printf("%s %d %f\n",curr->name,curr->roll_no,curr->percent);
        curr=curr->link;
    }
}
int main()
{
    struct node*head=(struct node*)malloc(sizeof(struct node));//this is header node,we will pass it to function and it won't be changed
     head->roll_no=0;//actually we store here count;
     head->percent=0;//in this we will store max. %
     head->link=last;//abhi sirf 1 node hogi bcz last=NULL here
    int c=1;
    while(c==1)
   {
    int ch;
   printf("press 1 to create a circular linked list :\n");
   printf("press 2 to insert element in the beginning of list:\n");
   printf("press 3 to insert at end of list:\n");
   printf("press 4 to insert after a given node:\n");
   printf("press 5 to delete a specific node:\n");
   printf("press 6 to display list :\n");
   printf("press 7 to print no. of students and max. percent:\n");
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
            printf("enter the roll no. of student:\n");//rest of inputs we will take in the function itself
            scanf("%d",&x);
            createLIST(x,head);
        }
         }
        break;
      case 2:
        {
            int x;
        printf("enter the roll no of student:\n");
        scanf("%d",&x);
        insertATbeg(x,head);
        }
        break;
      case 3:
                {
            int x;
        printf("enter the roll no of student:\n");
        scanf("%d",&x);
        insertATend(x,head);
        }
        break;

      case 4:
        {
            int x,y;
            printf("enter the roll no of student after which want to add details of this student and enter roll no this student:\n");
            scanf("%d%d",&x,&y);
            insertAFTER(x,y,head);
        }
        break;
     case 5:
        {
            int x;
            printf("enter the roll no of the node which you want to delete:\n");
            scanf("%d",&x);
            delete(x,head);
        }
        break;
      case 6:
        {
            display(head);
        }
        break;
      case 7:
        {
            printf("no.of students =%d and max. percent=%f\n",head->roll_no,head->percent);
        }
        break;
      default:
        printf("enter valid operation:\n");
      }
      printf("\npress 1 to continue ,else 0: ");
      scanf("%d",&c);
}
}
