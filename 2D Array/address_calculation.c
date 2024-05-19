#include <stdio.h>
int main()
{
    int a[10][10], i, j, k, l, m, n, base, LOC, lb = 1, LOC1;
    printf("Enter rows and columns: ");
    scanf("%d%d", &m, &n);
    for (i = 0; i < m; i++)
    {
        for (l = 0; l < n; l++)
        {
            printf("Enter element %d,%d: ", i + 1, l + 1);
            scanf("%d", &a[i][l]);
        } 
    }
    printf("Enter current row and column for address calculation: ");
    scanf("%d%d", &j, &k);
    printf("Enter base address: ");
    scanf("%d", &base);
    LOC = base + sizeof(int) * ((j - lb) * n + (k - lb));
    LOC1 = base + sizeof(int) * ((k - lb) * m + (j - lb));
    printf("Address of %d,%d is: %d by row major mapping.\n", j, k, LOC);
    printf("Address of %d,%d is: %d by column major mapping.", j, k, LOC1);

    return 0;
}