// Search In a Binary Search Tree.(Optimal) --> TC:O(logN)   SC:O(1).

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node *Search(Node *root, int val)
{
    while (root != nullptr && root->data != val)
    {
        root = (root->data > val) ? root->left : root->right;
    }
    return root;
}
int main()
{
    Node *root = new Node(8);
    root->left = new Node(5);
    root->left->left = new Node(4);
    root->left->right = new Node(7);
    root->left->right->left = new Node(6);
    root->right = new Node(12);
    root->right->left = new Node(10);
    root->right->right = new Node(14);
    root->right->right->left = new Node(13);

    Node *ans = Search(root, 9);
    ans != nullptr ? cout << "Found.\n\n" : cout << "Not Found.\n\n";
}