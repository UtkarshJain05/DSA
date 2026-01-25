// No. of Distinct Islands.  -->  TC:O(m*n*log(set_length))  SC:O(m*n)

#include <bits/stdc++.h>
using namespace std;

void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &grid,
         vector<pair<int, int>> &vec, int row_base, int col_base,
         int delrow[], int delcol[])
{
    int n = grid.size();
    int m = grid[0].size();
    vec.push_back({row - row_base, col - col_base});
    vis[row][col] = 1;
    for (int i = 0; i < 4; i++)
    {
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];
        if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m &&
            vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1)
        {
            dfs(nrow, ncol, vis, grid, vec, row_base, col_base, delrow, delcol);
        }
    }
}

int CountDistinctIslands(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));

    set<vector<pair<int, int>>> st;

    int delrow[] = {-1, 0, +1, 0};
    int delcol[] = {0, +1, 0, -1};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vis[i][j] == 0 && grid[i][j] == 1)
            {
                vector<pair<int, int>> vec;
                dfs(i, j, vis, grid, vec, i, j, delrow, delcol);
                st.insert(vec);
            }
        }
    }

    return st.size();
}

int main()
{
    vector<vector<int>> grid = {
        {1, 1, 0, 1, 1},
        {1, 0, 0, 0, 0},
        {0, 0, 0, 1, 1},
        {1, 1, 0, 1, 0}};

    cout << CountDistinctIslands(grid);
}