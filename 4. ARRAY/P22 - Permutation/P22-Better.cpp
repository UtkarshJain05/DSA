// Next Permutataion (Better)

// Using STL Library.

#include <bits/stdc++.h>
using namespace std;

vector<int> Permutation(vector<int> &a)
{
    next_permutation(a.begin(), a.end());
    return a;
}

int main()
{
    vector<int> arr = {2, 1, 5, 4, 3, 0, 0};
    Permutation(arr);
    for (auto i : arr)
    {
        cout << i << " ";
    }
}
