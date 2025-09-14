// BT to LinkedList (Optimal) --> TC:O(N)   SC:O(1).

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void to_Linkedlist(Node *root)
{
    if (!root)
        return;
    Node *curr = root;
    while (curr != nullptr)
    {
        if (curr->left != nullptr)
        {
            Node *prev = curr->left;
            while (prev->right)
            {
                prev = prev->right;
            }
            if (prev->right == nullptr)
            {
                prev->right = curr->right;
                curr->right = curr->left;
            }
        }
        curr = curr->right;
    }
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->right->left = new Node(8);

    to_Linkedlist(root);
    Node *curr = root;
    while (curr != nullptr)
    {
        cout << curr->data << " ";
        curr = curr->right;
    }
}