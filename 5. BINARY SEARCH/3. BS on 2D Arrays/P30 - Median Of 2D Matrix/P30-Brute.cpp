// Median of a Row Wise Sorted Matrix. (Brute)  -->  TC:O((m*n) + (m*n)log(m*n))   SC:O(m*n).
// Always n(elements) = Odd.

#include <bits/stdc++.h>
using namespace std;

int fnc(vector<vector<int>> &arr)
{
    int m = arr.size();
    int n = arr[0].size();
    vector<int> space;
    for (auto i : arr)
    {
        for (auto j : i)
        {
            space.push_back(j);
        }
    }

    sort(space.begin(), space.end());

    return space[(m * n) / 2];
}

int main()
{
    vector<vector<int>> mat = {{1, 5, 7, 9, 11},
                               {2, 3, 4, 5, 10},
                               {9, 10, 12, 14, 16}};
    cout << fnc(mat);
}
