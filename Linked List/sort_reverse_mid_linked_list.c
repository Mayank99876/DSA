// call by value
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
typedef struct node
{
    int info;
    struct node *next;
} Node;
void traverse(Node **);
void addlast(Node **, int);
void sort(Node **);
void reverse(Node **);
Node *middle_node(Node **);
void freeall(Node **);
Node *getNode(int);

int main()
{
    Node *start;
    start = NULL;
    addlast(&start, 5);
    addlast(&start, 4);
    addlast(&start, 1);
    addlast(&start, 3);
    addlast(&start, 2);
    printf("List is : \n");
    traverse(&start); // 5 4 1 3 2
    sort(&start);
    printf("Sorted list is: \n");
    traverse(&start); // 1 2 3 4 5
    reverse(&start);
    printf("Reverse list is: \n");
    traverse(&start); // 5 4 3 2 1
    Node *mid = middle_node(&start);
    if (mid == NULL)
        printf("List is empty...");
    else
        printf("Middle node of list is %d", mid->info);
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

void addlast(Node **p_start, int item)
{
    Node *newnode = getNode(item);
    if (*p_start == NULL)
        *p_start = newnode;
    else
    {
        Node *ptr = *p_start;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = newnode;
    }
}

void sort(Node **p_start)
{
    Node *p1, *p2;
    for (p1 = *p_start; p1->next != NULL; p1 = p1->next)
        for (p2 = p1->next; p2 != NULL; p2 = p2->next)
            if (p1->info > p2->info)
            {
                int t = p1->info;
                p1->info = p2->info;
                p2->info = t;
            }
}

void reverse(Node **p_start)
{
    Node *p1, *p2, *p3;
    p3 = *p_start;
    p2 = NULL;
    while (p3 != NULL)
    {
        p1 = p2;
        p2 = p3;
        p3 = p3->next;
        p2->next = p1;
    }
    *p_start = p2;
}

Node *middle_node(Node **p_start)
{
    Node *slow, *fast;
    if (*p_start == NULL)
        return NULL;
    slow = *p_start;
    fast = *p_start;
    while (fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
        if (fast->next != NULL)
            fast = fast->next;
    }
    return slow;
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