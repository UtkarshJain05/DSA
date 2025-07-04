// Merging Overlapping Intervals.(Brute)  -->  TC : O(NlogN + 2N)   SC : O(N)
// here N = No. of Intervals and 2N came from checking TC Manually.

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> interval(vector<vector<int>> &arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        int start = arr[i][0];
        int end = arr[i][1];
        if (ans.empty() == 0 && end <= ans.back()[1])
        {
            continue;
        }
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j][0] <= end)
            {
                end = max(end, arr[j][1]);
            }
            else
                break;
        }
        ans.push_back({start, end});
    }

    return ans;
}

int main()
{
    vector<vector<int>> arr = {{1, 3}, {2, 6}, {8, 9}, {9, 11}, {8, 10}, {2, 4}, {15, 18}, {16, 17}};
    vector<vector<int>> u = interval(arr);
    for (auto i : u)
    {
        for (auto it : i)
        {
            cout << it << " ";
        }
        cout << "\n";
    }
}