// NUMBER HASHING

#include <bits/stdc++.h>
using namespace std;
int main()
{
    // Array Size Input
    int n;
    cin >> n;
    int arr[n];

    // Array Input.
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Hashing
    int hash[13] = {0};
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]]++;
    }

    // Output.
    int m;
    for (int i = 1; i <= 5; i++)
    {
        cin >> m;
        cout << hash[m] << "\n";
    }
}