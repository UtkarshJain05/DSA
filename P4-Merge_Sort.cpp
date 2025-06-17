// MERGE SORT

#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int low, int mid, int high)
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
}

void merge_sort(int arr[], int low, int high)
{
    if (low >= high)
        return;
    int mid = (low + high) / 2;
    merge_sort(arr, low, mid);
    merge_sort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

void merge_sorting(int arr[], int n)
{
    merge_sort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    int arr[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    merge_sorting(arr, 10);
}