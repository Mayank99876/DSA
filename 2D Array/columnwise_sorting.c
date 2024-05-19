#include <stdio.h>
#define ROW 10
#define COL 10
void input(int[][COL], int, int);
void columnwise_sorting(int[][COL], int, int);
void output(int[][COL], int, int);
int main()
{
  int i, j, r, c;
  int m[ROW][COL];
  printf("Enter how many rows and columns you want: ");
  scanf("%d%d", &r, &c);
  input(m, r, c);
  columnwise_sorting(m, r, c);
  printf("After columnwise sorting : \n");
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

void columnwise_sorting(int m[][COL], int r, int c)
{
  int i, j, k, t;
  for (k = 0; k < c; k++)
  {
    for (i = 0; i < r - 1; i++)
    {
      for (j = i + 1; j < r; j++)
      {
        if (m[i][k] > m[j][k])
        {
          t = m[i][k];
          m[i][k] = m[j][k];
          m[j][k] = t;
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
