// Ceil In a Binary Search Tree.(Optimal) --> TC:O(logN)   SC:O(1).

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

int Ceil(Node *root, int val)
{
    int ceil = -1;
    while (root != nullptr)
    {
        if (root->data == val)
        {
            ceil = root->data;
            return ceil;
        }
        if (root->data > val)
        {
            ceil = root->data;
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return ceil;
}
int main()
{
    Node *root = new Node(10);
    root->left = new Node(5);
    root->left->left = new Node(3);
    root->left->left->left = new Node(2);
    root->left->left->right = new Node(4);
    root->left->right = new Node(6);
    root->left->right->right = new Node(9);
    root->right = new Node(13);
    root->right->left = new Node(11);
    root->right->right = new Node(14);

    int ans = Ceil(root, 11);
    cout << ans;
}