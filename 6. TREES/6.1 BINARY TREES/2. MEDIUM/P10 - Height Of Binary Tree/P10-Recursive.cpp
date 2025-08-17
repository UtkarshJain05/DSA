// Maximum Depth In Binary Tree.(Recursive) --> TC:O(N)  SC:O(N)

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
    int rh = fnc(root->right);
    return 1 + max(lh, rh);
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(6);
    root->right->left->left = new Node(5);
    int ans = fnc(root);
    cout << ans;
}