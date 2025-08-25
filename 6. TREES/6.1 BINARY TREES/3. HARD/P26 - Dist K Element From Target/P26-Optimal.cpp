// Print All Nodes at a dist of k -->  TC:(3N)   SC:O(2N).

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void store_parent(Node *root, unordered_map<Node *, Node *> &mp)
{
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();
        if (node->left)
        {
            mp[node->left] = node;
            q.push(node->left);
        }
        if (node->right)
        {
            mp[node->right] = node;
            q.push(node->right);
        }
    }
}

vector<int> fnc(Node *root, Node *&target, int k)
{
    unordered_map<Node *, Node *> parent;
    store_parent(root, parent);

    int level = 0;
    unordered_map<Node *, bool> vis;
    queue<Node *> q;
    q.push(target);
    vis[target] = true;
    while (!q.empty())
    {
        if (level == k)
            break;
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            Node *node = q.front();
            q.pop();
            if (node->left && !vis[node->left])
            {
                q.push(node->left);
                vis[node->left] = true;
            }
            if (node->right && !vis[node->right])
            {
                q.push(node->right);
                vis[node->right] = true;
            }

            if (parent[node] && !vis[parent[node]])
            {
                q.push(parent[node]);
                vis[parent[node]] = true;
            }
        }
        level++;
    }

    vector<int> ans;
    while (!q.empty())
    {
        ans.push_back(q.front()->data);
        q.pop();
    }
    return ans;
}

int main()
{
    Node *root = new Node(3);
    root->left = new Node(5);
    root->left->left = new Node(6);
    root->left->right = new Node(2);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(4);
    root->right = new Node(1);
    root->right->left = new Node(0);
    root->right->right = new Node(8);

    vector<int> ans = fnc(root, root->left, 2);
    for (auto u : ans)
    {
        cout << u << " ";
    }
}