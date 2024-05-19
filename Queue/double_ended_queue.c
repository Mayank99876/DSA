#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int info;
    struct node *prev, *next;
} Node;

void addleft(Node **, Node **, int);
void addright(Node **, Node **, int);
int delleft(Node **, Node **);
int delright(Node **, Node **);
Node *getNode(int);

int main()
{
    Node *left = NULL, *right = NULL;
    addleft(&left, &right, 10);
    addleft(&left, &right, 9);
    addleft(&left, &right, 8);
    addright(&left, &right, 11);
    addright(&left, &right, 12);
    printf("Leftmost element is %d\n", delleft(&left, &right));
    printf("Rightmost element is %d", delright(&left, &right));
    return 0;
}

void addleft(Node **p_left, Node **p_right, int item)
{
    Node *newnode = getNode(item);
    if (*p_left == NULL)
    {
        *p_left = *p_right = newnode;
    }
    else
    {
        (*p_left)->prev = newnode;
        newnode->next = *p_left;
        *p_left = newnode;
    }
}

void addright(Node **p_left, Node **p_right, int item)
{
    Node *newnode = getNode(item);
    if (*p_right == NULL)
    {
        *p_left = *p_right = newnode;
    }
    else
    {
        (*p_right)->next = newnode;
        newnode->prev = *p_right;
        *p_right = newnode;
    }
}

int delleft(Node **p_left, Node **p_right)
{
    Node *ptr;
    int item;
    if (*p_left == NULL)
    {
        printf("Queue is empty...");
        return -1;
    }
    ptr = *p_left;
    if (*p_left == *p_right)
    {
        *p_left = *p_right = NULL;
    }
    else
    {
        *p_left = ptr->next;
        (*p_left)->prev = NULL;
    }
    item = ptr->info;
    free(ptr);
    return item;
}

int delright(Node **p_left, Node **p_right)
{
    Node *ptr;
    int item;
    if (*p_right == NULL)
    {
        printf("Queue is empty...");
        return -1;
    }
    ptr = *p_right;
    if (*p_left == *p_right)
    {
        *p_left = *p_right = NULL;
    }
    else
    {
        *p_right = ptr->prev;
        (*p_left)->next = NULL;
    }
    item = ptr->info;
    free(ptr);
    return item;
}

Node *getNode(int item)
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->info = item;
    newnode->next = newnode->prev = NULL;
    return newnode;
}
