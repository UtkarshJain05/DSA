// Inorder Travesal {Recursive} --> TC:O(N)  SC:(N)

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void inorder(Node *root, vector<int> &arr)
{
    if (root == nullptr)
        return;
    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}

vector<int> fnc(Node *root)
{
    vector<int> arr;
    inorder(root, arr);
    return arr;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->right = new Node(3);
    root->right->left = new Node(7);
    root->right->right = new Node(8);
    root->right->right->left = new Node(9);
    root->right->right->right = new Node(10);

    vector<int> result = fnc(root);
    for (auto i : result)
    {
        cout << i << " ";
    }
}