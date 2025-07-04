// Merge 2 Sorted Array.(Optimal-2)  -->  TC : O(log(m+n) * (m+n))     SC :  O(1)
// GAP METHOD.

#include <bits/stdc++.h>
using namespace std;

void swap_element(vector<int> &arr, vector<int> &brr, int idx1, int idx2)
{
    if (arr[idx1] > brr[idx2])
    {
        swap(arr[idx1], brr[idx2]);
    }
    return;
}

void Merge(vector<int> &arr1, vector<int> &arr2)
{
    int m = arr1.size();
    int n = arr2.size();
    int len = m + n;
    int gap = (len) / 2 + len % 2;

    while (gap > 0) // if gap = 1 --> Loop will run once.
    {
        int left = 0, right = gap; // @ left = 0, right = 0 + gap.
        while (right < len)
        {
            // arr2 and arr2
            if (left >= m)
            {
                swap_element(arr2, arr2, left - m, right - m);
            }

            // arr1 and arr2
            else if (left < m && right >= m)
            {
                swap_element(arr1, arr2, left, right - m);
            }

            // arr1 and arr1
            else
            {
                swap_element(arr1, arr1, left, right);
            }
            left++, right++;
        }
        if (gap == 1)
            break;
        gap = gap / 2 + gap % 2;
    }
    return;
}

int main()
{
    vector<int> arr1 = {1, 3, 5, 7};
    vector<int> arr2 = {0, 2, 6, 8, 9};
    Merge(arr1, arr2);
    for (auto i : arr1)
    {
        cout << i << " ";
    }
    for (auto it : arr2)
    {
        cout << it << " ";
    }
}