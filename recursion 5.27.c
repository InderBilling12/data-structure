#include<stdio.h>//reversing a number by recursion
static number=0;
void reverse(int n)
{

   if(n==0)//base case
        return ;
   else
   {
       number=(n%10)+number*10;
       reverse(n/10);
   }
}
int main()
{
    int n;
    printf("enter the number:\n");
    scanf("%d",&n);
    reverse(n);
    printf("after reversal the number is:%d",number);
    return 0;
}
