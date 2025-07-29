// Min(Max Pages of a student). (Brute)  --> TC:O(n*(sum-max+1))   SC:O(1)

#include <bits/stdc++.h>
using namespace std;

pair<int, int> arr_info(vector<int> &arr)
{
    int maxi = INT_MIN;
    int sum = 0;
    for (auto i : arr)
    {
        sum += i;
        maxi = max(maxi, i);
    }
    return {maxi, sum};
}

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
    for (int i = arr_info(arr).first; i <= arr_info(arr).second; i++)
    {
        if (check(arr, i, s) == s)
            return i;
    }
}

int main()
{
    vector<int> arr = {25, 46, 28, 49, 24};
    int student = 4;
    cout << fnc(arr, student);
}