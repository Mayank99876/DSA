#include <iostream>
using namespace std;
void selection_sort(int *a, int);

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
    cout << "Sorted array by selection sort is: " << endl;
    selection_sort(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    delete[] a;
    return 0;
}

void selection_sort(int *a, int n)
{
    int i, j, t, minpos, cnt = 0;
    for (i = 0; i < n - 1; i++)
    {
        minpos = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[minpos])
            {
                minpos = j;
            }
        }
        if (i != minpos)
        {
            swap(a[i], a[minpos]);
            cnt++;
        }
    }
    cout << "Total swap: " << cnt << endl;
}