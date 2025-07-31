// Find Target In 2-D Matrix - I.(Optimal)  -->  TC:O(log(m*n))   SC:O(1).

#include <bits/stdc++.h>
using namespace std;

bool fnc(vector<vector<int>> &mat, int t)
{
    int m = mat.size();
    int n = mat[0].size();
    int low = 0, high = m * n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int r = mid / n;
        int c = mid % n;
        int val = mat[r][c];
        if (val == t)
            return true;
        else if (val < t)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return false;
}

int main()
{
    vector<vector<int>> mat = {{3, 4, 7, 9},
                               {12, 13, 16, 18},
                               {20, 21, 23, 29}};
    int target = 23;
    fnc(mat, target) == true ? cout << "True\n" : cout << "False\n";
}