// Print Largest Subarray with length of sum = 0. (Brute) --> TC : O(N^2)   SC : O(1)

#include <bits/stdc++.h>
using namespace std;

int sum(vector<int> &arr)
{
    int n = arr.size();
    int maxi = 0;
    int ansstart = -1, ansend = -1;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;

        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum == 0)
            {
                int len = j - i + 1;
                if (len > maxi)
                {
                    maxi = len;
                    ansstart = i, ansend = j;
                }
            }
        }
    }
    for (int i = ansstart; i <= ansend; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return maxi;
}

int main()
{
    vector<int> arr = {1, 2, -2, 4, -4};
    cout << sum(arr);
}
