#include<stdio.h>
int gcd(int x,int y)
{
    if(y==0)
        return x;
    else
        return gcd(y,x%y);
}
int main()
{
    int a,b;
    printf("enter 2 numbers :\n");
    scanf("%d%d",&a,&b);
    int c=(a>b)?gcd(a,b):gcd(b,a);
    printf("the gcd is:%d\n",c);
    return 0;

}
