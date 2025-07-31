// Max (Min. Distance b/w cows).(Optimal) --> TC : O((nlogn)+(n*log(max-min)))   SC:O(1)

#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &arr, int min_dis, int cows)
{
    int n = arr.size();
    int cnt_cows = 1, last = arr[0];
    for (int i = 1; i < n; i++)
    {
        if ((arr[i] - last) >= min_dis)
        {
            last = arr[i];
            cnt_cows++;
        }
    }
    return cnt_cows >= cows;
}

int fnc(vector<int> &arr, int cows)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    int low = 1, high = arr[n - 1] - arr[0];
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (check(arr, mid, cows) == true)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return high;
}

int main()
{
    vector<int> arr = {0, 3, 4, 7, 9, 10};
    int cows = 4;
    cout << fnc(arr, cows) << " Units.";
}