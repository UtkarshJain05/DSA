// Union (Brute).

#include <bits/stdc++.h>
using namespace std;

vector<int> Union(int arr[], int brr[], int m, int n)
{
    set<int> st;
    for (int i = 0; i < m; i++)
    {
        st.insert(arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        st.insert(brr[i]);
    }
    vector<int> uni;
    for (auto i : st)
    {
        uni.emplace_back(i);
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