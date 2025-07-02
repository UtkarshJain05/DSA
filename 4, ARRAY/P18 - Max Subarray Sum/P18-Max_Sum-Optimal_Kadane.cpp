// Maximum Subarray Sum (Optimal)  TC - O(N)  ; SC - O(1)

// Kadane's Algorithm.

#include <bits/stdc++.h>
using namespace std;

int kadane(vector<int> arr)
{
    int n = arr.size();
    int sum = 0;
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        maxi = max(sum, maxi);
        if (sum < 0)
        {
            sum = 0;
        }
    }
    if (maxi < 0)
        return 0;
    return maxi;
}

int main()
{
    vector<int> arr = {-2, -3, 4, -1, -2, 1, 5, -3};
    cout << kadane(arr);
}