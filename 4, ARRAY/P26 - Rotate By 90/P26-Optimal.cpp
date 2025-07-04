// Rotate Matrix By 90 Degree. (Optimal)   TC : O(2*N)    SC : O(1)

#include <bits/stdc++.h>
using namespace std;

/*
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
*/

/*
13 9 5 1
14 10 6 2
15 11 7 3
16 12 8 4
*/

void Rotate(vector<vector<int>> &arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i < j)
            {
                swap(arr[i][j], arr[j][i]);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0, k = n - 1; j < k; j++, k--)
        {
            swap(arr[i][j], arr[i][k]);
        }
    }
}

int main()
{
    vector<vector<int>> arr = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    int n = arr.size();
    Rotate(arr, n);
    for (auto it : arr)
    {
        for (auto ele : it)
        {
            cout << ele << " ";
        }
        cout << endl;
    }
}