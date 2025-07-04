// Print Largest Subarray with length of sum = 0. (Optimal) --> TC : O(N)   SC : O(N)

#include <bits/stdc++.h>
using namespace std;

int sum(vector<int> &arr)
{
    int n = arr.size();
    int ansstart = -1, ansend = -1;
    int maxlen = 0;
    unordered_map<int, int> mp;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == 0)
        {
            maxlen = max(maxlen, i + 1);
            ansstart = 0;
            ansend = i;
        }
        // remove = sum - k --> sum - 0 = sum.  i.e we'll find sum in map.
        if (mp.find(sum) != mp.end())
        {
            int len = i - mp[sum];
            if (maxlen < len)
            {
                ansstart = mp[sum] + 1; // becoz if we find sum -> ans array after its idx.
                ansend = i;
                maxlen = len;
            }
        }
        else
        {
            mp[sum] = i;
        }
    }
    for (int i = ansstart; i <= ansend; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return maxlen;
}

int main()
{
    // vector<int> arr = {1, 2, -2, 4, -4};
    vector<int> arr = {1, -1, 3, 2, -2, -3};
    cout << sum(arr);
}
