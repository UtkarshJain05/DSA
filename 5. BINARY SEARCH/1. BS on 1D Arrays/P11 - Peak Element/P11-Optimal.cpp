// Find Peak Element In Array {Index}. (Optimal)  --> TC:O(LogN)  SC:O(1).

#include <bits/stdc++.h>
using namespace std;

int fnc(vector<int> &arr)
{
    int n = arr.size();
    if (n == 1)
        return 0;
    if (arr[0] > arr[1])
        return 0;
    if (arr[n - 1] > arr[n - 2])
        return n - 1;

    int low = 1, high = n - 2;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        // mid is peak.
        if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
        {
            return mid;
        }

        // Lying On Increasing Curve.
        else if (arr[mid] < arr[mid + 1])
        {
            low = mid + 1;
        }

        // Lying On Decreasing Curve.
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = {1, 10, 13, 15, 6, 7, 4, 2, 1, 0};
    cout << fnc(arr);
}