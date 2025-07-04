// Sort Array Of 0's 1's & 2's.(Better)  TC --> O(2N) ; SC --> O(1).

#include <bits/stdc++.h>
using namespace std;

void arrange(vector<int> &arr)
{
    int n = arr.size();
    int cnt_0 = 0, cnt_1 = 0, cnt_2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            cnt_0++;
        }
        else if (arr[i] == 1)
        {
            cnt_1++;
        }
        else
        {
            cnt_2++;
        }
    }
    
    for (int i = 0; i < cnt_0; i++)
    {
        arr[i] = 0;
    }
    for (int i = cnt_0; i < cnt_0 + cnt_1; i++)
    {
        arr[i] = 1;
    }
    for (int i = cnt_0 + cnt_1; i < n; i++)
    {
        arr[i] = 2;
    }
}

int main()
{
    vector<int> arr = {0, 1, 2, 0, 1, 2, 0, 1, 2};
    arrange(arr);
    for (auto i : arr)
    {
        cout << i << " ";
    }
}