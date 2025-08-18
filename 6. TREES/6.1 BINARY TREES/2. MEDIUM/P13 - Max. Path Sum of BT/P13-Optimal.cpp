// MaxPath of Binary Tree. --> TC:O(N)  SC:O(N)

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

int rec(Node *root, int &maxi)
{
    if (root == nullptr)
        return 0;
    int lh = max(0, rec(root->left, maxi));
    int rh = max(0, rec(root->right, maxi));
    maxi = max(maxi, (root->data) + lh + rh);
    return (root->data) + max(lh, rh);
}

int fnc(Node *root)
{
    int ans = 0;
    rec(root, ans);
    return ans;
}

int main()
{
    Node *root = new Node(-10);
    root->left = new Node(9);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right = new Node(7);
    int ans = fnc(root);
    cout << ans;
}