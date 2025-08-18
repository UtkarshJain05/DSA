// Diameter Of BT --> TC:O(N)   SC:O(N)

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

int recur(Node *root, int &maxi)
{
    if (root == nullptr)
        return 0;
    int lh = recur(root->left, maxi);
    int rh = recur(root->right, maxi);
    maxi = max(maxi, lh + rh);
    return 1 + max(lh, rh);
}

int fnc(Node *root)
{
    int result = 0;
    int ans = recur(root, result);
    return result;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(6);
    root->left->left = new Node(5);
    int ans = fnc(root);
    cout << ans;
}