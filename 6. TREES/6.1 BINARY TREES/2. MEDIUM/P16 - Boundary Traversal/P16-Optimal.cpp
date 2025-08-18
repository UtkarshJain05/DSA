// Boundary Traversal. --> TC:O(N)  SC:O(N)

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

bool isLeaf(Node *node)
{
    return (node != nullptr && node->left == nullptr && node->right == nullptr);
}

void addleft(Node *root, vector<int> &res)
{
    Node *curr = root->left;
    while (curr)
    {
        if (!isLeaf(curr))
            res.push_back(curr->data);
        if (curr->left)
            curr = curr->left;
        else
            curr = curr->right;
    }
    return;
}

void addright(Node *root, vector<int> &res)
{
    Node *curr = root->right;
    stack<int> s;
    while (curr)
    {
        if (!isLeaf(curr))
            s.push(curr->data);
        if (curr->right)
            curr = curr->right;
        else
            curr = curr->left;
    }
    while(!s.empty()){
        res.push_back(s.top());
        s.pop();
    }
}

void addleaf(Node *root, vector<int> &res)
{
    if (isLeaf(root))
    {
        res.push_back(root->data);
        return;
    }
    if (root->left)
        addleaf(root->left, res);
    if (root->right)
        addleaf(root->right, res);
}

vector<int> fnc(Node *root)
{
    vector<int> res;
    if (!root)
        return res;
    if (!isLeaf(root))
        res.push_back(root->data);
    addleft(root, res);
    addleaf(root, res);
    addright(root, res);
    return res;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(3);
    root->left->left->right = new Node(4);
    root->left->left->right->left = new Node(5);
    root->left->left->right->right = new Node(6);
    root->right = new Node(7);
    root->right->right = new Node(8);
    root->right->right->left = new Node(9);
    root->right->right->left->left = new Node(10);
    root->right->right->left->right = new Node(11);

    vector<int> ans = fnc(root);

    for (auto j : ans)
    {
        cout << j << " ";
    }
}
