// Print frequency of each Element of Array -->   TC : O(2N)   SC : O(N)

#include <bits/stdc++.h>
using namespace std;

void count(vector<int> &arr)
{
    int n = arr.size();
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }
    for (auto it : mp)
    {
        cout << it.first << " " << it.second << endl;
    }
}

int main()
{
    vector<int> arr = {10, 5, 10, 15, 10, 5};
    count(arr);
}