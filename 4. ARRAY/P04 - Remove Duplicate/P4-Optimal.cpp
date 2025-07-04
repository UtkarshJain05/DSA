// Remove Duplicate Elements From Sorted Array. (Optimal)

#include <bits/stdc++.h>
using namespace std;

vector<int> fnc(vector<int> &arr)
{
    int n = arr.size();
    int uni = 1;
    for (int i = 0; i < n-1; i++)
    {
        if (arr[i] != arr[i + 1])
        {
            arr[uni] = arr[i + 1];
            uni++;
        }
    }
    arr.resize(uni);
    return arr;
}

int main()
{
    vector<int> arr = {1, 1, 1, 2, 2, 3, 4, 5, 5, 6, 7};
    vector<int> u = fnc(arr);
    for (auto i : u)
    {
        cout << i << " ";
    }
}