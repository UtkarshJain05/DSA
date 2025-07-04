// 2 Sum (B) - (Brute) --> TC : O(N^2) ; SC : O(1).

#include <bits/stdc++.h>
using namespace std;

vector<int> sum(vector<int> arr, int t)
{
    int n = arr.size();
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == t)
            {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> u = sum(arr, 10);
    for (auto i : u)
    {
        cout << i << " ";
    }
}