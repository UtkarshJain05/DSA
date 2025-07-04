// Count Inversions in Array.(Optimal) -->  TC: O(nlogn)  SC : O(n).
// Note : HERE ALTERING OF GIVEN ARRAY IS DONE : TO PREVENT --> MAKE brr as a COPY of arr.

#include <bits/stdc++.h>
using namespace std;

int merge(vector<int> &arr, int low, int mid, int high)
{
    int cnt = 0;
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    while (left <= mid && right <= high)
    {

        // left is smaller
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }

        // #right is smaller
        else
        {
            temp.push_back(arr[right]);
            cnt += (mid - left + 1);
            right++;
        }
    }
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }

    return cnt;
}

int split(vector<int> &arr, int low, int high)
{
    int count = 0;
    if (low == high)
        return count;
    int mid = (low + high) / 2;
    count += split(arr, low, mid);
    count += split(arr, mid + 1, high);
    count += merge(arr, low, mid, high);
    return count;
}

int fnc(vector<int> &arr)
{
    int n = arr.size();
    int ans = split(arr, 0, n - 1);
    return ans;
}

int main()
{
    vector<int> arr = {5, 3, 2, 4, 1};
    cout << fnc(arr);
}