#include <stdio.h>
#define ROW 10
#define COL 10
void input(int[][COL], int, int);
int check_unit(int[][COL], int, int);
int main()
{
  int i, j, r, c;
  int m[ROW][COL];
  printf("Enter how many rows and columns you want: ");
  scanf("%d%d", &r, &c);
  input(m, r, c);
  if (check_unit(m, r, c))
  {
    printf("Yes it is a unit matrix");
  }
  else
  {
    printf("No it is not a unit matrix");
  }
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

int check_unit(int m[][COL], int r, int c)
{
  int i, j;
  if (r != c)
  {
    return 0;
  }
  for (i = 0; i < r; i++)
  {
    for (j = 0; j < c; j++)
    {
      if (i != j && m[i][j] != 0 || i == j && m[i][j] != 1)
      {
        return 0;
      }
    }
  }
  return 1;
}
