// Cycle Detection in Directed Graph (DFS). -->  TC:O(V+E)  SC:O(V)    

#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &path)
{
    vis[node] = 1;
    path[node] = 1;

    // Checking Adj Nodes.
    for (auto it : adj[node])
    {
        // if node is not vis.
        if (!vis[it])
        {
            if (dfs(it, adj, vis, path) == true)
                return true;
        }

        // If vis node and in same path.
        else if (path[it])
        {
            return true;
        }
    }

    path[node] = 0;
    return false;
}

bool CheckCycle(int V, vector<int> adj[])   
{
    vector<int> vis(V + 1, 0);
    vector<int> path(V + 1, 0);
    for (int i = 1; i <= V; i++)
    {
        if (!vis[i])
        {
            if (dfs(i, adj, vis, path) == true)
                return true;
        }
    }
    return false;
}

int main()
{
    int V = 10;

    // Graph nodes are 1-based indexed
    vector<int> adj[V + 1];
    adj[1] = {2};
    adj[2] = {3};
    adj[3] = {4, 7};
    adj[4] = {5};
    adj[5] = {6};
    adj[6] = {};
    adj[7] = {5};
    adj[8] = {9};
    adj[9] = {10};
    adj[10] = {8};

    cout << CheckCycle(V, adj);
}