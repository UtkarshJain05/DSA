// Majority Element > N/2 -   TC: O(N)  ; SC : O(1).

// Moore's Voting Algorithm.

#include <bits/stdc++.h>
using namespace std;

int majority_optimal(vector<int> arr)
{
    int n = arr.size();
    int el = arr[0], cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == el)
        {
            cnt++;
        }
        else
        {
            cnt--;
        }
        if (cnt == 0)
        {
            el = arr[i + 1];
        }
    }
    int cnt_el = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == el)
        {
            cnt_el++;
        }
    }
    if (cnt_el > (n / 2))
    {
        return el;
    }
    return -1;
}

int main()
{
    vector<int> arr = {2, 3, 3, 3, 3, 3, 1, 2, 2};
    cout << majority_optimal(arr);
}