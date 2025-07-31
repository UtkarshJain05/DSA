// Find Target In 2-D Matrix - II.(Better)  -->  TC:O(m*logn)   SC:O(1).

#include <bits/stdc++.h>
using namespace std;

pair<int, int> fnc(vector<vector<int>> &mat, int t)
{
    int m = mat.size();
    int n = mat[0].size();
    for (int i = 0; i < m; i++)
    {
        if (mat[i][0] <= t && t <= mat[i][n - 1])
        {
            int low = 0, high = n - 1;
            while (low <= high)
            {
                int mid = (low + high) / 2;
                if (mat[i][mid] < t)
                    low = mid + 1;
                else if (mat[i][mid] > t)
                    high = mid - 1;
                else
                    return {i, mid};
            }
        }
    }
    return {-1, -1};
}

int main()
{
    vector<vector<int>> mat = {{1, 4, 7, 11, 15},
                               {2, 5, 8, 12, 19},
                               {3, 6, 9, 16, 22},
                               {10, 13, 14, 17, 24},
                               {18, 21, 23, 26, 30}};
    int target = 14;
    pair<int, int> ans = fnc(mat, target);
    cout << ans.first << "," << ans.second;
}