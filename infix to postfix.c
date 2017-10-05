#include<stdio.h>
#include<string.h>
#include<math.h>
#define max 50
#define BLANK ' '
#define TAB '\t'
int stack[max];
char infix[max],postfix[max];
int top=0;
void push(int item)
{
    if(top==max)//overflow condition
        printf("stack overflow occurred \n");
    else
    stack[++top]=item;//increment top and push item
}
int pop()
{
    int item;
       // if(top==0)//empty stack
        //printf("underflow condition\n");
    //else
    {
        item=stack[top];
        top=top-1;//decrease top by 1
    }
    return item;
}
int top_()
{
     if(top==0)//empty stack
       return 1000;
        else
        return stack[top];
}
int isEMPTY()
{
   return top;
}
int priority(char symbol)
{
      switch(symbol)
    {
    case '(':
        return 0;
         case '^':
             return 3;
              case '*':
              case '/':
              case '%':
                return 2;
              case '+':
              case '-':
              return 1;
              default ://means agar operand huya toh
                return 0;
     }
}
void conversion()//we need not to pass infix as it is global
{
    char symbol,next;
    int x=strlen(infix),i=0,j=0;
     for(i=0;i<x;i++)
     {//we assume that our expression contaoin only () this type of parenthesis
                  symbol=infix[i];
         if(!(symbol==BLANK||symbol==TAB))//agar white space huya to loop mein jaane ki zaroorat nahi
         {
             switch(symbol)
             {
             case '(':
                push(symbol);
                break;
             case ')'://pop until we don't get ')'
                while((next=pop())!='(')
                       postfix[j++]=next;//pop krke postfix array me send krdo
                       break;
             case'^':
             case '*':
             case '/':
             case'+':
             case '-':
             case '%':
                //abhi priority ke hisaab se isko push krna hain
                while(top>0&& (priority(symbol)<=priority(stack[top])))//top wale ki precedence check kro
                    postfix[j++]=pop();
                push(symbol);
                break;
             default:
                   postfix[j++]=symbol;//agar operand hain toh
             }
         }

     }
     while(top!=0)
        postfix[j++]=pop();//jo rehte hain sabhi ko pop krdo
        postfix[j]='\0';
}
void evaluation()
{
    int a,b,result,temp;
    int i=0;
    for(i=0;i<strlen(postfix);i++)
    {
        if(postfix[i]<='9' && postfix[i]>='0')
                push(postfix[i]-'0');
        else
        {
            a=pop();
            b=pop();
            switch(postfix[i])
            {
            case '+':
                temp=b+a;
                break;
                  case '-':
                temp=b-a;
                break;
                  case '*':
                temp=b*a;
                break;
                  case '/':
                temp=b/a;
                break;
                  case '%':
                temp=b%a;
                break;
                  case '^':
                temp=pow(b,a);
                break;
            }
            push(temp);
        }
    }
    result=pop();
    printf("result=%d\n",result);
}

int main()
{    int i=0;
       printf("enter the infix expression:\n");
       gets(infix);
       conversion();
       evaluation();
      printf("%s",postfix);
}
