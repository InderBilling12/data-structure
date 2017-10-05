#include<stdio.h>//reversing elements of an array by recursion
void reverse(int arr[],int a,int b)
{
    if(a==b||a>b)//base case
        return;
    else//we swap first with last ..second with second last
    {
        int temp=arr[a];
        arr[a]=arr[b];
        arr[b]=temp;
        reverse(arr,a+1,b-1);
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
    reverse(arr,0,n-1);
    printf("after reversing array is:\n");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
}
