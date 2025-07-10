// Min Days for M Bouquets.(Brute)  -->  TC:O(n*(max-min))   SC:O(1).

#include <bits/stdc++.h>
using namespace std;

pair<int, int> ele(vector<int> &arr)
{
    int maxi = INT_MIN;
    int mini = INT_MAX;
    for (auto i : arr)
    {
        mini = min(i, mini);
        maxi = max(i, maxi);
    }
    return {mini, maxi};
}

bool check(vector<int> &arr, int min, int m, int k)
{
    int cnt = 0;
    int nob = 0;
    for (auto i : arr)
    {
        if (i <= min)
        {
            cnt++;
            if (cnt == k)
            {
                nob++;
                cnt = 0;
            }
        }
        else
        {
            cnt = 0;
        }
    }
    return nob >= m;
}

int fnc(vector<int> &arr, int m, int k)
{
    int n = arr.size();
    if (n < (m * k))
        return -1;
    for (int i = ele(arr).first; i <= ele(arr).second; i++)
    {
        if (check(arr, i, m, k) == true)
            return i;
    }
    return -1;
}

int main()
{
    vector<int> flowers = {7, 7, 7, 7, 13, 11, 12, 7};
    int nob = 2, nof = 3;
    cout << fnc(flowers, nob, nof) << " Min. Days";
}