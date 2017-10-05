#include<stdio.h>//sum of all even numbers of array by recursion
static int summ=0;
void sum(int arr[],int a,int b)
{
    if(a==b)//base condition
        return 0;
        else
        {
            if(arr[a]%2==0)
                summ+=arr[a];
            sum(arr,a+1,b);
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
    sum(arr,0,n);
    printf("the sum of even elements of array is:%d\n",summ);
    return 0;
}
