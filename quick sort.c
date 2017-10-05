#include<stdio.h>
static int pivot;
void quick_sort(int a[],int low,int high)
{   int i=0;
    if(low<high)
    {
        pivot=partition(a,low,high);//now pivot will be updated
        quick_sort(a,low,pivot-1);
        quick_sort(a,pivot+1,high);
    }

}
int partition (int a[],int low,int high)
{
     pivot=a[high];
    int i=low-1,j=0;
    for(j=low;j<high;j++)
    {
        if(a[j]<=pivot)//toh uske piche wale se swap krdo
        {  i++;
            int temp=a[j];
            a[j]=a[i];
            a[i]=temp;
        }
    }
    int temp=a[i+1];//placing pivot at its right place
    a[i+1]=a[high];
    a[high]=temp;
    return (i+1);//returning logical address of pivot
}
int main()
{
    int a[10]={7,5,4,3,9,1,10,22,0,11};
    quick_sort(a,0,9);
    int i=0;
    for(i=0;i<10;i++)
        printf("%d ",a[i]);

}
