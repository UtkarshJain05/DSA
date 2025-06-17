// Bubble Sorting {Optimised}

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n = 8;
    int arr[n] = {1, 2, 3, 4, 5, 6, 7, 8};
    int pass = 1;
    while (pass < n)
    {
        bool flag = true;
        for (int i = 0; i < n - pass; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                flag = false;
            }
        }
        if (flag == true)
        {
            cout << "Array Sorted in " << pass - 1 << " passes.\n";
            break;
        }
        pass++;
    }
    cout << "Sorted Array : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}