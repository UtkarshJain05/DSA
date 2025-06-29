// 2 Sum (A) - (Optimal) --> TC : O(N) ; SC : O(1).

#include <bits/stdc++.h>
using namespace std;

string sum(vector<int> arr, int t)
{
    int n = arr.size();
    int i = 0, j = n - 1;
    while (i < j)
    {
        if (arr[i] + arr[j] < t)
        {
            i++;
        }
        else if (arr[i] + arr[j] > t)
        {
            j--;
        }
        else
        {
            return "Yes.";
        }
    }
    return "No.";
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << sum(arr, 18);
}
