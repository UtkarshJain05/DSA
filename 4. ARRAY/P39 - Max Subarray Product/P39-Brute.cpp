// Maximum Subarray Product. (Brute) -->  TC: O(n^2)  SC : O(1).

#include <bits/stdc++.h>
using namespace std;

int fnc(vector<int> &arr)
{
    int n = arr.size();
    int maxproduct = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int product = 1;
        for (int j = i; j < n; j++)
        {
            product *= arr[j];
            maxproduct = max(product, maxproduct);
        }
    }
    return maxproduct;
}

int main()
{
    vector<int> arr = {2, 3, -2, 4};
    cout << fnc(arr);
}