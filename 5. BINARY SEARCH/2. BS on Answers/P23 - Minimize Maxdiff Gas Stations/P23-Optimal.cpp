// Insert Gas Stations (Optimal)  --> TC:(n*log(max_diff) + n)   SC:O(1).

#include <bits/stdc++.h>
using namespace std;

int count_stations(vector<int> &arr, long double dist)
{
    int n = arr.size();
    int cnt = 0;
    for (int i = 0; i < n - 1; i++)
    {
        long double diff = arr[i + 1] - arr[i];
        int num_station_btw = diff / dist;
        if (diff / dist == num_station_btw)
            num_station_btw--;
        cnt += num_station_btw;
    }
    return cnt;
}

long double fnc(vector<int> &arr, int k)
{
    int n = arr.size();
    long double low = 0, high = 0;
    for (int i = 0; i < n - 1; i++)
    {
        high = max(high, (long double)arr[i + 1] - arr[i]);
    }

    long double diff = 1e-6;

    // Binary Search On Answers
    while ((high - low) > diff)
    {
        long double mid = (low + high) / (2.0);
        int cnt = count_stations(arr, mid);
        if (cnt > k)
            low = mid;
        else
            high = mid;
    }
    return high;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;
    cout << fnc(arr, k);
}