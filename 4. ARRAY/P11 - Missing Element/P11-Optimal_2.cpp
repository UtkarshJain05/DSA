// Missing Element.(Optimal_2) --> TC - O(N) ; SC - O(1).

#include <bits/stdc++.h>
using namespace std;

int optimal_2(vector<int> arr) // XOR (^)
{
    int n = arr.size();
    int XOR1 = 0, XOR2 = 0;
    for (int i = 0; i < n - 1; i++)
    {
        XOR1 = XOR1 ^ i + 1;
        XOR2 = XOR2 ^ arr[i];
    }
    XOR1 = XOR1 ^ n;
    return XOR1 ^ XOR2;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 8, 9, 10};
    int it = optimal_2(arr);
    cout << it;
}