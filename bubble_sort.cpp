#include <iostream>
using namespace std;
void bubble_sort(int *a, int);

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
    cout << "Sorted array by bubble sort is: " << endl;
    bubble_sort(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    delete[] a;
    return 0;
}

void bubble_sort(int *a, int n)
{
    int i, j, flag = 1, cnt = 0;
    for (i = 1; i < n && flag == 1; i++)
    {
        flag = 0;
        for (j = 0; j < n - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                flag = 1;
                swap(a[j], a[j + 1]);
                cnt++;
            }
        }
    }
    cout << "Total swap: " << cnt << endl;
}

