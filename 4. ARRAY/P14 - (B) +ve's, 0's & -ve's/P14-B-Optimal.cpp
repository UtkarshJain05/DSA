// Longest Subarray of (+ve/0/-ve) with sum k.(Optimal) --> TC : O(N) ; SC : O(N) -> if all elements sum is diff.

#include <bits/stdc++.h>
using namespace std;
int optimal_k(vector<int> arr, long long k)
{
    int n = arr.size();
    int maxlen = 0;
    long long sum = 0;
    unordered_map<long long, int> mp;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == k)
        // Checking Starting Sum but it will for Only 1 time so that we get first maxlen.
        {
            maxlen = max(maxlen, i + 1);
        }
        long long rem = sum - k;      // Remaining Part in sum Other than k from right --> left
        if (mp.find(rem) != mp.end()) // if rem exists in map
        {
            int len = i - mp[rem];     // then storing k sum subarray length
            maxlen = max(maxlen, len); // if (len > previous maxlen) --> maxlen = len.
        }
        if (mp.find(sum) == mp.end()) // At last if that Sum is not in map then store it in map.
        {
            mp[sum] = i;
        }
    }
    return maxlen;
}

/* Note --> 1. The Sum stored in hashmap is only used to check remaining Existence.
            2. If Sum is already there in hash then we'll not update it as we req. least rem.
               Only Eg.--> If Element = 0/-ves are also involved then Sum will be equal to Previous sum.
            3. TC is O(NXN) --> N for 'For Loop' and N for worst case of inserting Elements in Unordered Map. */

int main()
{
    vector<int> arr = {1, 2, 1, -1, 1, 1, 1, 0, 3, 1, 2, 1};
    cout << optimal_k(arr, 3);
}