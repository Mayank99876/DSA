#include <stdio.h>
void heap_sort(int[], int);
void insheap(int[], int, int);
int delheap(int[], int);

int main()
{
    int a[20], i, n;
    printf("Enter how many elements: ");
    scanf("%d", &n);
    /*Input Array*/
    for (i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &a[i]);
    }
    heap_sort(a, n);
    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    return 0;
}

void heap_sort(int a[], int n)
{
    int i, item;
    for (i = 1; i < n; i++)
    {
        insheap(a, i, a[i]);
    }
    while (n > 0)
    {
        item = delheap(a, n - 1);
        a[n - 1] = item;
        n--;
    }
}

void insheap(int tree[], int n, int item)
{
    int par, ptr;
    ptr = n;
    while (ptr > 0)
    {
        par = (ptr - 1) / 2;
        if (item <= tree[par])
        {
            tree[ptr] = item;
            return;
        }
        tree[ptr] = tree[par];
        ptr = par;
    }
    tree[ptr] = item;
}

int delheap(int tree[], int n)
{
    int item, last, ptr, left, right;
    item = tree[0];
    last = tree[n];
    n--;
    ptr = 0;
    left = 1;
    right = 2;
    while (right <= n)
    { // if both child are available
        if (last >= tree[left] && last >= tree[right])
        {
            tree[ptr] = last;
            return item;
        }
        if (tree[left] >= tree[right])
        {
            tree[ptr] = tree[left];
            ptr = left;
        }
        else
        {
            tree[ptr] = tree[right];
            ptr = right;
        }
        left = ptr * 2 + 1;
        right = left + 1;
    }
    if (left == n && tree[left] >= last)
    {
        // if no right child but left is there
        tree[ptr] = tree[left];
        ptr = left;
    }
    tree[ptr] = last; // if no left and no right child are there
    return item;
}