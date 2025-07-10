// Small Divisor - Given Threshold. (Burte)  -->  TC:O(n*max_ele(arr))   SC:O(1)

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
    int n = arr.size();

    // n is the min sum.
    if (n > t)
        return -1;

    for (int i = 1; i <= max_ele(arr); i++)
    {
        if (check(arr, i) <= t)
            return i;
    }
    return -1;
}

int main()
{
    vector<int> arr = {1, 2, 5, 9};
    int thr = 6;
    cout << fnc(arr, thr);
}