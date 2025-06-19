// Check Whether Array is Sorted ?

#include <bits/stdc++.h>
using namespace std;

int Is_Sorted(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[i - 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int arr[10] = {4, 3, 2, 1, 5, 6, 7, 7, 8, 9};
    int result = Is_Sorted(arr, 10);
    if (result == 0)
        cout << "Unsorted.";
    else
        cout << "Sorted.";
}