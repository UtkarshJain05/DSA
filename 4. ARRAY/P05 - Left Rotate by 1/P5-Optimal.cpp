// Left Rotate the Array by One place. 

#include <bits/stdc++.h>
using namespace std;

void rotate(int arr[], int n)
{
    int temp = arr[0];
    for (int i = 1; i < n; i++)
    {
        arr[i - 1] = arr[i];
    }
    arr[n - 1] = temp;
}

int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    rotate(arr, 10);
    for (auto i : arr)
    {
        cout << i << " ";
    }
}