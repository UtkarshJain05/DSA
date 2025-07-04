// Rotate Matrix By 90 Degree. (Brute)   TC : O(N^2)    SC : O(N^2)

#include <bits/stdc++.h>
using namespace std;

/*
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16*/

/*
13 9 5 1
14 10 6 2
15 11 7 3
16 12 8 4*/

vector<vector<int>> Rotate(vector<vector<int>> arr, int n)
{
    vector<vector<int>> brr(n,vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            brr[j][n-1-i] = arr[i][j];
        }
    }
    return brr;
}

int main()
{
    vector<vector<int>> arr = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    int n = arr.size();
    vector<vector<int>> u = Rotate(arr, n);
    for (auto it : u)
    {
        for (auto ele : it)
        {
            cout << ele << " ";
        }
        cout << endl;
    }
}