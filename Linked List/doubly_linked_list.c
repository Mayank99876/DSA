// call by reference
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
typedef struct node
{
    int info;
    struct node *next, *prev;
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
    newnode->prev = NULL;
    return newnode;
}

void traverse(Node **p_start)
{
    Node *ptr = *p_start;
    while (ptr != NULL)
    {
        printf("%d\t", ptr->info);
        ptr = ptr->next;
    }
    printf("\n");
}

void addfirst(Node **p_start, int item)
{
    Node *newnode;
    if (newnode == NULL)
    {
        printf("Overflow...");
        return;
    }
    newnode = getNode(item);

    if (*p_start == NULL)
    {
        newnode->next = NULL;
        *p_start = newnode;
    }
    else
    {
        newnode->next = *p_start;
        (*p_start)->prev = newnode;
        *p_start = newnode;
    }
}

void addlast(Node **p_start, int item)
{
    Node *newnode, *ptr;
    newnode = getNode(item);
    if (newnode == NULL)
    {
        printf("Overflow...");
        return;
    }
    if (*p_start == NULL)
        *p_start = newnode;
    else
    {
        ptr = *p_start;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = newnode;
        newnode->prev = ptr;
    }
}

void addafter(Node **p_start, int numb, int item)
{
    Node *newnode, *ptr;
    newnode = getNode(item);
    ptr = *p_start;
    while (ptr != NULL && ptr->info != numb)
    {
        ptr = ptr->next;
    }
    if (ptr == NULL)
    {
        printf("Number not found.");
        return;
    }
    if (newnode == NULL)
    {
        printf("Overflow...");
        return;
    }
    else
    {
        newnode->next = ptr->next;
        if (ptr->next != NULL)
            ptr->next->prev = newnode;
        ptr->next = newnode;
        newnode->prev = ptr;
    }
}

void addbefore(Node **p_start, int numb, int item)
{
    Node *newnode, *ptr, *preptr;
    preptr = NULL;
    ptr = *p_start;
    while (ptr != NULL && ptr->info != numb)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    if (ptr == NULL)
    {
        printf("Number not found.");
    }
    newnode = getNode(item);
    if (newnode == NULL)
    {
        printf("Overflow...");
        return;
    }
    else if (ptr == *p_start)
    {
        addfirst(p_start, item);
    }
    else
    {

        newnode->next = ptr;
        ptr->prev = newnode;
        preptr->next = newnode;
        newnode->prev = preptr;
    }
}

void delnode(Node **p_start, int item)
{
    Node *newnode, *ptr, *preptr;
    preptr = NULL;
    ptr = *p_start;
    while (ptr != NULL && ptr->info != item)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    if (ptr == NULL)
    {
        printf("Number not found.");
    }
    else if (ptr == *p_start)
    {
        *p_start = (*p_start)->next;
    }
    else
    {
        preptr->next = ptr->next;
        if (ptr->next != NULL)
            ptr->next->prev = preptr;
    }
    free(ptr);
}

void freeall(Node **p_start)
{
    Node *ptr;
    while (*p_start != NULL)
    {
        ptr = *p_start;
        *p_start = (*p_start)->next;
        free(ptr);
    }
}