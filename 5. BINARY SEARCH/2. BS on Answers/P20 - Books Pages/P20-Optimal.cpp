// Min(Max Pages of a student). (Optimal)  --> TC:O(n*log(sum-max))   SC:O(1)

#include <bits/stdc++.h>
using namespace std;

int check(vector<int> &arr, int max_pg, int s)
{
    int n = arr.size();
    int stu_no = 1, last = 0;
    for (int i = 0; i < n; i++)
    {
        if ((last + arr[i]) <= max_pg)
        {
            last += arr[i];
        }
        else
        {
            stu_no++;
            last = arr[i];
        }
    }
    return stu_no;
}

int fnc(vector<int> &arr, int s)
{
    int n = arr.size();
    if (s > n)
        return -1;
    int ans = INT_MAX;
    int low = *max_element(arr.begin(),arr.end());
    int high = accumulate(arr.begin(),arr.end(),0);
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int nos = check(arr, mid, s);
        if (nos <= s)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}

int main()
{
    vector<int> arr = {25, 46, 28, 49, 24};
    int student = 4;
    cout << fnc(arr, student);
}