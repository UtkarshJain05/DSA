// BFS Traversal  -->  TC:O(V+2E)  SC:O(3*V).

// V = No. of Nodes.
// 0 based Graph.
#include <bits/stdc++.h>
using namespace std;

vector<int> bfs_traverse(int V, vector<int> adj[])
{
    vector<int> ans;
    int vis[V] = {0};
    vis[0] = 1;
    queue<int> q;
    q.push(0);
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        ans.push_back(temp);
        for (auto i : adj[temp])
        {
            if (vis[i] != 1)
            {
                q.push(i);
                vis[i] = 1;
            }
        }
    }
    return ans;
}

void addEdge(int u, int v, vector<int> adj[])
{
    adj[u].push_back(v);
    adj[v].push_back(u);
    return;
}
int main()
{
    vector<int> adj[6];
    addEdge(5, 4, adj);
    addEdge(0, 1, adj);
    addEdge(0, 2, adj);
    addEdge(0, 3, adj);
    addEdge(2, 4, adj);

    vector<int> ans = bfs_traverse(6, adj);
    for (auto i : ans)
    {
        cout << i << " ";
    }
}