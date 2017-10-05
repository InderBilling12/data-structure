#include<stdio.h>//finding sum of all  elements of array by repeatedly partitioning into almost 2 parts
static int summ=0;
int sum(int arr[],int a ,int b)//a refers to lower index while b refers to the higher index
{
    if(a==b)
        return arr[a];//we can use arr[b]
    if(a>b)//when higher index<lower
        return 0;
    if(a<b)
    {
        summ+=sum(arr,a,(b-a)/2);
        return summ;

    }
}
int main()
{
     int arr[100],n,i=0;
    printf("enter size of array:\n");
    scanf("%d",&n);
    printf("enter elements of array:\n");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("the sum is:%d",sum(arr,0,n-1));
}
