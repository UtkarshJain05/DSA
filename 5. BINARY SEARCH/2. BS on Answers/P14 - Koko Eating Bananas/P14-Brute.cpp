// KOKO Eating Bananas.(Brute) --> TC:O(Max(arr)*n)  Sc:O(1).
// (Minutes count to 1 Hr.)

#include <bits/stdc++.h>
using namespace std;

int TimeReq(vector<int> &arr, int k, int h)
{
    int total_time = 0;
    for (auto i : arr)
    {
        total_time += ceil((double)i / (double)k);
        if (total_time > h)
            return 2;
    }
    return 1;
}

int fnc(vector<int> &arr, int h)
{
    int n = arr.size();
    int maxi = *max_element(arr.begin(), arr.end());
    for (int k = 1; k <= maxi; k++)
    {
        int val = TimeReq(arr, k, h);
        if (val == 1)
            return k;
    }
    return -1; // just for fulfilling fnc datatype.
}

int main()
{
    vector<int> arr = {3, 6, 7, 11};
    int h = 8;
    cout << fnc(arr, h) << " Bananas/Hr.";
}