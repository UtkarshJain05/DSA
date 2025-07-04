// Majority Element > n/3 times. (Better)     TC : O(N)   SC : O(N)

#include <bits/stdc++.h>
using namespace std;

vector<int> majority(vector<int> &arr)
{
    int n = arr.size();
    unordered_map<int, int> mp;
    vector<int> ele;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
        if (mp[arr[i]] > n / 3)
        {
            ele.push_back(arr[i]);
        }
    }
    return ele;
}

int main()
{
    vector<int> arr = {1, 1, 1, 2, 2, 3, 3, 3};
    vector<int> u = majority(arr);
    for (auto i : u)
    {
        cout << i << " ";
    }
}