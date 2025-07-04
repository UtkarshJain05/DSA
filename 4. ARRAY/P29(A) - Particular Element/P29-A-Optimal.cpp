// Pascal Triangle - Particular Element (Optimal).   TC : O(r)     SC : O(1)

#include <bits/stdc++.h>
using namespace std;

long long ncr(int n, int r)
{
    long long ans = 1;
    // At idx = 0 ans will come for next idx. (i.e idx = 1).
    for (int i = 0; i < r; i++)
    {
        ans = ans * (n - i) / (i + 1);
    }
    return ans;
}

long long pascal(int row, int col)
{
    long long res;
    res = ncr(row - 1, col - 1);
    return res;
}

int main()
{
    int row, col;
    cin >> row >> col;
    cout << pascal(row, col);
}