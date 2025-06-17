// Largest Element.(Optimal) --> TC : O() ; SC : O().

#include <bits/stdc++.h>
using namespace std;

// Optimal Approach:
int largest_Element(int arr[], int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    return max;
}
int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 61, 7, 8, 9, 10};
    cout << largest_Element(arr, 10);
}