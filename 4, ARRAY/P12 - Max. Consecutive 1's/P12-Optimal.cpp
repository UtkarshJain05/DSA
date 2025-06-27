// Maximum Consecutive 1's (Optimal) --> TC - O(N) ; SC - O(1).

#include <bits/stdc++.h>
using namespace std;

int optimal(vector<int> arr)
{
    int n = arr.size();
    int maxi = INT_MIN;
    int cons = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
        {
            cons++;
            maxi = max(cons, maxi);
        }
        else
        {

            cons = 0;
        }
    }
    return maxi;
}
int main()
{
    vector<int> arr = {1, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1};
    int it = optimal(arr);
    cout << it;
}