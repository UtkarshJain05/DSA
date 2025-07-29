// Insert Gas Stations (Brute)  --> TC:(k*(n-1))   SC:O(n-1).

#include <bits/stdc++.h>
using namespace std;

long double fnc(vector<int> arr, int k)
{
    int n = arr.size();
    vector<int> ele_spc(n - 1, 0);

    // Just Insertion of gas stations.
    for (int gas = 1; gas <= k; gas++)
    {
        long double maxdiff = -1;
        int maxspidx = -1;

        // Finding Max Section.
        for (int i = 0; i < n - 1; i++)
        {
            long double diff = arr[i + 1] - arr[i];
            long double secdiff = diff / (long double)(ele_spc[i] + 1);
            if (secdiff > maxdiff)
            {
                maxdiff = secdiff;
                maxspidx = i;
            }
        }
        ele_spc[maxspidx]++;
    }

    // Finding Max diff or ans;
    long double maxdis = -1;
    for (int i = 0; i < n - 1; i++)
    {
        long double diff = arr[i + 1] - arr[i];
        long double secdiff = diff / (long double)(ele_spc[i] + 1);
        maxdis = max(maxdis, secdiff);
    }
    return maxdis;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    int k = 6;
    cout << fnc(arr, k);
}