// No. of times Array Rotated.(Optimal)  -->  TC:O(N/2)   SC:O(1).

#include <bits/stdc++.h>
using namespace std;

int fnc(vector<int> &arr)
{
    int n = arr.size();
    int low = 0, high = n - 1;
    int mini = INT_MAX;
    int idx = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] < mini)
        {
            mini = arr[mid];
            idx = mid;
        }

        // Duplicates Handling.  --> TC:O(N/2).
        if (arr[low] == arr[mid] && arr[mid] == arr[high])
        {
            low++, high--;
            continue;
        }

        // Now Mid Will be in b/w Low And High Always.
        else if (arr[low] <= arr[high])
        {
            if (arr[low] < mini)
            {
                mini = arr[low];
                idx = low;
            }
            return idx;
        }
        // Left Sorted
        else if (arr[low] <= arr[mid])
        {
            if (arr[low] < mini)
            {
                mini = arr[low];
                idx = low;
            }
            low = mid + 1;
        }

        // Right Sorted
        else
        {
            if (arr[mid] < mini)
            {
                mini = arr[mid];
                idx = mid;
            }
            high = mid - 1;
        }
    }
    return idx;
}

int main()
{
    vector<int> arr = {6, 7, 1, 2, 3, 4, 5};
    cout << fnc(arr);
}
