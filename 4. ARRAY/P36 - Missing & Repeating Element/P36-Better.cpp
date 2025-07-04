// Missing & Repeating Elements.(Better) -->  TC : O(2*n)   SC : O(n)

#include <bits/stdc++.h>
using namespace std;

vector<int> fnc(vector<int> &arr)
{
    int n = arr.size();
    int missing = -1, repeating = -1;
    unordered_map<int, int> mp;

    for (auto i : arr)
    {
        mp[i]++;
    }

    for (int i = 1; i <= n; i++)
    {
        if (mp[i] == 0)
            missing = i;
        else if (mp[i] == 2)
            repeating = i;

        // Check
        if (missing != -1 && repeating != -1)
            break;
    }
    return {missing, repeating};
}

int main()
{
    vector<int> arr = {4, 3, 6, 2, 1, 1};
    vector<int> ans = fnc(arr);
    for (auto i : ans)
    {
        cout << i << " ";
    }
}