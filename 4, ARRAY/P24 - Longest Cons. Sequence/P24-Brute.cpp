// Longest Consecutive Sequence. (Brute) --> TC : O(N^2)  SC : O(1).

#include <bits/stdc++.h>
using namespace std;

bool ls(vector<int> arr, int num)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == num)
        {
            return true;
        }
    }
    return false;
}

int Conse(vector<int> &arr)
{
    int n = arr.size();
    int maxi = 1;
    for (int i = 0; i < n; i++)
    {
        int len = 1;
        int x = arr[i];
        while (ls(arr, x + 1) == true)
        {
            x = x + 1;
            len++;
            maxi = max(maxi, len);
        }
    }
    return maxi;
}

int main()
{
    vector<int> arr = {102, 4, 100, 1, 4, 3, 2, 1, 1};
    cout << Conse(arr);
}