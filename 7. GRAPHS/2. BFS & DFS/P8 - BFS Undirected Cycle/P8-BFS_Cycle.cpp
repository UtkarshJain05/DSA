// Cycle Detection BFS.   TC : O(N+2E)  SC : (2*N).

#include <bits/stdc++.h>
using namespace std;

bool cycle(int src, vector<int> adj[], vector<int> &vis, int n)
{
    vis[src] = 1;
    queue<pair<int, int>> q;
    q.push({src, -1});
    while (!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        for (auto it : adj[node])
        {
            if (vis[it] == 0)
            {
                vis[it] = 1;
                q.push({it, node});
            }
            else if (it != parent)
                return true;
        }
    }
    return false;
}

int main()
{
    vector<int> adj[8];
    adj[1] = {2, 3};
    adj[2] = {1, 5};
    adj[3] = {1, 4, 6};
    adj[4] = {3};
    adj[5] = {2, 7};
    adj[6] = {3, 7};
    adj[7] = {5, 6};

    bool result = 0;
    vector<int> vis(8, 0);
    for (int i = 1; i < 8; i++)
    {
        if (vis[i] == 0)
            if (cycle(i, adj, vis, 7))
            {
                result = true;
                break;
            }
    }
    cout << result;
}