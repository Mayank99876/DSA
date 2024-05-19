#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int info;
    struct node *next;
} Node;

void addq(Node **, Node **, int);
int delq(Node **, Node **);
void display(Node **);
Node *getNode(int);
int main()
{
    int ch, item;
    Node *front;
    Node *rear;
    front = rear = NULL;
    do
    {
        printf("\t\t\tMAIN MENU\n");
        printf("********************\n");
        printf("1. Add a item in queue\n");
        printf("2. Delete a item in queue\n");
        printf("3. Display the queue\n");
        printf("4. Exit.\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter item to add: ");
            scanf("%d", &item);
            addq(&front, &rear, item);
            break;
        case 2:
            item = delq(&front, &rear);
            if (item != 0)
                printf("Deleted item is: %d", item);
            break;
        case 3:
            display(&front);
        case 4:
            break;
        default:
            printf("Invalid Input. Try again!");
        }
    } while (ch != 4);
    return 0;
}

void addq(Node **p_front, Node **p_rear, int item)
{
    Node *newnode = getNode(item);
    if (newnode == NULL)
    {
        printf("OVERFLOW...");
        return;
    }
    else if (*p_front == *p_rear)
    {
        *p_front = *p_rear = newnode;
    }
    else
    {
        (*p_front)->next = newnode;
        *p_rear = newnode;
    }
}

int delq(Node **p_front, Node **p_rear)
{
    Node *ptr;
    int item;
    ptr = *p_front;
    if (*p_front == *p_rear)
    {
        *p_front = *p_rear = NULL;
    }
    else
        *p_front = (*p_front)->next;
    item = ptr->info;
    free(ptr);
    return item;
}

void display(Node **p_front)
{
    Node *ptr = *p_front; // Start from the top of the queue
    printf("Queue elements: ");
    while (ptr != NULL)
    {
        printf("%d ", ptr->info);
        ptr = ptr->next;
    }
    printf("\n");
}
Node *getNode(int item)
{
    Node *t;
    t = (struct node *)malloc(sizeof(struct node));
    t->info = item;
    t->next = NULL;
    return t;
}