#include <iostream>
using namespace std;
int binary_search(int *a, int, int);

int main()
{
    int *a, n, item, loc;
    // Size of array input
    cout << "Enter the size of array: ";
    cin >> n;
    // dynamic memory allocation
    a = new int[n];
    cout << "Enter elements in increasing order: " << endl;
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
    loc = binary_search(a, n, item);
    if (loc != -1)
    {
        cout << "Item found at position " << loc; // success
    }
    else
    {
        cout << "Item not found."; // failure
    }

    delete[] a;
    return 0;
}

int binary_search(int *a, int n, int item)
{
    int i = 0, low = 1, high = n - 1, mid, loc;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (a[mid] == item)
        {
            loc = mid;
            return loc+1;
        }
        else if (item > a[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}