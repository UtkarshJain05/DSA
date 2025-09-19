// Floor In a Binary Search Tree.(Optimal) --> TC:O(logN)   SC:O(1).

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

int Floor(Node *root, int val)
{
    int floor = -1;
    while (root != nullptr)
    {
        if (root->data == val)
        {
            floor = root->data;
            return floor;
        }
        if (root->data < val)
        {
            floor = root->data;
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    return floor;
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

    int ans = Floor(root, 15);
    cout << ans;
}