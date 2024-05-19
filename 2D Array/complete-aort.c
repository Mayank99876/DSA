#include <stdio.h>
#define ROW 10
#define COL 10
void input(int[][COL], int, int);
void complete_sort(int[][COL], int, int);
void output(int[][COL], int, int);
int main()
{
  int i, j, r, c;
  int m[ROW][COL];
  printf("Enter how many rows and columns you want: ");
  scanf("%d%d", &r, &c);
  input(m, r, c);
  complete_sort(m, r, c);
  printf("After complete sorting : \n");
  output(m, r, c);
  return 0;
}

void input(int m[][COL], int r, int c)
{
  int i, j;
  for (i = 0; i < r; i++)
  {
    for (j = 0; j < c; j++)
    {
      printf("Enter element %d,%d: ", i + 1, j + 1);
      scanf("%d", &m[i][j]);
    }
  }
}

void complete_sort(int m[][COL], int r, int c)
{
  int i, j, k, t, l;
  // Sort
  for (i = 0; i < r; i++)
  {
    for (j = 0; j < c; j++)
    {
      for (k = j == c - 1 ? i + 1 : i; k < r; k++)
      {
        for (l = k == i ? j + 1 : 0; l < c; l++)
        {
          if (m[i][j] > m[k][l])
          {
            t = m[i][j];
            m[i][j] = m[k][l];
            m[k][l] = t;
          }
        }
      }
    }
  }
}

void output(int m[][COL], int r, int c)
{
  int i, j;
  for (i = 0; i < r; i++)
  {
    for (j = 0; j < c; j++)
    {
      printf("%d\t", m[i][j]);
    }
    printf("\n");
  }
}
