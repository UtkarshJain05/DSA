// Row with Maximum n(1's).(Optimal)   TC:O(m*logn)    SC:(1)

#include <bits/stdc++.h>
using namespace std;

int lb(vector<int> &arr, int x)
{
    int n = arr.size();
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] >= x)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}

int fnc(vector<vector<int>> &mat)
{
    int m = mat.size();
    int n = mat[0].size();
    int maxCount = 0;
    int idx = -1;
    for (int i = 0; i < m; i++)
    {
        int val = lb(mat[i], 1);
        int no_1s = n - val;
        if (no_1s > maxCount)
        {
            maxCount = no_1s;
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