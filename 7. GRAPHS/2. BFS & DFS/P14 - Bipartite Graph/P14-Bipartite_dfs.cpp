// Bipartite Graph(DFS).  --> TC:O(V+2E)   SC:O(V)

#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, int curr_clr, vector<int> &color, vector<int> adj[])
{

    color[node] = curr_clr;
    for (auto it : adj[node])
    {
        if (color[it] == -1)
        {
            if (!dfs(it, !curr_clr, color, adj))
                return false;
        }
        else if (color[it] == color[node])
            return false;
    }
    return true;
}

bool bipartite(int V, vector<int> adj[])
{
    vector<int> color(V, -1);
    for (int i = 0; i < V; i++)
    {
        if (color[i] == -1)
        {
            if (!dfs(i, 0, color, adj))
                return false;
        }
    }
    return true;
}

int main()
{
    int V = 4;
    vector<int> adj[V];
    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[0].push_back(3);
    adj[3].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(2);

    cout << bipartite(V, adj);
}
