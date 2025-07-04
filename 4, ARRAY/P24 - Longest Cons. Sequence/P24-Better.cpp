// Longest Consecutive Sequence. (Better) --> TC : O(NlogN)  SC : O(1).

#include <bits/stdc++.h>
using namespace std;

int Conse(vector<int> &arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    // 1 1 1 2 2 3 4 100 101 102
    int maxi = 1, count = 1;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] != arr[i + 1])
        {
            if (arr[i] + 1 == arr[i + 1])
            {
                count++;
                maxi = max(count, maxi);
            }
            else
            {
                count = 1;
            }
        }
    }
    return maxi;
}

int main()
{
    vector<int> arr = {102, 4, 4, 6, 7, 100, 103, 101, 104, 105, 1, 5, 3, 2, 2, 1, 1};
    cout << Conse(arr);
}