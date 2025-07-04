// 4 Sum (Brute). --> TC : O(N^4 * log(No. of Quadruplet))   SC : O(No. of Quadruplet)

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> four_sum(vector<int> &arr, int t)
{
    int n = arr.size();
    set<vector<int>> st;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                for (int l = k + 1; l < n; l++)
                {
                    if (arr[i] + arr[j] + arr[k] + arr[l] == t)
                    {
                        vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

int main()
{
    vector<int> u = {1, 0, -1, 0, -2, 2};
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
