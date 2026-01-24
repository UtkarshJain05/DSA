// Surrounded Regions. -->  TC:O(m*n)  SC:O(m*n).

#include <bits/stdc++.h>
using namespace std;

void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &board, int delrow[], int delcol[])
{
    int n = board.size();
    int m = board[0].size();
    vis[row][col] = 1;
    for (int i = 0; i < 4; i++)
    {
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
            vis[nrow][ncol] == 0 && board[nrow][ncol] == 'O')
        {
            dfs(nrow, ncol, vis, board, delrow, delcol);
        }
    }
    return;
}

void solve(vector<vector<char>> &board)
{
    int n = board.size();
    int m = board[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));

    int delrow[] = {-1, 0, +1, 0};
    int delcol[] = {0, +1, 0, -1};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if ((i == 0 || i == n - 1 || j == 0 || j == m - 1) && (vis[i][j] == 0) && (board[i][j] == 'O'))
                dfs(i, j, vis, board, delrow, delcol);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vis[i][j] == 0 && board[i][j] == 'O')
                board[i][j] = 'X';
        }
    }
    return;
}

int main()
{
    vector<vector<char>> board = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}};

    solve(board);

    for (auto i : board)
    {
        for (auto it : i)
        {
            cout << it << " ";
        }
        cout << endl;
    }
}