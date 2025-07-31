// Split Subarray - Largest Sum. (Optimal) --> TC:O(n*log(sum-max+1))   SC:O(1).

#include <bits/stdc++.h>
using namespace std;

int check(vector<int> &arr, int unit)
{
    int n = arr.size();
    int sub_no = 1, last_Sum = 0;
    // Sub_no --> Subarray No.
    // last_sum --> Sum of All Elements now in Sub_no.

    for (auto i : arr)
    {
        if ((i + last_Sum) <= unit)
        {
            last_Sum += i;
        }
        else
        {
            sub_no++, last_Sum = i;
        }
    }
    return sub_no;
}

int fnc(vector<int> &arr, int k)
{
    int n = arr.size();

    // If (Elements < Req Subarrays.)
    if (n < k)
        return -1;

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int val = check(arr, mid);
        if (val <= k)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}

int main()
{
    vector<int> arr = {10, 20, 30, 40};
    int k = 2;
    cout << fnc(arr, k) << " is the Min. Sum.";
}