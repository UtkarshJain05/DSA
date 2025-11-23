// Finding LCA in BST .   TC:O(h)  SC:O(1).

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

int lca(Node *root, int p, int q)
{
    if (!root)
        return -1;
    if ((root->data >= p && root->data <= q) || (root->data >= q && root->data <= p))
        return root->data;
    if (root->data < p && root->data < q)
        return lca(root->right, p, q);
    if (root->data > p && root->data > q)
        return lca(root->left, p, q);
    return -1;
}

int main()
{
    Node *root = new Node(8);
    root->left = new Node(5);
    root->left->left = new Node(2);
    root->left->left->left = new Node(1);
    root->left->left->right = new Node(3);
    root->left->left->right->right = new Node(4);
    root->left->right = new Node(7);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(8);
    root->right = new Node(12);

    cout << lca(root, 2, 6);
}