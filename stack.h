#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include<stdio.h>
#define SIZE 20

struct stack_char
{
    int top;
    int array[SIZE];
    void(*push_char)(int,struct stack_char*);
    int(*pop_char)(struct stack_char*);
    void(*display_char)(struct stack_char*);
};

//to convert infix to postfix
struct stack_char stk_char;

void push_char(int,struct stack_char*);
int pop_char(struct stack_char*);
void display_char(struct stack_char*);

void push_char(int sym,struct stack_char *sta2)
{
    printf("push element : %d\n",sym);
    if(sta2->top==SIZE-1)
        printf("STACK OVERFLOW");
    else
    {
        sta2->top=sta2->top+1;
        sta2->array[sta2->top]=sym;
    }
}
int pop_char(struct stack_char *sta2)
{
    int temp_top;
    if(sta2->top==-1)
        printf("Stack is empty\n");
    else
    {
        temp_top=sta2->array[sta2->top];
        sta2->top=sta2->top-1;
        printf("poped element: %d\n",temp_top);
    }
    return(temp_top);

}
void display_char(struct stack_char *sta2)
{
    if(sta2->top==-1)
    {
        printf("The stack is empty\n");
    }
    else
    {
         for(int i=sta2->top; i>-1;i--)
         {
             printf(" %c",sta2->array[i]);
         }
	printf("\n");
    }
}

#endif // STACK_H_INCLUDED
