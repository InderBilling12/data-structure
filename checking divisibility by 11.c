#include<stdio.h>
int factor(int n)
{
    int sum1=0,sum2=0,diff;//one for sum of digits at odd places and other for sum of digits at even places
    if(n==0)
        return 1;
    if(n<10)//10 we will check for difference of digits
        return 0;
    while(n>0)
    {
        sum1+=n%10;
        n=n/10;
        sum2+=n%10;
        n=n/10;
    }
    diff=(sum1>sum2)?(sum1-sum2):(sum2-sum1);//this diff we will further check
    factor(diff);
}
int main()
{
    int n;
    printf("enter the number:\n");
    scanf("%d",&n);
    if(factor(n))
        printf("divisible by 11:");
    else
        printf("not divisible by 11");
    return 0;
}
