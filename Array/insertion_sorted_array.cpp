#include <iostream>
using namespace std;

void insert_in_sorted(int[], int, int);

int main()
{
    int a[100], n, i, item;
    cout << "Enter how many numbers: ";
    cin >> n;
    // array input
    cout << "Enter elements in increasing order: " << endl;
    for (i = 0; i < n; i++)
    {
        cout << "Enter element " << i + 1 << ":";
        cin >> a[i];
    }
    cout << "Enter item to insert: ";
    cin >> item;
    insert_in_sorted(a, n++, item);
    // output
    for (i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}

void insert_in_sorted(int a[], int n, int item)
{
    int i;
    // shifting
    for (i = n - 1; i >= 0 && a[i] > item; i--)
    {
        a[i + 1] = a[i];
    }
    // insert
    a[i + 1] = item;
}