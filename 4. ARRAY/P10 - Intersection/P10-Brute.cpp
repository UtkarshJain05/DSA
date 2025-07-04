// Intersection (Brute).   TC --> O(mxn) ; SC --> O(n)+ O(m+n).

#include <bits/stdc++.h>
using namespace std;

vector<int> Intersection(vector<int> arr, vector<int> brr)
{
    int m = arr.size();
    int n = brr.size();
    vector<int> in;
    int vis[n] = {0};
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i] < brr[j])
                break;
            if (arr[i] == brr[j] && vis[j] == 0)
            {
                in.push_back(arr[i]);
                vis[j] = 1;
                break;
            }
        }
    }
    return in;
}

int main()
{
    vector<int>arr= {1, 1, 2, 3, 3, 5};
    vector<int>brr= {1, 2, 3, 3, 5};
    vector<int> u = Intersection(arr, brr);
    for (auto i : u)
    {
        cout << i << " ";
    }
}