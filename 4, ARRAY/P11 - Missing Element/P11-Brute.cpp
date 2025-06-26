// Missing Element.(Brute) -->  TC - O(N^2) ; SC - O(1).

#include <bits/stdc++.h>
using namespace std;

int brute(vector<int> arr) // Sequence Digit Traversal.
{
    int n = arr.size();
    for (int i = 1; i <= n; i++)
    {
        int flag = 0;
        for (int j = 0; j < n - 1; j++) // here n-1 is used becoz 1 element is missing in arr.
        {
            if (arr[j] == i)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            return i;
    }
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 8, 9, 10};
    int it = brute(arr);
    cout << it;
}