// Zig ZagTraversal. --> TC:O(N)    SC:O(N).

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

vector<vector<int>> fnc(Node *root)
{
    vector<vector<int>> ans;
    if (root == nullptr)
        return ans;
    queue<Node *> q;
    q.push(root);
    int level = 1;
    while (!q.empty())
    {
        int n = q.size();
        vector<int> row;
        for (int i = 0; i < n; i++)
        {
            root = q.front();
            row.push_back(root->data);
            q.pop();
            if (root->left != nullptr)
                q.push(root->left);
            if (root->right != nullptr)
                q.push(root->right);
        }
        if (level % 2 == 0)
            reverse(row.begin(), row.end());
        ans.push_back(row);
        level++;
    }
    return ans;
}

int main()
{
    Node *root1 = new Node(1);
    root1->left = new Node(2);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);
    root1->right = new Node(3);
    root1->right->right = new Node(6);

    vector<vector<int>> ans = fnc(root1);
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
    }
}