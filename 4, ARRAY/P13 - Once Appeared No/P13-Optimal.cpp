// Once Appeared Number.(Optimal) --> TC - O(N) ; SC - O(1).

#include <bits/stdc++.h>
using namespace std;

int uniqueno(vector<int> arr)
{
    int n = arr.size();
    int XOR = 0;
    for (int i = 0; i < n; i++)
    {
        XOR ^= arr[i];
    }

    return XOR;
}

int main()
{
    vector<int> arr = {1, 2, 1, 3, 3, 4, 4};
    cout << uniqueno(arr);
}