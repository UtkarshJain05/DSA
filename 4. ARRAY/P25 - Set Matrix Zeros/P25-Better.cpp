// Set Matrix Zeros. (Better)   --> TC : O[2*(nxm)]  SC : O(n+m).

#include <bits/stdc++.h>
using namespace std;

void Matrix_zero(vector<vector<int>> &matrix, int n, int m)
{
    // Extra Space
    int row[n] = {0};
    int col[m] = {0};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (row[i] == 1 || col[j] == 1)
            {
                if (matrix[i][j] != 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
    return;
}

int main()
{
    int n = 4, m = 4;
    vector<vector<int>> matrix = {{1, 1, 1, 1}, {1, 0, 1, 1}, {1, 1, 0, 1}, {1, 0, 0, 1}};
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