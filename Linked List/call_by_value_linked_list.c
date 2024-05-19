// call by value
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
typedef struct node
{
    int info;
    struct node *next;
} Node;
void traverse(Node *);
Node *addfirst(Node *, int);
Node *addlast(Node *, int);
Node *addafter(Node *, int, int);
Node *addbefore(Node *, int, int);
Node *delnode(Node *, int);
Node *freeall(Node *);
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
            start = addfirst(start, item);
            break;
        case 2:
            printf("Enter value to add last: ");
            scanf("%d", &item);
            start = addlast(start, item);
            break;
        case 3:
            printf("Enter number after which you want to enter and add: ");
            scanf("%d%d", &numb, &item);
            start = addafter(start, numb, item);
            break;
        case 4:
            printf("Enter number before which you want to enter and add: ");
            scanf("%d%d", &numb, &item);
            start = addbefore(start, numb, item);
            break;
        case 5:
            printf("Enter item to delete: ");
            scanf("%d", &item);
            start = delnode(start, item);
            break;
        case 6:
            traverse(start);
            break;
        case 7:
            start = freeall(start);
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

void traverse(Node *start)
{
    Node *ptr = start;
    while (ptr != NULL)
    {
        printf("%d\t", ptr->info);
        ptr = ptr->next;
    }
    printf("\n");
}

Node *addfirst(Node *start, int item)
{
    Node *newnode = getNode(item);
    newnode->next = start;
    start = newnode;
    return start;
}

Node *addlast(Node *start, int item)
{
    Node *newnode = getNode(item);
    if (start == NULL)
        start = newnode;
    else
    {
        Node *ptr = start;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = newnode;
    }
    return start;
}

Node *addafter(Node *start, int numb, int item)
{
    Node *newnode, *ptr;
    ptr = start;
    while (ptr != NULL && ptr->info != numb)
    {
        ptr = ptr->next;
    }
    if (ptr == NULL)
    {
        printf("Number not found after which you want to add.");
    }
    else
    {
        newnode = getNode(item);
        newnode->next = ptr->next;
        ptr->next = newnode;
    }
    return start;
}

Node *addbefore(Node *start, int numb, int item)
{
    Node *newnode, *ptr, *preptr;
    preptr = NULL;
    ptr = start;
    while (ptr != NULL && ptr->info != numb)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    if (ptr == NULL)
    {
        printf("Number not found.");
    }
    else if (ptr == start)
    {
        start = addfirst(start, item);
    }
    else
    {
        newnode = getNode(item);
        newnode->next = ptr;
        preptr->next = newnode;
    }
    return start;
}

Node *delnode(Node *start, int item)
{
    Node *newnode, *ptr, *preptr;
    preptr = NULL;
    ptr = start;
    while (ptr != NULL && ptr->info != item)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    if (ptr == NULL)
    {
        printf("Number not found.");
    }
    else if (ptr == start)
    {
        start = start->next;
    }
    else
    {
        preptr->next = ptr->next;
    }
    free(ptr);
    return start;
}

Node *freeall(Node *start)
{
    Node *ptr;
    while (start != NULL)
    {
        ptr = start;
        start = start->next;
        free(ptr);
    }
}