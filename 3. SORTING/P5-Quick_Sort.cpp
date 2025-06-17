// QUICK SORT

#include<bits/stdc++.h>
using namespace std;

int partition(int arr[], int low, int high)
{
    int pivot = low;
    int left = low;
    int right = high;
    while (left < right)
    {
        while (arr[left] <= arr[pivot] && left <= high)
        {
            left++;
        }
        while (arr[right] > arr[pivot] && right >= low)
        {
            right--;
        }
        if (left < right)
        {
            swap(arr[left], arr[right]);
        }
    }
    swap(arr[pivot], arr[right]);
    return right;
}

void qs(int arr[], int low, int high)
{
    if (low < high)
    {
        int fix = partition(arr, low, high);
        qs(arr, low, fix - 1);
        qs(arr, fix + 1, high);
    }
}

void quick_sort(int arr[], int n)
{
    qs(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    quick_sort(arr, 10);
}