// Cycle Detection BFS.   TC : O(N+2E)  SC : (2*N).

#include <bits/stdc++.h>
using namespace std;

bool bfs(int start, vector<int> adj[], vector<int> &vis)
{
    queue<pair<int, int>> q;
    q.push({start, -1}); // {node, parent}
    vis[start] = 1;

    while (!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                vis[it] = 1;
                q.push({it, node});
            }
            else if (it != parent)
            {
                return true; // cycle detected
            }
        }
    }
    return false;
}

bool isCycle(vector<int> adj[], int n)
{
    vector<int> vis(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if (bfs(i, adj, vis))
                return true;
        }
    }
    return false;
}

int main()
{
    int n = 7;
    vector<int> adj[n + 1];

    adj[1] = {2, 3};
    adj[2] = {1, 5};
    adj[3] = {1, 4, 6};
    adj[4] = {3};
    adj[5] = {2, 7};
    adj[6] = {3, 7};
    adj[7] = {5, 6};

    cout << isCycle(adj, n);
}