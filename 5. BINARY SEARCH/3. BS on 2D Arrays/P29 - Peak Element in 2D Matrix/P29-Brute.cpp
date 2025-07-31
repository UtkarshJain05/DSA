// Peak Element in 2D Matrix. (Brute)   --> TC:(m*n)   SC:O(1).

#include <bits/stdc++.h>
using namespace std;

pair<int, int> fnc(vector<vector<int>> &mat)
{
    int m = mat.size();
    int n = mat[0].size();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int top = (i != 0) ? mat[i - 1][j] : -1;
            int bott = (i != m - 1) ? mat[i + 1][j] : -1;
            int left = (j != 0) ? mat[i][j - 1] : -1;
            int right = (j != n - 1) ? mat[i][j + 1] : -1;

            if (mat[i][j] > left && mat[i][j] > right && mat[i][j] > top && mat[i][j] > bott)
            {
                return {i, j};
            }
        }
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