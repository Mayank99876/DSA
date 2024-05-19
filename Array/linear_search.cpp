#include <iostream>
using namespace std;
int linear_search(int *a, int, int);

int main()
{
    int *a, n, item, pos;
    // Size of array input
    cout << "Enter the size of array: ";
    cin >> n;
    // dynamic memory allocation
    a = new int[n];
    // array input
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element " << i + 1 << ": ";
        cin >> a[i];
    }
    // Item to search
    cout << "Enter item to search: ";
    cin >> item;
    // output
    pos = linear_search(a, n, item);
    if (pos != -1)
    {
        cout << "Item found at position " << pos; // success
    }
    else
    {
        cout << "Item not found."; // failure
    }

    delete[] a;
    return 0;
}

int linear_search(int *a, int n, int item)
{
    int i = 0;
    for (i = 0; i < n; i++)
    {
        if (a[i] == item) // success
            return i + 1;
    }
    return -1;
}