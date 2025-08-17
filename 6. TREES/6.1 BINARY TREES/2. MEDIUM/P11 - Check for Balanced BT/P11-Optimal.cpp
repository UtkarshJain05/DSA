// Check for Balanced Binary Tree --> TC:O(N)   SC:O(N)

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

int fnc(Node *root)
{
    if (root == nullptr)
        return 0;
    int lh = fnc(root->left);
    if (lh == -1)
        return -1;
    int rh = fnc(root->right);
    if (rh == -1)
        return -1;
    if (abs(lh - rh) > 1)
        return -1;
    return 1 + max(lh, rh);
}

int main()
{
    Node *root = new Node(1);

    root->left = new Node(2);
    root->left->left = new Node(3);
    root->left->left->left = new Node(4);

    int ans = fnc(root);
    if (ans == -1)
        cout << "False.";
    else
        cout << "True.";
}
