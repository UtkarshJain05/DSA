// Push 0's To End. (Better) --> TC : O(N+K)  SC : O(1)

#include <bits/stdc++.h>
using namespace std;

vector<int> push(vector<int> &arr)
{
    int n = arr.size();
    int idx = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            arr[idx] = arr[i];
            idx++;
        }
    }
    for (int i = idx; i < n; i++)
    {
        arr[i] = 0;
    }
    return arr;
}

int main()
{
    vector<int> arr = {1, 0, 0, 2, 0, 3};
    vector<int> u = push(arr);
    for (auto i : u)
    {
        cout << i << " ";
    }
}