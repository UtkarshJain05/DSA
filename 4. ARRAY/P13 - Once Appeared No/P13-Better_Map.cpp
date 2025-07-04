// Once Appeared Number.(Better - Map) --> TC - O(N + N/2 + 1) ; SC - O(N/2 + 1).

#include <bits/stdc++.h>
using namespace std;

int uniqueno(vector<int> arr)
{
    int n = arr.size();
    unordered_map<long long, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }
    for (auto i : mp)
    {
        if (i.second == 1)
        {
            return i.first;
        }
    }
}

int main()
{
    vector<int> arr = {1, 2, 1, 3, 3, 4, 4};
    cout << uniqueno(arr);
}