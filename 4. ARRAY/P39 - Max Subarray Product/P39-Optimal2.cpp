// Maximum Subarray Product. (Optimal-2) -->  TC: O(n)  SC : O(1).

#include <bits/stdc++.h>
using namespace std;

int fnc(vector<int> &nums)
{
    int n = nums.size();
    int maxp = nums[0], minp = nums[0], ans = nums[0];
    for (int i = 1; i < n; i++)
    {
        if (nums[i] < 0)
            swap(minp, maxp);
        minp = min(minp * nums[i], nums[i]);
        maxp = max(maxp * nums[i], nums[i]);
        ans = max(ans, maxp);
    }
    return ans;
}

int main()
{
    vector<int> arr = {2, 3, -2, 4};
    cout << fnc(arr);
}