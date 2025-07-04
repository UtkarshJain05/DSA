// 3 Sum. (Optimal)    TC : O(N^2)     SC : O(1)

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> Three_Sum(vector<int> &arr, int target)
{
    int n = arr.size();
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    int i = 0;
    while (i < n)
    {
        int j = i + 1, k = n - 1;
        while (j < k)
        {
            if (arr[i] + arr[j] + arr[k] > target)
            {
                while (arr[k] == arr[k - 1] && (k - 1) > j)
                {
                    k--;
                }
                k--;
            }
            else if (arr[i] + arr[j] + arr[k] < target)
            {
                while (arr[j] == arr[j + 1] && (j + 1) < k)
                {
                    j++;
                }
                j++;
            }
            else
            {
                vector<int> temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp);
                while (arr[j] == arr[j + 1] && (j + 1) < k)
                {
                    j++;
                }
                j++;
                while (arr[k] == arr[k - 1] && (k - 1) > j)
                {
                    k--;
                }
                k--;
            }
        }
        while (arr[i] == arr[i + 1] && (i + 1) < n)
        {
            i++;
        }
        i++;
    }
    return ans;
}

// Note --> && (i+1 < n) is used here to prevent out of bound error in index.

int main()
{
    vector<int> arr = {-2, -2, -2, -1, -1, -1, 0, 0, 0, 2, 2, 2, 2};
    vector<vector<int>> u = Three_Sum(arr, -3);
    for (auto it : u)
    {
        for (auto ele : it)
        {
            cout << ele << " ";
        }
        cout << endl;
    }
}