// Stack Buy Or Sell  TC : O(N)    SC : O(1)

#include <bits/stdc++.h>
using namespace std;

int sell(vector<int> arr)
{
    int n = arr.size();
    int maxprofit = 0;
    int buy = arr[0];
    for (int i = 1; i < n; i++)
    {
        buy = min(arr[i], buy);
        int profit = arr[i] - buy;
        maxprofit = max(maxprofit, profit);
    }
    return maxprofit;
}

int main()
{
    vector<int> arr = {7, 5, 3, 2, 1, 6, 8, 0};
    cout << sell(arr);
}