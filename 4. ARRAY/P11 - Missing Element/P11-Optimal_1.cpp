// Missing Element.(Optimal) --> TC - O(n-1) ; SC - O(1).

#include <bits/stdc++.h>
using namespace std;

int optimal_1(vector<int> arr) // Sum(Digits) - Sum(Array Elements)
{
    int n = arr.size();
    int sum = n * (n + 1) / 2;
    int s2 = 0;
    for (int i = 0; i < n - 1; i++)
    {
        s2 = s2 + arr[i];
    }
    return sum - s2;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 8, 9, 10};
    int it = optimal_1(arr);
    cout << it;
}