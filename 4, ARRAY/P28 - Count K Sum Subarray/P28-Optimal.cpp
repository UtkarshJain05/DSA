// Count Subarray with Sum K.(Optimal)  TC : O(N)    SC : (N)

// Prefix Sum
#include <bits/stdc++.h>
using namespace std;

int Cnt_Subarray(vector<int> &arr, int n, int k)
{
    int count = 0;
    unordered_map<int, int> mp;
    int sum = 0;
    mp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        int remove = sum - k;

        // mp[remove] will check if remove is in hashmap or not.
        count = count + mp[remove];
        mp[sum]++;
    }
    return count;
}

int main()
{
    vector<int> arr = {1, 2, 3, -3, 1, 1, 1, 4, 2, -3};
    int n = arr.size();
    for (auto it : arr)
    {
        cout << it << " ";
    }

    cout << endl
         << endl;

    cout << Cnt_Subarray(arr, n, 3);
}