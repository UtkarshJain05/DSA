// Maximum Subarray Product. (Optimal) -->  TC: O(n)  SC : O(1).

#include <bits/stdc++.h>
using namespace std;

int fnc(vector<int> &arr)
{
    int n = arr.size();
    int pre = 1, suf = 1;
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (pre == 0)
            pre = 1;
        if (suf == 0)
            suf = 1;
        pre *= arr[i];
        suf *= arr[n - 1 - i];
        maxi = max(maxi, max(pre, suf));
    }
    return maxi;
}

int main()
{
    vector<int> arr = {2, 3, -2, 4};
    cout << fnc(arr);
}