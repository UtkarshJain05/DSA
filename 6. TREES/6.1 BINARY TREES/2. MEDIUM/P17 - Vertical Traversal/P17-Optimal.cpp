// Vertical Traversal. --> TC:O(N*logN)  SC:O(2N)

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
    if (!root)
        return ans;
    map<int, map<int, multiset<int>>> nodes;
    queue<pair<Node *, pair<int, int>>> q;
    q.push({root, {0, 0}});
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        int x = it.second.first;
        int y = it.second.second;
        root = it.first;
        nodes[x][y].insert(root->data);
        if (root->left)
            q.push({root->left, {x - 1, y + 1}});
        if (root->right)
            q.push({root->right, {x + 1, y + 1}});
    }
    for (auto p : nodes)
    {
        vector<int> temp;
        for (auto q : p.second) 
        {
            temp.insert(temp.end(), q.second.begin(), q.second.end());
        }
        ans.push_back(temp);
    }
    return ans;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(10);
    root->left->left->right = new Node(5);
    root->left->left->right->right = new Node(6);
    root->right = new Node(3);
    root->right->left = new Node(9);
    root->right->right = new Node(10);

    vector<vector<int>> ans = fnc(root);

    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
    }
}
