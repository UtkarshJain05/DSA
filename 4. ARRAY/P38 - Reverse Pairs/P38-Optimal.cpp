// Reverse Pair. (Optimal) -->  TC: O(2n*logn)  SC : O(n).

#include <bits/stdc++.h>
using namespace std;

int count_pairs(vector<int> &arr, int low, int mid, int high)
{
    int cnt = 0, right = mid + 1;
    for (int left = low; left <= mid; left++)
    {
        while (right <= high && arr[left] > 2 * arr[right])
        {
            right++;
        }
        cnt += (right - (mid + 1));
    }
    return cnt;
}

void merge(vector<int> &arr, int low, int mid, int high)
{
    int left = low;
    int right = mid + 1;
    vector<int> v;
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            v.emplace_back(arr[left]);
            left++;
        }
        else
        {
            v.emplace_back(arr[right]);
            right++;
        }
    }
    while (left <= mid)
    {
        v.emplace_back(arr[left]);
        left++;
    }
    while (right <= high)
    {
        v.emplace_back(arr[right]);
        right++;
    }
    for (int i = low; i <= high; i++)
    {
        arr[i] = v[i - low];
    }

    return;
}

int merge_sort(vector<int> &arr, int low, int high)
{
    int count = 0;
    if (low >= high)
        return count;
    int mid = (low + high) / 2;
    count += merge_sort(arr, low, mid);
    count += merge_sort(arr, mid + 1, high);
    count += count_pairs(arr, low, mid, high);
    merge(arr, low, mid, high);
    return count;
}

int fnc(vector<int> &arr)
{
    int n = arr.size();
    int ans = merge_sort(arr, 0, n - 1);
    return ans;
}

int main()
{
    vector<int> arr = {40, 25, 19, 12, 9, 6, 2};
    cout << fnc(arr);
}