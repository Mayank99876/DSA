#include <stdio.h>
#include <stdlib.h>
#define MAXSTK 5
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

int main()
{
    Stack s1; // Stack created
    int ch, item;
    s1.top = -1; // stack is empty
    do
    {
        printf("1. push 2. pop 3. peep 4. display 5. exit\n Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter item to push: ");
            scanf("%d", &item);
            push(&s1, item);
            break;
        case 2:
            if (!isEmpty(s1))
            {
                item = pop(&s1);
                printf("Popped item is %d\n", item);
            }
            else
                printf("Stack is empty...");
            break;

        case 3:
            if (!isEmpty(s1))
            {
                item = peep(s1);
                printf("Peeped item is %d\n", item);
            }
            else
                printf("List is empty...");
            break;

        case 4:
            display(s1);
            break;
        case 5:
            break;
        default:
            printf("\nInvalid input...");
            break;
        }
    } while (ch != 5);
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