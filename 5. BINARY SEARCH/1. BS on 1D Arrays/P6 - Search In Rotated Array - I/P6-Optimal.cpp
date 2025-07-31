// Search in Rotated Array - I {Uniques}(Optimal) -->  TC:O(logN)   SC : O(1)

#include <bits/stdc++.h>
using namespace std;

int fnc(vector<int> &arr, int t)
{
    int n = arr.size();
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == t)
            return mid;

        // left sorted
        else if (arr[low] <= arr[mid])
        {
            if (arr[low] <= t && t <= arr[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        // right is sorted
        else
        {
            if (arr[mid] <= t && t <= arr[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = {7, 8, 9, 10, 1, 2, 3, 4, 5, 6};
    int t = 10;
    cout << fnc(arr, t);
}
