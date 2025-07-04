// Pascal Triangle - Specific Row (Brute).   TC : O(n*r)     SC : O(1)

#include <bits/stdc++.h>
using namespace std;

long long ncr(int n, int r)
{
    long long ans = 1;
    for (int i = 0; i < r; i++)
    {
        ans = ans * (n - i) / (i + 1);
    }
    return ans;
}

vector<int> pascal(int n)
{
    vector<int> res;
    int ans = 1;
    for (int c = 1; c <= n; c++)
    {
        ans = ncr(n - 1, c - 1);
        res.push_back(ans);
    }
    return res;
}

int main()
{
    int row;
    cin >> row;
    vector<int> u = pascal(row);
    for (auto i : u)
    {
        cout << i << " ";
    }
}