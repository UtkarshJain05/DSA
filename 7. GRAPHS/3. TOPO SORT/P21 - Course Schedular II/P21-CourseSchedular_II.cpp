// Course Schedular - II.(DFS).  TC:O(V+E)   SC:O(V)
// Algo --> Detect Cycle if yes -> Return Empty Array; else -> Return Course Sequence.

#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<int> &vis, vector<int> &path, stack<int> &st, vector<int> adj[])
{
    vis[node] = 1;
    path[node] = 1;
    for (auto it : adj[node])
    {
        if (vis[it] == 0)
        {
            if (dfs(it, vis, path, st, adj) == false)
                return false;
        }

        // Cycle Detected.
        else if (path[it] == 1)
            return false;
    }
    path[node] = 0;
    st.push(node);
    return true;
}

vector<int> findOrder(int numCourses, vector<pair<int, int>> &prerequisites)
{
    int n = numCourses;

    // Creating Adj List.
    vector<int> adj[n];
    for (auto it : prerequisites)
        adj[it.second].push_back(it.first);

    vector<int> ans;
    vector<int> vis(n, 0);
    vector<int> path(n, 0);
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 0)
        {
            if (dfs(i, vis, path, st, adj) == false)
                return ans;
        }
    }

    // Final Ans.
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }

    return ans;
}

int main()
{
    int numCourses = 4;
    vector<pair<int, int>> prerequisitesArr = {
        {1, 0},
        {2, 0},
        {3, 1}};

    vector<int> ans = findOrder(numCourses, prerequisitesArr);
    for (auto it : ans)
        cout << it << " ";
}