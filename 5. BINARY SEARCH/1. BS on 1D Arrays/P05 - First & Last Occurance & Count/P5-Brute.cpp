// First & Last Occurance -> (Linear Search)  --> TC : O(N)  SC : O(1)

#include <bits/stdc++.h>
using namespace std;

pair<int, int> occurance(vector<int> arr, int t)
{
    int n = arr.size();
    pair<int, int> ans{-1, -1};
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == t)
        {
            if (ans.first == -1)
                ans.first = i;
            ans.second = i;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {2, 4, 6, 8, 8, 8, 11, 13};
    int t = 8;
    pair<int, int> ans = occurance(arr, t);
    cout << ans.first << " --> " << ans.second;
}