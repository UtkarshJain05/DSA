// Kth Element of 2 Sorted Array.(Optimal)  --> TC:O(log(min(n1,n2)))  SC:O(1).

#include <bits/stdc++.h>
using namespace std;

int fnc(vector<int> &arr, vector<int> &brr, int k)
{
    int n1 = arr.size();
    int n2 = brr.size();
    if (n1 > n2)
        return fnc(brr, arr, k);
    int n = n1 + n2;
    int low = max(0, k - n2), high = min(k, n1);
    while (low <= high)
    {
        int mid1 = (low + high) / 2;
        int mid2 = k - mid1;
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;
        if ((mid1 - 1) >= 0)
            l1 = arr[mid1 - 1];
        if ((mid2 - 1) >= 0)
            l2 = brr[mid2 - 1];
        if (mid1 < n1)
            r1 = arr[mid1];
        if (mid2 < n2)
            r2 = brr[mid2];
        if (l1 > r2)
            high = mid1 - 1;
        else if (l2 > r1)
            low = mid1 + 1;
        else
            return max(l1, l2);
    }
    return 0;
}

int main()
{
    vector<int> arr = {2, 3, 6, 7, 9};
    vector<int> brr = {1, 4, 8, 10};
    int k = 4;
    cout << fnc(arr, brr, k);
}