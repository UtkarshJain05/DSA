// Lower Bound (index)-> (Binary Search)  --> TC : O(logN)  SC : O(1)

#include <bits/stdc++.h>
using namespace std;

int fnc(vector<int> &arr, int t)
{
    int n = arr.size();
    int low = 0, high = n - 1;
    int ans = n;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] >= t)
        {
            ans = mid;      // may be an answer.
            high = mid - 1; // checking for smaller term.
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
    vector<int> a = {1, 2, 3, 3, 5, 8, 8, 10, 10, 11};
    int t = 9;
    int idx = fnc(a, t);
    cout << idx;

    // In built Function: (Gives the Iterator / Address)
    // cout << lower_bound(arr.begin(), arr.end(), t) - arr.begin();
}