#include<stdio.h>
#include"basefile.c"
int moveN(int a,int b)
{   int count=0;//to keep track of position of nodes
    struct node*temp=head,*p=NULL,*q=NULL,*r,*prev1=NULL,*prev2=NULL;//in these we will store addresses of node to be moved
                                                                    // and of node where new node will be adjusted and their previous nodes because
                                                                        // their links will also be changed
  while(temp!=NULL)// we have to reach at last node
  {   count++;
      if(count==a)
           {
               p=temp;//we will store that node which is to be moved
           }
       else if(count==a+b)//the new position of node to be moved
       q=temp;
    if(p==NULL)
        prev1=temp;//agar abhi bhi p null hain toh is node ko store kro bcz iski next node reqired node ho sakti hain
    if(q==NULL)
        prev2=temp;//same need as for prev1 bss yeh new position ke liye hain
      temp=temp->link;
  }
  if(p!=NULL && q!=NULL)//agar koi bhi null huya toh postion aur move mein se koi 1 valid yaa dono valid nahi hain
  {


   if(p!=head)//bcz otherwise prev1 null hoga aur uska link defined nahi hain
    {prev1->link=p->link;}//iss se movement wali node ke pehle ki node ka  link adjust huya
    if(p==head)
   head=p->link;//agar pehli node ko move krna hain toh head ko update krna padega ,,isko upar wale step ke baad krn ahain nahi tooh upar wala case true ho jaega
                // bcz head update ho chuka hain

    prev2->link=p;//iss se new postion par node insert huyi ,bcz us posiotio se prev node ka link movement wali node ho gyi

    p->link=q; //jis place par movement hoyi us wali node ka link movement waki node mein aaya
  return 1;
  }
  else
  return 0;
}
int main()
{
     int n=0,a,b,count=0;
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
    printf("\nenter the position of node and no. of moves for it:\n");
    scanf("%d%d",&a,&b);
       count=moveN(a,b+1);//meine code aise bnaya hain ki agar 2 moves hain to 1 move ke baad insert ho jaaye ,therefore proper 2 moves ke liye b+1 send krna padega
    if(count==1)
        {
         printf("\nhe list after movement of node n positions :\n ");
         print();
        }
        else
            printf("\nmovement not possible");

    return 0;
}
