// 3 Sum. (Better)    TC : O(N^2 * log(M))     SC : O(N + 2*(No. of Unique Triplets.))

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> Three_Sum(vector<int> &arr,int target)
{
    int n = arr.size();
    set<vector<int>> st;
    for (int i = 0; i < n; i++)
    {
        set<int> s;
        for (int j = i + 1; j < n; j++)
        {
            int third = target-(arr[i] + arr[j]);
            if (s.find(third) != s.end())
            {
                vector<int> temp = {arr[i], arr[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            s.insert(arr[j]);
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

int main()
{
    vector<int> arr = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> u = Three_Sum(arr,-3);
    for (auto it : u)
    {
        for (auto ele : it)
        {
            cout << ele << " ";
        }
        cout << endl;
    }
}