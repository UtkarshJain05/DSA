// First & Last Occurance -> (Binary Search)  --> TC : O(logN)  SC : O(1)
// Using Lower & Upper Bound. 

#include <bits/stdc++.h>
using namespace std;

int lowerbound(vector<int> arr, int t)
{
    int n = arr.size();
    int ans = n;
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] >= t)
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
int upperbound(vector<int> arr, int t)
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

pair<int, int> occurance(vector<int> arr, int t)
{
    int n = arr.size();
    int lb = lowerbound(arr, t);
    int ub = upperbound(arr, t);

    // Can also use STL Library.
    // int lb = lower_bound(arr.begin(), arr.end(), t) - arr.begin();
    // int ub = upper_bound(arr.begin(), arr.end(), t) - arr.begin();
    
    if (lb == n || arr[lb] != t)
        return {-1, -1};
    return {lb, ub - 1};
}

int main()
{
    vector<int> arr = {2, 4, 6, 8, 8, 8, 8, 8};
    int t = 0;
    pair<int, int> ans = occurance(arr, t);
    cout << ans.first << " --> " << ans.second;
}