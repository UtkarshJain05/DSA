// Rotten Oranges.   TC : O(n*m)  SC : O(n*m).

#include <bits/stdc++.h>
using namespace std;

int rotten_oranges(vector<vector<int>> &arr)
{
    int n = arr.size();
    int m = arr[0].size();
    queue<pair<pair<int, int>, int>> q;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 2)
            {
                q.push({{i, j}, 0});
            }
        }
    }

    int delrow[] = {-1, 0, +1, 0};
    int delcol[] = {0, +1, 0, -1};

    while (!q.empty())
    {
        int row = q.front().first.first;
        int col = q.front().first.second;
        cnt = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                arr[nrow][ncol] == 1)
            {
                arr[nrow][ncol] = 2;
                q.push({{nrow, ncol}, cnt + 1});
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 1)
                return -1;
        }
    }
    return cnt;
}

int main()
{
    vector<vector<int>> matrix = {{0, 1, 2}, {0, 1, 1}, {2, 1, 1}};
    cout << rotten_oranges(matrix);
}