// Small Divisor - Given Threshold. (Optimal)  -->  TC:O(n*log(max_ele(arr)))   SC:O(1)

#include <bits/stdc++.h>
using namespace std;

int max_ele(vector<int> &arr)
{
    int maxi = INT_MIN;
    for (auto i : arr)
    {
        maxi = max(maxi, i);
    }
    return maxi;
}

int check(vector<int> &arr, int d)
{
    int sum = 0;
    for (auto i : arr)
    {
        sum += ceil((double)i / d);
    }
    return sum;
}

int fnc(vector<int> &arr, int t)
{
    int low = 1, high = max_ele(arr);
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (check(arr, mid) <= t)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}

int main()
{
    vector<int> arr = {1, 2, 5, 9};
    int thr = 6;
    cout << fnc(arr, thr);
}
