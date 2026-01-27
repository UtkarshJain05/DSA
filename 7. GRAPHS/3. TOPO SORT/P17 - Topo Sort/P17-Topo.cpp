// Topological Sort --> Only For DAG.  --> TC:O(V+E)   SC:O(N)
// DAG -> Directed Acyclic Graph.

#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> &vis, stack<int> &st, vector<int> adj[])
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
            dfs(it, vis, st, adj);
    }
    st.push(node);
    return;
}

vector<int> topo(int V, vector<int> adj[])
{
    vector<int> vis(V, 0);
    stack<int> st;
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfs(i, vis, st, adj);
        }
    }

    vector<int> ans;
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

int main()
{
    int V = 6;
    vector<int> adj[V];

    adj[0] = {};
    adj[1] = {};
    adj[2] = {3};
    adj[3] = {1};
    adj[4] = {0, 1};
    adj[5] = {0, 2};

    vector<int> ans = topo(V, adj);
    for (auto it : ans)
    {
        cout << it << " ";
    }
}