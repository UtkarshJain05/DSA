// Min Days for M Bouquets.(Optimal)  -->  TC:O(n*(log(max-min)))   SC:O(1).

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

bool check(vector<int> &arr, int day, int m, int k)
{
    int nof = 0, nob = 0;
    for (auto i : arr)
    {
        if (i <= day)
        {
            nof++;
            if (nof == k)
            {
                nob++;
                nof = 0;
            }
        }
        else
            nof = 0;
    }
    return nob >= m;
}

int fnc(vector<int> &arr, int m, int k)
{
    int n = arr.size();
    if (n < (m * k))
        return -1;

    int low = ele(arr).first, high = ele(arr).second;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (check(arr, mid, m, k) == true)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}

int main()
{
    vector<int> flowers = {7, 7, 7, 7, 13, 11, 12, 7};
    int nob = 2, nof = 3;
    cout << fnc(flowers, nob, nof) << " Min. Days";
}