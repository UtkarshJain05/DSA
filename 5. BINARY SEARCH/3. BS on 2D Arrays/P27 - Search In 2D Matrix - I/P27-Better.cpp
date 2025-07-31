// Search in 2D matrix - I.(Better) -->  TC:O(m + logn)    SC:(1)

#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &arr, int t)
{
    int n = arr.size();
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == t)
            return true;
        else if (arr[mid] < t)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return false;
}

bool fnc(vector<vector<int>> &mat, int t)
{
    int m = mat.size();
    int n = mat[0].size();
    for (int i = 0; i < m; i++)
    {
        if (mat[i][0] <= t && t <= mat[i][n - 1])
        {
            return check(mat[i], t);
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> mat = {{3, 4, 7, 9},
                               {12, 13, 16, 18},
                               {20, 21, 23, 29}};
    int target = 25;
    cout << fnc(mat, target);
}