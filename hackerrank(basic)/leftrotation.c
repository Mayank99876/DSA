#include <stdio.h>
#include<stdlib.h>
int rotateLeft(int d, int arr[],int n)
{
    int rotatedArr[n];

    for (int k = 0; k < d; k++)
    {
        for (int i = 0; i < n; i++)
        {
            rotatedArr[(i + d) % n] = arr[i];
        }
        arr = rotatedArr;
    }
    return arr;
}

int main()
{
    int n, d;
    scanf("%d%d", &n, &d);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int* result = rotateLeft(d, arr, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d\t", result[i]);
    } 

    return 0;
}