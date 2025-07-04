// Merge 2 Sorted Array.(Brute)  -->  TC : O(2*(m+n))     SC :  O(m+n)

#include <bits/stdc++.h>
using namespace std;

void Merge(vector<int> &arr, vector<int> &brr)
{
    int m = arr.size();
    int n = brr.size();
    vector<int> ans;
    int left = 0, right = 0;
    while (left < m && right < n)
    {
        if (arr[left] <= brr[right])
        {
            ans.push_back(arr[left]);
            left++;
        }
        else
        {
            ans.push_back(brr[right]);
            right++;
        }
    }
    while (left < m)
    {
        ans.push_back(arr[left]);
        left++;
    }
    while (right < n)
    {
        ans.push_back(brr[right]);
        right++;
    }

    for (int i = 0; i < m + n; i++)
    {
        if (i < m)
        {
            arr[i] = ans[i];
        }
        else
        {
            brr[i - m] = ans[i];
        }
    }
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