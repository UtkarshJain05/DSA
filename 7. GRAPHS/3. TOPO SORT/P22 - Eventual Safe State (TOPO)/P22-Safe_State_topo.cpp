// Eventual Safe Nodes. (Topo)  --> TC:O()   SC:O().
// Algo : Reverse the Adj list and apply topo.
// Because topo works on (indegree==0) while Terminal Node -> ends at (outdegree==0).

#include <bits/stdc++.h>
using namespace std;

vector<int> safe_node(int V, vector<int> adj[])
{
    // Reverse Adj list & Indegree.
    vector<int> indegree(V, 0);
    vector<int> adjRev[V];
    for (int i = 0; i < V; i++)
    {
        // i -> it (given)
        // it -> i (to be created)
        for (auto it : adj[i])
        {
            adjRev[it].push_back(i);
            indegree[i]++;
        }
    }

    // Pushing all Terminals in q.
    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    // Detecting Cycle and pushing in ans.
    vector<int> ans;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for (auto it : adjRev[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
                q.push(it);
        }
    }

    // Final Sorted Ans.
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    int V = 7;
    vector<int> adj[V + 1];
    adj[0] = {1};
    adj[1] = {2, 3};
    adj[2] = {5};
    adj[3] = {0};
    adj[4] = {5};
    adj[5] = {};
    adj[6] = {};
    vector<int> ans = safe_node(V, adj);

    for (auto it : ans)
        cout << it << " ";
}