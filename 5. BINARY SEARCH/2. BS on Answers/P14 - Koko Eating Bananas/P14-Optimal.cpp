// KOKO Eating Bananas.(Optimal) --> TC:O(n*Log(Max(arr)))   Sc:O(1).
// (Minutes count to 1 Hr.)

#include <bits/stdc++.h>
using namespace std;

int TimeReq(vector<int> &arr, int k, int h)
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

int fnc(vector<int> &arr, int h)
{
    int n = arr.size();
    int maxi = *max_element(arr.begin(), arr.end());
    int low = 1, high = maxi;
    while (low <= high)
    {
        int k = (low + high) / 2;
        int val = TimeReq(arr, k, h);
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