// EKO Problem  --> TC:O(nlogm)  SC:O(1).

#include <bits/stdc++.h>
using namespace std;

int check(vector<int> &arr, int h)
{
    int units = 0;
    for (auto i : arr)
    {
        if ((i - h) >= 0)
            units += (i - h);
    }
    return units;
}

int fnc(vector<int> &arr, int k)
{

    int n = arr.size();
    int all = accumulate(arr.begin(), arr.end(), 0);
    if (k > all)
        return -1;
    int low = 0, high = *max_element(arr.begin(), arr.end());
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int val = check(arr, mid);
        if (val >= k)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return high;
}

int main()
{
    vector<int> arr = {20, 15, 10, 17};
    int k = 7;
    cout << fnc(arr, k);
}