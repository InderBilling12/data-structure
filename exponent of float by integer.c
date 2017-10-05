#include<stdio.h>
float exponent(float n,int a)
{
    if(a==0)
        return 1;
    else
        return (n*exponent(n,a-1));
}
int main()
{
    float n;
    printf("enter number :\n");
    scanf("%f",&n);
    int a;
    printf("enter exponent:\n");
    scanf("%d",&a);
    printf("after exponentiation :%f\n",exponent(n,a));
    return 0;

}
