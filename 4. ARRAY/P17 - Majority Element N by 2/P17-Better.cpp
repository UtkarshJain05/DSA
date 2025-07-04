// Majority Element > N/2 -   TC --> O(N) ; SC O(N).

#include <bits/stdc++.h>
using namespace std;

int majority_better(vector<int> arr)
{
    int n = arr.size();
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }
    for (auto i : mp)
    {
        if (i.second > (n / 2))
        {
            return i.first;
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = {2, 3, 3, 3, 3, 3, 1, 2, 2};
    cout << majority_better(arr);
}