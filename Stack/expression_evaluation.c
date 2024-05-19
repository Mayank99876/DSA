#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h> // For ceil function

#define MAXSTK 100

typedef struct Stack
{
    char data[MAXSTK];
    int top;
} Stack;

void push(Stack *, char); // call by reference
char pop(Stack *);        // call by reference
int evalPost(char[]);
int evalPre(char[]);
int eval(char, int, int);
int isOperator(char);

int main()
{
    char postfix[50], prefix[50];
    int ans;
    printf("Enter Postfix expression: ");
    fgets(postfix, 50, stdin); // Using fgets instead of gets
    ans = evalPost(postfix);
    printf("Postfix Answer is : %d\n", ans); // Added newline character
    printf("Enter Prefix expresssion: ");
    fgets(prefix, 50, stdin); // Using fgets instead of gets
    ans = evalPre(prefix);
    printf("Prefix Answer is : %d\n", ans); // Changed "Postfix" to "Prefix"
    return 0;
}

int evalPost(char postfix[])
{
    Stack s1;
    s1.top = -1;
    // Scan left to right
    int i = 0, ans, a, b;
    while (postfix[i] != '\0')
    {
        if (isOperator(postfix[i]))
        { // operator
            a = pop(&s1);
            b = pop(&s1);
            ans = eval(postfix[i], b, a);
            push(&s1, ans);
        }
        else
        { // operand
            push(&s1, postfix[i] - '0');
        }
        i++;
    }
    ans = pop(&s1);
    return ans;
}

int evalPre(char prefix[])
{
    Stack s1;
    s1.top = -1;
    // Scan right to left
    int i = strlen(prefix) - 1;
    int ans1, a, b;
    while (i >= 0)
    {
        if (isOperator(prefix[i]))
        { // operator
            a = pop(&s1);
            b = pop(&s1);
            ans1 = eval(prefix[i], a, b); // Corrected order of operands
            push(&s1, ans1);
        }
        else
        { // operand
            push(&s1, prefix[i] - '0');
        }
        i--;
    }
    ans1 = pop(&s1);
    return ans1;
}

int eval(char op, int x, int y)
{
    switch (op)
    {
    case '+':
        return x + y;
    case '-':
        return x - y;
    case '*':
        return x * y;
    case '/':
        if (y != 0)
            return x / y;
        else
        {
            printf("Error: Division by zero\n");
            exit(EXIT_FAILURE);
        }
    case '^':
        return ceil(pow(x, y));
    default:
        return 0;
    }
}

int isOperator(char op)
{
    if (op == '+' || op == '-' || op == '*' || op == '/' || op == '^')
        return 1;
    else
        return 0;
}

void push(Stack *p, char item)
{
    if (p->top == MAXSTK - 1)
    {
        printf("OVERFLOW...\n");
        return;
    }
    p->top++;
    p->data[p->top] = item;
}

char pop(Stack *p)
{
    char item;
    if (p->top == -1)
    {
        printf("UNDERFLOW...\n");
        return '\0'; // Return a default value in case of underflow
    }
    item = p->data[p->top];
    p->top--;
    return item;
}