#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include"stack.h"
#define MAX 100


int main()
{
    char infix[MAX];
    char postfix[MAX]={0};
    printf("Enter the infix expression:\n");
    scanf("%s",infix);
    printf("The corresponding infix expression is: %s \n",infix);



    stk_char.top = -1;
    stk_char.push_char=push_char;
    stk_char.pop_char=pop_char;
    stk_char.display_char=display_char;

    infixtopostfix(infix,postfix);
    printf("The corresponding postfix expression is: %s \n",postfix);
    return 0;
}
int getpriority(char x)
{

    printf("Inside get priority %c \n", x);

    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/' || x == '%')
        return 2;
    if(x == '^')
        return 3;
}

void infixtopostfix(char source[],char target[])
{
    int i=0,j=0;
    char temp;
    strcpy(target,"");
    int prio1=0, prio2=0;
    while(source[i] != '\0')
    {
        if(source[i] == '(')
        {
            push_char(source[i],&stk_char);
            i++;
        }
        else if(source[i]==')')
        {
            while((stk_char.top != -1)&&(stk_char.array[stk_char.top]!='('))
            {
                target[j]= pop_char(&stk_char);
                j++;
            }
            if(stk_char.top == -1)
            {
                printf("Incorrect expression");
                exit(1);
            }
            temp=pop_char(&stk_char);
            i++;
        }
        else if(isdigit(source[i])|| isalpha(source[i]))
        {
            target[j]=source[i];
            j++;
            i++;
        }
        else if(source[i] == '+'|| source[i] == '-' || source[i] == '*' || source[i] == '/' || source[i] == '^' || source[i] == '%')
        {
            while (stk_char.top != -1 && (getpriority(source[i]) <= getpriority(stk_char.array[stk_char.top])))
                {
                    target[j] = pop_char(&stk_char);
                    j++;
                }
            push_char(source[i],&stk_char);
            i++;
        }
        else
        {
            printf("Incorrect element in expression\n");
            exit(1);
        }
    }
        while((stk_char.top!=-1)&&(stk_char.array[stk_char.top]!='('))
        {
            target[j] = pop_char(&stk_char);
            j++;
        }
        target[j]='\0';

}





