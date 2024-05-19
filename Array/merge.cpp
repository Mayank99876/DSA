#include <iostream>
using namespace std;

void merge(int *, int, int *, int, int *);
int main()
{
    int *a, n1, *b, n2, *c;
    // Array 1 size
    cout << "Enter the size of array 1: ";
    cin >> n1;
    // dynamic memory allocation of array 1
    a = new int[n1];
    cout << "Enter elements: " << endl;
    // array 1 input
    for (int i = 0; i < n1; i++)
    {
        cout << "Enter element " << i + 1 << ": ";
        cin >> a[i];
    }
    // Array 2 size
    cout << "Enter the size of second array: ";
    cin >> n2;
    // dynamic memory allocation of array 2
    b = new int[n2];
    // dynamic memory allocation of array 3
    c = new int[n1 + n2];
    // array 2 input
    cout << "Enter elements : " << endl;
    for (int j = 0; j < n2; j++)
    {
        cout << "Enter element " << j + 1 << ": ";
        cin >> b[j];
    }
    // output
    cout << "Merged array by sorting is: " << endl;
    // Count sort is fastest way of sorting and it is only for the small numbers, not negative numbers
    merge(a, n1, b, n2, c);
    for (int i = 0; i < n1 + n2; i++)
    {
        cout << c[i] << " ";
    }

    delete[] a;
    delete[] b;
    delete[] c;
    return 0;
}

void merge(int *a, int n1, int *b, int n2, int *c)
{
    int i, j, k;
    // compare and copy
    for (i = 0, j = 0, k = 0; i < n1 && j < n2; k++)
    {
        if (a[i] < b[j])
            c[k] = a[i++];
        else
            c[k] = b[j++];
    }
    // remaining of array 1
    while (i < n1)
    {
        c[k++] = a[i++];
    }
    // remaining of array 2
    while (j < n2)
    {
        c[k++] = b[j++];
    }
}