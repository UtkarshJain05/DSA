// Missing & Repeating Elements.(Brute) -->  TC : O(n^2)   SC : O(1)

#include <bits/stdc++.h>
using namespace std;

vector<int> fnc(vector<int> &arr)
{
    int n = arr.size();
    int missing = -1, repeating = -1;
    for (int i = 1; i <= n; i++)
    {
        int count = 0;
        for (auto j : arr)
        {
            if (i == j)
            {
                count++;
            }
        }
        if (count == 0)
            missing = i;
        else if (count == 2)
            repeating = i;

        if (missing != -1 && repeating != -1)
            break;
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