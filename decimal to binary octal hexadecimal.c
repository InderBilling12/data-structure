#include<stdio.h>
void conversion(int number,int base)
{
    if(number==0)
        return ;
        int rem=number%base;
    conversion(number/base,base);
    if(rem<10)
     printf("%d",rem);//ok for binary and octal
     else
        printf("%c",rem-10+'A');//for hexadecimal
}
int main()
{
    int n;
    printf("enter the number:\n");
    scanf("%d",&n);
    printf("the binary is:\n");
    conversion(n,2);
    printf("\n");
     printf("the octal is:\n");
     conversion(n,8);
     printf("\n");
      printf("the hexadecimal is\n");
      conversion(n,16);

}
