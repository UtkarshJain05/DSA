// Majority Element > n/3 times. (Optimal)     TC : O(2N)   SC : O(1)

#include <bits/stdc++.h>
using namespace std;

vector<int> majority(vector<int> &arr)
{
    int n = arr.size();
    vector<int> ls;
    int ele1, ele2;
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (cnt1 == 0 && arr[i] != ele2)
        {
            cnt1++;
            ele1 = arr[i];
        }
        else if (cnt2 == 0 && arr[i] != ele1)
        {
            cnt2++;
            ele2 = arr[i];
        }
        else if (arr[i] == ele1)
            cnt1++;
        else if (arr[i] == ele2)
            cnt2++;
        else
            cnt1--, cnt2--;
    }

    cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == ele1)
            cnt1++;
        if (arr[i] == ele2)
            cnt2++;
    }
    if (cnt1 > n / 3)
        ls.push_back(ele1);
    if (cnt2 > n / 3)
        ls.push_back(ele2);

    return ls;
}

int main()
{
    vector<int> arr = {1, 1, 1, 2, 2, 2, 3, 3};
    vector<int> u = majority(arr);
    for (auto i : u)
    {
        cout << i << " ";
    }
}