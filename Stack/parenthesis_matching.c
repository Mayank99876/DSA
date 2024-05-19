#include <stdio.h>
#include <stdlib.h>
#define MAXSTK 100
typedef struct Stack
{
    int data[MAXSTK];
    int top;
} Stack;

void push(Stack *, int); // call by reference
int pop(Stack *);        // call by reference
int peep(Stack);         // call by value
void display(Stack);     // call by value
int isEmpty(Stack);
int isValid(char[]);

int main()
{
    int ans;
    char eq[50];
    printf("Enter equation: ");
    gets(eq);
    ans = isValid(eq);
    if (ans == 1)
        printf("Expression is valid.");
    else
        printf("Expression is not valid.");
    return 0;
}

void push(Stack *p, int item)
{
    if (p->top == MAXSTK - 1)
    {
        printf("OVERFLOW...\n");
        return;
    }
    p->top++;
    p->data[p->top] = item;
}

int pop(Stack *p)
{
    int item;
    if (p->top == -1)
    {
        printf("UNDERFLOW...\n");
        return -1;
    }
    item = p->data[p->top];
    p->top--;
    return item;
}

int peep(Stack s1)
{
    int item;
    if (s1.top == -1)
    {
        printf("UNDERFLOW...\n");
        return -1;
    }
    item = s1.data[s1.top];
    return item;
}

void display(Stack s1)
{
    for (int i = s1.top; i >= 0; i--)
    {
        printf("%d\n", s1.data[i]);
    }
}

int isEmpty(Stack s1)
{
    return s1.top == -1 ? 1 : 0;
}

int isValid(char eq[])
{
    Stack s1;
    int i = 0;
    s1.top = -1;
    while (eq[i] != '\0')
    {
        if (eq[i] == '(')
        {
            push(&s1, eq[i]);
        }
        else if (eq[i] == ')')
        {
            if (isEmpty(s1))
                return -1;
            else
                pop(&s1);
        }
        i++;
    }
    if (isEmpty(s1))
        return 1;
    else
        return -1;
}