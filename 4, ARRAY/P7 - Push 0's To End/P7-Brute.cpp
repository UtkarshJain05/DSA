// Push 0's To End. (Brute) --> TC : O(2N)  SC : O(N)

#include <bits/stdc++.h>
using namespace std;

vector<int> push(vector<int> &arr)
{
    int n = arr.size();
    vector<int> temp;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            temp.push_back(arr[i]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (i < temp.size())
            arr[i] = temp[i];
        else
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