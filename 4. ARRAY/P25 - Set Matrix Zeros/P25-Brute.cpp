// Set Matrix Zeros. (Brute)   --> TC : O[(nxm)(n+m)+(nxm)]   SC : O(1).

#include <bits/stdc++.h>
using namespace std;

void mark_row(vector<vector<int>> &matrix, int n, int m, int i)
{
    for (int j = 0; j < m; j++)
    {
        if (matrix[i][j] != 0)
        {
            matrix[i][j] = -1;
        }
    }
    return;
}

void mark_col(vector<vector<int>> &matrix, int n, int m, int j)
{
    for (int i = 0; i < n; i++)
    {
        if (matrix[i][j] != 0)
        {
            matrix[i][j] = -1;
        }
    }
    return;
}

void Matrix_zero(vector<vector<int>> &matrix, int n, int m)
{
    // Row & Col --> -1
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                mark_row(matrix, n, m, i);
                mark_col(matrix, n, m, j);
            }
        }
    }

    // -1 --> 0
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(matrix[i][j]==-1){
                matrix[i][j]=0;
            }
        }
    }
    return;
}

int main()
{
    int n = 4, m = 4;
    vector<vector<int>> matrix = {{1,1,1,1},{1,0,1,1},{1,1,0,1},{1,0,0,1}};
    Matrix_zero(matrix, n, m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}