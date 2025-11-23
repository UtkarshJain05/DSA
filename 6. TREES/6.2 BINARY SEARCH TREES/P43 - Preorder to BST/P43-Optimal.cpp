// Construct preorder to BST.(Optimal)   TC:O(N)   SC:O(N)

// using range --> upper bound.
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node*build(vector<int>&pre,int&i,int bound)
{
    if(i==pre.size()||pre[i]>bound) return nullptr;

    Node*root = new Node(pre[i++]);
    root->left = build(pre,i,root->data);
    root->right = build(pre,i,bound);
    return root;
}

Node *construct_bst(vector<int> &pre)
{
    int i =0;
    return build(pre,i,INT_MAX);
}

void print(Node *root)
{
    if (!root)
        return;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            Node *node = q.front();
            q.pop();
            cout << node->data << " ";
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        cout << endl;
    }
}

int main()
{
    vector<int> pre = {8, 5, 1, 7, 10, 12};
    Node *root = construct_bst(pre);
    print(root);
}