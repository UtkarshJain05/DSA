// Linear Search.

#include <bits/stdc++.h>
using namespace std;

int LS(int arr[], int n, int k)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == k)
        {
            return i;
        }
    }
    return -1;
    
}
int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << LS(arr, 10, 11);
}