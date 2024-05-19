#include <iostream>
using namespace std;

void delete_in_unsorted(int[], int, int);

int main()
{
    int a[100], n, i, pos;
    cout << "Enter how many numbers: ";
    cin >> n;
    // array input
    for (i = 0; i < n; i++)
    {
        cout << "Enter element " << i + 1 << ":";
        cin >> a[i];
    }
    cout << "Enter position to delete: ";
    cin >> pos;
    pos--; // as array index starts from 0
    delete_in_unsorted(a, n--, pos);
    // output
    for (i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}

void delete_in_unsorted(int a[], int n, int pos)
{
    int i;
    // position check
    if (pos < 0 || pos > n)
    {
        cout << "Invalid position can't delete...";
        return;
    }
    // deletion
    for (i = pos - 1; i < n - 1; i++)
        a[i] = a[i + 1];
}