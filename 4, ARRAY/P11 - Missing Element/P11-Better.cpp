// Missing Element.(Better) --> TC - O(2N) ; SC - O(N+1).

#include <bits/stdc++.h>
using namespace std;

int better(vector<int> arr) // Hashing
{
    int n = arr.size();
    int hash[n + 1] = {0};
    for (int i = 0; i < n - 1; i++)
    {
        hash[arr[i]] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        if (hash[i] == 0)
        {
            return i;
        }
    }
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 8, 9, 10};
    int it = better(arr);
    cout << it;
}