// Finding x In Sorted Array.(Recursive)  --> TC : O(logN)  SC : O(logN)

#include <bits/stdc++.h>
using namespace std;

int recursive(vector<int> &arr, int low, int high, int t)
{
    if (low > high)
        return -1;
    int mid = (low + high) / 2;
    if (arr[mid] < t)
        return recursive(arr, mid + 1, high, t);
    else if (arr[mid] == t)
        return mid;
    else
        return recursive(arr, low, mid - 1, t);
}

int fnc(vector<int> &arr, int t)
{
    int n = arr.size();
    return recursive(arr, 0, n - 1, t);
}

int main()
{
    vector<int> a = {3, 4, 6, 7, 9, 12, 16, 17};
    int t = 3;
    int idx = fnc(a, t);
    if (idx != -1)
        cout << t << " is at Index : " << idx;
    else
        cout << t << " is Not Present in the Array.";
}