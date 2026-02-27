// Shortest Path for Undirected Graph with unit Weights.  -> TC:O(N+M)  SC:O(N+M).

#include <bits/stdc++.h>
using namespace std;
class Solution
{

public:
    vector<int> shortestPath(int n, vector<vector<int>> &edges, int src)
    {
        int m = edges.size();
        // Creating adjacency list.
        vector<int> adj[n];
        for (int i = 0; i < m; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Now BFS Traversal and updating dist arr

        vector<int> dist(n, 1e9);
        dist[src] = 0;
        queue<int>q;
        q.push(src);
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for (auto it : adj[node])
            {
                if ((dist[node] + 1) < dist[it])
                {
                    dist[it] = dist[node] + 1;
                    q.push(it);
                }
            }
        }

        // Marking Unreachable Node as -1.
        for (int i = 0; i < n; i++)
        {
            if (dist[i] == 1e9)
                dist[i] = -1;
        }

        return dist;
    }
};

int main()
{
    int n = 9;
    vector<vector<int>> edges = {
        {0, 1},
        {0, 3},
        {1, 2},
        {2, 6},
        {3, 4},
        {4, 5},
        {5, 6},
        {6, 7},
        {6, 8},
        {7, 8}};

    int src = 0;

    Solution obj;
    vector<int> ans = obj.shortestPath(n, edges, src);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}