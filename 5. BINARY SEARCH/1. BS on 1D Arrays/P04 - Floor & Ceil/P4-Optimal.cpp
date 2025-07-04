// Floor And Ceiling in Array -> (Binary Search)  --> TC : O(logN)  SC : O(1)

#include <bits/stdc++.h>
using namespace std;

// Floor
int findFloor(vector<int> arr, int t)
{
    int n = arr.size();
    int floor = -1;
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] <= t)
        {
            floor = arr[mid];
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return floor;
}

// Ceil
int findCeil(vector<int> arr, int t)
{
    int n = arr.size();
    int ceil = -1;
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] >= t)
        {
            ceil = arr[mid];
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ceil;
}

pair<int, int> getFloorAndCeil(vector<int> &arr, int x)
{
    int f = findFloor(arr, x);
    int c = findCeil(arr, x);
    return make_pair(f, c);
}

int main()
{
    vector<int> arr = {1, 2, 4, 7};
    int t = 8;
    pair<int, int> ans = getFloorAndCeil(arr, t);
    cout << "The floor is " << ans.first
         << " and ceil is " << ans.second << endl;
}