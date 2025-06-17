// Second Largest Element.(Brute) --> TC - O(N + NlogN) ; SC : O(1).

#include <bits/stdc++.h>
using namespace std;

int second_largest(vector<int> &arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    int largest = arr[n - 1];
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] != largest)
        {
            return arr[i];
        }
    }
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 4, 5, 5, 10};
    cout << second_largest(arr);
}