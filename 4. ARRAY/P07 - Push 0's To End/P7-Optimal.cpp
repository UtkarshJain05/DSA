// Push 0's To End. (Better) --> TC : O(N)  SC : O(1)

#include <bits/stdc++.h>
using namespace std;

vector<int> push(vector<int> &arr)
{
    int n = arr.size();
    int zidx = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            zidx = i;
            break;
        }
    }
    for (int i = zidx + 1; i < n; i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[zidx], arr[i]);
            zidx++;
        }
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