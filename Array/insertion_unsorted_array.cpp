#include <iostream>
using namespace std;

void insert_in_unsorted(int[], int, int, int);

int main()
{
    int a[100], n, i, item, pos;
    cout << "Enter how many numbers: ";
    cin >>n;
    // array input
    for (i = 0; i < n; i++)
    {
        cout << "Enter element " << i + 1 << ":";
        cin >>a[i];
    }
    cout << "Enter item and it's position to insert: ";
    cin >> item >> pos;
    pos--; // as array index starts from 0
    insert_in_unsorted(a, n++, item, pos);
    // output
    for (i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}

void insert_in_unsorted(int a[], int n, int item, int pos)
{
    int i;
    // position check
    if (pos < 0 || pos > n)
    {
        cout << "Invalid position can't insert...";
        return;
    }
    // shifting
    for (i = n - 1; i >= pos; i--)
    {
        a[i + 1] = a[i];
    }
    // insert
    a[pos] = item;
}