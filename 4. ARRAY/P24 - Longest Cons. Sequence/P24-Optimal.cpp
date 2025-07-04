// Longest Consecutive Sequence. (Optimal) --> TC : O(3N)  SC : O(N).

#include <bits/stdc++.h>
using namespace std;

int Conse(vector<int> arr)
{
    int n = arr.size();
    unordered_set<int> st;
    for (int i = 0; i < n; i++)
    {
        st.insert(arr[i]);
    }

    int maxi = INT_MIN;
    for (auto it : st)
    {
        if (st.find(it - 1) == st.end())
        {
            int count = 1;
            int x = it;
            while (st.find(x + 1) != st.end())
            {
                x++;
                count++;
            }
            maxi = max(maxi, count);
        }
    }
    return maxi;
}

int main()
{
    vector<int> arr = {102, 4, 100, 1, 101, 3, 2, 1, 1};
    cout << Conse(arr);
}