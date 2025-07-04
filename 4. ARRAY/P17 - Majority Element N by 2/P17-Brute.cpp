// Majority Element > N/2 -   TC --> O(N^2) ; SC O(1).

#include <bits/stdc++.h>
using namespace std;

int majority_brute(vector<int> arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = i; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
        }
        if (count > (n / 2))
            return arr[i];
    }
    return -1;
}

int main()
{
    vector<int> arr = {2, 3, 3, 3, 3, 3, 1, 2, 2};
    cout << majority_brute(arr);
}