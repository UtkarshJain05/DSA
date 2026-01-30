// Eventual Safe States. (Cycle Detection DFS) --> TC:O(V+E)  SC:O(V)

// Terminal Nodes -> Which have outdegree = 0
// Safe Node -> Whose all outdegrees path ends terminal nodes.

// Algo: If an element connected or a part of cycle to be not safe.

#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<int> &vis, vector<int> &path, vector<int> &check, vector<int> adj[])
{
    vis[node] = 1;
    path[node] = 1;

    for (auto it : adj[node])
    {
        if (vis[it] == 0)
        {
            if (dfs(it, vis, path, check, adj))
            {
                check[node] = 0;
                return true;
            }
        }
        else if (path[it] == 1)
        {
            check[node] = 0;
            return true;
        }
    }
    path[node] = 0;
    check[node] = 1;
    return false;
}

vector<int> safe_node(int V, vector<int> adj[])
{
    vector<int> vis(V + 1, 0);
    vector<int> path(V + 1, 0);
    vector<int> check(V + 1, 0);
    vector<int> ans;
    for (int i = 1; i <= V; i++)
    {
        if (vis[i] == 0)
            dfs(i, vis, path, check, adj);
    }

    for (int i = 1; i <= V; i++)
    {
        if (check[i] == 1)
            ans.push_back(i);
    }
    return ans;
}

int main()
{
    int V = 11;

    // Graph nodes are 1-based indexed
    vector<int> adj[V + 1];
    adj[1] = {2};
    adj[2] = {3};
    adj[3] = {4, 7};
    adj[4] = {5};
    adj[5] = {6};
    adj[6] = {};
    adj[7] = {5};
    adj[8] = {2, 9};
    adj[9] = {10};
    adj[10] = {8};
    adj[11] = {9};

    vector<int> ans = safe_node(V, adj);

    for (auto it : ans)
        cout << it << " ";
}