#include<stdio.h>//proper divisors and their sum by recursion
static int sum=0;
void factor(int n,int i)
{
    if(i==n)//base condition
        return 0;
        else
            {
                if(n%i==0)
                {
                    printf("%d\n",i);//this only if divisor
                    sum+=i;
                }
                factor(n,i+1);//this call is must
            }
}
int main()
{
    int n;
    printf("enter the number:\n");
    scanf("%d",&n);
    factor(n,1);
    printf("the sum of proper divisors is %d\n",sum);
    if(sum==n)
        printf("\n perfect number:\n");
    else
        printf("\nnot a perfect number:\n");
    return 0;


}
