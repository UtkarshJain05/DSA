// Successor in BST. (Optimal)  -->  TC:O(N)  SC:O(1).

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

int successor(Node *root, int k)
{
    if (!root)
        return -1;
    int ans = INT_MAX;
    while (root)
    {
        if (root->data > k)
        {
            ans = min(ans, root->data);
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return ans;
}

int main()
{
    Node *root = new Node(9);
    root->left = new Node(5);
    root->left->left = new Node(2);
    root->left->left->left = new Node(1);
    root->left->left->right = new Node(3);
    root->left->left->right->right = new Node(4);
    root->left->right = new Node(7);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(8);
    root->right = new Node(12);

    cout << successor(root, 5);
}
