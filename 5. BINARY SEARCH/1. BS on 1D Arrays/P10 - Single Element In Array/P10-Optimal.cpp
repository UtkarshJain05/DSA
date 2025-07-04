// Search Single Element In Array.(Optimal)  --> TC : O(logN)   SC : O(1)

#include <bits/stdc++.h>
using namespace std;

int fnc(vector<int> &arr)
{
    int n = arr.size();
    if (n == 1)
        return arr[0];
    if (arr[0] != arr[1])
        return arr[0];
    if (arr[n - 1] != arr[n - 2])
        return arr[n - 1];

    int low = 1, high = n - 2;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1])
        {
            return arr[mid];
        }

        // Eliminating Left Part.
        else if ((mid % 2 == 0 && arr[mid] == arr[mid + 1]) or (mid % 2 != 0 && arr[mid] == arr[mid - 1]))
        {
            low = mid + 1;
        }

        // Eliminating Right Part.
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};
    cout << fnc(arr);
}