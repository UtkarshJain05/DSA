// Lowest Common Ancestor --> TC:O(N)    SC:O(N)

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node *rec(Node *root, Node *p, Node *q)
{
    if (root == nullptr || root == p || root == q)
        return root;

    Node *l = rec(root->left, p, q);
    Node *r = rec(root->right, p, q);

    if (l == nullptr)
        return r;
    else if (r == nullptr)
        return l;
    else   // result
        return root;
}

int fnc(Node *root, Node *p, Node *q)
{
    if (!root)
        return 0;
    Node *ans;
    ans = rec(root, p, q);
    return ans->data;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->left->left = new Node(8);
    root->right->right = new Node(5);
    root->right->right->left = new Node(6);
    root->right->right->right = new Node(7);

    cout << fnc(root, root->right->right->right, root->right->left->left);
}