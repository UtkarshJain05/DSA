// Once Appeared Number.(Better - Hashing) --> TC - O(3N) ; SC - O(maxi+1).

#include <bits/stdc++.h>
using namespace std;

int uniqueno(vector<int> arr)
{
    int n = arr.size();

    // For Size of Hash Array we'll Find Max Element & then hash[max+1].

    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, arr[i]);
    }

    int hash[maxi + 1] = {0};
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]]++;
    }

    // Checking For Single Element.
    for (int i = 1; i <= n; i++)
    {
        if (hash[i] == 1)
            return i;
    }
}

int main()
{
    vector<int> arr = {1, 2, 1, 3, 3, 4, 4};
    cout << uniqueno(arr);
}