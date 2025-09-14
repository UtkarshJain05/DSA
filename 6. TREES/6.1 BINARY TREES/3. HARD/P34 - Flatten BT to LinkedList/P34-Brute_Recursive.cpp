// BT to LinkedList (Recursive).(Brute) --> TC:O(N)   SC:O(N).

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void to_Linkedlist(Node *&root, Node *&prev)
{
    if (!root)
        return;
    to_Linkedlist(root->right, prev);
    to_Linkedlist(root->left, prev);

    root->right = prev;
    root->left = nullptr;
    prev = root;
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
    Node *prev = nullptr;
    to_Linkedlist(root, prev);
    Node *curr = root;
    while (curr != nullptr)
    {
        cout << curr->data << " ";
        curr = curr->right;
    }
}