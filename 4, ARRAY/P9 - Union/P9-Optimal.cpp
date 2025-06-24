// Union (Optimal).

#include <bits/stdc++.h>
using namespace std;

vector<int> Union(int arr[], int brr[], int m, int n)
{
    vector<int> uni;
    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if (arr[i] <= brr[j])
        {
            if (uni.empty() == 1 || uni.back() != arr[i])
            {
                uni.emplace_back(arr[i]);
            }
            i++;
        }

        else
        {
            if (uni.empty() == 1 || uni.back() != brr[j])
            {
                uni.emplace_back(brr[j]);
            }
            j++;
        }
    }
    while (i < m)
    {
        if (uni.empty() == 1 || arr[i] != uni.back())
        {
            uni.emplace_back(arr[i]);
        }
        i++;
    }
    while (j < n)
    {
        if (uni.empty() == 1 || brr[j] != uni.back())
        {
            uni.emplace_back(brr[j]);
        }
        j++;
    }
    return uni;
}

int main()
{
    int arr[10] = {1, 2, 5, 5, 6, 8, 8, 9, 10, 11};
    int brr[5] = {3, 5, 5, 6, 6};
    vector<int> u = Union(arr, brr, 10, 5);
    for (auto it : u)
    {
        cout << it << " ";
    }
}
