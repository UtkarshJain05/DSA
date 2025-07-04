// Missing & Repeating Elements.(Optimal_2) -->  TC : O(n)   SC : O(1)
// Using XOR

#include <bits/stdc++.h>
using namespace std;

vector<int> fnc(vector<int> &arr)
{
    int n = arr.size();
    int missing = -1, repeating = -1;

    // Xor of (arr) & (1 to n).
    int xr = 0;
    for (int i = 0; i < n; i++)
    {
        xr ^= arr[i];
        xr ^= (i + 1);
    }

    // Here xr = x^y.

    // Finding Differentiating  bit in Number.
    int bitno = 0;
    while (true)
    {
        if ((xr & (1 << bitno)) != 0)
        {
            break;
        }
        bitno++;
    }

    
    int zero = 0;
    int one = 0;

    // Dividing All Elements in 2 groups wrt bitno. of arr.
    for (int i = 0; i < n; i++)
    {
        if ((arr[i] & (1 << bitno)) != 0)
        {
            one ^= arr[i];
        }
        else
        {
            zero ^= arr[i];
        }
    }

    // Dividing All Elements in 2 groups wrt bitno. from (1 to n).
    for (int i = 1; i <= n; i++)
    {
        if ((i & (1 << bitno)) != 0)
        {
            one ^= i;
        }
        else
        {
            zero ^= i;
        }
    }

    // Finding Which is Missing and Repeating.
    int cnt_0 = 0, cnt_1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == zero)
        {
            cnt_0++;
        }
    }
    if (cnt_0 == 2)
    {
        repeating = zero;
        missing = one;
    }
    else
    {
        repeating = one;
        missing = zero;
    }

    return {missing, repeating};
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