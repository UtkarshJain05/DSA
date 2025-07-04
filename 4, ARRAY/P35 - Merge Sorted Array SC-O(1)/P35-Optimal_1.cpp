// Merge 2 Sorted Array.(Optimal-1)  -->  TC : O(min(m+n) + mlogm + nlogn)     SC :  O(1)

#include <bits/stdc++.h>
using namespace std;

void Merge(vector<int> &arr, vector<int> &brr)
{
    int m = arr.size();
    int n = brr.size();
    int left = m - 1, right = 0;
    while (left >= 0 && right < n)
    {
        if (arr[left] > brr[right])
        {
            swap(arr[left], brr[right]);
            left--, right++;
        }
        else
        {
            break;
        }
    }
    sort(arr.begin(), arr.end());
    sort(brr.begin(), brr.end());        
    return;
}

int main()
{
    vector<int> arr = {1, 3, 5, 7};
    vector<int> brr = {0, 2, 6, 8, 9};
    Merge(arr, brr);

    for (auto i : arr)
    {
        cout << i << " ";
    }
    for (auto it : brr)
    {
        cout << it << " ";
    }
}   