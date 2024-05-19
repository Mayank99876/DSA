#include <iostream>
// #include <bits/stdc++.h>
using namespace std;

int rotateLeft(int d, int arr[])
{
    int n = arr.size();
    int rotatedArr[n];

    for (int k = 0; k < d; k++)
    {
        for (int i = 0; i < n; i++)
        {
            rotatedArr[(i + d) % n] = arr[i];
        }
        arr = rotatedArr;
    }
    return arr;
}

int main()
{
    int n, d;
    cin >> n >> d;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int result = rotateLeft(d, arr);

    for (int i = 0; i < n; i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}