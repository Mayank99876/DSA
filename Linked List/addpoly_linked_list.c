#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
typedef struct node
{
    int coeff, pow;
    struct node *next;
} Node;
void traverse(Node *);
Node *addlast(Node *, int, int);
Node *add_poly(Node *, Node *);
Node *getNode(int, int);

int main()
{
    Node *l1 = NULL, *l2 = NULL, *l3 = NULL;
    l1 = addlast(l1, 5, 3);
    l1 = addlast(l1, 4, 2);
    l1 = addlast(l1, 7, 1);
    l1 = addlast(l1, 3, 0);
    l2 = addlast(l2, 8, 3);
    l2 = addlast(l2, 3, 1);
    l2 = addlast(l2, 2, 0);
    l3 = add_poly(l1, l2);
    traverse(l3);
    return 0;
}

Node *getNode(int c, int p)
{
    Node *newnode;
    newnode = (Node *)malloc(sizeof(Node));
    if (newnode == NULL)
    {
        printf("Overflow...");
        exit(0);
    }
    newnode->coeff = c;
    newnode->pow = p;
    newnode->next = NULL;
    return newnode;
}

void traverse(Node *start)
{
    Node *ptr = start;
    while (ptr != NULL)
    {
        printf("%+dx^%d\t", ptr->coeff, ptr->pow);
        ptr = ptr->next;
    }
    printf("\n");
}

Node *addlast(Node *start, int coeff, int pow)
{
    Node *newnode = getNode(coeff, pow);
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

Node *add_poly(Node *l1, Node *l2)
{
    Node *l3 = NULL;
    while (l1 != NULL && l2 != NULL)
    {
        if (l1->pow == l2->pow)
        {
            l3 = addlast(l3, l1->coeff + l2->coeff, l1->pow);
            l1 = l1->next;
            l2 = l2->next;
        }
        else if (l1->pow > l2->pow)
        {
            l3 = addlast(l3, l1->coeff, l1->pow);
            l1 = l1->next;
        }
        else
        {
            l3 = addlast(l3, l2->coeff, l2->pow);
            l2 = l2->next;
        }
    }

    // remaining of l1
    while (l1 != NULL)
    {
        l3 = addlast(l3, l1->coeff, l1->pow);
        l1 = l1->next;
    }

    // remainig of l2
    while (l2 != NULL)
    {
        l3 = addlast(l3, l2->coeff, l2->pow);
        l2 = l2->next;
    }
    return l3;
}