#include <iostream>
using namespace std;
void count_sort(int *a, int);

int main()
{
    int *a, n;
    // Size of array input
    cout << "Enter the size of array: ";
    cin >> n;
    // dynamic memory allocation
    a = new int[n];
    cout << "Enter elements: " << endl;
    // array input
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element " << i + 1 << ": ";
        cin >> a[i];
    }

    // output
    cout << "Sorted array by count sort is: " << endl;
    // Count sort is fastest way of sorting and it is only for the small numbers, not negative numbers
    count_sort(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    delete[] a;
    return 0;
}

void count_sort(int *a, int n)
{
    int i, j;

    // finding max
    // In C++, max(array, array + size of array) finds out the maximum of array
    int m = max(*a, *a + n);

    // array create of size m+1
    int *cnt = new int[m + 1];

    // initialize cnt array with 0
    for (i = 0; i < m + 1; i++)
        cnt[i] = 0;

    // hashing
    for (i = 0; i < n; i++)
        cnt[a[i]]++;

    // decrement cnt till 0
    for (i = 0, j = 0; i < (m + 1);)
    {
        if (cnt[i] == 0)
            i++;
        else
        {
            a[j] = i;
            cnt[i]--;
            j++;
        }
    }
}