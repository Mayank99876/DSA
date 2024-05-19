#include <iostream>
using namespace std;

void merging(int *, int, int, int, int);
int *t;
int main()
{
    int *a, n, i;
    cout << "Enter how many numbers: ";
    cin >> n;
    a = new int[n];
    t = new int[n];
    for (i = 0; i < n; i++)
    {
        cout << "Enter element " << i + 1 << ":";
        cin >> a[i];
    }
    merging(a, 8, 11, 12, 15);
    // output
    cout<<"Sorted array is : "<<endl;
    for (i = 0; i < n; i++)
    {
        cout << a[i] <<" ";
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