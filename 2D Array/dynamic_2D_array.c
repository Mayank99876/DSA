#include <stdio.h>
#include <stdlib.h>
int main()
{
    int **m, r, c;
    printf("Enter rows and columns for dynamic 2D array: ");
    scanf("%d%d", &r, &c);
    m = (int **)malloc(r * sizeof(int *));
    for (int i = 0; i < r; i++)
    {
        m[i] = (int *)malloc(c * sizeof(int));
    }
    // input
    for (int i = 0; i < r; i++){
        for (int j = 0; j<c; j++)
        {
            printf("Enter element %d,%d: ", i + 1, j + 1);
            scanf("%d", &m[i][j]);
        }
    }

    // output
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j< c; j++)
        {
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }

    // free memory
    for (int i = 0; i < r; i++)
    {
        free(m[i]);
    }
    free(m);
    m = NULL;
    return 0;
}