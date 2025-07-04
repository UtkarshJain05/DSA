// Pascal Triangle - Specific Row (Optimal).   TC : O(n)     SC : O(1)

#include <bits/stdc++.h>
using namespace std;

vector<int> pascal(int n)
{
    vector<int> res;
    int ans = 1; // idx = 0
    res.push_back(ans);

    // Starting From Idx = 1.
    for (int col = 2; col <= n; col++)
    {
        int i = col - 1;
        ans = ans * (n - i) / (i);
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