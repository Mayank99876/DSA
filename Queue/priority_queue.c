#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int info;
    int priority;
    struct node *next;
} Node;

void push(Node **, int, int);
int pop(Node **);
int peep(Node *);
void display(Node *);

int main()
{
    int ch, item, priority;
    Node *start = NULL;
    do
    {
        printf("\t\t\tMAIN MENU\n");
        printf("\t\t\t1.push\n");
        printf("\t\t\t2.pop\n");
        printf("\t\t\t3.peep\n");
        printf("\t\t\t4.display queue\n");
        printf("\t\t\t5.exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter item and priority to push in queue: ");
            scanf("%d%d", &item, &priority);
            push(&start, item, priority);
            break;
        case 2:
            item = pop(&start);
            if (item != 0)
            {
                printf("Popped item is: %d", item);
            }
            else
                printf("Queue is empty...");
            break;
        case 3:
            item = peep(start);
            if (item != 0)
            {
                printf("Peep item is: %d", item);
            }
            else
                printf("Queue is empty...");
            break;
        case 4:
            display(start);
            break;
        case 5:
            break;
        default:
            printf("Invaid choice!");
            break;
        }

    } while (ch != 5);
    return 0;
}

void push(Node **p, int item, int priority)
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->info = item;
    newnode->priority = priority;
    if (*p == NULL || priority > (*p)->priority)
    {
        newnode->next = *p;
        *p = newnode;
    }
    else
    {
        Node *preptr = *p;
        Node *ptr = (*p)->next;
        while (ptr != NULL && priority <= (ptr)->priority)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        newnode->next = ptr;
        preptr->next = newnode;
    }
}

int pop(Node **p)
{
    int item;
    Node *ptr;
    ptr = *p;
    if (ptr == NULL)
    {
        printf("List is empty...");
        return -1;
    }
    else
    {
        *p = ptr->next;
    }
    item = ptr->info;
    free(ptr);
    return item;
}

int peep(Node *start)
{
    int item;
    if (start == NULL)
    {
        printf("List is empty...");
        return -1;
    }
    item = start->info;
    return item;
}

void display(Node *start)
{
    Node *ptr = start;
    printf("Queue is: ");
    while (ptr != NULL)
    {
        printf("%d\t", ptr->info);
        ptr = ptr->next;
    }
    printf("\n");
}