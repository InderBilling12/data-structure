#include<stdio.h>
#define max 50
static int pivot;
int top1=-1,top2=-1;
int stack1[max];//for low limit
int stack2[max];//for high limit
void push1(int index)
{
    if(top1<max)
    stack1[++top1]=index;
}
void push2(int index)
{
if(top2<max)
    stack2[++top2]=index;
}
int pop1()
{
    return stack1[top1--];
}
int  pop2()
{
    return stack2[top2--];
}
void quick_sort(int a[],int low,int high)
{
    int beg, end,piv_loc;
    push1(low);
    push2(high);
    while(top1 != -1 || top2 != -1)
    {
        beg = pop1();
        end = pop2();
        piv_loc = partition(a,beg,end);
        if(beg < piv_loc - 1)
        {
            push1(beg);
            push2(piv_loc - 1);
        }
        if(end > piv_loc + 1)
        {
            push1(piv_loc+1);
            push2(end);

        }
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
    int a[10]={7,5,4,3,9,1,13,22,0,11};
    quick_sort(a,0,9);
    int i=0;
    for(i=0;i<10;i++)
        printf("%d ",a[i]);

}
