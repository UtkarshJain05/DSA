// Row with Maximum n(1's).(Brute)   TC:O(m*n)    SC:(1)

#include <bits/stdc++.h>
using namespace std;

int fnc(vector<vector<int>> &mat)
{
    int m = mat.size();
    int n = mat[0].size();
    int max = 0;
    int idx = -1;
    for (int i = 0; i < m; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == 1)
                cnt++;
        }
        if (max < cnt)
        {
            max = cnt;
            idx = i;
        }
    }
    return idx;
}

int main()
{
    vector<vector<int>> mat = {{0, 0, 1, 1, 1},
                               {0, 0, 0, 0, 0},
                               {0, 1, 1, 1, 1},
                               {0, 0, 0, 0, 0},
                               {0, 1, 1, 1, 1}};
    cout << fnc(mat);
}