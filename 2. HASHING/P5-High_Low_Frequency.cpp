// Print Highest and Lowest frequency Elements of Array.   TC : O(NlogN)   SC : O(1)

#include <bits/stdc++.h>
using namespace std;

void count(vector<int> &arr)
{
    int maxe = 0, max = INT_MIN;
    int mine = 0, min = INT_MAX;
    int n = arr.size();
    sort(arr.begin(), arr.end());
    int count = 1;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            count++;
        }
        else
        {
            if (min > count)
            {
                min = count;
                mine = arr[i];
            }
            if (max < count)
            {
                max = count;
                maxe = arr[i];
            }
            count = 1;
        }
    }
    if (count < min)
    {
        min = count;
        mine = arr[n - 1];
    }
    if (count > max)
    {
        max = count;
        maxe = arr[n - 1];
    }
    cout << maxe << " " << mine;
}

int main()
{
    vector<int> arr = {10, 5, 10, 15, 10, 5};
    count(arr);
}
