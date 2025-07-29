// Insert Gas Stations (Better)  --> TC:(nlogn + k*log(n))   SC:O(2*(n-1)).

#include <bits/stdc++.h>
using namespace std;

long double fnc(vector<int> arr, int k)
{
    int n = arr.size();
    vector<int> ele_spc(n - 1, 0);

    // Just Entering {Secdiff,spcidx}
    priority_queue<pair<long double, int>> pq;
    for (int i = 0; i < n - 1; i++)
    {
        long double diff = arr[i + 1] - arr[i];
        pq.push({diff, i});
    }

    // Inserting k Gas Stations.
    for (int gas = 1; gas <= k; gas++)
    {
        int secidx = pq.top().second;
        pq.pop();
        ele_spc[secidx]++;

        long double diff_ini = arr[secidx + 1] - arr[secidx];  // Original Diff.
        long double secdiff = diff_ini / (long double)(ele_spc[secidx] + 1);
        
        pq.push({secdiff, secidx});
    }
    return pq.top().first;
}

int main()
{
    vector<int> arr = {1, 13, 17, 23};
    int k = 4;
    cout << fnc(arr, k);
}