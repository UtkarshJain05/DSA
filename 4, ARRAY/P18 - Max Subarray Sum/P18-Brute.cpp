//  Maximum Subarray Sum.(Brute)  TC : O(N^2)  : SC O(1)

#include <bits/stdc++.h>
using namespace std;

int kadane(vector<int> arr)
{
    int n = arr.size();
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            maxi = max(sum, maxi);
        }
    }
    return maxi;
}

int main()
{
    vector<int> arr = {-2, -3, 4, -1, -2, 1, 5, -3};
    cout << kadane(arr);
}