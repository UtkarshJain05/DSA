// Bipartite Graph(BFS).  --> TC:O(V+2E)   SC:O(V)

#include <bits/stdc++.h>
using namespace std;

bool bfs(int start, vector<int> &color, vector<int> adj[])
{
    color[start] = 0;
    queue<int> q;
    q.push(start);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto it : adj[node])
        {
            if (color[it] == -1)
            {
                color[it] = !color[node];
                q.push(it);
            }
            else if (color[it] == color[node])
            {
                return false;
            }
        }
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
            if (!bfs(i, color, adj))
                return false;
        }
    }
    return true;
}

int main()
{
    int V = 3;
    vector<int> adj[V];

    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[2].push_back(0);
    adj[0].push_back(2);

    cout << bipartite(V, adj);
}
