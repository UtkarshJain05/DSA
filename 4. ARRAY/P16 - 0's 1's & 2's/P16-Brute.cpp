// Sort Array Of 0's 1's & 2's.(Brute)  TC --> O(NlogN) ; SC --> O(1).

// Quick Sort.

#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int low, int high)
{
    int pivot = low;
    int left = low;
    int right = high;
    while (left < right)
    {
        while (arr[left] <= arr[pivot] && left <= right)
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
    swap(arr[right], arr[pivot]);
    return right;
}
void qs(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int fix = partition(arr, low, high);
        qs(arr, low, fix - 1);
        qs(arr, fix + 1, high);
    }
}
void arrange(vector<int> &arr)
{
    int n = arr.size();
    qs(arr, 0, n - 1);
}

int main()
{
    vector<int> arr = {0, 1, 2, 0, 1, 2, 0, 1, 2};
    arrange(arr);
    for (auto i : arr)
    {
        cout << i << " ";
    }
}