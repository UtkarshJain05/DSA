// Leaders (Brute)   TC : O(N^2)  ;  SC : O(N).

#include <bits/stdc++.h>
using namespace std;

vector<int> leader(vector<int> &arr)
{
    int n = arr.size();
    vector<int> lead;
    for (int i = 0; i < n; i++)
    {
        bool flag = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] < arr[j])
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
        {
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