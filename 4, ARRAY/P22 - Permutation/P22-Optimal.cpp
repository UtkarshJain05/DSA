// Next Permutataion (Optimal)  --> TC : O(3N)  ,  SC : O(1).

#include <bits/stdc++.h>
using namespace std;

void Permutation(vector<int> &arr)
{
    int n = arr.size();

    // 1. Find Break Point.
    int idx = -1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] < arr[i + 1])
        {
            idx = i;
            break;
        }
    }
    // If Last Permutation is Given print 1st one.
    if (idx == -1)
    {
        reverse(arr.begin(), arr.end());
        return;
    }

    // 2. Find Minimum Greater Number Than arr[idx].
    for (int i = n - 1; i > idx; i--)
    {
        if (arr[i] > arr[idx])
        {
            swap(arr[i], arr[idx]);
            break;
        }
    }

    // 3. Sort The Remaining array.
    reverse(arr.begin() + idx + 1, arr.end());

    return;
}

int main()
{
    vector<int> arr = {2, 1, 5, 4, 3, 0, 0};
    Permutation(arr);
    for (auto i : arr)
    {
        cout << i << " ";
    }
}