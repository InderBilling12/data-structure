#include<stdio.h>
void prime(int n)
{
    int i=2;
    if(n==1)
    return ;
    else
        while(n%i!=0)//agar 0 hain toh print kro nahi toh next number as a factor check kro
            i++;
        printf("%d ",i);
        prime(n/i);

}
int main()
{
    int n;
    printf("enter the number:\n");
    scanf("%d",&n);
    printf("the prime factors are:\n");
    prime(n);
    return 0;
}
