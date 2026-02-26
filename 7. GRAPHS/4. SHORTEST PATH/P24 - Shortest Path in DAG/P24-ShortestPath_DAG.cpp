// Shortest Path in DAG.  --> TC:O(N+M)  SC:O(N+M).

#include <bits/stdc++.h>
using namespace std;

class Solution
{

private:
    void dfs(int node, vector<int> &vis, stack<int> &st, vector<pair<int, int>> adj[])
    {
        vis[node] = 1;
        for (auto it : adj[node])
        {
            if (!vis[it.first])
                dfs(it.first, vis, st, adj);
        }
        st.push(node);
        return;
    }

public:
    vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
    {
        // Creating Adj List
        vector<pair<int, int>> adj[N];
        for (int i = 0; i < M; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
        }

        // Topo Sort
        // O(N+E)
        vector<int> vis(N, 0);
        stack<int> st;
        for (int i = 0; i < N; i++)
        {
            if (!vis[i])
                dfs(i, vis, st, adj);
        }

        // Pick Stack Element and mark dis array.
        // O(N+M)
        vector<int> dist(N, 1e9);
        int src = 0;
        dist[src] = 0;
        while (!st.empty())
        {
            int node = st.top();
            st.pop();

            for (auto it : adj[node])
            {
                int v = it.first;
                int wt = it.second;
                if (wt + dist[node] < dist[v])
                    dist[v] = wt + dist[node];
            }
        }

        return dist;
    }
};

int main()
{
    int N = 4;
    int M = 1;

    vector<vector<int>> edges = {{2, 3, 5}};

    Solution obj;
    vector<int> ans = obj.shortestPath(N, M, edges);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}