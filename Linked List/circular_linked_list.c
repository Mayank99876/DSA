// call by reference
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
typedef struct node
{
    int info;
    struct node *next;
} Node;
void traverse(Node **);
void addfirst(Node **, int);
void addlast(Node **, int);
void addafter(Node **, int, int);
void addbefore(Node **, int, int);
void delnode(Node **, int);
void freeall(Node **);
Node *getNode(int);

int main()
{
    Node *start = NULL;
    int ch, item, numb;
    do
    {
        // system("cls");
        printf("1. Addfirst\n2. AddLast\n3. Addafter\n4. Addbefore\n5. Delnode\n6. Transverse\n 7. Exit\n Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter value to add first:");
            scanf("%d", &item);
            addfirst(&start, item);
            break;
        case 2:
            printf("Enter value to add last: ");
            scanf("%d", &item);
            addlast(&start, item);
            break;
        case 3:
            printf("Enter number after which you want to enter and add: ");
            scanf("%d%d", &numb, &item);
            addafter(&start, numb, item);
            break;
        case 4:
            printf("Enter number before which you want to enter and add: ");
            scanf("%d%d", &numb, &item);
            addbefore(&start, numb, item);
            break;
        case 5:
            printf("Enter item to delete: ");
            scanf("%d", &item);
            delnode(&start, item);
            break;
        case 6:
            traverse(&start);
            break;
        case 7:
            freeall(&start);
            break;
        default:
            printf("Invalid choice.");
        }
        // getch();
    } while (ch != 7);
    return 0;
}

Node *getNode(int item)
{
    Node *newnode;
    newnode = (Node *)malloc(sizeof(Node));
    if (newnode == NULL)
    {
        printf("Overflow...");
        exit(0);
    }
    newnode->info = item;
    newnode->next = NULL;
    return newnode;
}

void traverse(Node **p_tail)
{
    Node *ptr = (*p_tail)->next;
    if (*p_tail == NULL)
        return;
    do
    {
        printf("%d\t", ptr->info);
        ptr = ptr->next;
    } while (ptr != (*p_tail)->next);
    printf("\n");
}

void addfirst(Node **p_tail, int item)
{
    Node *newnode;
    if (newnode == NULL)
    {
        printf("Overflow...");
        return;
    }
    newnode = getNode(item);

    if (*p_tail == NULL)
    {
        newnode->next = newnode;
        *p_tail = newnode;
    }
    else
    {
        newnode->next = (*p_tail)->next;
        (*p_tail)->next = newnode;
    }
}

void addlast(Node **p_tail, int item)
{
    Node *newnode;
    newnode = getNode(item);
    if (newnode == NULL)
    {
        printf("Overflow...");
        return;
    }
    if (*p_tail == NULL)
    {
        newnode->next = newnode;
        *p_tail = newnode;
    }

    else
    {
        newnode->next = (*p_tail)->next;
        (*p_tail)->next = newnode;
        *p_tail = newnode;
    }
}

void addafter(Node **p_tail, int numb, int item)
{
    Node *newnode, *ptr;
    newnode = getNode(item);
    if (*p_tail == NULL)
    {
        printf("Number not found...");
        return;
    }
    ptr = (*p_tail)->next;
    do
    {
        ptr = ptr->next;
    } while (ptr != (*p_tail)->next && ptr->info != numb);
    if (ptr->info != numb)
    {
        printf("Number not found.");
        return;
    }
    if (newnode == NULL)
    {
        printf("Overflow...");
        return;
    }
    newnode->next = ptr->next;
    ptr->next = newnode;
    if (ptr == *p_tail)
        *p_tail = newnode;
}

void addbefore(Node **p_tail, int numb, int item)
{
    Node *newnode, *ptr, *preptr;
    if (*p_tail == NULL)
    {
        printf("Overflow...");
        return;
    }
    preptr = *p_tail;
    ptr = (*p_tail)->next;
    do
    {
        preptr = ptr;
        ptr = ptr->next;
    } while (ptr != (*p_tail)->next && ptr->info != numb);
    if (ptr->info != numb)
    {
        printf("Number not found.");
    }
    newnode = getNode(item);
    if (newnode == NULL)
    {
        printf("Overflow...");
        return;
    }

    preptr->next = newnode;
    newnode->next = ptr;
}

void delnode(Node **p_tail, int item)
{
    Node *newnode, *ptr, *preptr;
    preptr = *p_tail;
    ptr = (*p_tail)->next;
    while (ptr != NULL && ptr->info != item)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    if (ptr == NULL)
    {
        printf("Number not found.");
    }
    else if (ptr == *p_tail)
    {
        *p_tail = (*p_tail)->next;
    }
    else
    {
        preptr->next = ptr->next;
    }
    free(ptr);
}

void freeall(Node **p_tail)
{
    Node *ptr;
    do
    {
        ptr = (*p_tail)->next;
        if ((*p_tail)->next == ptr->next)
            *p_tail = NULL;
        else
            (*p_tail)->next = ptr->next;
        free(ptr);
    } while (*p_tail != NULL);
}