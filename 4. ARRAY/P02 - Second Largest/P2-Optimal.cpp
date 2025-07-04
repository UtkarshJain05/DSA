// Second Largest Element.(Optimal) --> TC - O(N) ; SC : O(1).

#include <bits/stdc++.h>
using namespace std;

int second_largest(vector<int> arr)
{
    int n = arr.size();
    int max = INT_MIN, smax = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            smax = max;
            max = arr[i];
        }
        else if (arr[i] > smax && arr[i] != max)
        {
            smax = arr[i];
        }
    }
    return smax;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 4, 5, 5, 10};
    cout << second_largest(arr);
}