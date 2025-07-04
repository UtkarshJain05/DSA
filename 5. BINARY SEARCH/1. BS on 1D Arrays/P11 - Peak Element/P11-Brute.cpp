// Find Peak Element In Array {Index}. (Brute)  --> TC:O(N)  SC:O(1).

#include <bits/stdc++.h>
using namespace std;

int fnc(vector<int> &arr)
{
    int n = arr.size();
    if (n == 1)
        return 0;
    for (int i = 0; i < n; i++)
    {
        if ((i == 0 || arr[i] > arr[i - 1]) && (i == n - 1 || arr[i] > arr[i + 1]))
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = {1, 10, 13, 15, 6, 7, 4, 2, 1, 0};
    cout << fnc(arr);
}