// Rearrange Array By Sign. (Brute)   TC - O(N+N/2)  ;  SC - O(N)

#include <bits/stdc++.h>
using namespace std;

// hashing
void Sign(vector<int> &arr)
{
    int n = arr.size();
    vector<int> hashp;
    vector<int> hashn;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            hashn.push_back(arr[i]);
        }
        else
        {
            hashp.push_back(arr[i]);
        }
    }
    for (int i = 0; i < n / 2 + 1; i++)
    {
        arr[2 * i] = hashp[i];
        arr[2 * i + 1] = hashn[i];
    }
    return;
}

int main()
{
    vector<int> arr = {-2, -3, -4, -6, 7, 5, 3, 6, 2, -1};
    Sign(arr);
    for (auto i : arr)
    {
        cout << i << " ";
    }
}