// Rearrange Array By Sign.{Unequal} (Brute)   TC - O(2N)  ;  SC - O(N)

// Somewhat Merge Sort Algo.
#include <bits/stdc++.h>
using namespace std;
void Sign(vector<int> &arr)
{
    int n = arr.size();
    vector<int> hp, hn;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            hn.push_back(arr[i]);
        }
        else
        {
            hp.push_back(arr[i]);
        }
    }
    int pos = 0, neg = 0, i = 0;
    while (pos < hp.size() && neg < hn.size())
    {
        if (i % 2 == 0)
        {
            arr[i] = hp[pos];
            pos++;
        }
        else
        {
            arr[i] = hn[neg];
            neg++;
        }
        i++;
    }
    while (pos < hp.size())
    {
        arr[i] = hp[pos];
        pos++;
        i++;
    }
    while (neg < hn.size())
    {
        arr[i] = hn[neg];
        neg++;
        i++;
    }
    return;
}

int main()
{
    vector<int> arr = {-2, -3, 7, 5, 3, 6, 2};
    // 7 -2 5 -3 3 6 2
    Sign(arr);
    // vector<int> u = Sign(arr);
    for (auto i : arr)
    {
        cout << i << " ";
    }
}