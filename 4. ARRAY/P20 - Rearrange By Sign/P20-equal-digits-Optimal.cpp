// Rearrange Array By Sign. (Optimal)   TC - O(N)  ;  SC - O(N)

#include <bits/stdc++.h>
using namespace std;

vector<int> Sign(vector<int> arr)
{
    int n = arr.size();
    vector<int> ans (n, 0);
    int pos = 0, neg = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= 0)
        {
            ans[pos] = arr[i];
            pos += 2;
        }
        else
        {
            ans[neg] = arr[i];
            neg += 2;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {-2, -3, -4, -6, 7, 5, 3, 6, 2, -1};
    vector<int> u = Sign(arr);
    for (auto i : u)
    {
        cout << i << " ";
    }
}