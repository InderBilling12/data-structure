#include<stdio.h>
int main()
{
long int n,nn,i=0;
scanf("%d",&n);
nn=n;
int num_factors = 1;
for (i = 2; i * i <= nn; ++i) // for each number i up until the square root of the given number
{
   int    power = 0; // suppose the power i appears at is 0
    while (n % i == 0) // while we can divide n by i
    {
        n = n / i; // divide it, thus ensuring we'll only check prime factors
        ++power; // increase the power i appears at
    }
    num_factors = num_factors * (power + 1); // apply the formula
}

if (n > 1) // will happen for example for 14 = 2 * 7
{
    num_factors = num_factors * 2 ;// n is prime, and its power can only be 1, so multiply the number of factors by 2
}
printf("%d",num_factors);
}
