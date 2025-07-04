// Left Rotate The Array by K Places. (Optimal)

#include <bits/stdc++.h>
using namespace std;

void reverse(int arr[], int si, int ei)
{
    for (int i = si, j = ei; i < j; i++, j--)
    {
        swap(arr[i], arr[j]);
    }
}
void Krotate(int arr[], int n, int k)
{
    k = k % n;
    reverse(arr, 0, n-1);
    reverse(arr, 0, n - k-1);
    reverse(arr, n - k, n-1);
}


int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Krotate(arr, 10, 4);
    for (auto i : arr)
    {
        cout << i << " ";
    }
}