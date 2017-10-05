#include<stdio.h>// to count and print all  the prime numbers between a range by recursion
#include<math.h>
void check_prime(int a,int b)
{
    int i,count=0;//if it remains 0 then number is  prime
    if(a==b+1)//base case
    return ;
    else
    {
      for(i=2;i<sqrt(a)+1;i++)
      {
          if(a%i==0 && a!=2)
          {
              count=1;
              break;

          }
      }
      if(count==0 && a!=1)
        printf("%d\n",a);
      check_prime(a+1,b);
    }
}
int main()
{
    int a ,b;
    printf("enter the range:\n");
    scanf("%d%d",&a,&b);
    check_prime(a,b);
    return 0;
}
