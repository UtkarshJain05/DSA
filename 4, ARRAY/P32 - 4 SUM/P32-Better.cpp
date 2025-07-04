// 4 Sum (Better). --> TC : O(N^3 * log(No. of Quadruplet))   SC : O(No. of Quadruplet + N)

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
            unordered_set<int> s;
            for (int k = j + 1; k < n; k++)
            {
                int four = t - (arr[i] + arr[j] + arr[k]);
                if (s.find(four) != s.end())
                {
                    vector<int> temp = {arr[i], arr[j], arr[k], four};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                s.insert(arr[k]);
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
