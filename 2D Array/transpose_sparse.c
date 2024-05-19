#include <stdio.h>
#define MAX 20
void readsparse(int[][3]);
void transpose(int[][3], int[][3]);
void printsparse(int[][3]);
int main()
{
    int m1[MAX][3], m2[MAX][3];
    readsparse(m1);
    transpose(m1, m2);
    printsparse(m2);
    return 0;
}

void readsparse(int m[][3])
{
    int r, c, i, j, n;
    printf("Enter the size of matrix(rows,columns): ");
    scanf("%d%d", &r, &c);
    printf("Enter no. of non-zero elements: ");
    scanf("%d", &n);
    m[0][0] = r;
    m[0][1] = c;
    m[0][2] = n;
    // triplet input
    for (i = 1; i <= n; i++)
    {
        printf("Enter the %d triplet(row,column,value): ",i);
        scanf("%d%d%d", &m[i][0], &m[i][1], &m[i][2]);
    }
}

void transpose(int sm1[][3], int sm2[][3])
{
    int n, j, k, COL, i;
    n = sm1[0][2];
    // header copy
    sm2[0][0] = sm1[0][1];
    sm2[0][1] = sm1[0][0];
    sm2[0][2] = sm1[0][2];

    j = 1;
    if (n > 0)
    {
        for (COL = 0; COL < sm1[0][1]; COL++)
        {
            for (i = 1; i <= n; i++)
            {
                if (COL == sm1[i][1])
                {
                    sm2[j][0] = sm1[i][1];
                    sm2[j][1] = sm1[i][0];
                    sm2[j][2] = sm1[i][2];
                    j++;
                }
            }
        }
    }
}

void printsparse(int m[][3])
{
    int i, j, n;
    n = m[0][2];
    printf("\nrow\t\tcolumn\t\tvalue\n");
    for (i = 0; i <= n; i++)
    {
        printf("%d\t\t%d\t\t%d", m[i][0], m[i][1], m[i][2]);
        printf("\n"); 
    }
}
