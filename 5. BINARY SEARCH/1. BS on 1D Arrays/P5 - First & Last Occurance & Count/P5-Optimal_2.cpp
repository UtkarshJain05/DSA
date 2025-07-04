// First & Last Occurance -> (Binary Search)  --> TC : O(logN)  SC : O(1)
// Using Pure Binary Search

// Count Occurances.

#include <bits/stdc++.h>
using namespace std;

int first(vector<int> arr, int t)
{
    int n = arr.size();
    int first = -1;
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == t)
        {
            first = mid;
            high = mid - 1;
        }
        else if (arr[mid] < t)
        {
            low = mid + 1;
        }

        else // arr[mid]>t
        {
            high = mid - 1;
        }
    }
    return first;
}

int last(vector<int> arr, int t)
{
    int n = arr.size();
    int last = -1;
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == t)
        {
            last = mid;
            low = mid + 1;
        }
        else if (arr[mid] < t)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return last;
}

pair<int, int> occurance(vector<int> arr, int t)
{
    if (first(arr, t) == -1)
        return {-1, -1};
    return {first(arr, t), last(arr, t)};
}

int count(pair<int, int> ans)
{
    if (ans.first == -1)
        return 0;
    else
        return {ans.second - ans.first + 1};
}
int main()
{
    vector<int> arr = {2, 8, 8, 8, 8, 8, 11, 13};
    int t = 8;

    // First And Last Occurance:
    pair<int, int> ans = occurance(arr, t);
    cout << ans.first << " --> " << ans.second << endl;

    // Count Occurances:
    cout << count(ans);
}