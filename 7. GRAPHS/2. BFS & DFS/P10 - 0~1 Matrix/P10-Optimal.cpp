// Matrix Distance – Nearest Cell Having 1.   TC:O(m*n)  SC:O(m*n).

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> nearest(vector<vector<int>> &mat)
{
    int m = mat.size();
    int n = mat[0].size();
    vector<vector<int>> vis(m, vector<int>(n, 0));
    vector<vector<int>> ans(m, vector<int>(n));
    queue<pair<pair<int, int>, int>> q;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == 1)
            {
                q.push({{i, j}, 0});
                vis[i][j] = 1;
            }
        }
    }

    int delrow[] = {-1, 0, +1, 0};
    int delcol[] = {0, +1, 0, -1};

    while (!q.empty())
    {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int steps = q.front().second;
        ans[row][col] = steps;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n &&
                vis[nrow][ncol] == 0)
            {
                vis[nrow][ncol] = 1;
                q.push({{nrow, ncol}, steps + 1});
            }
        }
    }

    return ans;
}

int main()
{
    vector<vector<int>> mat = {
        {1, 0, 0},
        {0, 0, 0},
        {0, 0, 1}};

    vector<vector<int>>
        ans = nearest(mat);

    for (auto i : ans)
    {
        for (auto it : i)
            cout << it << " ";
        cout << endl;
    }
}