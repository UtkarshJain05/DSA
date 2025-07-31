// Median of 2 Sorted Array.(Brute) --> TC:O(n)   SC:O(n).

#include <bits/stdc++.h>
using namespace std;

double fnc(vector<int> &arr, vector<int> &brr)
{
    vector<int> temp;
    int n1 = arr.size();
    int n2 = brr.size();
    int n = n1 + n2;
    int left = 0, right = 0;
    while (left < n1 && right < n2)
    {
        if (arr[left] <= brr[right])
            temp.push_back(arr[left++]);
        else
            temp.push_back(brr[right++]);
    }
    while (left < n1)
        temp.push_back(arr[left++]);
    while (right < n2)
        temp.push_back(brr[right++]);

    if (n % 2 == 1)
        return temp[n / 2];

    return ((double)temp[n / 2 - 1] + (double)temp[n / 2]) / (2.0);
}

int main()
{
    vector<int> arr = {1, 3, 4, 7, 10, 12};
    vector<int> brr = {2, 3, 6, 15};
    cout << fnc(arr, brr);
}