// Intersection (Optimal).  TC --> O(a+b) ; SC --> O(a+b).

#include <bits/stdc++.h>
using namespace std;

vector<int> Intersection(vector<int> arr, vector<int> brr)
{
    int a = arr.size();
    int b = brr.size();
    vector<int> inter;
    int i = 0, j = 0;
    while (i < a && j < b)
    {
        if (arr[i] == brr[j])
        {
            inter.push_back(arr[i]);
            i++, j++;
        }
        else if (arr[i] < brr[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    return inter;
}

int main()
{
    vector<int> arr = {1, 1, 2, 3, 3, 5}, brr = {1, 2, 3, 3, 4, 5};
    vector<int> u = Intersection(arr, brr);
    for (auto i : u)
    {
        cout << i << " ";
    }
}