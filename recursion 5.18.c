#include<stdio.h>//input a line of text and display in reverse order using recursion without storing it in an array
#include<string.h>
void string_input()
{
    char c;
    scanf("%c",&c);
    if(c!='\n')//if it is new line character then we must start printing the text
    {
        string_input();
        printf("%c",c);

    }
    else
        return ;
}
int main()
{
    string_input();
    return 0;
}
