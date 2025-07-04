// Leader (Optimal)   TC : O(N)   SC : O(N)

#include <bits/stdc++.h>
using namespace std;

vector<int> leader(vector<int> &arr)
{
    int n = arr.size();
    vector<int> lead;
    int max = INT_MIN;
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            lead.push_back(arr[i]);
        }
    }
    return lead;
}

int main()
{
    vector<int> a = {10, 22, 12, 3, 0, 6};
    vector<int> u = leader(a);
    for (auto i : u)
    {
        cout << i << " ";
    }
}