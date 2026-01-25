// No. of Enclaves.(DFS)  --> TC:O(m*n)  SC:O(m*n).

#include <bits/stdc++.h>
using namespace std;

void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &grid, int delrow[], int delcol[])
{
    int n = grid.size();
    int m = grid[0].size();
    vis[row][col] = 1;
    for (int i = 0; i < 4; i++)
    {
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
            vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1)
        {
            dfs(nrow, ncol, vis, grid, delrow, delcol);
        }
    }
    return;
}

int n_enclaves(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));

    int delrow[] = {-1, 0, +1, 0};
    int delcol[] = {0, +1, 0, -1};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if ((i == 0 || i == n - 1 || j == 0 || j == m - 1) &&
                (vis[i][j] == 0) && (grid[i][j] == 1))
            {
                dfs(i, j, vis, grid, delrow, delcol);
            }
        }
    }

    // count ans

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vis[i][j] == 0 && grid[i][j] == 1)
            {
                ans++;
            }
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> grid = {
        {0, 0, 0, 1},
        {0, 1, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 1},
        {0, 1, 1, 0}};

    cout << n_enclaves(grid);
}