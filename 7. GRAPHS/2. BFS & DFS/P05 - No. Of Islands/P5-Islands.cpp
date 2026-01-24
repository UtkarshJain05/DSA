// Islands. -->  TC:O(N^2)    SC:O(2*(N^2))

#include <bits/stdc++.h>
using namespace std;

void bfs(int ro, int co, vector<vector<int>> &arr, vector<vector<int>> &vis)
{
    int n = arr.size();
    int m = arr[0].size();
    vis[ro][co] = 1;
    queue<pair<int, int>> q;
    q.push({ro, co});
    while (!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        for (int del_ro = -1; del_ro <= 1; del_ro++)
        {
            for (int del_co = -1; del_co <= 1; del_co++)
            {
                int n_row = row + del_ro;
                int n_col = col + del_co;
                if (n_row >= 0 && n_row < n && n_col >= 0 && n_col < m &&
                    vis[n_row][n_col] == 0 && arr[n_row][n_col] == 1)
                {
                    vis[n_row][n_col] = 1;
                    q.push({n_row, n_col});
                }
            }
        }
    }
    return;
}

int Islands(vector<vector<int>> &arr)
{
    int ans = 0;
    int n = arr.size();
    int m = arr[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < m; col++)
        {
            if (vis[row][col] == 0 && arr[row][col] == 1)
            {
                ans++;
                bfs(row, col, arr, vis);
            }
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> arr = {
        {0, 1, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 0},
        {1, 1, 0, 1}};

    int ans = Islands(arr);
    cout << "No. of Islands : " << ans;
}