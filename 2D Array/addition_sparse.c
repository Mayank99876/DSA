#include <stdio.h>
#include <stdlib.h>
#define MAX 20
void readsparse(int[][3]);
void addition(int[][3], int[][3], int[][3]);
void printsparse(int[][3]);
int main()
{
    int m1[MAX][3], m2[MAX][3], m3[MAX][3];
    printf("Enter first matrix: \n");
    readsparse(m1);
    printf("Enter second matrix: \n");
    readsparse(m2);
    addition(m1, m2, m3);
    printsparse(m3);
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
        printf("Enter the %d triplet(row,column,value): ", i);
        scanf("%d%d%d", &m[i][0], &m[i][1], &m[i][2]);
    }
}

void addition(int m1[][3], int m2[][3], int m3[][3])
{
    int i, j, k, n1, n2;
    if (m1[0][0] != m2[0][0] || m1[0][1] != m2[0][1])
    {
        printf("can't add");
        exit(0);
    }
    m3[0][0] = m1[0][0];
    m3[0][1] = m1[0][1];

    k = 1;
    n1 = m1[0][2];
    n2 = m2[0][2];

    for (i = 1, j = 1; i <= n1 && j <= n2; k++)
    {
        if (m1[i][0] < m2[j][0] || m1[i][0] == m2[j][0] && m1[i][1] < m2[j][1])
        {
            m3[k][0] = m1[i][0];
            m3[k][1] = m1[i][1];
            m3[k][2] = m1[i][2];
            i++;
        }
        else if (m2[j][0] < m1[i][0] || m2[j][0] == m1[i][0] && m2[j][1] < m1[i][1])
        {
            m3[k][0] = m2[j][0];
            m3[k][1] = m2[j][1];
            m3[k][2] = m2[j][2];
            j++;
        }
        else
        {
            m3[k][0] = m1[i][0];
            m3[k][1] = m1[i][1];
            m3[k][2] = m1[i][2] + m2[j][2];
            i++;
            j++;
        }

        // Remaining of 1st matrix
        while (i <= n1)
        {
            m3[k][0] = m1[i][0];
            m3[k][1] = m1[i][1];
            m3[k][2] = m1[i][2];
            i++;
            k++;
        }

        // Remaining of 2nd matrix
        while (j <= n2)
        {
            m3[k][0] = m2[j][0];
            m3[k][1] = m2[j][1];
            m3[k][2] = m2[j][2];
            j++;
            k++;
        }
        m3[0][2] = k - 1;
    }
}

void printsparse(int m[][3])
{
    int i, n;
    n = m[0][2];
    printf("\nrow\t\tcolumn\t\tvalue\n");
    for (i = 0; i <= n; i++)
    {
        printf("%d\t\t%d\t\t%d", m[i][0], m[i][1], m[i][2]);
        printf("\n");
    }
}
