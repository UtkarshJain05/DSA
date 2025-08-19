// Symmetrical BT or not.  --> TC:O(N)  SC:O(N)

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// p = Original Root
// q = Mirror Root
bool rec(Node *p, Node *q)
{
    if (!p || !q)
        return (p == q);
    return (p->data == q->data) &&
           rec(p->left, q->right) &&
           rec(p->right, q->left);
}

bool fnc(Node *root)
{
    if (!root)
        return root == nullptr;
    return rec(root, root);
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->right->right = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(4);

    bool ans = fnc(root);
    (ans == 1) ? cout << "Symmetric." : cout << "Unsymmetric.";
}
