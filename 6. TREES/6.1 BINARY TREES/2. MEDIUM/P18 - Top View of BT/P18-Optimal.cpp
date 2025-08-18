// Top View of BT  --> TC:O(NlogN)    SC:O(2N)

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

vector<int> fnc(Node *root)
{
    vector<int> ans;
    if (root == nullptr)
        return ans;
    map<int, int> mp;
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        auto it = q.front();
        root = it.first;
        int x = it.second;
        q.pop();
        if (mp.find(x) == mp.end())
            mp[it.second] = root->data;
        if (root->left)
            q.push({root->left, x - 1});
        if (root->right)
            q.push({root->right, x + 1});
    }

    for (auto i : mp)
    {
        ans.push_back(i.second);
    }
    return ans;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> ans = fnc(root);
    for (auto i : ans)
    {
        cout << i << " ";
    }
}