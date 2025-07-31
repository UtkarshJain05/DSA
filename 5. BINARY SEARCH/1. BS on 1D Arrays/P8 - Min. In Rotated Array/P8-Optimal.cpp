// Minimum In Rotated Sorted Array. (Optimal)  -->  TC:O(N/2)  SC : O(1).

#include <bits/stdc++.h>
using namespace std;

int fnc(vector<int> &arr)
{
    int n = arr.size();
    int mini = INT_MAX;
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        mini = min(arr[mid], mini);

        // Checking Duplicates
        if (arr[low] == arr[mid] && arr[mid] == arr[high])
        {
            low++;
            high--;
            continue;
        }

        // If only Sorted Array Left.
        if (arr[low] <= arr[high])
        {
            mini = min(arr[low], mini);
            return mini;
        }

        // Left Sorted
        else if (arr[low] <= arr[mid])
        {
            mini = min(arr[low], mini);
            low = mid + 1;
        }

        // Right Sorted
        else
        {
            mini = min(arr[mid], mini);
            high = mid - 1;
        }
    }
    return mini;
}

int main()
{
    vector<int> arr = {6, 7, 1, 2, 3, 4, 5};
    cout << fnc(arr);
}