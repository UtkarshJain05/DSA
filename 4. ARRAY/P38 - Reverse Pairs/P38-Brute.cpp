// Reverse Pair. (Brute) -->  TC: O(N^2)  SC : O(1).

#include <bits/stdc++.h>
using namespace std;

int fnc(vector<int> &arr)
{
    int n = arr.size();
    int cnt = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > 2 * arr[j])
            {
                cnt++;
            }
        }   
    }
    return cnt;
}

int main()
{
    vector<int> arr = {40, 25, 19, 12, 9, 6, 2};
    cout << fnc(arr);
}