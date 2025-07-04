// Left Rotate The Array by K Places. (Brute)

#include <bits/stdc++.h>
using namespace std;

void Krotate(int arr[], int n, int k)
{
    k = k % n;
    vector<int> temp;
    for (int i = 0; i < n; i++)
    {
        if (i < k)
        {
            temp.emplace_back(arr[i]);
        }
        else
        {
            arr[i - k] = arr[i];
        }
    }
    for (int i = n - k; i < n; i++)
    {
        arr[i] = temp[i - n + k];
    }
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
