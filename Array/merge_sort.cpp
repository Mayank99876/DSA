#include <iostream>
using namespace std;

void merging(int *, int, int, int, int);
void merge_sort(int *, int);
int *t;
int main()
{
    int *a, n, i;
    // Size of array
    cout << "Enter how many numbers: ";
    cin >> n;
    // dynamic memory allocation
    a = new int[n];
    t = new int[n];
    // array input
    for (i = 0; i < n; i++)
    {
        cout << "Enter element " << i + 1 << ":";
        cin >> a[i];
    }
     // function calling
    merge_sort(a, n);
    // output
    cout << "Sorted array by merge sort is : " << endl;
    for (i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    delete[] a;
    delete[] t;
    return 0;
}

void merging(int *a, int lb1, int ub1, int lb2, int ub2)
{
    int i, j, k;
    // compare and copy
    for (i = lb1, j = lb2, k = lb1; i <= ub1 && j <= ub2; k++)
    {
        if (a[i] < a[j])
            t[k] = a[i++];
        else
            t[k] = a[j++];
    }
    // remaining of 1st array
    while (i <= ub1)
        t[k++] = a[i++];
    // remaining of 2nd array
    while (j <= ub2)
        t[k++] = a[j++];
    // copying of a[i] to t[i]
    for (i = lb1; i <= ub2; i++)
        a[i] = t[i];
}

void merge_sort(int *a, int n)
{
    int lb1, ub1, lb2, ub2, sz;
    for (sz = 1; sz < n; sz = sz * 2)
    {
        for (lb1 = 0; lb1 + sz < n; lb1 = ub2 + 1)
        {
            lb2 = lb1 + sz;
            ub1 = lb2 - 1;
            ub2 = ub1 + sz < n ? ub1 + sz : n - 1;
            merging(a, lb1, ub1, lb2, ub2);
        }
    }
}