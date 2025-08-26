// Burn The Tree From a Node. --> TC:O(2N)   SC:O(3N).

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void parent(Node *root, unordered_map<Node *, Node *> &parent_track)
{
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();
        if (node->left)
        {
            parent_track[node->left] = node;
            q.push(node->left);
        }
        if (node->right)
        {
            parent_track[node->right] = node;
            q.push(node->right);
        }
    }
}

int fnc(Node *root, Node *t)
{
    unordered_map<Node *, Node *> parent_track;
    parent(root, parent_track);

    unordered_map<Node *, bool> vis;
    queue<Node *> q;
    int ans = 0;

    q.push(t);
    vis[t] = true;
    while (!q.empty())
    {
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
            if (parent_track[node] && !vis[parent_track[node]])
            {
                q.push(parent_track[node]);
                vis[parent_track[node]] = true;
            }
        }
        if (!q.empty())
            ans++;
    }
    return ans;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->left->right = new Node(7);
    root->right->left = new Node(5);
    root->right->right = new Node(6);

    Node *target = root->left;
    cout << fnc(root, target);
}