#include <stdio.h>
int cnt;
void tower(int, char, char, char);

int main()
{
    int n;
    printf("Enter no. of disks: ");
    scanf("%d", &n);
    tower(n, 'A', 'B', 'C');
    return 0;
}

void tower(int n, char beg, char aux, char end)
{
    if (n == 1)
    {
        printf("\n%d. Disk %d is from %c to %c", ++cnt, n, beg, end);
        return;
    }
    tower(n - 1, beg, end, aux);
    printf("\n%d. Disk %d is from %c to %c", ++cnt, n, beg, end);
    tower(n - 1, aux, beg, end);
    return;
}