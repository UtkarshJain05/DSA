// MATRIX Spiral. (Optimal)    TC : O(nxm)    SC : (nxm).

#include <bits/stdc++.h>
using namespace std;

vector<int> matrix(vector<vector<int>> &arr, int n, int m)
{
    vector<int> brr;
    int minr = 0, maxc = m - 1, maxr = n - 1, minc = 0;
    int count = 0;
    int tne = n * m;
    while (count < tne)
    {
        // minr
        for (int j = minc; j <= maxc && count < tne; j++)
        {
            brr.push_back(arr[minr][j]);
            count++;
        }
        minr++;
        // maxc
        for (int i = minr; i <= maxr && count < tne; i++)
        {
            brr.push_back(arr[i][maxc]);
            count++;
        }
        maxc--;
        // maxr
        for (int j = maxc; j >= minc && count < tne; j--)
        {
            brr.push_back(arr[maxr][j]);
            count++;
        }
        maxr--;
        // minc
        for (int i = maxr; i >= minr && count < tne; i--)
        {
            brr.push_back(arr[i][minc]);
            count++;
        }
        minc++;
    }
    cout << endl
         << tne << " " << count << endl;
    return brr;
}

int main()
{
    vector<vector<int>> arr = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}, {16, 17, 18, 19, 20}, {21, 22, 23, 24, 25}};
    int n = arr.size();
    int m = arr[0].size();
    for (auto it : arr)
    {
        for (auto ele : it)
        {
            cout << ele << " ";
        }
        cout << endl;
    }

    cout << endl
         << endl;

    vector<int> brr = matrix(arr, n, m);
    for (auto it : brr)
    {
        cout << it << " ";
    }
}