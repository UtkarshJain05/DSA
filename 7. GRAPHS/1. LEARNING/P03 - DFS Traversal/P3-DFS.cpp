// DFS Traversal  -->  TC:O(V+E))  SC:O(3*V).

// V = No. of Nodes.
// 1 based Graph.

#include <bits/stdc++.h>
using namespace std;

void dfs_traversal(int node, vector<int> &vis, vector<int> &ans, vector<int> adj[])
{
    vis[node] = 1;
    ans.push_back(node);
    for (auto it : adj[node])
    {
        if (vis[it] == 0)
            dfs_traversal(it, vis, ans, adj);
    }
    return;
}

vector<int> graph_traversal(int node, vector<int> adj[], int n)
{
    vector<int> ans;
    vector<int> vis(n + 1, 0);
    dfs_traversal(node, vis, ans, adj);
    return ans;
}

int main()
{
    vector<int> adj[9];
    adj[1] = {2, 3};
    adj[2] = {1, 5, 6};
    adj[3] = {1, 4, 7};
    adj[4] = {3, 8};
    adj[5] = {2};
    adj[6] = {2};
    adj[7] = {3, 8};
    adj[8] = {4, 7};

    vector<int> result = graph_traversal(1, adj, 8);
    for (auto it : result)
    {
        cout << it << " ";
    }
}