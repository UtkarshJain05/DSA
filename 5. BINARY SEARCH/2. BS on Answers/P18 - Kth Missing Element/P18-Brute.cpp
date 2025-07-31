// Find Kth Missing Element in array.(Brute)  -->  TC:O(n)   SC:O(1).

#include <bits/stdc++.h>
using namespace std;

int k_missing(vector<int> &arr, int k)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= k)
            k++;
        else
            return k;
    }
}

int main()
{
    vector<int> arr = {2, 5, 6, 9, 12, 14};
    int k = 7;
    cout << k_missing(arr, k);
}