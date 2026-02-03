// Detect Cycle in Directed Graph Using bfs. --> TC:O(V+E)  SC:O(V).

#include <bits/stdc++.h>
using namespace std;

bool kahn_cycle(int V, vector<int> adj[])
{
    // Creating Indegree.
    vector<int> indegree(V+1,0);
    for (int i = 1; i <= V; i++)
    {
        for (auto it : adj[i])
            indegree[it]++;
    }

    queue<int> q;
    // Running Kahn's Algo
    for (int i = 1; i <= V; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    int cnt = 0;
    // In cycle Elements Indegree will != 0.
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cnt++;
        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
                q.push(it);
        }
    }

    // if (cnt != V) then there's a cycle.
    if (cnt != V)
        return true;
    return false;
}

int main()
{
    int V = 10;

    // Graph nodes are 1-based indexed
    vector<int> adj[V + 1];
    adj[1] = {2};
    adj[2] = {3};
    adj[3] = {4, 7};
    adj[4] = {5};
    adj[5] = {6};
    adj[6] = {};
    adj[7] = {5};
    adj[8] = {2, 9};
    adj[9] = {10};
    adj[10] = {8};

    cout << kahn_cycle(V, adj);
}