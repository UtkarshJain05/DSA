// Sort Array Of 0's 1's & 2's.(Optimal)  TC --> O() ; SC --> O().

// DUTCH NATIONAL FLAG ALGORITHM.

#include <bits/stdc++.h>
using namespace std;

void arrange(vector<int> &arr)
{
    int n = arr.size();
    int low = 0, mid = 0, high = n - 1;
    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            low++, mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
    return;
}

int main()
{
    vector<int> arr = {0, 1, 2, 0, 1, 2, 0, 1, 2};
    arrange(arr);
    for (auto i : arr)
    {
        cout << i << " ";
    }
}