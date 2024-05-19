#include <stdio.h>
#include <stdlib.h>
#define size 50

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
    if (lb >= ub)
        return;
    int mid = partition(a, lb, ub);
    quick_sort(a, lb, mid - 1);
    quick_sort(a, mid + 1, ub);
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
