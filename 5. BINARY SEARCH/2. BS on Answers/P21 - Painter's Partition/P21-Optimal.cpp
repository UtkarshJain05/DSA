// Painter's Partition. (Optimal) --> TC:O(n*log(sum-max+1))   SC:O(1).

#include <bits/stdc++.h>
using namespace std;

int check(vector<int> &arr, int unit)
{
    int n = arr.size();
    int pno = 1, last = 0;
    for (auto i : arr)
    {
        if ((i + last) <= unit)
        {
            last += i;
        }
        else
        {
            pno++, last = i;
        }
    }
    return pno;
}

int fnc(vector<int> &arr, int k)
{
    int n = arr.size();
    if (n < k)
        return -1;
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int val = check(arr, mid);
        if (val <= k)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}

int main()
{
    vector<int> arr = {10, 20, 30, 40};
    int k = 2;
    cout << fnc(arr, k) << " Sq. Units.";
}