// CHecking for BST or BT.(Recursive)   TC:O(N)  SC:O(N).

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

bool isvalidBST(Node *root, int min_val, int max_val)
{
    if (!root)
        return true;
    if ( root->data <=min_val || root->data >= max_val)
        return false;
    return isvalidBST(root->left, min_val, root->data) && isvalidBST(root->right, root->data, max_val);
}

bool Check(Node *root)
{
    return isvalidBST(root, INT_MIN, INT_MAX);
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

    (Check(root) != 0) ? cout << "BST." : cout << "BT.";
}