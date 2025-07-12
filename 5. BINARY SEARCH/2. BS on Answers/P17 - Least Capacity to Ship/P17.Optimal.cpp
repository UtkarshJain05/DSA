// Least Capacity to ship in D Days (Optimal).  TC:O(n*Log(Sum-Max))    SC:O(1)

#include <bits/stdc++.h>
using namespace std;

pair<int, int> arr_info(vector<int> &arr)
{
    int sum = 0;
    int maxi = INT_MIN;
    for (auto i : arr)
    {
        sum += i;
        maxi = max(i, maxi);
    }
    return {maxi, sum};
}

bool check(vector<int> &arr, int cap, int d)
{
    int days = 1, load = 0;
    for (auto i : arr)
    {
        if ((load + i) > cap)
            days++, load = i;
        else
            load += i;
    }
    return days <= d;
}

int fnc(vector<int> &arr, int d)
{
    int low = arr_info(arr).first, high = arr_info(arr).second;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (check(arr, mid, d) == true)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}

int main()
{
    vector<int> weight = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int days = 5;
    cout << fnc(weight, 5);
}