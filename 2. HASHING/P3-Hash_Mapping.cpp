// HASH MAPPING

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];

    map<int, int> hash;
    // Note --> If unordered map is used then TC will be less than map for Average cases.

    // Input And Hash-Mapping.
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        hash[arr[i]]++;
    }

    // printing Map.
    for (auto it : hash)
    {
        cout << it.first << " --> " << it.second << endl
             << endl;
    }

    int q;
    cin >> q;
    // No. of Inputs too check Frequency.
    while (q--)
    {
        int m;
        cin >> m;
        cout << hash[m] << endl;
    }
}