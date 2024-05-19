#include <stdio.h>
#include <stdlib.h>
#define MAXSTK 20
typedef struct Stack
{
    int data[MAXSTK];
    int top;
} Stack;

void push(Stack *p, int t)
{
    if (p->top == MAXSTK - 1)
        return;
    p->data[++p->top] = t;
}

int pop(Stack *p)
{
    if (p->top == -1)
        return -999;
    return p->data[p->top--];
}

int main()
{
    Stack st;
    int a[10][10];
    int status[10];
    int n, i, j, start;
    st.top = -1;
    printf("enter no. of vertex: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        status[i] = 1; // initialize status array with 1
    }
    printf("Enter adjacency matrix: \n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("enter starting vertex: ");
    scanf("%d", &start);
    push(&st, start);
    status[start]++;
    while (st.top != -1)
    {
        start = pop(&st);
        printf("v%d\t", start);
        status[start]++;
        for (i = 0; i < n; i++)
        {
            if (a[start][i] == 1 && status[i] == 1)
            {
                push(&st, i);
                status[i]++;
            }
        }
    }
    return 0;
}