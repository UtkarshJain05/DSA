// Median of 2 Sorted Array.(Optimal) --> TC:O(log(min(n1, n2)))  SC:O(1).

#include <bits/stdc++.h>
using namespace std;

double fnc(vector<int> &a, vector<int> &b)
{
    int n1 = a.size();
    int n2 = b.size();
    if (n1 > n2)
        return fnc(b, a);
    int left = (n1 + n2 + 1) / 2;
    int low = 0, high = n1;
    int n = n1 + n2;
    while (low <= high)
    {

        int mid1 = (low + high) / 2;
        int mid2 = left - mid1;
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;
        if (mid1 < n1)
            r1 = a[mid1];
        if (mid2 < n2)
            r2 = b[mid2];
        if (mid1 - 1 >= 0)
            l1 = a[mid1 - 1];
        if (mid2 - 1 >= 0)
            l2 = b[mid2 - 1];
        if (l1 > r2)
            high = mid1 - 1;
        else if (l2 > r1)
            low = mid1 + 1;
        else
        {
            if (n % 2 == 1)
                return max(l1, l2);
            else
                return (double)(max(l1, l2) + min(r1, r2)) / (2.0);
        }
    }
    return 0;
}

int main()
{
    vector<int> arr = {2, 4, 6};
    vector<int> brr = {1, 3, 5};
    cout << fnc(arr, brr);
}
