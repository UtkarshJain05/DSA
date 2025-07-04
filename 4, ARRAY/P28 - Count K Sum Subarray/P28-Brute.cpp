// Count Subarray with Sum K.(Brute)  TC : O(N^2)    SC : (1)

#include <bits/stdc++.h>
using namespace std;

int Cnt_Subarray(vector<int> &arr, int k)
{
    int n = arr.size();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum == k)
            {
                count++;
            }
        }
    }
    return count;
}

int main()
{
    vector<int> arr = {1, 2, 3, -3, 1, 1, 1, 4, 2, -3};
    cout << Cnt_Subarray(arr, 3);
}