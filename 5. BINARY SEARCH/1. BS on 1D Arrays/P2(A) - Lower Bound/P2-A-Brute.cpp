// Lower Bound (index)-> (Linear Search)  --> TC : O(N)  SC : O(1)

#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> arr, int x)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= x)
        {
            // lower bound found:
            return i;
        }
    }
    return n;
}

int main()
{
    vector<int> arr = {3, 5, 8, 15, 19};
    int x = 9;
    int idx = lowerBound(arr, x);
    cout << idx;
}
