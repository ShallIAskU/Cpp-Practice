//Program to implement stack
#include<stdio.h>
#define SIZE 10
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

int main()
{
    int num,choice;

    struct stack stk1;
    stk1.push=push;
    stk1.pop=pop;
    stk1.display=display;
    stk1.top=-1;

    char sym;

    struct stack_char stk_char;
    stk_char.top = -1;
    stk_char.push_char=push_char;
    stk_char.pop_char=pop_char;
    stk_char.display_char=display_char;

    printf ("STACK OPERATION\n");
    while (1)
    {
        printf ("------------------------------------------\n");
        printf ("      1    PUSH INT                          \n");
        printf ("      2    POP  INT                          \n");
        printf ("      3    DISPLAY  INT                      \n");
        printf ("      4    PUSH CHAR                         \n");
        printf ("      5    POP  CHAR                         \n");
        printf ("      6    DISPLAY  CHAR                     \n");
        printf ("      7    EXIT                              \n");
        printf ("------------------------------------------\n");

        printf ("Enter your choice:");
        scanf    ("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter a number to be pushed:");
            scanf("%d", &num);
            stk1.push(num,&stk1);
            break;
        case 2:
            stk1.pop(&stk1);
            break;
        case 3:
            stk1.display(&stk1);
            break;
        case 4:
            printf("Character to be pushed:");
            scanf(" %c",&sym);
            stk_char.push_char(sym,&stk_char);
            break;
        case 5:
            stk_char.pop_char(&stk_char);
            break;
        case 6:
            stk_char.display_char(&stk_char);
        case 7:
            return 0;
        default:
            printf("Wrong choice, try again!\n");
        }
    }
}

//Function to push an element into the stack
void push(int num,struct stack *sta)
{
    if(sta->top == SIZE-1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        sta->top=sta->top + 1;
        sta->arr[sta->top]=num;
    }
}
//Function to pop an element from the stack
void pop(struct stack *sta)
{
    if(sta->top==-1)
    {
        printf("The stack is empty\n");
    }
    else
    {
         sta->top=sta->top - 1;
    }
}
//Function to display the contents in the Stack
void display(struct stack *sta)
{
    if(sta->top==-1)
    {
        printf("The stack is empty\n");
    }
    else
    {
         for(int i=sta->top; i>-1;i--)
         {
             printf("%d",sta->arr[i]);
         }
	printf("\n");
    }
}
void push_char(char sym,struct stack_char *sta2)
{
    if(sta2->top==SIZE-1)
        printf("STACK OVERFLOW");
    else
    {
        sta2->top=sta2->top+1;
        sta2->array[sta2->top]=sym;
    }
}
void pop_char(struct stack_char *sta2)
{
    if(sta2->top==-1)
        printf("Stack is empty");
    else
    {
        sta2->top=sta2->top-1;
    }
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

