// Majority Element > n/3 times. (Brute)     TC : O(N^2)   SC : O(1)

#include <bits/stdc++.h>
using namespace std;

vector<int> majority(vector<int> &arr)
{
    int n = arr.size();
    vector<int> ele;
    for (int i = 0; i < n; i++)
    {
        if (ele.size() == 0 || ele[0] != arr[i])
        {
            int count = 0;
            for (int j = 0; j < n; j++)
            {
                if (arr[i] == arr[j])
                {
                    count++;
                }
            }

            if (count > (n / 3))
            {
                ele.push_back(arr[i]);
            }
        }
        if (ele.size() == 2)
        {
            break;
        }
    }
    return ele;
}

int main()
{
    vector<int> arr = {1, 1, 1, 2, 2, 4, 3, 3};
    vector<int> u = majority(arr);
    for (auto i : u)
    {
        cout << i << " ";
    }
}