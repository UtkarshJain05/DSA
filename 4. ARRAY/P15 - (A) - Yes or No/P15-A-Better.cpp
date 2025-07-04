// 2 Sum (A) - (Better) --> TC : O(N) ; SC : O(N).

#include <bits/stdc++.h>
using namespace std;

string sum(vector<int> arr, int t)
{
    int n = arr.size();
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int rem = t - arr[i];
        if (mp.find(rem) != mp.end())
        {
            return "Yes.";
        }
        mp[arr[i]] = i;
    }
    return "No.";
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << sum(arr, 1);
}