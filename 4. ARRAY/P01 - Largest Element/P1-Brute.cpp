// Largest Element.(Optimal) --> TC - O(NlogN) ; SC : O(1).

#include <bits/stdc++.h>
using namespace std;

int largest(vector<int> &arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end()); // Sorting The Array {Shortcut}.
    return arr[n - 1];
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 61, 79, 8, 9, 10};
    cout << largest(arr);
}