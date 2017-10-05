#include<stdio.h>
int fibo(int i)
{
    if(i==0||i==1)
        return 1;
    else
        return fibo(i-1)+fibo(i-2);
}
int main()
{
    int n,i;
    printf("enter no. of terms of fibonacci series:\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
        printf("%d ",fibo(i));
    return 0;
}
