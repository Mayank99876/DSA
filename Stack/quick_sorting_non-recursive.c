#include <stdio.h>
#include <stdlib.h>
#define size 50
#define MAXSTK 100
typedef struct Stack
{
    int data[MAXSTK];
    int top;
} Stack;
void push(Stack *, int);
int pop(Stack *);
int partition(int *, int, int);
void quick_sort(int *, int, int);

int main()
{
    int a[size], n, i;
    printf("Enter array size: ");
    scanf("%d", &n);
    // Input array
    for (i = 0; i < n; i++)
    {
        printf("Enter %d element: ", i + 1);
        scanf("%d", &a[i]);
    }
    quick_sort(a, 0, n - 1);
    printf("Sorted array is: ");
    // Sorted array
    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    return 0;
}

void quick_sort(int *a, int lb, int ub)
{
    Stack stklb, stkub;
    stklb.top = -1;
    stkub.top = -1;
    if (lb < ub)
    {
        push(&stklb, lb);
        push(&stkub, ub);
    }
    else
        return;
    while (stklb.top != -1)
    {
        int lb = pop(&stklb);
        int ub = pop(&stkub);
        int mid = partition(a, lb, ub);
        if (lb < mid - 1)
        {
            push(&stklb, lb);
            push(&stkub, mid - 1);
        }
        if (mid + 1 < ub)
        {
            push(&stklb, mid + 1);
            push(&stkub, ub);
        }
    }
}

int partition(int *a, int lb, int ub)
{
    int pivot, down, up;
    pivot = a[lb];
    down = lb;
    up = ub;
    while (down < up)
    {
        while (a[down] <= pivot && down < up)
        { // down
            down++;
        }
        while (a[up] > pivot)
        { // up
            up--;
        }
        if (down < up)
        {
            int t = a[down];
            a[down] = a[up];
            a[up] = t;
        }
    }
    a[lb] = a[up];
    a[up] = pivot;
    return up;
}

void push(Stack *p, int item)
{
    if (p->top == MAXSTK - 1)
    {
        printf("OVERFLOW...\n");
        return;
    }
    p->top++;
    p->data[p->top] = item;
}

int pop(Stack *p)
{
    int item;
    if (p->top == -1)
    {
        printf("UNDERFLOW...\n");
        return '\0'; // Return a default value in case of underflow
    }
    item = p->data[p->top];
    p->top--;
    return item;
}