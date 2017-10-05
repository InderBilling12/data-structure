#include<stdio.h>//program to input and add numbers through recursion
static int sum=0;
int add(int n)
{
    int x;
    if(n>0)//base case
    {
      scanf("%d",&x);
      sum=x+add(n-1);
      return sum;
    }
    else
        return 0;
}
int main()
{
    int n;
    printf("enter count of numbers:\n");
    scanf("%d",&n);
    printf("the sum of input numbers is: %d\n",add(n));

}
