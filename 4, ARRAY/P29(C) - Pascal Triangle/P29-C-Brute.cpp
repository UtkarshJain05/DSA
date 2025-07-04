// Pascal Triangle (Brute)     TC : O(n*n*r)    SC : O(1)

#include <bits/stdc++.h>
using namespace std;

int ncr(int n, int r)
{
    long long ans = 1;
    for (int k = 0; k < r; k++)
    {
        ans = ans * (n-k)/(k+1);
    }
    return ans;
}
vector<vector<int>> pascal(int n)
{
    vector<vector<int>> res;
    for (int row = 1; row <= n; row++)
    {
        int i = row - 1;
        vector<int> Col;
        int ans;
        for (int col = 1; col <= row; col++)
        {
            int j = col - 1;
            ans = ncr(i, j);
            Col.push_back(ans);
        }
        res.push_back(Col);
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> u = pascal(n);
    for (auto it : u)
    {
        for (auto ele : it)
        {
            cout << ele << " ";
        }
        cout << endl;
    }
}