// Search Insert Position -> (Binary Search)  --> TC : O(logN)  SC : O(1)

#include <bits/stdc++.h>
using namespace std;

int fnc(vector<int> arr, int t)
{
    int n = arr.size();
    int ans = n;
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] >= t)
        {
            ans = mid;      // may be an answer.
            high = mid - 1; // checking for smaller Position.
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {2, 3, 4, 7};
    int t = 2.5;
    cout << t << endl;
    cout << fnc(arr, t);
}