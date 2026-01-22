// Cycle Detection DFS.   TC : O(V+E)  SC : (2*V).

#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, int parent, vector<int> adj[], vector<int> &vis)
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (vis[it] == 0)
        {
            if (dfs(it, node, adj, vis) == true)
                return true;
        }
        // Else if already includes vis[it]==1.
        else if (it != parent)
            return true;
    }
    return false;
}

bool isCycle(int V, vector<int> adj[])
{
    vector<int> vis(V + 1, 0);

    // Handling Disconnected Graph.
    for (int i = 1; i <= V; i++)
    {
        if (vis[i] == 0)
            if (dfs(i, -1, adj, vis))
                return true;
    }
    return false;
}

int main()
{
    int V = 7;
    vector<int> adj[V + 1];

    adj[1] = {2, 3};
    adj[2] = {1, 5};
    adj[3] = {1, 4, 6};
    adj[4] = {3};
    adj[5] = {2, 7};
    adj[6] = {3, 7};
    adj[7] = {5, 6};

    cout << isCycle(V, adj);
}