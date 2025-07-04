
/* XOR Working:
    4 ^ 2 --> binaries --> (100 ^ 010)
    100
  ^ 010
    110  --> same value = 0 & diff value = 1

    So, 4^2 = 6.
*/

// No. of Subarrays with XOR K. (Optimal) --> TC : O(N)   SC : O(N)

#include <bits/stdc++.h>
using namespace std;

// x ^ k = xr
// (x ^ k) ^ k = xr ^ k
// x = xr ^ k    -->   Formula Used.

int XOR(vector<int> &arr, int k)
{
    int n = arr.size();
    int cnt = 0;
    unordered_map<int, int> mp;
    int xr = 0;
    mp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        xr = xr ^ arr[i];
        int x = xr ^ k;
        cnt += mp[x];
        mp[xr]++;
    }
    return cnt;
}

int main()
{
    vector<int> arr = {4, 2, 2, 6, 4};
    int k = 6;
    cout << XOR(arr, k);
}