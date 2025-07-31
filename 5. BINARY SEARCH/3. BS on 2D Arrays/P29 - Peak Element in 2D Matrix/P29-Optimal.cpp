// Peak Element in 2D Matrix. (Optimal)   --> TC:(mlogn)   SC:O(1).

#include <bits/stdc++.h>
using namespace std;

int max_rowidx(vector<vector<int>> &arr, int col)
{
    int m = arr.size();
    int max_ele = INT_MIN, max_idx = -1;
    for (int i = 0; i < m; i++)
    {
        if (arr[i][col] > max_ele)
        {
            max_ele = arr[i][col];
            max_idx = i;
        }
    }
    return max_idx;
}

pair<int, int> fnc(vector<vector<int>> &mat)
{
    int m = mat.size();
    int n = mat[0].size();
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int row = max_rowidx(mat, mid);
        int left = (mid - 1) >= 0 ? mat[row][mid - 1] : -1;
        int right = (mid + 1) < n ? mat[row][mid + 1] : -1;

        if (mat[row][mid] > left && mat[row][mid] > right)
        {
            return {row, mid};
        }
        else if (mat[row][mid] < left)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return {-1, -1};
}

int main()
{
    vector<vector<int>> mat = {{4, 2, 5, 1, 4, 5},
                               {2, 9, 3, 2, 3, 2},
                               {1, 7, 6, 0, 1, 3},
                               {3, 6, 2, 3, 7, 2}};
    pair<int, int> res = fnc(mat);
    cout << res.first << " , " << res.second;
}