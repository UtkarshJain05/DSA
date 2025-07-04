// Search Insert Position -> (Linear Search)  --> TC : O(N)  SC : O(1)

#include <bits/stdc++.h>
using namespace std;

int fnc(vector<int> arr, int t)
{
    int n = arr.size();
    int ans = n;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= t)
        {
            ans = i;
            return ans;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {2, 3, 4, 7};
    int t = 1;
    cout << fnc(arr, t);
}