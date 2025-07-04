// Pascal Triangle (Optimal)     TC : O(n^2)    SC : O(1)

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> pascal(int n)
{
    vector<vector<int>> res;
    for (int row = 1; row <= n; row++)
    {
        vector<int> Col;

        // col = 1;
        int ans = 1;
        Col.push_back(ans);

        // Starting from col = 2.
        for (int col = 2; col <= row; col++)
        {
            int j = col - 1;
            ans = ans * (row - j) / (j);
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