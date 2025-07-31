// Median of 2 Sorted Array.(Better) --> TC:O(n)   SC:O(1).

#include <bits/stdc++.h>
using namespace std;

double fnc(vector<int> &arr, vector<int> &brr)
{
    int n1 = arr.size(), n2 = brr.size();
    int n = n1 + n2;
    int idx2 = n / 2;
    int idx1 = idx2 - 1;
    int ele1 = INT_MIN, ele2 = INT_MIN;
    int cnt = 0;
    int left = 0, right = 0;
    while (left < n1 && right < n2)
    {
        if (arr[left] < brr[right])
        {
            if (cnt == idx1)
                ele1 = arr[left];
            if (cnt == idx2)
                ele2 = arr[left];
            left++;
        }
        else
        {
            if (cnt == idx1)
                ele1 = brr[right];
            if (cnt == idx2)
                ele2 = brr[right];
            right++;
        }
        cnt++;
    }
    while (left < n1)
    {
        if (cnt == idx1)
            ele1 = arr[left];
        if (cnt == idx2)
            ele2 = arr[left];
        left++;
        cnt++;
    }
    while (right < n2)
    {
        if (cnt == idx1)
            ele1 = brr[right];
        if (cnt == idx2)
            ele2 = brr[right];
        right++;
        cnt++;
    }

    if (n % 2 == 1)
        return (double)ele2;
    return (double)(((double)ele1 + (double)ele2) / 2.0);
}

int main()
{
    vector<int> arr = {1, 3, 4, 7, 10, 12};
    vector<int> brr = {2, 3, 6, 15};
    cout << fnc(arr, brr);
}