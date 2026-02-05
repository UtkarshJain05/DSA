// Alien Dictionary.   TC:O((N*L)+(V+E))   SC:O(V+E)

#include <bits/stdc++.h>
using namespace std;

vector<int> topoSort(int V, vector<int> adj[])
{
    vector<int> indegree(V, 0);
    // Creating Indegree.
    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
            indegree[it]++;
    }

    // Creating q and staring topo sort.
    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    vector<int> topo_ans;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topo_ans.push_back(node);
        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
                q.push(it);
        }
    }

    return topo_ans;
}

string findOrder(string dict[], int N, int K)
{
    vector<int> adj[K];
    // graph Creation.
    for (int i = 0; i < N - 1; i++)
    {
        string s1 = dict[i];
        string s2 = dict[i + 1];
        int len = min(s1.length(), s2.length());
        bool mismatchFound = false;

        for (int j = 0; j < len; j++)
        {
            if (s1[j] != s2[j])
            {
                adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                mismatchFound = true;
                break;
            }
        }

        // Prefix Invalid Case.
        if (!mismatchFound && s1.length() > s2.length())
            return "";
    }

    vector<int> topo = topoSort(K, adj);

    // Cycle Detected Case.
    if (topo.size() != K)
        return "";
    string ans = "";
    for (auto it : topo)
    {
        ans = ans + char(it + 'a');
    }
    return ans;
}

int main()
{
    int N = 5;
    int K = 4;
    string dict[] = {
        "baa",
        "abcd",
        "abca",
        "cab",
        "cad"};

    string ans = findOrder(dict, N, K);
    cout << ans;
}