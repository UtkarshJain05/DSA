// Longest Subarray of (+ve/0/-ve) with sum k.(Brute) --> TC : O(N^2) ; SC : O(1).

#include <bits/stdc++.h>
using namespace std;
int brute_k(vector<int> arr, int k)
{
    int n = arr.size();
    int length = 0;
    for (int i = 0; i < n; i++)
    {
        int s = 0;
        for (int j = i; j < n; j++)
        {
            s += arr[j];
            if (s == k)
            {
                length = max(length, j - i + 1);
            }
        }
    }
    return length;
}

int main()
{
    vector<int> arr = {1, 2, 1, -1, 1, 1, 1, 0, 3, 1, 2, 1};
    cout << brute_k(arr, 3);
}