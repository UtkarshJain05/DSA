// 2 Sum (B) - (Optimal) --> TC : O(N) ; SC : O(N).

#include <bits/stdc++.h>
using namespace std;

vector<int> sum(vector<int> arr, int t)
{
    int n = arr.size();
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int rem = t - arr[i];
        if (mp.find(rem) != mp.end())
        {
            // Return Number :
            // return {rem,arr[i]};
            // Return Index :
            return {mp[rem], i};
        }
        mp[arr[i]] = i;
    }
    return {-1, -1};
}

int main()
{
    vector<int> arr = {2,7,11,15};
    vector<int> u = sum(arr, 9);
    for (auto i : u)
    {
        cout << i << " ";
    }
}