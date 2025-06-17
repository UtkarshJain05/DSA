// Insertion Sort

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[5] = {7, 5, 6, 4, 3};
    int n = 5, j;
    for (int i = 1; i < n; i++)
    {
        j = i;
        while (j > 0 && arr[j] < arr[j - 1])
        {
            swap(arr[j], arr[j - 1]);
            j--;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}