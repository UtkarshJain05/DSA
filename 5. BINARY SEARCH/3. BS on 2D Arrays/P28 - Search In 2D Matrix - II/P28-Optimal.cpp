// Find Target In 2-D Matrix - II {Staicase}.(Optimal)  -->  TC:O(m+n)   SC:O(1).

#include <bits/stdc++.h>
using namespace std;

pair<int, int> fnc(vector<vector<int>> &mat, int t)
{
    int m = mat.size();
    int n = mat[0].size();
    int row = 0, col = n - 1;
    while (row < m && col >= 0)
    {
        int val = mat[row][col];
        if (val > t)
            col--;
        else if (val < t)
            row++;
        else
            return {row, col};
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
    cout << ans.first << ", " << ans.second;
}