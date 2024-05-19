#include <iostream>
using namespace std;
int max(int *, int);
int count(int);
int digit(int, int);
void radix_sort(int *, int);

int main()
{
    int *a, i, n;
    // Size of array
    cout << "Enter how many numbers: ";
    cin >> n;
    // dynamic memory allocation
    a = new int[n];
    for (i = 0; i < n; i++)
    {
        cout << "Enter element " << i + 1 << ": ";
        cin >> a[i];
    }
    radix_sort(a, n);
    cout << "Array after radix sort is : " << endl;
    // output
    for (i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}

int count(int n)
{
    int cnt = 0;
    while (n)
    {
        n /= 10;
        cnt++;
    }
    return cnt;
}

int max(int *a, int n)
{
    int m = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] > m)
            m = a[i];
    }
    return m;
}
int digit(int n, int k)
{
    int dig;
    for (int i = 1; i <= k; i++)
    {
        dig = n % 10;
        n /= 10;
    }
    return dig;
}

void radix_sort(int *a, int n)
{
    int mat[10][n], i, j, k, r, c, d, m;
    m = max(a, n);
    d = count(m);

    for (k = 1; k <= d; k++)
    {
        // initialize mat matrix with -1
        for (i = 0; i < 10; i++)
            for (j = 0; j < n; j++)
            {
                mat[i][j] = -1;
            }

        // copy A array into mat matrix according to kth digit
        for (i = 0; i < n; i++) // for A array
        {
            r = digit(a[i], k);
            c = 0;
            while (mat[r][c] != -1)
                c++;
                mat[r][c] = a[i];
            
        }

        // copy mat matrix into A array
        int index = 0;
        for (i = 0; i < 10; i++)
            for (j = 0; j < n; j++)
            {
                if (mat[i][j] != -1)
                
                    a[index++] = mat[i][j];
                
            }
    }
}
