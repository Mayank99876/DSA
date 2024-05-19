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
Node *addlast(Node *, int);
Node *merge(Node *, Node *);
Node *getNode(int);

int main()
{
    Node *l1 = NULL, *l2 = NULL, *l3 = NULL;
    l1 = addlast(l1, 1);
    l1 = addlast(l1, 3);
    l1 = addlast(l1, 5);
    l1 = addlast(l1, 10);
    l1 = addlast(l1, 20);
    l2 = addlast(l2, 2);
    l2 = addlast(l2, 4);
    l2 = addlast(l2, 6);
    l2 = addlast(l2, 7);
    l3 = merge(l1, l2);
    traverse(l3);
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

Node *merge(Node *l1, Node *l2)
{
    Node *l3 = NULL;
    while (l1 != NULL && l2 != NULL)
    {
        if (l1->info < l2->info)
        {
            l3 = addlast(l3, l1->info);
            l1 = l1->next;
        }
        else
        {
            l3 = addlast(l3, l2->info);
            l2 = l2->next;
        }
    }

    // remaining of l1
    while (l1 != NULL)
    {
        l3 = addlast(l3, l1->info);
        l1 = l1->next;
    }
    // remaining of l2
    while (l2 != NULL)
    {
        l3 = addlast(l3, l2->info);
        l2 = l2->next;
    }
    return l3;
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