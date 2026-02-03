// Kahn's Algorithm.  --> TC:O(V+E)   SC:O(V)

#include <bits/stdc++.h>
using namespace std;

vector<int> kahn_sort(int V, vector<int> adj[])
{
    vector<int> indegree(V, 0);

    // Filling Indegree Array
    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }

    // Pushing all nodes (indegree = 0) in q.
    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    vector<int> ans;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);

        // Remove the edge from indegree for adj. nodes
        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
                q.push(it);
        }
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

    vector<int> ans = kahn_sort(V, adj);
    for (auto it : ans)
        cout << it << " ";
}