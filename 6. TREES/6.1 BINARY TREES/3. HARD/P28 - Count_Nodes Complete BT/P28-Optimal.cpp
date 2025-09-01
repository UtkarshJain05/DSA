// Count Nodes of Complete BT.(Optimal) --> TC:O(N)   SC:O(N).

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

int lheight(Node *root)
{
    int lh = 0;
    while (root)
    {
        lh++;
        root = root->left;
    }
    return lh;
}

int rheight(Node *root)
{

    int rh = 0;
    while (root)
    {
        rh++;
        root = root->right;
    }
    return rh;
}

int count_nodes(Node *root)
{
    if (!root)
        return 0;
    int lh = lheight(root);
    int rh = rheight(root);
    if (lh == rh)
    // 1<<lh = 2^lh
        return (1<<lh)-1;

    return 1 + count_nodes(root->left) + count_nodes(root->right);
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);
    root->left->right = new Node(5);
    root->left->right->left = new Node(9);
    root->left->right->right = new Node(10);
    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    int cnt = count_nodes(root);
    cout << cnt;
}