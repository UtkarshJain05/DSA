// Number of Provinces.  --> TC:O(N+V+2E)   SC:O(2N)

#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> &vis, vector<int> adj[])
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (vis[it] == 0)
            dfs(it, vis, adj);
    }
    return;
}

int n_provinces(vector<int> adj[], int n)
{
    int ans = 0;
    vector<int> vis(n + 1, 0);
    for (int v = 1; v <= n; v++)
    {
        if (vis[v] == 0)
        {
            ans++;
            dfs(v, vis, adj);
        }
    }
    return ans;
}

int main()
{
    vector<int> adj[9];
    adj[1] = {2};
    adj[2] = {1, 3};
    adj[3] = {2};
    adj[4] = {5};
    adj[5] = {4, 6};
    adj[6] = {5};
    adj[7] = {8};
    adj[8] = {7};

    int ans = n_provinces(adj, 8);
    cout << "No. of Provinces = " << ans;
}