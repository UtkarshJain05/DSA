// Longest Subarray of (+ve's/0's) with sum k.(Optimal) --> TC : O(2N) ; SC : O(1)

#include <bits/stdc++.h>
using namespace std;
int optimal_k(vector<int> arr, long long k)
{
    int n = arr.size();
    int left = 0, right = 0;
    int maxlen = 0, sum = 0;
    while (right < n)
    {
        sum += arr[right];
        while (left <= right && sum > k) // removing arr[i]'s from sum till sum<=k.
        {
            /* TC(N) --> As this loop is running sometimes only & for some random values.
                         so Completely can be counted for running N times. */
            sum -= arr[left];
            left++;
        }
        if (sum == k)
        {
            maxlen = max(maxlen, right - left + 1);
        }
        right++;
    }
    return maxlen;
}

// // Notes --> TC : O(2N)  --> ?

int main()
{
    vector<int> arr = {2, 3, 5, 1, 1, 2, 1};
    cout << optimal_k(arr, 5);
}