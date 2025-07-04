// No. of Subarrays with XOR K. (Brute) --> TC : O(N^2)   SC : O(1)

#include <bits/stdc++.h>
using namespace std;

int XOR(vector<int> &arr, int k)
{
    int n = arr.size();
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int x = 0;
        for (int j = i; j < n; j++)
        {
            x = x ^ arr[j];
            if (x == k)
            {
                cnt++;
            }
        }
    }
    return cnt;
}

int main()
{
    vector<int> arr = {4, 2, 2, 6, 4};
    int k = 6;
    cout << XOR(arr, k);
}