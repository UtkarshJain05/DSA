// Finding x In Sorted Array.(Iterative)  --> TC : O(logN)  SC : O(1)

#include <bits/stdc++.h>
using namespace std;

int fnc(vector<int> &arr, int t)
{
    int n = arr.size();
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        // low++;
        if (arr[mid] < t)
            low = mid + 1;
        // high--
        else if (arr[mid] > t)
            high = mid - 1;
        else
            return mid;
    }
    return -1;
}

int main()
{
    vector<int> a = {3, 4, 6, 7, 9, 12, 16, 17};
    int t = 10;
    int idx = fnc(a, t);
    if (idx != -1)
        cout << t << " is at Index : " << idx;
    else
        cout << t << " is Not Present in the Array.";
}