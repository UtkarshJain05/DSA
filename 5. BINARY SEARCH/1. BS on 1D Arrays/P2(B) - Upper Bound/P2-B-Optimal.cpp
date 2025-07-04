// Upper Bound (index)-> (Binary Search)  --> TC : O(logN)  SC : O(1)

#include <bits/stdc++.h>
using namespace std;

int upperBound(vector<int> arr, int t)
{
    int n = arr.size();
    int ans = n;
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] > t)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {2, 3, 6, 7, 8, 8, 11, 11, 11, 12};
    int t = 6;
    int idx = upperBound(arr, t);
    cout << idx;

    // In built Function: (Gives the Iterator / Address)
    // cout << upper_bound(arr.begin(), arr.end(), t) - arr.begin();
}
