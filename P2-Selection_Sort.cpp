// Selection Sort.

#include <bits/stdc++.h>
using namespace std;
int main()
{
    // Array Size input
    int n;
    cin >> n;
    int arr[n];

    // Array Input
    cout << "Unsorted Array : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int min, minidx;
    for (int i = 0; i < n - 1; i++)
    {
        min = INT_MAX, minidx = -1;
        for (int j = i; j < n; j++)
        {
            if (min > arr[j])
            {
                min = arr[j];
                minidx = j;
            }
        }
        swap(arr[i], arr[minidx]);
    }

    // Array Output
    cout << "Sorted Array : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}