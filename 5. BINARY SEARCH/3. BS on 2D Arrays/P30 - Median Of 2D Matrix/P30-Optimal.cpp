// Median of a Row Wise Sorted Matrix. (Optimal)  -->  TC:O(log(10^9)*m*logn)   SC:O(1).
// Always n(elements) = Odd.

#include <bits/stdc++.h>
using namespace std;


pair<int, int> arr_info(vector<vector<int>> &arr)
{
    int m = arr.size();
    int n = arr[0].size();
    int mini = INT_MAX;
    int maxi = INT_MIN;
    for (int i = 0; i < m; i++)
    {
        mini = min(arr[i][0], mini);
        maxi = max(arr[i][n - 1], maxi);
    }
    return {mini, maxi};
}

int ub(vector<int> &a, int x)
{
    int n = a.size();
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (a[mid] > x)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}

int cnt(vector<vector<int>> &arr, int x)
{
    int m = arr.size();
    int n = arr[0].size();
    int count = 0;
    for (int i = 0; i < m; i++)
    {
        count += ub(arr[i], x);
    }
    return count;
}

int fnc(vector<vector<int>> &arr)
{
    int m = arr.size();
    int n = arr[0].size();
    pair<int, int> val = arr_info(arr);
    int low = val.first, high = val.second;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int no_Small_ele = cnt(arr, mid);
        int req = (m * n) / 2;
        if (no_Small_ele > req)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}

int main()
{
    vector<vector<int>> mat = {{1, 5, 7, 9, 11},
                               {2, 3, 4, 5, 10},
                               {9, 10, 12, 14, 16}};
    cout << fnc(mat);
}