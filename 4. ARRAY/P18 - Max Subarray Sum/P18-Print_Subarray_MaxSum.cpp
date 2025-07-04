// Maximum Subarray Sum (Optimal)  TC - O(N)  ;  SC - O(1)

// Kadane's Algorithm.

#include <bits/stdc++.h>
using namespace std;

int kadane(vector<int> arr)
{
    int n = arr.size();
    int sum = 0;
    int maxi = INT_MIN;

    int start = 0;
    int ansstart = -1, ansend = -1;
    
    for (int i = 0; i < n; i++)
    {
        if (sum == 0)
            start = i;
        sum += arr[i];
        if (sum > maxi)
        {
            maxi = sum;

            ansstart = start;
            ansend = i;
        }
        if (sum < 0)
            sum = 0;
    }
    if (maxi > 0)
    {
        for (int i = ansstart; i <= ansend; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
        return maxi;
    }
    return 0;
}

int main()
{
    vector<int> arr = {-2, -3, 6, 1, -8, 15, -3};
    cout << kadane(arr);
}