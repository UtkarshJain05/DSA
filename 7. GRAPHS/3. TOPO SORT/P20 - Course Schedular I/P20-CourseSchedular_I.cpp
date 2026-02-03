// Course Schedular - I.(BFS).  TC:O(V+E)   SC:O(V)
// Algo --> Detect Cycle if yes -> not possible ; else -> return true.

#include <bits/stdc++.h>
using namespace std;

bool canFinish(int numCourses, vector<pair<int, int>> &prerequisites)
{
    int V = numCourses;

    // Creating Adj List.
    vector<int> adj[V];
    for (auto it : prerequisites)
        adj[it.second].push_back(it.first);

    // Creating Indegree.
    vector<int> indegree(V, 0);
    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
            indegree[it]++;
    }

    // queue
    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    // Cycle Detection.
    int cnt = 0;
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

    // Cycle Detected.
    if (cnt != V)
        return false;

    return true;
}

int main()
{
    int numCourses = 6;
    vector<pair<int, int>> prerequisitesArr = {
        {1, 0},
        {2, 1},
        {3, 2},
        {4, 3},
        {5, 4}};

    canFinish(numCourses, prerequisitesArr);
}