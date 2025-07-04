// 4 Sum (Optimal). --> TC : O(N^3)   SC : O(1)

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> four_sum(vector<int> &arr, int t)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    int i = 0;
    while (i < n)
    {
        int j = i + 1;
        while (j < n)
        {
            int k = j + 1, l = n - 1;
            while (k < l)
            {
                long long sum = arr[i] + arr[j];
                sum += arr[k];
                sum += arr[l];

                if (sum < t)
                {
                    while (arr[k] == arr[k + 1] && (k + 1) < l)
                    {
                        k++;
                    }
                    k++;
                }
                else if (sum > t)
                {
                    while (arr[l] == arr[l - 1] && (l - 1) > k)
                    {
                        l--;
                    }
                    l--;
                }
                else
                {
                    vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
                    ans.push_back(temp);
                    while (arr[k] == arr[k + 1] && (k + 1) < l)
                    {
                        k++;
                    }
                    k++;
                    while (arr[l] == arr[l - 1] && (l - 1) > k)
                    {
                        l--;
                    }
                    l--;
                }
            }
            while (arr[j] == arr[j + 1] && (j + 1) < n)
            {
                j++;
            }
            j++;
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
    vector<int> u = {1, 0, -1, 0, -2, 2};
    // Another Eg. --> {1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5}  : T = 8.
    vector<vector<int>> p = four_sum(u, 0);
    for (auto i : p)
    {
        for (auto it : i)
        {
            cout << it << " ";
        }
        cout << endl;
    }
}
