#include<stdio.h>
int recursion(int n)
{
    if(n==0)
        return n;//beacuse we have to display also as sequence of characters
   int sum=(n%10+recursion(n/10));//remainder plus call with quotient
    printf("%d\n",n);
     return sum;
}
int main()
{
    int n;
    printf("enter any number:\n");
    scanf("%d",&n);
     printf("the sum of digits of number is:%d",recursion(n));
    return 0;
}
