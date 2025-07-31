// KOKO Eating Bananas.(Optimal) --> TC:O(n*Log(Max(arr)))   Sc:O(1).
// (Minutes count to 1 Hr.)

#include <bits/stdc++.h>
using namespace std;

int Time_Req(vector<int> &arr, int h, int k)
{
    int total_time = 0;
    for (auto i : arr)
    {
        total_time += ceil((double)i / k);
        if (total_time > h)
            return 2;
    }
    return 1;
}

int maxi(vector<int> &arr)
{
    int maxi = INT_MIN;
    for (auto i : arr)
    {
        maxi = max(i, maxi);
    }
    return maxi;
}

int fnc(vector<int> &arr, int h)
{
    int low = 1, high = maxi(arr);
    while (low <= high)
    {
        int k = (low + high) / 2;
        int val = Time_Req(arr, h, k);
        if (val == 1)
            high = k - 1;
        else
            low = k + 1;
    }
    return low;
}

int main()
{
    vector<int> arr = {3, 6, 7, 11};
    int h = 8;
    cout << fnc(arr, h) << " Bananas/Hr.";
}