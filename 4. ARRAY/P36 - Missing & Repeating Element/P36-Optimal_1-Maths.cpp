// Missing & Repeating Elements.(Optimal_1) -->  TC : O(N)   SC : O(1)
// Basic Maths.

#include <bits/stdc++.h>
using namespace std;

vector<int> fnc(vector<int> &arr)
{
    int n = arr.size();
    long long SN = ((n) * (n + 1)) / 2;
    long long S2N = ((n) * (n + 1) * (2 * n + 1)) / 6;

    long long S = 0;
    long long S2 = 0;
    for (auto i : arr)
    {
        S += i;
        S2 += (long long)i * (long long)i;
    }

    // x = Missing & y = Repeating
    long long val1 = S - SN;   // x-y
    long long val2 = S2 - S2N; // x2-y2 --> (x-y)(x+y)
    val2 = val2 / val1;        // x+y
    long long x = (val1 + val2) / 2;
    long long y = x - val1;

    return {(int)x, (int)y};
}

int main()
{
    vector<int> arr = {4, 3, 6, 2, 1, 1};
    vector<int> ans = fnc(arr);
    for (auto i : ans)
    {
        cout << i << " ";
    }
}