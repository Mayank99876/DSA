#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int info;
    struct Node *next;
} Node;

Node *getNode(int);
void push(Node **, int);
int pop(Node **);
int peep(Node **);
void display(Node **);
int isEmpty(Node **);

int main()
{
    Node *top = NULL;
    int ch, item;
    do
    {
        printf("1. push 2. pop 3. peep 4. display 5. exit\n Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter item to push: ");
            scanf("%d", &item);
            push(&top, item);
            break;
        case 2:
            if (!isEmpty(&top))
            {
                item = pop(&top);
                printf("Popped item is %d\n", item);
            }
            else
                printf("Stack is empty...");
            break;

        case 3:
            if (!isEmpty(&top))
            {
                item = peep(&top);
                printf("Peeped item is %d\n", item);
            }
            else
                printf("List is empty...");
            break;

        case 4:
            display(&top);
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

Node *getNode(int item)
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->info = item;
    newnode->next = NULL;
    return newnode;
}

void push(Node **p_top, int item)
{
    Node *newnode = getNode(item);
    if (newnode == NULL)
    {
        printf("OVERFLOW...\n");
        return;
    }
    newnode->next = *p_top;
    *p_top = newnode;
}

int pop(Node **p_top)
{
    Node *ptr;
    int item;
    if (*p_top == NULL)
    {
        printf("UNDERFLOW...");
        return -1;
    }
    ptr = *p_top;
    *p_top = ptr->next;
    item = ptr->info;
    free(ptr);
    return item;
}

int peep(Node **p_top)
{
    Node *ptr;
    int item;
    if (*p_top == NULL)
    {
        printf("UNDERFLOW...");
        return -1;
    }
    ptr = *p_top;
    item = ptr->info;
    return item;
}

void display(Node **p_top)
{
    Node *ptr = *p_top; // Start from the top of the stack
    printf("Stack elements: ");
    while (ptr != NULL)
    {
        printf("%d ", ptr->info);
        ptr = ptr->next;
    }
    printf("\n");
}


int isEmpty(Node **p_top)
{
    return *p_top == NULL ? 1 : 0;
}