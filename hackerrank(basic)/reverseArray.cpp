#include <iostream>
using namespace std;
#define MAXARR 1000
int main()
{
    int a[MAXARR], n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        cout << " ";
    }
    for (int i = n-1; i >= 0; i--)
    {
        cout << a[i]<<" ";
    }

    return 0;
}